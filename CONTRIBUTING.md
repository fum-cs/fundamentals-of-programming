# Contributing — instructor & TA workflow

This repository is co-managed by the instructor and TAs. These conventions
keep the book buildable and the history reviewable.

## Repository layout

```
myst.yml                      # ALL book config: metadata + table of contents
lectures/
  index.md                    # book cover / landing page
  NN-topic/                   # one folder per lecture
    lecture-name.ipynb        # the lecture notebook (may be .md)
    img/ or data files        # keep assets next to the lecture
  img/                        # book-wide assets (logo, favicon)
.github/workflows/deploy.yml  # Pages deployment (do not edit casually)
production.md                 # build & serve instructions
```

## Adding a lecture

1. Create `lectures/NN-topic/my-lecture.ipynb` (or `.md`), where `NN` follows
   the lecture numbering (`10-functions`, …). Lowercase-hyphenated filenames.
2. **Add it to `myst.yml`**: the TOC is explicit in v2 — a file not listed in
   the TOC is not part of the book. Put it under the right `title:` group (add
   a new group if it starts a new topic).
3. Build locally to check before pushing:
   ```
   env -u PORT jupyter book build --html
   ```
4. Push a branch and open a PR, or push to `main` directly for small fixes —
   either way the site redeploys automatically.

## Rules of thumb

- **Do not** commit build output (`_build/` is git-ignored) or
  `.ipynb_checkpoints/`.
- **Clear notebook outputs** before committing when outputs are bulky
  (`jupyter nbconvert --clear-output --inplace file.ipynb`) — the site builds
  from source; execution is opt-in (`jupyter book build --html --execute`).
- Notebooks run top-to-bottom in order: keep cells executable and self-contained.
- Keep lecture assets inside the lecture folder; book-wide images in
  `lectures/img/`.
- Branch protection and review: TAs open PRs; the instructor merges. (To be
  enforced in repo settings.)
