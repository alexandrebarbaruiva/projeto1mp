# Projeto Somador de strings numéricas

This project aims to implement knowledge acquired in the class of Métodos de Programação by means of the simulation of the fall of a ball inside a 2D box.

## Requirements

You must have a C ++ compiler installed on the machine.
The operating system can be Linux, Windows or MacOS.
Compiler installation:
- [Windows.](https://cs.calvin.edu/courses/cs/112/resources/installingEclipse/cygwin/)
- [Mac.](https://www.mkyong.com/mac/how-to-install-gcc-compiler-on-mac-os-x/)
- [Linux.](https://askubuntu.com/questions/348654/how-to-install-g-compiler)

For coverage, gcovr is used. Go to http://gcovr.com/ for installation process.
It's used valgrind to check use of memory.

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
For tests, run
```
make test
```
For checking performance
```
make perf
```


## File description

- testa_soma_string_stdin.cpp - Program for checking text files
- string_soma.hpp - Abstract file for function soma_string
- string_soma.cpp - Implementation of function soma_string
- testa_string_soma.cpp - Code for all the unit tests (it was used TDD in this project! Yay!)

## TODO

- [x] Criar doxygen
- [x] Checar vírgulas duplas
