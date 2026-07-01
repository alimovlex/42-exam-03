#!/usr/bin/env python3
import subprocess

# 3. Define the mandatory function signature for the exam
def bracket_validator(s: str) -> bool:
    # 1. Store the filename in a variable
    file = "bracket_validator.c"

    # 2. Compile the C binary once when the script loads
    # We use 'cat' to write the file and 'clang' to compile it
    subprocess.run(["clang", file, "-o", "validator.out"], capture_output=True, text=True)
    
    # Run the compiled C binary, passing the string 's' as a command-line argument
    # We wrap it in a list to safely handle spaces and special characters
    result = subprocess.run(
        ["./validator.out", s], 
        capture_output=True, 
        text=True
    )
    
    # Read stdout, strip whitespace, and convert "1" -> True, "0" -> False
    output = result.stdout.strip()
    return output == "1"

# --- Test Cases ---
if __name__ == "__main__":
    bracket_validator("([)]")
    bracket_validator("{[]}")
    bracket_validator("hello(world)")
    bracket_validator("((())")
    bracket_validator("")