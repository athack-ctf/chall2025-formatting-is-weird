FROM ubuntu:latest

RUN apt-get update && apt-get upgrade -y
RUN apt-get install -y socat gcc gcc-multilib sudo adduser

RUN adduser --disabled-password --gecos '' pwn
RUN chown -R root:pwn /home/pwn/
RUN chmod 750 /home/pwn
RUN chmod 740 /usr/bin/top
RUN chmod 740 /bin/ps
RUN chmod 740 /usr/bin/pgrep
RUN export TERM=xterm

WORKDIR /home/pwn/

COPY pwnme /home/pwn/
COPY flag.txt /home/pwn/

RUN chown root:pwn /home/pwn/flag.txt
RUN chmod 440 /home/pwn/flag.txt
RUN chown root:pwn /home/pwn/pwnme
RUN chmod +x /home/pwn/pwnme

EXPOSE 10001

CMD su pwn -c "socat -T10 TCP-LISTEN:10001,reuseaddr,fork EXEC:/home/pwn/pwnme"


