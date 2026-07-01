#!/usr/bin/env python3
import subprocess

def bracket_validator(s: str) -> bool:
    # Run the C program, pass the string as a single argument
    file = "bracket_validator.c"

    # Write C code to file and compile once
    subprocess.run(["clang", file, "-o", "validator_bin"], capture_output=True, text=True)
    # 3. Execute and pass the python list elements safely as sequential system arguments
    proc = subprocess.run(["./validator_bin", s], capture_output=True, text=True)
    # Exit code 0 => valid, non‑zero => invalid
    return proc.returncode == 0


if __name__ == "__main__":
    print(bracket_validator("()"))          # True
    print(bracket_validator("()[]{}"))      # True
    print(bracket_validator("(]"))          # False
    print(bracket_validator("([)]"))        # False
    print(bracket_validator("{[]}"))        # True
    print(bracket_validator("hello(world)"))# True
    print(bracket_validator("((())"))       # False
    print(bracket_validator(""))            # True