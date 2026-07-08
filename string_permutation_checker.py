#!/usr/bin/env python3
import subprocess


def string_permutation_checker(s1: str, s2: str) -> bool:

    # 1. Store the filename in a variable
    file = "string_permutation_checker.c"
    executable = "./a.out"
    # 2. Compile the C file (swap "clang" with "gcc" if needed by your machine)
    subprocess.run(["clang", file], capture_output=True, text=True)

    # 3. Execute and pass the python list elements safely as sequential system arguments
    result = subprocess.run([executable, s1, s2], capture_output=True, text=True)

    stdout = result.stdout.strip()
    return stdout == "1"


if __name__ == "__main__":
    print(string_permutation_checker("abc", "bca"))  # Output: True
    print(string_permutation_checker("abc", "def"))  # Output: False
    print(string_permutation_checker("listen", "silent"))  # Output: True
    print(string_permutation_checker("hello", "bello"))  # Output: False
    print(string_permutation_checker("", ""))  # Output: True
    print(string_permutation_checker("a", ""))  # Output: False
    print(string_permutation_checker("Abc", "abc"))  # Output: False
    print(string_permutation_checker("a gentleman", "elegant man"))  # Output: True
