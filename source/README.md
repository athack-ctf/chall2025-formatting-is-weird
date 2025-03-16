# Building This Challenge

## Quick and easy docker build then run.

Build
```
docker build -t athack-ctf/chall2025-formatting-is-weird:latest .
```

Run
```
docker run -d --name formatting-is-weird \
  -p 52027:10001 \
  athack-ctf/chall2025-formatting-is-weird:latest
```

The container binds port 52027 to the services exposed port 10001. This can be changed inside the docker-compose file.

## DO NOT BUILD FROM SOURCE CODE. 

### The pre-built binary is used in the docker container and is also given to the participant.
### This pre-built version includes known offsets for the solution, exploit.py, to work.

### I have only included the source code and build script for archival purposes
