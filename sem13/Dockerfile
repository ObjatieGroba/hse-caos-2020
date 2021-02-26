FROM debian:buster-slim

COPY main.c /root/

RUN apt update && apt install -y gcc nano

RUN apt update && apt install openssh-server sudo -y

RUN useradd -rm -s /bin/bash -g root -G sudo -u 1000 test

RUN  echo 'test:test' | chpasswd

EXPOSE 22
