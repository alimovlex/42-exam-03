#!/usr/bin/env python3
import subprocess

def echo_validator(text: str) -> bool:

    # 1. Store the filename in a variable
    file = "echo_validator.c"

    # 2. Compile the C file (swap "clang" with "gcc" if needed by your machine)
    subprocess.run(["clang", file, "-o", "validator_bin"], capture_output=True, text=True)
    
    # 3. Execute and pass the python list elements safely as sequential system arguments
    result = subprocess.run(["./validator_bin", text], capture_output=True, text=True)

    stdout = result.stdout.strip()
    # C prints "1" for palindrome, "0" otherwise
    return stdout == "1"


if __name__ == "__main__":
    print(echo_validator("racecar"))                          # True
    print(echo_validator("A man a plan a canal Panama"))      # True
    print(echo_validator("race a car"))                       # False
    print(echo_validator("Was it a car or a cat I saw"))      # True
    print(echo_validator("hello"))                            # False
    print(echo_validator("Madam Im Adam"))                    # True
    print(echo_validator(""))                                 # False