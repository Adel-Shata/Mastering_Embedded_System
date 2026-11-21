#!/usr/bin/env python3
"""
Capture the Student Management System interaction.
Since piped stdin doesn't echo input to stdout (unlike a real terminal),
we construct the transcript by reading program output and appending
user input where the program blocks on scanf/fgets.
"""

import subprocess
import os
import sys
import time
import re
import threading

SCREENSHOTS_DIR = "docs/screenshots"
EXECUTABLE = "./sms.exe"


def run_interactive(input_lines, timeout=30):
    """
    Run program interactively, reading output line by line
    and feeding input when the program needs it.
    Returns the full transcript with both prompts and input visible.
    """
    proc = subprocess.Popen(
        [EXECUTABLE],
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,
        text=True,
        bufsize=1,
    )

    transcript = []
    input_queue = list(input_lines)
    input_idx = 0

    # We'll read stdout line by line and send input when needed
    # The trick: after each program output line, if there's pending input,
    # the user has typed it on the same line

    # Actually, since we can't interleave with blocking scanf,
    # we use a different strategy: read ALL output, then
    # reconstruct the interactive view.

    # Send all input at once
    full_input = "\n".join(input_lines) + "\n"
    proc.stdin.write(full_input)
    proc.stdin.close()

    # Read all output
    output = proc.stdout.read()
    proc.wait()

    return output


def build_interactive_transcript(program_output, input_lines):
    """
    Reconstruct an interactive transcript from program output and input lines.
    The program output contains prompts but no user input.
    We need to insert user input after each prompt.

    Strategy: for each prompt line in the output that expects user input,
    append the corresponding input value.
    """
    lines = program_output.split('\n')
    input_idx = 0
    result = []

    # Known patterns that indicate the program is waiting for input
    # Each pattern maps to how many input lines it consumes
    input_patterns = [
        (r'Enter your choice: ', 1),
        (r'Enter the roll number: ', 1),
        (r'Enter student\'?s? Name: ', 1),
        (r'Enter the first name of the student: ', 1),
        (r'Enter the last name of the student: ', 1),
        (r'Enter student\'?s? GPA: ', 1),
        (r'Enter course\'?s? ID: ', 1),
        (r'Enter Y if you want to add another course', 1),
        (r'Enter the course ID needed', 1),
        (r'Enter roll number for student to be deleted: ', 1),
        (r'Enter student\'? roll number, to be updated: ', 1),
        (r'Enter the new roll number: ', 1),
        (r'Enter the new first name', 1),
        (r'Enter the new last name', 1),
        (r'Enter your choice: \n', 1),
        (r'Enter Y if you want to perform another update', 1),
        (r'Enter the course to be deleted: ', 1),
        (r'Press Enter to continue', 1),
    ]

    for line in lines:
        result.append(line)
        # Check if any input pattern matches
        for pattern, count in input_patterns:
            if re.search(pattern, line):
                # Append input value(s) on the same line
                for _ in range(count):
                    if input_idx < len(input_lines):
                        result[-1] = result[-1] + input_lines[input_idx]
                        input_idx += 1
                break

    return '\n'.join(result)


def save_output(filename, content):
    filepath = os.path.join(SCREENSHOTS_DIR, filename)
    with open(filepath, "w", encoding="utf-8") as f:
        f.write(content)
    print(f"Saved: {filepath}")


def main():
    os.makedirs(SCREENSHOTS_DIR, exist_ok=True)

    # Build input lines
    lines = []

    # 1. Load from file (menu choice 2)
    lines.append("2")
    lines.append("1")
    lines.append("n")
    lines.append("3.5")
    lines.append("3.0")
    lines.append("")

    # 2. Add student manually (menu choice 1)
    lines.append("1")
    lines.append("2001")
    lines.append("John")
    lines.append("Doe")
    lines.append("3.5")
    lines.append("1")
    lines.append("n")
    lines.append("")

    # 3. Search by roll (menu choice 4)
    lines.append("4")
    lines.append("1001")
    lines.append("")

    # 4. Search by first name (menu choice 5)
    lines.append("5")
    lines.append("Adel")
    lines.append("")

    # 5. Search by course (menu choice 6)
    lines.append("6")
    lines.append("1")
    lines.append("")

    # 6. Update student (menu choice 8)
    lines.append("8")
    lines.append("1001")
    lines.append("2")
    lines.append("AdelUpdated")
    lines.append("n")
    lines.append("")

    # 7. Delete student (menu choice 7)
    lines.append("7")
    lines.append("1001")
    lines.append("")

    # 8. Show stats (menu choice 3)
    lines.append("3")
    lines.append("")

    # 9. Add student with invalid GPA (menu choice 1)
    lines.append("1")
    lines.append("2002")
    lines.append("Test")
    lines.append("User")
    lines.append("5.0")
    lines.append("3.0")
    lines.append("1")
    lines.append("n")
    lines.append("")

    # 10. Add student with duplicate roll (menu choice 1)
    lines.append("1")
    lines.append("2003")
    lines.append("Dup")
    lines.append("Test")
    lines.append("3.0")
    lines.append("1")
    lines.append("n")
    lines.append("")

    # 11. Try duplicate roll (menu choice 1)
    lines.append("1")
    lines.append("2003")
    lines.append("Another")
    lines.append("Test")
    lines.append("3.0")
    lines.append("1")
    lines.append("n")
    lines.append("")

    # 12. Exit (menu choice 9)
    lines.append("9")

    print("Running comprehensive test...")
    output = run_interactive(lines, timeout=30)

    print("Building interactive transcript...")
    transcript = build_interactive_transcript(output, lines)
    save_output("full_run.txt", transcript)

    # Also save main menu separately
    menu_lines = ["9"]
    output = run_interactive(menu_lines, timeout=10)
    transcript = build_interactive_transcript(output, menu_lines)
    save_output("main_menu.txt", transcript)

    print("\nDone!")


if __name__ == "__main__":
    main()
