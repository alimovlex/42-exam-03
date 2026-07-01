#!/usr/bin/env python3

import subprocess

# Running a multi-line Bash script
bash_script = """
#!/bin/bash
echo "This is running inside Python!"
for i in {1..3}; do
    echo "Count $i"
done
"""

subprocess.run(bash_script, shell=True, executable="/bin/bash")

