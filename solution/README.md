# How to Solve the Challenge?

`exploit.py` provides a working solution to the challenge with comments giving a high-level overview of the exploit process.

Pwntools will have to be installed to run this script. (`pip install pwntools`)

There are two ways to run the script:

1. `python3 exploit.py` - Will run the exploit on the local binary
2. `python3 exploit.py REMOTE IP PORT` - Will run the exploit on a remote server

Please use the 2nd option to test the solution on a remote server as this avoids the trouble of having a different libc version affecting the results.