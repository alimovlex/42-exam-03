#!/usr/bin/env python3
import subprocess


def whisper_cipher(text: str, shift: int) -> str:

    # 1. Store the filename in a variable
    file = "whisper_cipher.c"
    executable = "./a.out"
    # 2. Compile the C file (swap "clang" with "gcc" if needed by your machine)
    subprocess.run(["clang", file], capture_output=True, text=True)

    # 3. Execute and pass the python list elements safely as sequential system arguments
    result = subprocess.run(
        [executable, text, str(shift)], capture_output=True, text=True
    )

    stdout = result.stdout.strip()
    return stdout


if __name__ == "__main__":
    print(repr(whisper_cipher("hello", 3)))  # Output: 'khoor'
    print(repr(whisper_cipher("Hello World!", 1)))  # Output: 'Ifmmp Xpsme!'
    print(repr(whisper_cipher("xyz", 3)))  # Output: 'abc'
    print(repr(whisper_cipher("ABC123def", 5)))  # Output: 'FGH123ijk'
    print(repr(whisper_cipher("", 10)))  # Output: ''
    print(repr(whisper_cipher("abc", -3)))  # Output: 'xyz'
