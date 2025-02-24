# Building Your Challenge

## You may deploy the challenge by building the container: 

```
docker build .
```

The docker container exposes port **10001** for the client connection. 

This can be changed inside the Dockerfile.

## DO NOT BUILD FROM SOURCE CODE. 

### The pre-built binary is used in the docker container and is also given to the participant.
### This pre-built version includes known offsets for the solution, exploit.py, to work.

### I have only included the source code and build script for archival purposes
