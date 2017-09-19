# Projeto Somador de strings numéricas

This project aims to implement knowledge acquired in the class of Métodos de Programação by means of summing a string of numbers.

## Requirements

You must have a C++ compiler (4.9 or above) installed on the machine.
The operating system can be Linux, Windows or MacOS.
Compiler installation:
- [Windows.](https://cs.calvin.edu/courses/cs/112/resources/installingEclipse/cygwin/)
- [Mac.](https://www.mkyong.com/mac/how-to-install-gcc-compiler-on-mac-os-x/)
- [Linux.](https://askubuntu.com/questions/348654/how-to-install-g-compiler)
- [Linux 4.9.](https://askubuntu.com/questions/428198/getting-installing-gcc-g-4-9-on-ubuntu)

For coverage, gcovr is used. Go to http://gcovr.com/ for installation process.
It's used [valgrind](http://valgrind.org/) to check use of memory. [Installation process here] (http://valgrind.org/docs/manual/dist.install.html)

## Installing/Compiling

Download the entire project directory, open the terminal or the equivalent of your machine, access the directory in which the project was downloaded using

```
cd /YourDirectory/YourFolder/projeto1mp
```
Insert your input according to the requisites found here: [PDF Document](mp_t1.pdf).
Then compile using make.

```
make
```
In case your gcc is below 4.9, install using the [link provided](https://askubuntu.com/questions/428198/getting-installing-gcc-g-4-9-on-ubuntu)
and use
```
make stable
```
For tests, run
```
make test
```
or
```
make stabletest
```
For checking performance
```
make perf
```
or
```
make stableperf
```

## GCOV

If you want to check the gcov results, go to [this link](https://cdn.rawgit.com/alexandrebarbaruiva/projeto1mp/f2607218/coverage.html).

## File description

- testa_soma_string_stdin.cpp - Program for checking text files
- string_soma.hpp - Abstract file for function soma_string
- string_soma.cpp - Implementation of function soma_string
- testa_string_soma.cpp - Code for all the unit tests (it was used TDD in this project! Yay!)

## TODO

- [x] Criar doxygen
- [x] Checar vírgulas duplas
