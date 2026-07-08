#!/usr/bin/env python3
import subprocess


def twist_sequence(arr: list[int], k: int) -> list[int]:

    # 1. Store the filename in a variable
    file = "twist_sequence.c"
    executable = "./a.out"
    # 2. Compile the C file (swap "clang" with "gcc" if needed by your machine)
    subprocess.run(["clang", file], capture_output=True, text=True)
    cmd_args = [executable, str(len(arr)), str(k)] + [str(x) for x in arr]
    # 3. Execute and pass the python list elements safely as sequential system arguments
    result = subprocess.run(cmd_args, capture_output=True, text=True)

    stdout = result.stdout.strip()
    return [int(x) for x in stdout.split()]


if __name__ == "__main__":
    print(twist_sequence([1, 2, 3, 4, 5], 2))  # Output: [4, 5, 1, 2, 3]
    print(twist_sequence([1, 2, 3], 1))  # Output: [3, 1, 2]
    print(twist_sequence([1, 2, 3, 4], 0))  # Output: [1, 2, 3, 4]
    print(twist_sequence([1, 2, 3], 5))  # Output: [2, 3, 1]
    print(twist_sequence([], 3))  # Output: []
