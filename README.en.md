# Fundamentals of Programming (C) — مبانی کامپیوتر و برنامه‌سازی

[فارسی](README.md) | **English**

Course book and materials for **Computer Fundamentals and Programming**
(B.Sc., first year), [Computer Science Dept., Ferdowsi University of Mashhad](https://fum-cs.github.io/).

- **Online book:** <https://fum-cs.github.io/fundamentals-of-programming/>
- **Official syllabus:** [Computer-Fundamentals-and-Programming](https://fum-cs.github.io/docs/curriculum/base/Computer-Fundamentals-and-Programming)
- **Instructor:** Dr. Mahmood Amintoosi

> The book text is written in **Persian**. Code, identifiers and technical terms
> are in English.

The language of the course is **C**, but the emphasis is on problem solving and
algorithmic thinking: the computer as a computational model, algorithms, and
then a high-level language to express them (functions, arrays, files,
recursion, searching and sorting).

## Contents

Eight parts, 17 chapters in total (numbered continuously):

| Part | Title | Folder | Status |
|:--|:--|:--|:--|
| 1 | Foundations (algorithm, computer and data, C and tooling) | `book/parts/p01-basics/` | ✅ |
| 2 | Data and operators | `book/parts/p02-data-operators/` | ✅ |
| 3 | Control flow | `book/parts/p03-control-flow/` | ✅ |
| 4 | Functions and recursion (ch. 8–10) | `book/parts/p04-functions/` | ✅ |
| 5 | Basic data structures: arrays, searching/sorting, strings (ch. 11–13) | `book/parts/p05-basic-data-structures/` | ✅ |
| 6 | Pointers and dynamic memory (ch. 14–15) | `book/parts/p06-pointers-memory/` | ✅ |
| 7 | Structs, unions and files (ch. 16–17) | `book/parts/p07-structs-files/` | ✅ |
| 8 | Miscellaneous topics (preprocessor, command-line arguments, …) | `book/parts/p08-misc/` | 🚧 placeholder |

## Repository layout

```
myst.yml                  # book configuration + table of contents (the one in use)
book/
  index.md                # landing page
  style.css               # RTL / Persian styling (Vazirmatn font)
  parts/pNN-topic/
    part-xxx.ipynb        # the part as a notebook (listed in the TOC)
    part-xxx.md           # the same part as Markdown
    src/                  # C example programs: pNN_cCC_SS_name.c
    images/               # images used by this part only
.github/workflows/        # Pages deployment, build check, C examples check
docs/                     # style guide and part template
```

## Build locally

Built with **Jupyter Book 2** (MyST). From the repository root:

```bash
pip install jupyter-book                 # or: npm install -g jupyter-book
env -u PORT jupyter book build --html    # output: _build/html/
```

Open the result through a web server (not by double-clicking `index.html`);
see [production.md](production.md). Every push to `main` is deployed to GitHub
Pages automatically.

## Run the C examples

```bash
gcc -std=c11 -Wall -Wextra -o prog book/parts/p01-basics/src/p01_c01_02_max_of_five.c
./prog
```

## Contributing

Maintained by the instructor and TAs; readers are welcome to report mistakes.
See [CONTRIBUTING.md](CONTRIBUTING.md) (Persian) and
[open an issue](../../issues/new/choose) for typos, wrong explanations or
broken examples.

## Status

🚧 Under construction for the current semester.
