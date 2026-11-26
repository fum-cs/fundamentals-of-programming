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

assert.ok(examples.length > 0, 'The downloadable notebook must keep its runnable C cells');
const missing = examples.filter((source) => !rendered.has(source));
assert.equal(missing.length, 0, `${missing.length} examples did not render as C: ${missing[0]}`);
assert.ok(html.includes('language-c'), 'Static HTML must highlight C');
const search = readFileSync(join(output, 'myst.search.json'), 'utf8');
assert.ok(!html.includes('_PAGE_B64') && !search.includes('_PAGE_B64'), 'The notebook-only HTML runner leaked into the book');
assert.ok(!html.includes('نمای کامل (عین فایل HTML اصلی)'), 'The notebook-only heading leaked into the book');
const streams = nodes.filter((node) => node.jupyter_data?.output_type === 'stream')
  .map((node) => node.jupyter_data.text.trim());
assert.ok(streams.some((text) => text.endsWith('13 13 13 13')), 'Saved output from printf is missing');
assert.ok(streams.some((text) => text.endsWith('items read: 0')), 'Saved output from scanf is missing');
assert.ok(streams.every(Boolean), 'Empty stream output is displayed');
for (const id of [10, 11, 34, 48, 66]) {
  assert.ok(html.includes(`id="sec-${id}"`), `Missing HTML link target: sec-${id}`);
}
const download = html.match(/\/_public\/(part-two-[\da-f]+\.ipynb)/)?.[1];
assert.ok(download, 'Part 2 notebook is not downloadable');
assert.ok(readFileSync(join(output, '_public', download)).equals(readFileSync(sourcePath)), 'The exported notebook changed');
console.log(`Part 2: ${examples.length} runnable examples render as C, with outputs and working references`);
