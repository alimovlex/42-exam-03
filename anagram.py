#!/usr/bin/env python3
import subprocess


def anagram(s1: str, s2: str) -> bool:

    # 1. Store the filename in a variable
    file = "anagram.c"
    executable = "./a.out"
    # 2. Compile the C file (swap "clang" with "gcc" if needed by your machine)
    subprocess.run(["clang", file], capture_output=True, text=True)

    # 3. Execute and pass the python list elements safely as sequential system arguments
    result = subprocess.run([executable, s1, s2], capture_output=True, text=True)

    stdout = result.stdout.strip()
    return stdout == "1"


if __name__ == "__main__":
    print(anagram("listen", "silent"))  # Output: True
    print(anagram("Triangle", "Integral"))  # Output: True
    print(anagram("Dormitory", "Dirty Room"))  # Output: True
    print(anagram("hello", "world"))  # Output: False
    print(anagram("", ""))  # Output: True
    print(anagram("abc", "abcc"))  # Output: False
