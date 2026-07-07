#!/usr/bin/env python3
import subprocess


def inter(s1: str, s2: str) -> str:

    # 1. Store the filename in a variable
    file = "inter.c"
    executable = "./a.out"
    # 2. Compile the C file (swap "clang" with "gcc" if needed by your machine)
    subprocess.run(["clang", file], capture_output=True, text=True)

    # 3. Execute and pass the python list elements safely as sequential system arguments
    result = subprocess.run([executable, s1, s2], capture_output=True, text=True)
    stdout = result.stdout.strip()
    return stdout


if __name__ == "__main__":
    print(repr(inter("hello", "world")))  # Output: 'lo'
    print(repr(inter("banana", "band")))  # Output: 'ban'
    print(repr(inter("abcabc", "bc")))  # Output: 'bc'
    print(repr(inter("abc", "xyz")))  # Output: ''
    print(repr(inter("", "abc")))  # Output: ''
