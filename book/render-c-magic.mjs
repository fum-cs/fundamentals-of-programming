export const plugin = {
  name: 'C notebook examples',
  transforms: [{
    name: 'render-c-magic',
    stage: 'document',
    plugin: (_options, { selectAll }) => (tree) => {
      // Omit notebook-only cells from the HTML, outline, and search index.
      tree.children = tree.children.filter((node) => !node.data?.tags?.includes('notebook-only'));

      for (const code of selectAll('block[kind=notebook-code] > code[executable=true][lang=python]', tree)) {
        const body = code.value.replace(/^%%c(?:[ \t][^\r\n]*)?\r?\n/, '');
        if (body === code.value) continue;

        // MyST runs the original Python cell before formatting it for the book.
        code.value = body;
        code.lang = 'c';
        code.executable = false;
      }
    },
  }],
};
