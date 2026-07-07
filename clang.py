#!/usr/bin/env python3
import subprocess

c_file = r"""
#include <stdio.h>

void main(int argc, char **argv)
{
    while(*++argv)
        printf("%s\n", *argv);
}
"""

# subprocess.run(["bash", "-c", "cat > main.c"], input=c_file, text=True)
with open("main.c", "w") as f:
    f.write(c_file)
subprocess.run(["clang", "main.c"], capture_output=True, text=True)
a_out = subprocess.run(
    ["./a.out", "1", "-1", "42", "1 -1 0 42"], capture_output=True, text=True
)

argv = a_out.stdout

print(argv.split())
