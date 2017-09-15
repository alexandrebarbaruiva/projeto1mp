default: run

cppcov:
	g++ -fprofile-arcs -ftest-coverage -fPIC -O0 test.cpp -o program -std=c++11
	./program
	gcovr -r . -e "./others/*"
	gcovr -r . -e "./others/*" --html --html-details -o detailedcoverage.html
	rm *.gcda *.gcno
	cppcheck --enable=all string_soma.cpp string_soma.hpp

run:
	g++ test.cpp -o program -std=c++11
	./program
	cppcheck --enable=all string_soma.cpp string_soma.hpp
	
clean:
	rm *.gcda *.gcno
