# Fundamentals of Programming (C) — مبانی کامپیوتر و برنامه‌سازی

Course book and materials for **Computer Fundamentals and Programming**
(B.Sc., first year), [Computer Science Dept., Ferdowsi University of Mashhad](https://fum-cs.github.io/).

- **Online book:** <https://fum-cs.github.io/fundamentals-of-programming/>
- **Official syllabus:** [fum-cs.github.io/docs/curriculum/base/Computer-Fundamentals-and-Programming](https://fum-cs.github.io/docs/curriculum/base/Computer-Fundamentals-and-Programming)
- **Instructor:** Mahmood Amintoosi

The course language is **C**; the teaching emphasis is problem solving and
algorithmic thinking — computer as a computational model, algorithms, then a
high-level language to express them (functions, arrays, files, recursion,
searching and sorting). Some lecture content is written in Persian.

## Contributing (instructor + TAs)

This repo is managed by the instructor and TAs. Quick rules — full details in
[CONTRIBUTING.md](CONTRIBUTING.md):

- One folder per lecture under `lectures/NN-topic/` (notebook + supporting files).
- Add every new page to the TOC in `myst.yml` (root) — the TOC is explicit.
- Never commit build output; `_build/` is ignored.
- Pushes to `main` auto-deploy to GitHub Pages via Actions.

## Build (local)

Built with **Jupyter Book 2** (MyST). All configuration is in a single
`myst.yml` at the repository root. From the repository root:

```
pip install jupyter-book
env -u PORT jupyter book build --html   # site in _build/html/
```

See [production.md](production.md) for details, local serving, and server
cleanup. The site deploys automatically on every push to `main`.

## Status

🚧 Under construction for the current semester — chapters appear as lectures are developed.
