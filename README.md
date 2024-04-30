# SCLP - Compiler

This is a compiler for a simple C like programming language. The specifics of the language can be found [here](https://www.cse.iitb.ac.in/~uday/sclp-web).

## Running instructions

In the `project` folder, run `make`. This would make an executable `sclp` which is the compiler
program. If there is some dependency issue, use following docker commands in the current folder:

```bash
docker compose up -d
docker compose exec -ti test bash
```

Inside the shell that opened, run `make` to compile the code and use the `sclp`
inside the docker. Testing programs can be added in `testing` folder and can
be accessed inside docker at `/testing`. Project folder is mounted in docker
at `/project`.


### Contributors

- [Hrishikesh](https://hrishi-06.github.io/)
- [Khushang Singla](https://khushangsingla.github.io/)

This project was done under guidance of [Prof. Uday Khedker](https://www.cse.iitb.ac.in/~uday/)
as a part of the Course Implementation of Programming Languages Lab (CS 316) at IIT Bombay.
