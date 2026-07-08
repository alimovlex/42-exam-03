#!/usr/bin/env python3
import subprocess


def pattern_tracker(text: str) -> int:

    # 1. Store the filename in a variable
    file = "pattern_tracker.c"
    executable = "./a.out"
    # 2. Compile the C file (swap "clang" with "gcc" if needed by your machine)
    subprocess.run(["clang", file], capture_output=True, text=True)

    # 3. Execute and pass the python list elements safely as sequential system arguments
    result = subprocess.run([executable, text], capture_output=True, text=True)

    stdout = result.stdout.strip()
    return int(stdout)


if __name__ == "__main__":
    print(pattern_tracker("123"))  # 2
    print(pattern_tracker("12a34"))  # 2
    print(pattern_tracker("987654321"))  # 0
    print(pattern_tracker("01234567"))  # 7
    print(pattern_tracker("abc"))  # 0
    print(pattern_tracker("1a2b3c4"))  # 0
    print(pattern_tracker("112233"))  # 2
