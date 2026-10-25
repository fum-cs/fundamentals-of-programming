# Fundamentals of Programming (C)

Course book and materials for **Computer Fundamentals and Programming**
(*مبانی کامپیوتر و برنامه‌سازی*, course code 22210088), a first-year B.Sc.
course at the
[Department of Computer Science, Ferdowsi University of Mashhad](https://fum-cs.github.io/).

- **Online book:** <https://fum-cs.github.io/fundamentals-of-programming/>
- **Official syllabus:** [fum-cs.github.io/docs/curriculum/base/Computer-Fundamentals-and-Programming](https://fum-cs.github.io/docs/curriculum/base/Computer-Fundamentals-and-Programming)
- **Instructor:** Mahmood Amintoosi

This course teaches how to solve problems with computers. It first develops
algorithmic thinking, then shows how to express algorithms in the **C**
programming language, together with an introduction to how data is stored and
processed inside a computer. Lecture content is mostly written in Persian;
code and repository documentation are in English.

**Contents**

1. [Course at a glance](#course-at-a-glance)
2. [The book](#the-book)
3. [Course schedule](#course-schedule)
4. [Repository layout](#repository-layout)
5. [Getting started](#getting-started)
6. [Contributing](#contributing)
7. [Status](#status)

## Course at a glance

| | |
|---|---|
| Course | Computer Fundamentals and Programming (22210088) |
| Credits | 3 (core course) |
| Faculty | Mathematical Sciences |
| Term | 1405-1 (Persian calendar) |
| Sessions | Mondays and Wednesdays, 10:00, 120 minutes each, Room 0 |
| Prerequisites | None. Basic familiarity with a computer and an operating system (Windows or Linux); the first practical sessions of the Workshop 1 course cover the rest. |
| Teaching method | In-class lectures following the syllabus, with worked examples in algorithm design and programming |

### Learning objectives

1. Understand how a computer processes data at a high level.
2. Understand how numbers and characters are represented and stored.
3. Learn how to solve problems and write algorithms.
4. Become familiar with the C programming language.

### Assessment

Midterm and final exams, in-class exercises and Quera assignments, quizzes,
and a final project.

### Textbooks and references

- Saeed Abrishami, *Programming in C* (in Persian).
- P. Deitel and H. Deitel, *C: How to Program*, 8th Edition, 2015.

### Policy on the use of AI tools

The use of AI tools in this course is permitted, provided that the student
maintains an active role and academic responsibility. Using AI to learn
concepts, debug programs, brainstorm, review code, and improve writing is
allowed; however, presenting AI-generated content as the student's own
independent work, without reviewing and understanding it, is not acceptable.
The student is responsible for the scientific accuracy of the code, results,
and sources presented, and in assessed activities may be asked to explain the
process of carrying out the work and their technical decisions.

## The book

The book has eight chapters. Each chapter has three lesson documents
(**lecture**, **supplementary** topics, **exercises**), a set of **selected
problems**, and their **selected answers**.

| Chapter | Contents | Lessons | Problems | Answers |
|---------|----------|---------|----------|---------|
| 1. Basics | Course introduction, problem solving, algorithms, first look at C, number systems | [ch01-basics](book/lessons/ch01-basics/) | [problems](book/problems/ch01-basics/problems.md) | [answers](book/answers/ch01-basics/answers.md) |
| 2. Data and operators | Variables, data types, input/output, operators, integer and floating-point representation | [ch02-data-operators](book/lessons/ch02-data-operators/) | [problems](book/problems/ch02-data-operators/problems.md) | [answers](book/answers/ch02-data-operators/answers.md) |
| 3. Control flow | Conditionals and loops | [ch03-control-flow](book/lessons/ch03-control-flow/) | [problems](book/problems/ch03-control-flow/problems.md) | [answers](book/answers/ch03-control-flow/answers.md) |
| 4. Functions and recursion | Functions, the call stack, recursion, the preprocessor | [ch04-functions-recursion](book/lessons/ch04-functions-recursion/) | [problems](book/problems/ch04-functions-recursion/problems.md) | [answers](book/answers/ch04-functions-recursion/answers.md) |
| 5. Basic data structures | Arrays, matrices, searching, sorting, strings | [ch05-basic-data-structures](book/lessons/ch05-basic-data-structures/) | [problems](book/problems/ch05-basic-data-structures/problems.md) | [answers](book/answers/ch05-basic-data-structures/answers.md) |
| 6. Pointers and memory | Pointers, arrays and pointers, function pointers, dynamic memory | [ch06-pointers-memory](book/lessons/ch06-pointers-memory/) | [problems](book/problems/ch06-pointers-memory/problems.md) | [answers](book/answers/ch06-pointers-memory/answers.md) |
| 7. Structs and files | Structures and file handling | [ch07-structs-files](book/lessons/ch07-structs-files/) | [problems](book/problems/ch07-structs-files/problems.md) | [answers](book/answers/ch07-structs-files/answers.md) |
| 8. Miscellaneous | Supplementary topics and course review | [ch08-misc](book/lessons/ch08-misc/) | [problems](book/problems/ch08-misc/problems.md) | [answers](book/answers/ch08-misc/answers.md) |

## Course schedule

Session dates use the Persian calendar. The *Chapter* column shows where the
material of each session lives in this repository; a chapter can span several
sessions, and boundaries are approximate.

| # | Date | Topic | Chapter |
|--:|------|-------|---------|
| 1 | 1405/07/06 | Introduction to the field and the course | [ch01](book/lessons/ch01-basics/) |
| 2 | 1405/07/08 | Introduction to problem solving and algorithms | [ch01](book/lessons/ch01-basics/) |
| 3 | 1405/07/13 | Basic introduction to C + number systems | [ch01](book/lessons/ch01-basics/) |
| 4 | 1405/07/15 | Variables and data types | [ch02](book/lessons/ch02-data-operators/) |
| 5 | 1405/07/20 | Input/output + representation of integers | [ch02](book/lessons/ch02-data-operators/) |
| 6 | 1405/07/22 | Operators + representation of floating-point numbers | [ch02](book/lessons/ch02-data-operators/) |
| 7 | 1405/07/27 | Conditional structures | [ch03](book/lessons/ch03-control-flow/) |
| 8 | 1405/07/29 | Completing loops + introduction to functions | [ch03](book/lessons/ch03-control-flow/), [ch04](book/lessons/ch04-functions-recursion/) |
| 9 | 1405/08/04 | Functions | [ch04](book/lessons/ch04-functions-recursion/) |
| 10 | 1405/08/06 | One-dimensional arrays | [ch05](book/lessons/ch05-basic-data-structures/) |
| 11 | 1405/08/11 | Multidimensional arrays + searching | [ch05](book/lessons/ch05-basic-data-structures/) |
| 12 | 1405/08/13 | Sorting | [ch05](book/lessons/ch05-basic-data-structures/) |
| 13 | 1405/08/18 | Strings | [ch05](book/lessons/ch05-basic-data-structures/) |
| 14 | 1405/08/20 | Exam | n/a |
| 15 | 1405/08/25 | Pointers | [ch06](book/lessons/ch06-pointers-memory/) |
| 16 | 1405/08/27 | Pointers | [ch06](book/lessons/ch06-pointers-memory/) |
| 17 | 1405/09/02 | Dynamic memory management | [ch06](book/lessons/ch06-pointers-memory/) |
| 18 | 1405/09/04 | Completing dynamic memory + introduction to structs | [ch06](book/lessons/ch06-pointers-memory/), [ch07](book/lessons/ch07-structs-files/) |
| 19 | 1405/09/09 | Structures | [ch07](book/lessons/ch07-structs-files/) |
| 20 | 1405/09/11 | File handling | [ch07](book/lessons/ch07-structs-files/) |
| 21 | 1405/09/16 | Completing file handling + supplementary topics | [ch07](book/lessons/ch07-structs-files/), [ch08](book/lessons/ch08-misc/) |
| 22 | 1405/09/18 | Review and final summary | [ch08](book/lessons/ch08-misc/) |

## Repository layout

```
.
├── myst.yml                  # book configuration and table of contents
├── README.md
├── CONTRIBUTING.md           # conventions for instructors and TAs
├── production.md             # build, serve, and deploy instructions
└── book/
    ├── index.md              # book cover / landing page
    ├── lessons/              # lectures, supplementary topics, exercises
    │   └── chNN-topic/
    ├── problems/             # selected problems, per chapter
    │   └── chNN-topic/problems.md
    ├── answers/              # selected answers, per chapter
    │   └── chNN-topic/answers.md
    ├── images/               # book-wide images
    ├── style.css
    └── sidebar-footer.md
```

Every lesson folder follows the same pattern:

```
book/lessons/chNN-topic/
├── lecture.ipynb / lecture.md              # main lecture material
├── supplementary.ipynb / supplementary.md  # optional deeper material
├── exercises.ipynb / exercises.md          # practice exercises
├── src/                                    # C example programs (.c, .h)
├── bin/                                    # compiled executables of the examples
└── images/                                 # figures used by this chapter
```

Not every chapter has all folders yet. Each `.md` file and the `.ipynb` file
with the same name are two forms of the same document (kept in sync with
Jupytext). The book is built from the `.ipynb` files listed in `myst.yml`.

### Naming of example programs

Example programs are named `pPP_cLL_SS_slug`, for example
`p05_c12_03_bubble_sort.c`:

- `pPP`: chapter number (`p05` is `ch05-...`)
- `cLL`: lecture number in the book
- `SS`: sequence number of the example within that lecture
- `slug`: short description in `snake_case`

The compiled program in `bin/` has the same name without the extension. All
naming conventions, including the rules for C identifiers, are in
[CONTRIBUTING.md](CONTRIBUTING.md).

## Getting started

### Get the materials

```
git clone https://github.com/fum-cs/fundamentals-of-programming.git
cd fundamentals-of-programming
```

Or read the [online book](https://fum-cs.github.io/fundamentals-of-programming/)
without installing anything.

### Compile and run the C examples

You need a C compiler (GCC or Clang). On Windows, use
[MSYS2/MinGW](https://www.msys2.org/) or WSL.

```
cd book/lessons/ch05-basic-data-structures
mkdir -p bin
gcc -std=c11 -Wall -Wextra -o bin/p05_c12_03_bubble_sort src/p05_c12_03_bubble_sort.c
./bin/p05_c12_03_bubble_sort
```

Programs that use `<math.h>` may need `-lm` at the end of the command.

To build every example of a chapter (run from inside the chapter folder):

```
for f in src/*.c; do
  gcc -std=c11 -Wall -Wextra -o "bin/$(basename "$f" .c)" "$f" -lm
done
```

Some examples are deliberately wrong (memory leaks, dangling pointers, double
free, and so on) to demonstrate common mistakes. They are marked in their
source comments and may produce warnings.

### Work with the notebooks

```
pip install jupyterlab
jupyter lab
```

Then open any `lecture.ipynb`, `supplementary.ipynb`, or `exercises.ipynb`
under `book/lessons/`.

### Build the book locally

The book is built with **Jupyter Book 2** (MyST). All configuration, including
the table of contents, is in the single `myst.yml` at the repository root.

```
pip install jupyter-book
env -u PORT jupyter book build --html   # site in _build/html/
env -u PORT jupyter book start          # live preview at http://localhost:3000
```

See [production.md](production.md) for serving and deployment details. The
site is deployed to GitHub Pages automatically on every push to `main`.

## Contributing

The repository is maintained by the instructor and the teaching assistants.
Please read [CONTRIBUTING.md](CONTRIBUTING.md) before making changes. In short:

- Each chapter lives in its own `chNN-topic/` folder under `book/lessons/`,
  with `lecture`, `supplementary`, and `exercises` documents. Its problems and
  answers live under `book/problems/` and `book/answers/`.
- C examples go in `src/` and follow the `pPP_cLL_SS_slug` naming scheme and
  the C naming conventions.
- Every new page must be added to the table of contents in `myst.yml`, and
  there must be only one `myst.yml`, at the repository root.
- Do not commit build output such as `_build/`.

Students who find a mistake are welcome to open an issue.

## Status

In progress for the current semester. Chapters 1 to 6 contain lecture
material; chapters 7 and 8 are still being written.