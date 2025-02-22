# Chall - Formatting Is Weird

> The PIE was a lie

## Type

- [X] **OFF**line
- [X] **ON**line

## Designer(s)

- William Mailhot

## Description

This challenge focuses on a format string vulnerability which then leads to information disclosure about PIE. 

We can combine our findings of the PIE base and use the buffer overflow vulnerability to calculate the address of libc using a simple ROP chain.

This then gives us access to call system("/bin/sh")

### Protections used
- Stack is not executable
- PIE is enabled
- Very simple custom stack protection

**IMPORTANT:** This description will **NOT** be shared with participants.

## Category(ies)

- `pwn`
- `re`

---

# Project Structure

## 1. HACKME.md

- **[HACKME.md](HACKME.md)**: A teaser or description of the challenge to be shared with participants (in CTFd).

## 2. Source Code

- **[source/README.md](source/README.md)**: Sufficient instructions for building your offline artifacts from source
  code. If your project includes multiple subprojects, please consult us (Anis and Hugo).
- **[source/*](source/)**: Your source code.

## 3. Offline Artifacts

- **[offline-artifacts/*](offline-artifacts/)**: All files (properly named) intended for local download by
  participants (e.g., a binary executable for reverse engineering, a custom-encoded image, etc.). For large files (
  exceeding 100 MB), please consult us (Anis and Hugo).

## 4. Solution

- **[solution/README.md](solution/README.md)**: A detailed writeup of the working solution.
- **[solution/FLAGS.md](solution/FLAGS.md)**: A single markdown file listing all (up-to-date) flags.
- **[solution/*](solution/)**: Any additional files or code necessary for constructing a reproducible solution for the
  challenge (e.g., `PoC.py`, `requirement.txt`, etc.). 
