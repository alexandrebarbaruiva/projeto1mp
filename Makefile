default: run

run:
	g++ -fprofile-arcs -ftest-coverage -fPIC -O0 test.cpp -o program
	./program
	gcovr -r .
	rm *.gcda *.gcno
