#!/usr/bin/env python3
"""
Script to run the Student Management System and capture terminal output
for documentation screenshots.
"""

import subprocess
import os
import time

SCREENSHOTS_DIR = "docs/screenshots"
EXECUTABLE = "./sms.exe"

def run_program(input_data, timeout=20):
    """Run the program with given input and return stdout."""
    try:
        result = subprocess.run(
            [EXECUTABLE],
            input=input_data,
            capture_output=True,
            text=True,
            timeout=timeout
        )
        return result.stdout
    except subprocess.TimeoutExpired:
        return "[TIMEOUT]"
    except Exception as e:
        return f"[ERROR: {e}]"

def save_output(filename, content):
    """Save output to a text file."""
    filepath = os.path.join(SCREENSHOTS_DIR, filename)
    with open(filepath, 'w') as f:
        f.write(content)
    print(f"Saved: {filepath}")

def main():
    os.makedirs(SCREENSHOTS_DIR, exist_ok=True)

    # 1. Main Menu
    print("Capturing: Main Menu")
    output = run_program("9\n")
    save_output("main_menu.txt", output)

    # 2. Add Student Manually
    print("Capturing: Add Student Manually")
    output = run_program("1\n2001\nJohn\nDoe\n3.5\n1\nn\n\n9\n")
    save_output("add_manual.txt", output)

    # 3. Load Students from File
    # File has 10 valid entries, then some with issues:
    # - 1014 No Courses: prompts for manual course entry -> course 1, n
    # - 1015 High GPA: prompts for valid GPA -> 3.5
    # - 1016 Negative GPA: prompts for valid GPA -> 3.0
    # After file loading, shows stats and "Press Enter to continue"
    # Then menu, then 9 to exit
    print("Capturing: File Loading")
    file_load_input = "2\n"  # Choose file loading
    # For 1014 No Courses: manual course entry
    file_load_input += "1\nn\n"  # Add course 1 (MATH1), then n
    # For 1015 High GPA: manual GPA entry
    file_load_input += "3.5\n"
    # For 1016 Negative GPA: manual GPA entry
    file_load_input += "3.0\n"
    # Press Enter after file loading stats
    file_load_input += "\n"
    # Exit
    file_load_input += "9\n"
    output = run_program(file_load_input)
    save_output("file_loading.txt", output)

    # 4. Search by Roll Number (after file load, roll 1001 exists)
    print("Capturing: Search by Roll")
    output = run_program("2\n\n4\n1001\n\n9\n")
    save_output("search_roll.txt", output)

    # 5. Search by First Name
    print("Capturing: Search by First Name")
    output = run_program("2\n\n5\nAdel\n\n9\n")
    save_output("search_name.txt", output)

    # 6. Search by Course
    print("Capturing: Search by Course")
    output = run_program("2\n\n6\n1\n\n9\n")
    save_output("search_course.txt", output)

    # 7. Update Student
    print("Capturing: Update Student")
    output = run_program("2\n\n8\n1001\n2\nAdelUpdated\n\nn\n\n9\n")
    save_output("update_student.txt", output)

    # 8. Delete Student
    print("Capturing: Delete Student")
    output = run_program("2\n\n7\n1001\n\n9\n")
    save_output("delete_student.txt", output)

    # 9. Invalid Input / Validation
    print("Capturing: Invalid Input")
    output = run_program("1\n2002\nTest\nUser\n5.0\n3.0\n1\nn\n\n9\n")
    save_output("invalid_input.txt", output)

    # 10. Duplicate Roll
    print("Capturing: Duplicate Roll")
    output = run_program("1\n2003\nDup\nTest\n3.0\n1\nn\n\n1\n2003\nAnother\nTest\n3.0\n1\nn\n\n9\n")
    save_output("duplicate_roll.txt", output)

    # 11. Find Number of Students (database stats)
    print("Capturing: Database Stats")
    output = run_program("2\n\n3\n\n9\n")
    save_output("database_stats.txt", output)

    print("\nAll captures complete!")

if __name__ == "__main__":
    main()