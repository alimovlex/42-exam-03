#!/usr/bin/env python3
import subprocess

c_file=r"""
#include <stdio.h>

void main(int argc, char **argv)
{
    while(*++argv)
        printf("%s\n", *argv);
}
"""

subprocess.run(["bash", "-c", "cat > temp.c"], input=c_file, text=True)
subprocess.run(
    ["bash", "-c", "clang temp.c"],
    capture_output=True,
    text=True
)
a_out=subprocess.run(["./a.out", "1", "-1", "42", "1 -1 0 42"], capture_output=True, text=True)

argv=a_out.stdout;

print(argv.split())

