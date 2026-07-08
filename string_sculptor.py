#!/usr/bin/env python3
import subprocess


def string_sculptor(text: str) -> str:

    # 1. Store the filename in a variable
    file = "string_sculptor.c"
    executable = "./a.out"
    # 2. Compile the C file (swap "clang" with "gcc" if needed by your machine)
    subprocess.run(["clang", file], capture_output=True, text=True)

    # 3. Execute and pass the python list elements safely as sequential system arguments
    result = subprocess.run([executable, text], capture_output=True, text=True)

    stdout = result.stdout.strip()
    return stdout


if __name__ == "__main__":
    print(repr(string_sculptor("hello")))  # Output: 'hElLo'
    print(repr(string_sculptor("Hello World")))  # Output: 'hElLo wOrLd'
    print(repr(string_sculptor("abc123def")))  # Output: 'aBc123DeF'
    print(repr(string_sculptor("Python3.9!")))  # Output: 'pYtHoN3.9!'
    print(repr(string_sculptor("")))  # Output: ''
