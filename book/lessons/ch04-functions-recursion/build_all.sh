#!/bin/sh
# Compile every example in src/ into bin/ (p04_c10_06_define_expansion has no main: preprocess only).
mkdir -p bin
for f in src/p04_*.c; do
    name=$(basename "$f" .c)
    if [ "$name" = "p04_c10_06_define_expansion" ]; then
        gcc -E -P "$f" > /dev/null && echo "ok (preprocess)  $name"
    elif [ "$name" = "p04_c09_07_stack_depth" ]; then
        gcc -Wall -DN=1000 -I src -o "bin/$name" "$f" && echo "ok  $name (use -DN=... to change N)"
    else
        gcc -Wall -I src -o "bin/$name" "$f" && echo "ok  $name"
    fi
done
