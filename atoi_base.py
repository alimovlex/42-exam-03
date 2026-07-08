#!/usr/bin/env python3
import subprocess


def number_base_converter(number: str, from_base: int, to_base: int) -> str:

    # 1. Store the filename in a variable
    file = "atoi_base.c"
    executable = "./a.out"
    # 2. Compile the C file (swap "clang" with "gcc" if needed by your machine)
    subprocess.run(["clang", file], capture_output=True, text=True)

    # 3. Execute and pass the python list elements safely as sequential system arguments
    result = subprocess.run(
        [executable, str(number), str(from_base), str(to_base)],
        capture_output=True,
        text=True,
    )

    stdout = result.stdout.strip()
    return stdout


if __name__ == "__main__":
    print(number_base_converter("1010", 2, 10))  # Expected: "10"
    print(number_base_converter("FF", 16, 10))  # Expected: "255"
    print(number_base_converter("255", 10, 16))  # Expected: "FF"
    print(number_base_converter("123", 10, 2))  # Expected: "1111011"
    print(number_base_converter("Z", 36, 10))  # Expected: "35"
    print(number_base_converter("35", 10, 36))  # Expected: "Z"
    print(number_base_converter("123", 1, 10))  # Expected: "ERROR"
    print(number_base_converter("G", 16, 10))  # Expected: "ERROR"
    print(
        number_base_converter("  \t-1010", 2, 10)
    )  # Expected: "-10" (Testing the atoi_base robustness!)
