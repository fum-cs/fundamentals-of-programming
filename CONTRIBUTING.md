# Contributing

This repository is co-managed by the instructor and the teaching assistants
(TAs). These conventions keep the book buildable, the code consistent, and the
history reviewable. Read the whole file once; after that, use the table of
contents to jump to what you need.

**Contents**

1. [Workflow](#workflow)
2. [Repository layout](#repository-layout)
3. [Naming conventions (files, folders, Git)](#naming-conventions-files-folders-git)
4. [C naming conventions](#c-naming-conventions)
5. [C code style](#c-code-style)
6. [Writing lectures and notebooks](#writing-lectures-and-notebooks)
7. [Common tasks](#common-tasks)
8. [Pull request checklist](#pull-request-checklist)

## Workflow

- TAs open pull requests (PRs); the instructor reviews and merges.
- Small fixes (typos, broken links) may be pushed directly to `main` by the
  instructor.
- Every push to `main` redeploys the site to GitHub Pages, so build locally
  before pushing.
- Use of AI tools is allowed, as in the course policy, but the contributor is
  responsible for understanding and verifying everything they submit.
- Language: repository-level files (README, CONTRIBUTING, issues, PRs, commit
  messages, code comments, identifiers) are written in English. Lecture
  content may be written in Persian.

## Repository layout

```
.
├── myst.yml                          # the ONLY book config: metadata + TOC
├── README.md
├── CONTRIBUTING.md
├── production.md                     # build and serve instructions
├── .github/workflows/deploy.yml      # Pages deployment (do not edit casually)
└── book/
    ├── index.md                      # book cover / landing page
    ├── style.css
    ├── sidebar-footer.md
    ├── images/                       # book-wide images (logo, ...)
    ├── lessons/
    │   ├── index.md
    │   └── chNN-topic/               # one folder per chapter
    │       ├── lecture.ipynb / .md           # main lecture
    │       ├── supplementary.ipynb / .md     # optional deeper material
    │       ├── exercises.ipynb / .md         # practice exercises
    │       ├── src/                          # C sources and headers
    │       ├── bin/                          # executables built from src/
    │       └── images/                       # figures used by this chapter
    ├── problems/
    │   ├── index.md
    │   └── chNN-topic/problems.md    # selected problems of the chapter
    └── answers/
        ├── index.md
        └── chNN-topic/answers.md     # selected answers of the chapter
```

Rules:

- There must be exactly **one** `myst.yml`, at the repository root. All paths
  in it are relative to the root (`book/lessons/...`). A second `myst.yml`
  inside `book/` makes MyST treat `book/` as a separate project and breaks the
  build.
- The `.md` and `.ipynb` files with the same name are two forms of one
  document (paired with Jupytext). Edit one, then sync the other so they never
  diverge: `jupytext --sync <file>`. The table of contents lists the `.ipynb`
  files, because some notebooks contain animations.
- Files in `bin/` are build products. Never edit them by hand; rebuild them
  from `src/`.
- Keep assets next to the chapter that uses them (`images/` inside the
  chapter folder).
- Do not commit `_build/`, `venv/`, or `.ipynb_checkpoints/`.

## Naming conventions (files, folders, Git)

### Guiding principle

Anything that can end up inside a C identifier or a compiled program uses
`snake_case`. Everything else (folders, documents, images, branches, labels)
uses `kebab-case`. Use English, ASCII letters, digits, and the separators
listed below. No spaces, no uppercase letters in file names.

C identifiers have their own, much more detailed rules in
[C naming conventions](#c-naming-conventions).

### Quick reference

| Item | Convention | Example |
|------|------------|---------|
| Chapter folder | `chNN-kebab-case` | `ch04-functions-recursion` |
| Lesson documents | fixed names | `lecture.ipynb`, `supplementary.md`, `exercises.ipynb` |
| Problem / answer documents | fixed names | `problems.md`, `answers.md` |
| C source file | `pPP_cLL_SS_snake_case.c` | `p05_c12_03_bubble_sort.c` |
| Compiled program | source name, no extension | `p05_c12_03_bubble_sort` |
| Header file | `snake_case.h` | `adt.h` |
| Hero animation | `pPP_hero_snake_case.gif` | `p05_hero_bubble_sort.gif` |
| Image file | `kebab-case.ext` | `tony-hoare.jpg` |
| Data file | `kebab-case.ext` | `students-sample.csv` |
| Shell script | `kebab-case.sh` | `build-all.sh` |
| Python script | `snake_case.py` | `check_links.py` |
| MyST label | `prefix-kebab-case` | `fig-bubble-sort` |
| Branch | `type/kebab-case` | `docs/ch05-sorting-exercises` |
| Commit message | Conventional Commits | `feat(ch05): add insertion sort example` |
| Git tag | `YYYY-T` for a term | `1405-1` |

### Folders and documents

- Chapters are numbered with two digits and a short topic name:
  `ch06-pointers-memory`. The same folder name is used under `lessons/`,
  `problems/`, and `answers/`. Keep the number in sync with the order in
  `myst.yml`.
- Inside a chapter, use only the fixed document names `lecture`,
  `supplementary`, and `exercises`. Add new kinds of document only after
  discussing it.
- Lesson folders use these subfolder names exactly: `src`, `bin`, `images`.
- Hero animations and figures go in `images/`, not in `bin/`.

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
in the imperative mood, subject line at most 72 characters, no trailing
period.

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

## C naming conventions

All C code in this book (example programs, notebook cells, exercise
skeletons, and answers) follows the rules below. Students copy what they see,
so consistent names are part of the teaching.

### Principles

1. **Names describe meaning, not type or implementation.** `average_score`,
   not `float_value` or `tmp2`.
2. **The shape of a name tells you what it is.** `snake_case` is a variable or
   function, `UPPER_SNAKE_CASE` is a compile-time constant, a `_t` suffix is a
   type, and a short prefix or suffix (`g_`, `s_`, `out_`, `_ptr`) tells you
   about scope or role.
3. **Be consistent inside a file, then across the book.** If two rules both
   fit, follow the more specific one and keep the choice within the file.
4. **Short names are for short scopes.** `i` is fine in a three-line loop;
   a variable that lives across a whole function needs a real name.
5. **English only, ASCII only.** Abbreviate only well-known words (`num`,
   `max`, `min`, `len`, `buf`, `tmp`, `ptr`, `idx`, `src`, `dst`).

### Quick reference

| Kind of identifier | Convention | Example |
|--------------------|------------|---------|
| Local variable | `snake_case` noun | `total_score` |
| Function parameter | `snake_case` noun | `max_value` |
| Function | `snake_case` verb | `compute_average()` |
| Predicate function or boolean | `is_` / `has_` / `can_` | `is_prime()`, `has_next` |
| Array or collection | plural noun | `scores`, `names` |
| Count of elements | `num_` prefix or `_count` suffix | `num_scores`, `scores_count` |
| Size in bytes, capacity | `_size`, `_capacity` | `buffer_size`, `stack_capacity` |
| Loop index | `i`, `j`, `k` / `row`, `col` | `matrix[row][col]` |
| Stored index or position | `_index` suffix | `start_index`, `max_index` |
| Temporary swap variable | `tmp` | `tmp = a; a = b; b = tmp;` |
| Pointer variable | `_ptr` suffix (when helpful) | `node_ptr` |
| Pointer to pointer | `_pp` suffix | `head_pp` |
| Output parameter | `out_` prefix | `out_min`, `out_max` |
| Input-and-output parameter | `inout_` prefix | `inout_total` |
| File handle | `_file` suffix | `in_file`, `out_file` |
| Global variable | `g_` prefix | `g_call_count` |
| File-scope `static` variable | `s_` prefix | `s_next_id` |
| Constant, object-like macro | `UPPER_SNAKE_CASE` | `MAX_STUDENTS`, `PI` |
| Function-like macro | `UPPER_SNAKE_CASE` | `SQUARE(x)` |
| Feature or debug switch | `ENABLE_` / `DEBUG_` prefix | `ENABLE_TRACE` |
| Size or limit constant | `MAX_` / `MIN_` / `NUM_` prefix, `_SIZE` / `_CAPACITY` suffix | `MAX_NAME_LENGTH`, `LINE_SIZE` |
| Include guard | `FILE_NAME_H` | `ADT_H` |
| Struct tag | `snake_case` | `struct student` |
| Typedef name | `snake_case_t` | `student_t` |
| Enum type | `snake_case_t` | `color_t` |
| Enum constant | `ENUMNAME_VALUE` | `COLOR_RED` |
| Bit flag constant | `NAME_FLAG_VALUE` | `FILE_FLAG_READ` |
| Union tag and typedef | `snake_case` / `snake_case_t` | `number_value_t` |
| Struct or union member | `snake_case`, no prefix | `student->average` |
| Function pointer type | `snake_case_fn_t` | `compare_fn_t` |
| Callback function | `on_` prefix | `on_timeout` |
| Comparator function | `compare_by_` prefix | `compare_by_average` |
| Module function | `module_verb` | `stack_push()` |
| Constructor / destructor | `_create` / `_destroy` | `student_create()` |
| Initializer / cleaner | `_init` / `_deinit` | `stack_init()` |
| Conversion function | `a_to_b` | `celsius_to_fahrenheit()` |
| Label (for `goto`) | `snake_case` | `cleanup:` |
| Source file | `pPP_cLL_SS_slug.c` | `p05_c12_03_bubble_sort.c` |
| Header file | `snake_case.h` | `adt.h` |

### Variables

- Use nouns: `total_score`, `student_name`, `remaining_attempts`.
- Arrays and collections are plural: `scores`, `names`, `students`. A single
  element taken from one is singular: `score`, `name`, `student`.
- Counts and sizes are explicit. Pick one style per file: either `num_scores`
  or `scores_count`. Do not mix them. Use `_size` for bytes or buffer sizes
  and `_capacity` for how much a container can hold. Reserve `length` and
  `len` for strings.
- Booleans read like a yes/no question: `is_prime`, `has_next`, `can_move`.
  Never `flag`, `status`, or negated names such as `is_not_empty`. Use
  `<stdbool.h>` (`bool`, `true`, `false`).
- Loop indices are `i`, `j`, `k`. When the loop walks a matrix use `row` and
  `col`; for binary search use `low`, `high`, `mid`; for two-pointer loops use
  `left` and `right`. An index that is stored and used later gets a full name:
  `max_index`, `start_index`.
- The temporary variable for a swap is `tmp`.
- Accumulators describe what they accumulate: `sum`, `product`, `total_score`,
  `max_value`, `min_value`.
- Characters and strings: `ch` for one character, `str` or a descriptive name
  (`name`, `line`, `word`) for a string, `buffer` or `buf` for a scratch
  array.
- A variable that holds a function result may be called `result`, `status`, or
  `exit_code`, but prefer a name that says what the result is.
- Avoid one-letter names outside loops, except in short mathematical code
  where the letter matches the formula (`n`, `x`, `a`, `b`).
- Declare variables where they are first used, with the narrowest scope.

```c
int scores[MAX_STUDENTS];     /* collection: plural */
int num_scores = 0;           /* count */
double average_score = 0.0;   /* quantity */
bool is_valid = false;        /* boolean question */
char line[LINE_SIZE];         /* string buffer */
```

### Pointers and parameters

- A `_ptr` suffix is encouraged when it helps learners see that a variable is
  an address: `node_ptr`, `students_ptr`, `best_ptr`. It is optional for
  parameters whose type already makes the role obvious (`char *str`).
- A pointer to a pointer uses `_pp`: `head_pp`, `numbers_pp`.
- A pointer to a function is named after what it does, not after its type:
  `compare`, `operation`, `callback`.
- Parameters that the function writes through are marked: `out_` for output
  only, `inout_` for read-modify-write. Put them last in the parameter list.
- Read-only pointer parameters are `const`: `const int *scores`.
- Array parameters come with their size: `int scores[], int num_scores`.
- A `NULL`-able pointer is checked before use; its name does not need a
  special prefix.

```c
/* Finds the smallest and largest value of an array. */
void find_min_max(const int *numbers, int num_numbers,
                  int *out_min, int *out_max);

/* Allocates an array; the caller owns the result. */
bool make_int_array(int count, int **out_array);
```

### Functions

- Function names are verbs or verb phrases: `compute_average`, `print_board`,
  `find_min`. Functions that only answer a question are predicates: `is_prime`,
  `has_next`, `can_move`.
- Functions that convert one thing into another are `a_to_b`:
  `celsius_to_fahrenheit`, `string_to_int`.
- Functions that belong to a module share its name as a prefix, followed by the
  verb: `stack_push`, `stack_pop`, `stack_is_empty`, `student_print`.
- Lifetimes follow a fixed vocabulary:

  | Pair | Meaning |
  |------|---------|
  | `x_create` / `x_destroy` | allocate on the heap and initialize / release |
  | `x_init` / `x_deinit` | initialize or clean up an existing object |
  | `x_open` / `x_close` | acquire and release an external resource |

- Comparators passed to `qsort` or to your own sorting code are named
  `compare_by_<criterion>`: `compare_by_average`, `compare_ints_ascending`.
- Callbacks are named `on_<event>`: `on_error`, `on_item_found`.
- Recursive functions carry the problem in the name; a helper that does the
  real recursion may add `_rec` or `_helper`: `power`, `power_rec`.
- Functions that are not part of a module's public interface are declared
  `static` in the `.c` file. They need no module prefix.
- Getters and setters, where used, are `module_get_field` and
  `module_set_field`.

### Constants and macros

- Compile-time constants use `UPPER_SNAKE_CASE`: macros, enum constants, and
  `const` objects defined at file scope. A `const` local variable or parameter
  is just a read-only variable and stays in `snake_case`.
- Limits and sizes put the meaning first: `MAX_STUDENTS`, `MIN_AGE`,
  `NUM_ROWS`, `NAME_SIZE`, `STACK_CAPACITY`. Use a prefix, not a suffix, for
  limits (`MAX_STUDENTS`, not `STUDENTS_MAX`; see
  [Reserved and risky names](#reserved-and-risky-names)).
- Function-like macros are also uppercase and parenthesize every parameter and
  the whole body: `#define SQUARE(x) ((x) * (x))`.
- On/off switches use `ENABLE_` or `DEBUG_`: `ENABLE_TRACE`, `DEBUG_PRINT`.
- Prefer `const` and `enum` over `#define` for constants. Macro pitfalls are
  shown only in the examples that teach them.
- Magic numbers do not appear in the code. Give them a name, except `0`, `1`,
  and obvious values such as `2` in `n % 2`.

```c
#define MAX_STUDENTS 100
#define SQUARE(x) ((x) * (x))
#define ENABLE_TRACE 1

static const double PI = 3.14159265358979;   /* file-scope constant */
```

### Types

- `typedef` names end with `_t`: `student_t`, `color_t`.
- Struct, enum, and union tags use plain `snake_case`, and the `typedef` is
  written separately, one line after the definition:

  ```c
  struct student {
      char name[NAME_SIZE];
      double average;
  };
  typedef struct student student_t;
  ```

- Members are plain `snake_case` with no prefix and no type hints: `name`,
  `average`, `next_ptr`, not `m_name` or `str_name`.
- Function pointer types end with `_fn_t`:

  ```c
  typedef int (*compare_fn_t)(const student_t *a, const student_t *b);
  ```

- A union is named after what it holds. Its members say which interpretation
  they provide: `as_int`, `as_double`.

  ```c
  union number_value {
      int as_int;
      double as_double;
  };
  typedef union number_value number_value_t;
  ```

- Do not invent a type name that already exists in the standard library or in
  POSIX (`stack_t`, `time_t`, `size_t`, `index_t`, and so on).

### Enums and flags

- An enum constant is `UPPER_SNAKE_CASE` and starts with the enum name, so
  names from different enums never collide:

  ```c
  typedef enum {
      COLOR_RED,
      COLOR_GREEN,
      COLOR_BLUE
  } color_t;
  ```

- Result and error codes use a common `STATUS_` prefix, with `STATUS_OK` for
  success:

  ```c
  typedef enum {
      STATUS_OK,
      STATUS_NULL_ARG,
      STATUS_EMPTY
  } status_t;
  ```

- Bit flags are powers of two, written with shifts, and combined with `|`:

  ```c
  typedef enum {
      FILE_FLAG_READ   = 1 << 0,
      FILE_FLAG_WRITE  = 1 << 1,
      FILE_FLAG_APPEND = 1 << 2
  } file_flag_t;

  unsigned flags = FILE_FLAG_READ | FILE_FLAG_WRITE;
  ```

### Scope and storage

| Scope | Rule | Example |
|-------|------|---------|
| Local | plain `snake_case` | `int total = 0;` |
| Function-local `static` | plain `snake_case`, explained by a comment | `static int call_count;` |
| File-scope `static` | `s_` prefix | `static int s_next_id = 1;` |
| Global (external linkage) | `g_` prefix | `int g_call_count = 0;` |
| Private function | `static`, no prefix | `static int helper(int n)` |
| Public function | module prefix, declared in the header | `stack_push()` |

Global variables are discouraged; use one only in an example that teaches
scope, and then give it the `g_` prefix so it stands out.

### Headers, modules, and include guards

- A module is a `snake_case.h` / `snake_case.c` pair: `value_stack.h`,
  `value_stack.c`. Every public name starts with the module name:
  `value_stack_push`, `value_stack_pop`, `VALUE_STACK_CAPACITY`,
  `value_stack_t`.
- Include guards are the file name in uppercase, with `.` and `/` replaced by
  `_`: `value_stack.h` gives `VALUE_STACK_H`. The closing `#endif` repeats it
  in a comment.

  ```c
  #ifndef VALUE_STACK_H
  #define VALUE_STACK_H

  #include <stdbool.h>

  #define VALUE_STACK_CAPACITY 64

  typedef struct value_stack {
      int items[VALUE_STACK_CAPACITY];
      int top;
  } value_stack_t;

  void value_stack_init(value_stack_t *stack_ptr);
  bool value_stack_push(value_stack_t *stack_ptr, int value);
  bool value_stack_pop(value_stack_t *stack_ptr, int *out_value);
  bool value_stack_is_empty(const value_stack_t *stack_ptr);

  #endif /* VALUE_STACK_H */
  ```

- Headers do not define variables or non-`static` functions.

### Labels and `goto`

- Avoid `goto`. When a lecture needs it (single exit for cleanup), label names
  are `snake_case` and describe the destination: `cleanup:`, `retry:`.

  ```c
  int read_first_line(const char *path, char *out_line, size_t size) {
      FILE *in_file = fopen(path, "r");
      int exit_code = -1;

      if (in_file == NULL) {
          goto cleanup;
      }
      if (fgets(out_line, (int)size, in_file) == NULL) {
          goto cleanup;
      }
      exit_code = 0;
  cleanup:
      if (in_file != NULL) {
          fclose(in_file);
      }
      return exit_code;
  }
  ```

### Reserved and risky names

Some names are reserved by the C standard or POSIX, or silently clash with the
library. Avoid them even when the compiler does not complain:

| Avoid | Why | Use instead |
|-------|-----|-------------|
| Leading underscore (`_count`) or double underscore (`a__b`) | reserved for the implementation | `count`, `a_b` |
| `str`, `mem`, `is`, `to` directly followed by a lowercase letter (`strrev`, `isprime`, `toupper2`) | reserved for future `<string.h>` and `<ctype.h>` functions | `str_reverse`, `is_prime`, `to_upper` |
| Macros starting with `E` plus a digit or uppercase letter (`EMPTY`, `ERR_FULL`) | reserved for `<errno.h>` | `STATUS_EMPTY`, `STATUS_FULL` |
| Types `intN_t` / `uintN_t` shapes (`int_stack_t`) | reserved for `<stdint.h>` | `value_stack_t` |
| Macros ending in `_MAX` or `_MIN` (`STUDENTS_MAX`) | reserved by `<limits.h>` and `<stdint.h>` | `MAX_STUDENTS` |
| Library names as your own (`index`, `time`, `div`, `remove`, `exp`, `y1`, `j0`) | shadows or collides with `<string.h>`, `<time.h>`, `<stdlib.h>`, `<math.h>` | `item_index`, `elapsed_time`, `quotient`, `remove_item` |
| Typedef names that exist in POSIX (`stack_t`, `size_t`, `time_t`) | redefinition error | a more specific name (`char_stack_t`) |

The `_t` suffix is formally reserved by POSIX for the implementation. In this
book it is the type marker, so choose specific names (`student_t`, not
`record_t`) that cannot collide with a system type.

### Wrong and right

| Instead of | Write | Because |
|------------|-------|---------|
| `int a1, a2, a3;` | `int scores[3];` | collections are arrays |
| `float StudentAvg;` | `double student_average;` | `snake_case`, no mixed case |
| `int cnt;` | `int num_scores;` | counts say what they count |
| `int flag;` | `bool is_sorted;` | booleans read like questions |
| `void Process(int *p);` | `void normalize(int *numbers_ptr);` | verb, role, snake_case |
| `#define max 100` | `#define MAX_STUDENTS 100` | constants are uppercase |
| `#define SQUARE(x) x*x` | `#define SQUARE(x) ((x) * (x))` | parenthesize everything |
| `typedef struct {...} Student;` | `typedef struct student {...} student_t;` | tag and `_t` type |
| `enum {RED, GREEN};` | `typedef enum {COLOR_RED, COLOR_GREEN} color_t;` | enum prefix prevents clashes |
| `int (*f)(int, int);` | `binary_op_fn_t operation;` | named function pointer type |
| `int getSum(...)` | `int compute_sum(...)` | verb, `snake_case` |
| `int _total;` | `int total;` | leading underscores are reserved |

### One program that uses the rules

The file below uses almost every rule above in 90 lines. It is a complete,
warning-free C11 program (`gcc -std=c11 -Wall -Wextra`).

```c
/*
 * p07_c19_01_naming_showcase.c
 * Lecture 19: Structures
 *
 * Applies the C naming rules of CONTRIBUTING.md in one small program.
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 4
#define NAME_SIZE 16
#define PASS_MARK 10.0
#define SQUARE(x) ((x) * (x))

typedef enum {
    STATUS_OK,
    STATUS_NULL_ARG,
    STATUS_EMPTY
} status_t;

struct student {
    char name[NAME_SIZE];
    double average;
};
typedef struct student student_t;

typedef int (*compare_fn_t)(const student_t *a, const student_t *b);

int g_call_count = 0;          /* global: g_ prefix */
static int s_next_id = 1;      /* file-scope static: s_ prefix */

static int compare_by_average(const student_t *a, const student_t *b) {
    g_call_count++;
    return (a->average > b->average) - (a->average < b->average);
}

static bool is_passing(const student_t *student_ptr) {
    return student_ptr->average >= PASS_MARK;
}

static void student_init(student_t *student_ptr, const char *name,
                         double average) {
    strncpy(student_ptr->name, name, NAME_SIZE - 1);
    student_ptr->name[NAME_SIZE - 1] = '\0';
    student_ptr->average = average;
    s_next_id++;
}

static status_t student_find_best(const student_t *students, int num_students,
                                  compare_fn_t compare,
                                  const student_t **out_best) {
    if (students == NULL || compare == NULL || out_best == NULL) {
        return STATUS_NULL_ARG;
    }
    if (num_students <= 0) {
        return STATUS_EMPTY;
    }
    *out_best = &students[0];
    for (int i = 1; i < num_students; i++) {
        if (compare(&students[i], *out_best) > 0) {
            *out_best = &students[i];
        }
    }
    return STATUS_OK;
}

int main(void) {
    const char *names[MAX_STUDENTS] = {"Ali", "Sara", "Reza", "Mina"};
    const double averages[MAX_STUDENTS] = {12.5, 18.0, 9.75, 16.25};
    student_t students[MAX_STUDENTS];
    const student_t *best_ptr = NULL;
    int num_passed = 0;

    for (int i = 0; i < MAX_STUDENTS; i++) {
        student_init(&students[i], names[i], averages[i]);
        if (is_passing(&students[i])) {
            num_passed++;
        }
    }

    if (student_find_best(students, MAX_STUDENTS, compare_by_average,
                          &best_ptr) == STATUS_OK) {
        printf("best: %s (%.2f), squared: %.2f\n", best_ptr->name,
               best_ptr->average, SQUARE(best_ptr->average));
    }
    printf("passed: %d of %d, comparisons: %d\n", num_passed, MAX_STUDENTS,
           g_call_count);
    return 0;
}
```

Expected output:

```
best: Sara (18.00), squared: 324.00
passed: 3 of 4, comparisons: 3
```

## C code style

Naming is covered above. Layout and safety rules:

- Language standard: C11. All examples must compile cleanly with
  `gcc -std=c11 -Wall -Wextra` and produce no warnings. The only exceptions are
  deliberately buggy examples, which must say so.
- Indentation: 4 spaces, no tabs.
- Braces: opening brace on the same line (K&R style), for functions and
  statements alike. Always use braces, even for one-line `if`, `else`, `for`,
  and `while` bodies.
- One statement per line and one declaration per line.
- Maximum line length: 80 characters. When a signature does not fit, break
  after a comma and align the continuation under the first parameter.
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
  lines. A program that exists to show many rules together (such as the naming
  showcase) may be longer.

## Writing lectures and notebooks

- Notebooks run top to bottom: keep cells executable and self-contained.
- Keep an `.ipynb` file's output only when the lecture needs it (animations
  and plots). Otherwise clear it before committing:
  `jupyter nbconvert --clear-output --inplace file.ipynb`. The site builds from
  source; execution is opt-in (`jupyter book build --html --execute`).
- Include C programs in lectures from `src/` rather than pasting copies, so
  the code on the page and the compiled program cannot drift apart.
- Persian text is allowed in lecture content. Code, identifiers, and code
  comments stay in English.
- Author metadata: in a page's front matter the `github` field of an author
  is a **username**, not a URL:

  ```yaml
  authors:
    - name: Mahmood Amintoosi
      github: mamintoosi
  ```

- Keep images small. Prefer SVG or PNG for diagrams and compress photos.

## Common tasks

### Add a new example program

1. Choose the chapter `PP`, the lecture `LL`, and the next free sequence `SS`.
2. Create `book/lessons/chNN-topic/src/pPP_cLL_SS_slug.c` with the header
   comment.
3. Build it into `bin/`:

   ```
   cd book/lessons/chNN-topic
   gcc -std=c11 -Wall -Wextra -o bin/pPP_cLL_SS_slug src/pPP_cLL_SS_slug.c
   ```

4. Reference it from the lecture, then build the book to check.

### Rebuild every example

From the repository root:

```
for dir in book/lessons/ch*/; do
  [ -d "${dir}src" ] || continue
  mkdir -p "${dir}bin"
  for f in "${dir}"src/*.c; do
    gcc -std=c11 -Wall -Wextra -o "${dir}bin/$(basename "$f" .c)" "$f" -lm
  done
done
```

Deliberately wrong examples may print warnings; that is expected.

### Add a new chapter

1. Create `book/lessons/chNN-topic/` with `lecture`, `supplementary`, and
   `exercises` documents (both `.md` and `.ipynb`).
2. Create `book/problems/chNN-topic/problems.md` and
   `book/answers/chNN-topic/answers.md`.
3. **Add every new file to `myst.yml`.** The table of contents is explicit: a
   file that is not listed is not part of the book. Add the chapter group
   (`فصل ...: ...`) with its three lesson files, and the problems group
   (`مسائل فصل ...: ...`) with the problems and answers files.
4. Update the chapter tables in `README.md`.

### Sync a notebook and its Markdown twin

```
jupytext --sync book/lessons/chNN-topic/lecture.ipynb
```

### Build and preview locally

```
env -u PORT jupyter book build --html
env -u PORT jupyter book start        # live preview at http://localhost:3000
```

Details on serving and deployment are in [production.md](production.md).

## Pull request checklist

- [ ] Branch and commit names follow the conventions above.
- [ ] New files follow the naming rules and are listed in `myst.yml`.
- [ ] C identifiers follow [C naming conventions](#c-naming-conventions).
- [ ] `.md` and `.ipynb` pairs are in sync.
- [ ] Notebook outputs are cleared where not needed; no `_build/`, `venv/`, or
      checkpoints are committed.
- [ ] All changed C code compiles with `-std=c11 -Wall -Wextra` without
      warnings (except marked buggy examples).
- [ ] `bin/` executables were rebuilt from the current `src/`.
- [ ] There is still only one `myst.yml`, and the book builds locally with
      `jupyter book build --html`.
- [ ] README tables are updated if chapters, sessions, or layout changed.