default: run

run:
	g++ -fprofile-arcs -ftest-coverage -fPIC -O0 test.cpp -o program -std=c++11
	./program
	gcovr -r .
	gcovr -r . --html --html-details -o detailedcoverage.html
	rm *.gcda *.gcno
