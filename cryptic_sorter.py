#!/usr/bin/env python3
import subprocess


def cryptic_sorter(strings: list[str]) -> list[str]:
    # Edge case: If the input list is empty, return empty immediately
    if not strings:
        return []

    # 1. Store the filename in a variable
    file = "cryptic_sorter.c"
    executable = "./a.out"
    # 2. Compile the C file (swap "clang" with "gcc" if needed by your machine)
    subprocess.run(["clang", file], capture_output=True, text=True)

    # 3. Execute and pass the python list elements safely as sequential system arguments
    result = subprocess.run([executable] + strings, capture_output=True, text=True)

    # 4. Clean up output strings safely by splitting strictly on newlines
    output_lines = result.stdout.split("\n")
    if output_lines and output_lines[-1] == "":
        output_lines.pop()  # Removes trailing blank line caused by final \n

    return output_lines


if __name__ == "__main__":
    print(cryptic_sorter(["apple", "cat", "banana", "dog", "elephant"]))
    print(cryptic_sorter(["aaa", "bbb", "AAA", "BBB"]))
    print(cryptic_sorter(["hello", "world", "hi", "test"]))
