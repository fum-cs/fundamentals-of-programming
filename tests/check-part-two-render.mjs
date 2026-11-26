import assert from 'node:assert/strict';
import { readFileSync } from 'node:fs';
import { join } from 'node:path';

const output = process.argv[2] ?? '_build/html';
const sourcePath = new URL('../book/parts/p02-data-operators/part-two.ipynb', import.meta.url);
const notebook = JSON.parse(readFileSync(sourcePath, 'utf8'));
const page = JSON.parse(readFileSync(join(output, 'part-two.json'), 'utf8'));
const html = readFileSync(join(output, 'part-two', 'index.html'), 'utf8');

function* walk(node) {
  yield node;
  for (const child of node.children ?? []) yield* walk(child);
}

const examples = notebook.cells.filter((cell) => cell.cell_type === 'code')
  .map((cell) => cell.source.join(''))
  .filter((source) => /^%%c(?:\s|$)/.test(source))
  .map((source) => source.slice(source.indexOf('\n') + 1).trimEnd());
const nodes = [...walk(page.mdast)];
const rendered = new Set(nodes.filter((node) => node.type === 'code' && node.lang === 'c' && !node.executable)
  .map((node) => node.value.trimEnd()));

assert.ok(examples.some((source) => source.includes('scanf("%49s", name)')), 'The complete input example must be runnable');
const missing = examples.filter((source) => !rendered.has(source));
assert.equal(missing.length, 0, `${missing.length} examples did not render as C: ${missing[0]}`);
assert.equal(page.frontmatter.title, 'بخش دوم: داده‌ها و عملگرها');
const authors = page.frontmatter.authors.map((author) => author.name);
for (const name of ['ملیکا محمدبیگی', 'درسا عناصری', 'زینب قاراچشمه']) assert.ok(authors.includes(name));
assert.ok(html.includes('language-c'), 'Static HTML must highlight C');
const search = readFileSync(join(output, 'myst.search.json'), 'utf8');
assert.ok(!html.includes('def run_c(') && !search.includes('def run_c('), 'The notebook-only compiler leaked into the book');
const streams = nodes.filter((node) => node.jupyter_data?.output_type === 'stream')
  .map((node) => node.jupyter_data.text.trim());
assert.ok(streams.some((text) => /\b13 13 13 13\b/.test(text)), 'Saved output from printf is missing');
assert.ok(streams.some((text) => /\b1\n7\n6\n10\n2$/.test(text)), 'Saved output from the bitwise example is missing');
assert.ok(streams.every(Boolean), 'Empty stream output is displayed');
assert.ok([...rendered].some((source) => source.includes('int 2ndYear = 5;')), 'The invalid identifier example should still be displayed');
assert.ok(!examples.some((source) => source.includes('int 2ndYear = 5;') || source.includes('x + 1); // وارد محدوده')), 'An intentionally invalid example became executable');
assert.ok(html.includes('Name: Banafsheh'), 'The sample input transcript is missing');
const download = html.match(/\/_public\/(part-two-[\da-f]+\.ipynb)/)?.[1];
assert.ok(download, 'Part 2 notebook is not downloadable');
assert.ok(readFileSync(join(output, '_public', download)).equals(readFileSync(sourcePath)), 'The exported notebook changed');
console.log(`Part 2: ${examples.length} runnable examples render as C; saved outputs and notebook download verified`);
