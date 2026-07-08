#!/usr/bin/env python3
import subprocess


def shadow_merge(list1: list[int], list2: list[int]) -> list[int]:

    # 1. Store the filename in a variable
    file = "shadow_merge.c"
    executable = "./a.out"
    # 2. Compile the C file (swap "clang" with "gcc" if needed by your machine)
    subprocess.run(["clang", file], capture_output=True, text=True)

    cmd_args = (
        [executable, str(len(list1)), str(len(list2))]
        + [str(x) for x in list1]
        + [str(x) for x in list2]
    )

    # 3. Execute and pass the python list elements safely as sequential system arguments
    result = subprocess.run(cmd_args, capture_output=True, text=True)

    stdout = result.stdout.strip()
    return [int(x) for x in stdout.split()]


if __name__ == "__main__":
    print(shadow_merge([1, 3, 5], [2, 4, 6]))  # Output: [1, 2, 3, 4, 5, 6]
    print(shadow_merge([1, 2, 3], [4, 5, 6]))  # Output: [1, 2, 3, 4, 5, 6]
    print(shadow_merge([1], [2, 3, 4]))  # Output: [1, 2, 3, 4]
    print(shadow_merge([], [1, 2, 3]))  # Output: [1, 2, 3]
    print(shadow_merge([1, 1, 2], [1, 3, 3]))  # Output: [1, 1, 1, 2, 3, 3]
