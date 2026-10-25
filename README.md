# Fundamentals of Programming (C)

Course book and materials for **Computer Fundamentals and Programming**
(course code 22210088), a first-year B.Sc. course at the
[Department of Computer Science, Ferdowsi University of Mashhad](https://fum-cs.github.io/).

- **Online book:** <https://fum-cs.github.io/fundamentals-of-programming/>
- **Official syllabus:** [fum-cs.github.io/docs/curriculum/base/Computer-Fundamentals-and-Programming](https://fum-cs.github.io/docs/curriculum/base/Computer-Fundamentals-and-Programming)
- **Instructor:** Mahmood Amintoosi

This course teaches how to solve problems with computers. It first develops
algorithmic thinking, then shows how to express algorithms in the **C**
programming language, together with an introduction to how data is stored and
processed inside a computer. Some lecture content is written in Persian.

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

## Course schedule

Session dates use the Persian calendar. The *Chapter* column shows where the
material of each session lives in this repository; a chapter can span several
sessions, and boundaries are approximate.

| # | Date | Topic | Chapter |
|--:|------|-------|---------|
| 1 | 1405/07/06 | Introduction to the field and the course | [ch01](ch01-basics/) |
| 2 | 1405/07/08 | Introduction to problem solving and algorithms | [ch01](ch01-basics/) |
| 3 | 1405/07/13 | Basic introduction to C + number systems | [ch01](ch01-basics/) |
| 4 | 1405/07/15 | Variables and data types | [ch02](ch02-data-operators/) |
| 5 | 1405/07/20 | Input/output + representation of integers | [ch02](ch02-data-operators/) |
| 6 | 1405/07/22 | Operators + representation of floating-point numbers | [ch02](ch02-data-operators/) |
| 7 | 1405/07/27 | Conditional structures | [ch03](ch03-control-flow/) |
| 8 | 1405/07/29 | Completing loops + introduction to functions | [ch03](ch03-control-flow/), [ch04](ch04-functions-and-recursion/) |
| 9 | 1405/08/04 | Functions | [ch04](ch04-functions-and-recursion/) |
| 10 | 1405/08/06 | One-dimensional arrays | [ch05](ch05-basic-data-structures/) |
| 11 | 1405/08/11 | Multidimensional arrays + searching | [ch05](ch05-basic-data-structures/) |
| 12 | 1405/08/13 | Sorting | [ch05](ch05-basic-data-structures/) |
| 13 | 1405/08/18 | Strings | [ch05](ch05-basic-data-structures/) |
| 14 | 1405/08/20 | Exam | n/a |
| 15 | 1405/08/25 | Pointers | [ch06](ch06-pointers-memory/) |
| 16 | 1405/08/27 | Pointers | [ch06](ch06-pointers-memory/) |
| 17 | 1405/09/02 | Dynamic memory management | [ch06](ch06-pointers-memory/) |
| 18 | 1405/09/04 | Completing dynamic memory + introduction to structs | [ch06](ch06-pointers-memory/), [ch07](ch07-structs-files/) |
| 19 | 1405/09/09 | Structures | [ch07](ch07-structs-files/) |
| 20 | 1405/09/11 | File handling | [ch07](ch07-structs-files/) |
| 21 | 1405/09/16 | Completing file handling + supplementary topics | [ch07](ch07-structs-files/), [ch08](ch08-misc/) |
| 22 | 1405/09/18 | Review and final summary | [ch08](ch08-misc/) |

## Repository layout

```
.
├── index.md                        # book cover / landing page
├── myst.yml                        # book configuration and table of contents
├── ch01-basics/
├── ch02-data-operators/
├── ch03-control-flow/
├── ch04-functions-and-recursion/
├── ch05-basic-data-structures/
├── ch06-pointers-memory/
├── ch07-structs-files/
└── ch08-misc/
```

Every chapter folder follows the same pattern:

```
chNN-topic/
├── lecture.md / lecture.ipynb              # main lecture material
├── exercises.md / exercises.ipynb          # practice problems
├── supplementary.md / supplementary.ipynb  # optional deeper material
├── src/                                    # C example programs (.c, .h)
├── bin/                                    # compiled executables of the examples
└── images/                                 # figures used by this chapter
```

Not every chapter has all folders yet. Each `.md` file and the `.ipynb` file
with the same name are two forms of the same document.

### Chapters

| Chapter | Contents |
|---------|----------|
| [ch01-basics](ch01-basics/) | Course introduction, problem solving, algorithms, first look at C, number systems |
| [ch02-data-operators](ch02-data-operators/) | Variables, data types, input/output, operators, integer and floating-point representation |
| [ch03-control-flow](ch03-control-flow/) | Conditionals and loops |
| [ch04-functions-and-recursion](ch04-functions-and-recursion/) | Functions, the call stack, recursion, the preprocessor |
| [ch05-basic-data-structures](ch05-basic-data-structures/) | Arrays, matrices, searching, sorting, strings |
| [ch06-pointers-memory](ch06-pointers-memory/) | Pointers, arrays and pointers, function pointers, dynamic memory |
| [ch07-structs-files](ch07-structs-files/) | Structures and file handling |
| [ch08-misc](ch08-misc/) | Supplementary topics and course review |

### Naming of example programs

Example programs are named `pPP_cLL_SS_slug`, for example
`p05_c12_03_bubble_sort.c`:

- `pPP`: chapter number (`p05` is `ch05-...`)
- `cLL`: lecture number in the book
- `SS`: sequence number of the example within that lecture
- `slug`: short description in `snake_case`

The compiled program in `bin/` has the same name without the extension. See
[CONTRIBUTING.md](CONTRIBUTING.md) for all naming conventions.

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
cd ch05-basic-data-structures
mkdir -p bin
gcc -std=c11 -Wall -Wextra -o bin/p05_c12_03_bubble_sort src/p05_c12_03_bubble_sort.c
./bin/p05_c12_03_bubble_sort
```

Programs that use `<math.h>` may need `-lm` at the end of the command.

To build every example of a chapter:

```
for f in src/*.c; do
  gcc -std=c11 -Wall -Wextra -o "bin/$(basename "$f" .c)" "$f"
done
```

Some examples are deliberately wrong (memory leaks, dangling pointers, double
free, and so on) to demonstrate common mistakes. They are marked in their
source comments.

### Work with the notebooks

```
pip install jupyterlab
jupyter lab
```

Then open any `lecture.ipynb`, `exercises.ipynb`, or `supplementary.ipynb`.

### Build the book locally

The book is built with **Jupyter Book 2** (MyST). All configuration, including
the table of contents, is in `myst.yml` at the repository root.

```
pip install jupyter-book
env -u PORT jupyter book build --html   # site in _build/html/
```

See [production.md](production.md) for local serving and deployment details.
The site is deployed to GitHub Pages automatically on every push to `main`.

## Contributing

The repository is maintained by the instructor and the teaching assistants.
Please read [CONTRIBUTING.md](CONTRIBUTING.md) before making changes. In short:

- Each chapter lives in its own `chNN-topic/` folder with `lecture`,
  `exercises`, and `supplementary` documents.
- C examples go in `src/` and follow the `pPP_cLL_SS_slug` naming scheme.
- Every new page must be added to the table of contents in `myst.yml`.
- Do not commit build output such as `_build/`.

Students who find a mistake are welcome to open an issue.

## Status

In progress for the current semester. Chapters 1 to 6 contain lecture
material; chapters 7 and 8 are still being written.
