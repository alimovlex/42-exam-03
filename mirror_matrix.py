#!/usr/bin/env python3
import subprocess


def mirror_matrix(matrix: list[list[int]]) -> list[list[int]]:

    # 1. Write and compile the C code globally (executes only once on script load)
    file = "mirror_matrix.c"
    executable = "./a.out"
    # Using gcc or clang (Moulinette usually has gcc if any)
    subprocess.run(["clang", file])

    result_matrix = []

    for row in matrix:
        # Handle empty rows
        if not row:
            result_matrix.append([])
            continue

        # Convert the row of integers to a list of strings for argv
        str_row = [str(x) for x in row]

        # Run the C executable, passing the row as arguments
        run_out = subprocess.run([executable] + str_row, capture_output=True, text=True)

        # Grab stdout, split it, and convert back to integers
        reversed_row = [int(x) for x in run_out.stdout.split()]
        result_matrix.append(reversed_row)

    return result_matrix


if __name__ == "__main__":
    print(mirror_matrix([[1, 2, 3], [4, 5, 6]]))  # [[3,2,1],[6,5,4]]
    print(mirror_matrix([[1, 2], [3, 4], [5, 6]]))  # [[2,1],[4,3],[6,5]]
    print(mirror_matrix([[7]]))  # [[7]]
    print(mirror_matrix([[1, 2, 3, 4]]))  # [[4,3,2,1]]
    print(mirror_matrix([[-1, -2], [-3, -4]]))  # [[-2,-1],[-4,-3]]
