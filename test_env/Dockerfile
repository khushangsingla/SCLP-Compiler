FROM ubuntu:22.04

RUN apt update && apt upgrade -y
RUN apt install bison flex g++ gcc build-essential -y

RUN apt install gdb -y
RUN apt install libjsoncpp-dev libbison-dev -y

COPY ./entry.sh /entry.sh
RUN chmod +x /entry.sh

RUN mkdir /project
WORKDIR /project

ENTRYPOINT ["/entry.sh"]

