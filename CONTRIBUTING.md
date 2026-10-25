# Contributing

This repository is co-managed by the instructor and the teaching assistants
(TAs). These conventions keep the book buildable, the code consistent, and the
history reviewable.

**Contents**

1. [Workflow](#workflow)
2. [Repository layout](#repository-layout)
3. [Naming conventions](#naming-conventions)
4. [C code style](#c-code-style)
5. [Writing lectures and notebooks](#writing-lectures-and-notebooks)
6. [Common tasks](#common-tasks)
7. [Pull request checklist](#pull-request-checklist)

## Workflow

- TAs open pull requests (PRs); the instructor reviews and merges.
- Small fixes (typos, broken links) may be pushed directly to `main` by the
  instructor.
- Every push to `main` redeploys the site to GitHub Pages, so build locally
  before pushing.
- Use of AI tools is allowed, as in the course policy, but the contributor is
  responsible for understanding and verifying everything they submit.

## Repository layout

```
index.md                        # book cover / landing page
myst.yml                        # ALL book config: metadata + table of contents
production.md                   # build and serve instructions
.github/workflows/deploy.yml    # Pages deployment (do not edit casually)

chNN-topic/                     # one folder per chapter
├── lecture.md / .ipynb         # main lecture
├── exercises.md / .ipynb       # practice problems
├── supplementary.md / .ipynb   # optional deeper material
├── src/                        # C sources and headers
├── bin/                        # compiled executables built from src/
└── images/                     # figures used by this chapter
```

Rules:

- The `.md` and `.ipynb` files with the same name are two forms of one
  document. Edit one, then regenerate the other (for example with
  `jupytext --sync <file>`) so they never diverge.
- Files in `bin/` are build products. Never edit them by hand; rebuild them
  from `src/`.
- Keep assets next to the chapter that uses them (`images/` inside the chapter).
- Do not commit `_build/` or `.ipynb_checkpoints/`.

## Naming conventions

### Guiding principle

Anything that can end up inside a C identifier or a compiled program uses
`snake_case`. Everything else (folders, documents, images, branches, labels)
uses `kebab-case`. Use English, ASCII letters, digits, and the separators
listed below. No spaces, no uppercase letters in file names.

### Quick reference

| Item | Convention | Example |
|------|------------|---------|
| Chapter folder | `chNN-kebab-case` | `ch04-functions-and-recursion` |
| Chapter documents | fixed names | `lecture.md`, `exercises.ipynb`, `supplementary.md` |
| C source file | `pPP_cLL_SS_snake_case.c` | `p05_c12_03_bubble_sort.c` |
| Compiled program | source name, no extension | `p05_c12_03_bubble_sort` |
| Header file | `snake_case.h` | `adt.h` |
| Hero animation | `pPP_hero_snake_case.gif` | `p05_hero_bubble_sort.gif` |
| Image file | `kebab-case.ext` | `tony-hoare.jpg` |
| Data file | `kebab-case.ext` | `students-sample.csv` |
| Shell script | `kebab-case.sh` | `build-all.sh` |
| Python script | `snake_case.py` | `check_links.py` |
| Variable, function, parameter | `snake_case` | `max_value`, `find_min()` |
| Constant, macro | `UPPER_SNAKE_CASE` | `MAX_STUDENTS` |
| Type (typedef) | `snake_case_t` | `student_t` |
| Struct or enum tag | `snake_case` | `struct student` |
| Enum constant | `ENUM_PREFIX_NAME` | `COLOR_RED` |
| Include guard | `PATH_FILE_H` | `ADT_H` |
| MyST label | `prefix-kebab-case` | `fig-bubble-sort` |
| Branch | `type/kebab-case` | `docs/ch05-sorting-exercises` |
| Commit message | Conventional Commits | `feat(ch05): add insertion sort example` |
| Git tag | `YYYY-T` for a term | `1405-1` |

### Folders and documents

- Chapters are numbered with two digits and a short topic name:
  `ch06-pointers-memory`. Keep the number in sync with the order in `myst.yml`.
- Inside a chapter, use only the fixed document names `lecture`, `exercises`,
  and `supplementary`. Add new kinds of document only after discussing it.
- Chapter folders use these subfolder names exactly: `src`, `bin`, `images`.

### Example programs (`src/` and `bin/`)

Name example programs `pPP_cLL_SS_slug.c`:

| Part | Meaning | Example |
|------|---------|---------|
| `pPP` | chapter number, two digits | `p04` for `ch04-...` |
| `cLL` | lecture number in the book, two digits | `c09` |
| `SS` | sequence of the example within that lecture, two digits | `05` |
| `slug` | short `snake_case` description, about two to five words | `factorial_trace` |

Result: `p04_c09_05_factorial_trace.c`, compiled to
`bin/p04_c09_05_factorial_trace`.

Slug guidelines:

- Describe what the example demonstrates, not how it is implemented:
  `binary_search`, not `while_loop_example`.
- Use these suffixes or words consistently:
  - `_demo` for a short demonstration of a concept (`leak_demo`)
  - `_wrong` or `_pitfalls` for deliberately incorrect code
  - `_two_ways` or `_vs_` for comparisons (`gcd_two_ways`, `stack_vs_queue`)
  - `_trace` for programs that print their own execution
- Do not renumber existing examples. If an example is removed, leave a gap or
  update every reference to it in the lecture.
- Shared headers (such as `adt.h`) have no numeric prefix and live in `src/`.

### C identifiers

**Variables, parameters, and functions: `snake_case`**

- Variables are nouns (`total_score`), functions are verbs (`compute_average`).
- Arrays and collections use plural nouns: `scores`, `names`.
- Counts and sizes use a prefix or suffix: `num_scores` or `scores_count`,
  `buffer_size`. Pick one style per file.
- Booleans start with `is_`, `has_`, or `can_`: `is_prime`, `has_next`.
- Pointers may carry a `_ptr` suffix when it helps learners see what they are
  looking at: `node_ptr`. A pointer to a pointer may use `_pp`.
- Output parameters may use an `out_` prefix: `out_min`, `out_max`.
- Loop indices are `i`, `j`, `k`. For matrices use `row` and `col`.
- Temporary swap variables are `tmp`.
- Avoid one-letter names elsewhere, except in short mathematical code where the
  letter matches the formula (`n`, `x`, `a`, `b`).
- Global variables are discouraged. If an example needs one to teach scope,
  prefix it with `g_`: `g_call_count`. File-scope `static` variables use `s_`.

**Constants and macros: `UPPER_SNAKE_CASE`**

- `#define MAX_STUDENTS 100`, `const int DAYS_IN_WEEK = 7;`
- Function-like macros are also uppercase and parenthesize every parameter and
  the whole body: `#define SQUARE(x) ((x) * (x))`.
- Prefer `const` and `enum` over `#define` for constants. Macro pitfalls are
  shown only in the examples that teach them.

**Types**

- `typedef` names end with `_t`: `typedef struct student student_t;`
- Struct and enum tags use plain `snake_case`: `struct student { ... };`
- Function pointer types end with `_fn_t`: `typedef int (*compare_fn_t)(const void *, const void *);`

**Enum constants**

- `UPPER_SNAKE_CASE` with the enum name as a prefix, so names do not collide:

  ```c
  typedef enum {
      COLOR_RED,
      COLOR_GREEN,
      COLOR_BLUE
  } color_t;
  ```

**Headers and modules**

- Include guards use the file path in uppercase: `adt.h` gives `ADT_H`.
- Functions that belong to a module share its prefix: `stack_push`,
  `stack_pop`, `stack_is_empty`.

**Labels and `goto`**

- Avoid `goto`. If a lecture needs it, label names are `snake_case`
  (`cleanup:`, `retry:`).

### Documents: headings, labels, and exercises

- Titles of lectures use Title Case; section headings use sentence case.
- MyST labels are `kebab-case` with a type prefix:

  | Prefix | Used for | Example |
  |--------|----------|---------|
  | `sec-` | section | `sec-stack-frames` |
  | `fig-` | figure | `fig-bubble-sort` |
  | `tbl-` | table | `tbl-ascii-codes` |
  | `eq-` | equation | `eq-binomial` |
  | `code-` | code listing | `code-binary-search` |
  | `ex-` | exercise | `ex-05-03` (chapter 05, exercise 3) |

- Exercises are numbered within the chapter: `Exercise 3`, label `ex-05-03`.
- Refer to example programs by their full file name in backticks, for example
  `p05_c12_03_bubble_sort.c`.
- Image alt text describes the image in a full sentence.

### Git and GitHub

**Branches:** `type/kebab-case-description`, optionally with the chapter:

| Type | Use |
|------|-----|
| `feature/` | new lecture, example, or exercise set |
| `fix/` | corrections to content or code |
| `docs/` | README, CONTRIBUTING, and other documentation |
| `refactor/` | renaming or restructuring without changing content |
| `chore/` | tooling, configuration, CI |

Examples: `feature/ch07-file-handling`, `fix/ch06-dangling-demo`,
`docs/update-contributing`.

**Commit messages:** [Conventional Commits](https://www.conventionalcommits.org/),
in the imperative mood, subject line at most 72 characters, no trailing period.

```
type(scope): short summary

Optional body explaining what and why.
```

- Types: `feat`, `fix`, `docs`, `refactor`, `style`, `test`, `build`, `ci`,
  `chore`.
- Scope is the chapter (`ch04`) or area (`ci`, `readme`, `toc`).
- Examples: `feat(ch05): add insertion sort example`,
  `fix(ch06): free memory in realloc_grow`,
  `refactor(ch04): rename examples to pPP_cLL_SS scheme`.

**Pull requests:** the title follows the commit style. The description states
what changed, which chapters are affected, and how it was checked.

**Issues:** a short imperative or descriptive title, such as
`Wrong output in p04_c09_08_fibonacci_calls`.

**Labels:** `kind:name` form, all lowercase.

| Group | Labels |
|-------|--------|
| Kind | `kind:bug`, `kind:content`, `kind:typo`, `kind:enhancement`, `kind:question` |
| Area | `area:ch01` to `area:ch08`, `area:build`, `area:docs` |
| Status | `status:in-progress`, `status:needs-review`, `status:blocked` |

**Tags:** one per term, named after the term: `1405-1`.

## C code style

- Language standard: C11. All examples must compile cleanly with
  `gcc -std=c11 -Wall -Wextra` and produce no warnings. The only exceptions are
  deliberately buggy examples, which must say so.
- Indentation: 4 spaces, no tabs.
- Braces: opening brace on the same line (K&R style). Always use braces, even
  for one-line `if`, `else`, `for`, and `while` bodies.
- One statement per line and one declaration per line.
- Maximum line length: 80 characters.
- Spaces around binary operators and after commas and keywords
  (`if (x > 0)`, `for (int i = 0; i < n; i++)`). No space between a function
  name and its parenthesis.
- Pointer declarations attach the `*` to the name: `int *ptr;`.
- Always check the result of `malloc`, `calloc`, `realloc`, and `fopen`, and
  release what you allocate.
- `main` returns `int` and ends with `return 0;`.
- Comments are in English. Every example starts with a header comment:

  ```c
  /*
   * p05_c12_03_bubble_sort.c
   * Lecture 12: Sorting
   *
   * Demonstrates bubble sort on an integer array and prints each pass.
   */
  ```

- Deliberately incorrect code is marked at the top of the file:

  ```c
  /* INTENTIONALLY BUGGY: demonstrates a memory leak. Do not copy. */
  ```

- Examples should be short and focused: one idea per file, ideally under 60
  lines.

## Writing lectures and notebooks

- Notebooks run top to bottom: keep cells executable and self-contained.
- Clear bulky outputs before committing:
  `jupyter nbconvert --clear-output --inplace file.ipynb`. The site builds from
  source; execution is opt-in (`jupyter book build --html --execute`).
- Include C programs in lectures from `src/` rather than pasting copies, so
  the code on the page and the compiled program cannot drift apart.
- Persian text is allowed in lecture content where the lecture is written in
  Persian. Repository-level files (README, CONTRIBUTING, issue and PR text)
  are written in English.
- Keep images small. Prefer SVG or PNG for diagrams and compress photos.

## Common tasks

### Add a new example program

1. Choose the chapter `PP`, the lecture `LL`, and the next free sequence `SS`.
2. Create `chNN-topic/src/pPP_cLL_SS_slug.c` with the header comment.
3. Build it into `bin/`:

   ```
   gcc -std=c11 -Wall -Wextra -o bin/pPP_cLL_SS_slug src/pPP_cLL_SS_slug.c
   ```

4. Reference it from the lecture, then build the book to check.

### Add a new chapter

1. Create `chNN-topic/` with `lecture`, `exercises`, and `supplementary`
   documents (both `.md` and `.ipynb`).
2. **Add every new file to `myst.yml`.** The table of contents is explicit: a
   file that is not listed is not part of the book. Put it in the right
   `title:` group.
3. Update the chapter tables in `README.md`.

### Build and preview locally

```
env -u PORT jupyter book build --html
```

Details on serving and deployment are in [production.md](production.md).

## Pull request checklist

- [ ] Branch and commit names follow the conventions above.
- [ ] New files follow the naming rules and are listed in `myst.yml`.
- [ ] `.md` and `.ipynb` pairs are in sync.
- [ ] Notebook outputs are cleared where bulky; no `_build/` or checkpoints.
- [ ] All changed C code compiles with `-std=c11 -Wall -Wextra` without
      warnings (except marked buggy examples).
- [ ] `bin/` executables were rebuilt from the current `src/`.
- [ ] The book builds locally with `jupyter book build --html`.
- [ ] README tables are updated if chapters, sessions, or layout changed.
