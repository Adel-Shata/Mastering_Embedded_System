#!/usr/bin/env python3
"""
Capture individual screenshots for each operation.
"""

import subprocess
import os

SCREENSHOTS_DIR = "docs/screenshots"
EXECUTABLE = "./sms.exe"

def run_capture(input_data, timeout=15):
    """Run program with input and return stdout."""
    proc = subprocess.Popen([EXECUTABLE], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    stdout, stderr = proc.communicate(input=input_data, timeout=timeout)
    return stdout

def save_screenshot(name, content):
    """Save screenshot text and SVG."""
    txt_path = os.path.join(SCREENSHOTS_DIR, f"{name}.txt")
    with open(txt_path, 'w') as f:
        f.write(content)
    print(f"Saved: {txt_path}")

def main():
    os.makedirs(SCREENSHOTS_DIR, exist_ok=True)

    # 1. Main Menu
    print("Capturing: Main Menu")
    out = run_capture("9\n")
    save_screenshot("main_menu", out)

    # 2. Add Student Manually - just show the initial prompts (roll, name, GPA)
    # We'll capture up to GPA entry, then exit
    print("Capturing: Add Student Manually")
    # Input: 1 (manual), 2001 (roll), John (first), Doe (last), 3.5 (GPA), then 9 to exit before course selection
    # But we can't exit mid-operation. Let's just capture the file loading and other ops which work cleanly.
    # For manual add, we'll use a simpler approach - capture the prompts that appear
    out = run_capture("1\n2001\nJohn\nDoe\n3.5\n1\nn\n\n9\n", timeout=20)
    save_screenshot("add_manual", out)

    # 3. File Loading
    print("Capturing: File Loading")
    out = run_capture("2\n\n1\nn\n3.5\n3.0\n\n9\n")
    save_screenshot("file_loading", out)

    # 4. Search by Roll (after file load)
    print("Capturing: Search by Roll")
    out = run_capture("2\n\n1\nn\n3.5\n3.0\n\n4\n1001\n\n9\n")
    save_screenshot("search_roll", out)

    # 5. Search by First Name
    print("Capturing: Search by First Name")
    out = run_capture("2\n\n1\nn\n3.5\n3.0\n\n5\nAdel\n\n9\n")
    save_screenshot("search_name", out)

    # 6. Search by Course
    print("Capturing: Search by Course")
    out = run_capture("2\n\n1\nn\n3.5\n3.0\n\n6\n1\n\n9\n")
    save_screenshot("search_course", out)

    # 7. Update Student
    print("Capturing: Update Student")
    out = run_capture("2\n\n1\nn\n3.5\n3.0\n\n8\n1001\n2\nAdelUpdated\nn\n\n9\n")
    save_screenshot("update_student", out)

    # 8. Delete Student
    print("Capturing: Delete Student")
    out = run_capture("2\n\n1\nn\n3.5\n3.0\n\n7\n1001\n\n9\n")
    save_screenshot("delete_student", out)

    # 9. Database Stats
    print("Capturing: Database Stats")
    out = run_capture("2\n\n1\nn\n3.5\n3.0\n\n3\n\n9\n")
    save_screenshot("database_stats", out)

    # 10. Invalid Input (GPA validation)
    print("Capturing: Invalid Input")
    out = run_capture("1\n2002\nTest\nUser\n5.0\n3.0\n1\nn\n\n9\n")
    save_screenshot("invalid_input", out)

    # 11. Duplicate Roll
    print("Capturing: Duplicate Roll")
    out = run_capture("1\n2003\nDup\nTest\n3.0\n1\nn\n\n1\n2003\nAnother\nTest\n3.0\n1\nn\n\n9\n")
    save_screenshot("duplicate_roll", out)

    print("\nAll captures complete!")

if __name__ == "__main__":
    main()