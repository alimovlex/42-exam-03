#!/usr/bin/env python3
import subprocess


def hidenp(small: str, big: str) -> bool:

    # 1. Store the filename in a variable
    file = "hidenp.c"
    executable = "./a.out"
    # 2. Compile the C file (swap "clang" with "gcc" if needed by your machine)
    subprocess.run(["clang", file], capture_output=True, text=True)

    # 3. Execute and pass the python list elements safely as sequential system arguments
    result = subprocess.run([executable, small, big], capture_output=True, text=True)

    stdout = result.stdout.strip()
    return stdout == "1"


if __name__ == "__main__":
    print(hidenp("abc", "a1b2c3"))  # Output: True
    print(hidenp("ace", "abcde"))  # Output: True
    print(hidenp("aec", "abcde"))  # Output: False
    print(hidenp("", "abc"))  # Output: True
    print(hidenp("abc", "ab"))  # Output: False
    print(hidenp("aaaa", "aaa"))  # Output: False
    print(hidenp("sing", "subsequence testing"))  # Output: True
