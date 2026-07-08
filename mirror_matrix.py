#!/usr/bin/env python3
import subprocess


def mirror_matrix(matrix: list[list[int]]) -> list[list[int]]:

    # 1. Write and compile the C code globally (executes only once on script load)
    file = "mirror_matrix.c"
    executable = "./a.out"
    # Using gcc or clang (Moulinette usually has gcc if any)
    subprocess.run(["clang", file])
    flat_args = [str(item) for row in matrix for item in row]
    # 3. Execute and pass the python list elements safely as sequential system arguments
    result = subprocess.run(
        [executable, str(len(matrix)), str(len(matrix[0]))] + flat_args,
        capture_output=True,
        text=True,
    )

    stdout = result.stdout.strip()
    return [[int(x) for x in line.split()] for line in stdout.split("\n") if line]


if __name__ == "__main__":
    print(mirror_matrix([[1, 2, 3], [4, 5, 6]]))  # [[3,2,1],[6,5,4]]
    print(mirror_matrix([[1, 2], [3, 4], [5, 6]]))  # [[2,1],[4,3],[6,5]]
    print(mirror_matrix([[7]]))  # [[7]]
    print(mirror_matrix([[1, 2, 3, 4]]))  # [[4,3,2,1]]
    print(mirror_matrix([[-1, -2], [-3, -4]]))  # [[-2,-1],[-4,-3]]
