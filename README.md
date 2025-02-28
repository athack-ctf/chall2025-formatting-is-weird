# Chall - Formatting Is Weird

> The PIE was a lie

## Type

- [ ] **OFF**line
- [X] **ON**line

## Designer

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

## Category

- `pwn`
- `re`
