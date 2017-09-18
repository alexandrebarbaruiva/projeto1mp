default: run

cppcov:
	g++ -fprofile-arcs -ftest-coverage -fPIC -O0 testa_string_soma.cpp -o program -std=c++11
	valgrind --leak-check=yes ./program
	valgrind --tool=cachegrind ./program
	gcovr -r . -e "./others/*"
	gcovr -r . -e "./others/*" --html --html-details -o coverage.html
	rm *.gcda *.gcno program
	cppcheck --enable=warning string_soma.cpp string_soma.hpp

run:
	g++ testa_string_soma.cpp -o program -std=c++11
	./program
	cppcheck --enable=warning string_soma.cpp string_soma.hpp
	rm program

main:
	g++ testa_soma_string_stdin.cpp -o testa_soma_string_stdin -std=c++11
	./testa_soma_string_stdin < entrada.txt > saida.txt
	rm testa_soma_string_stdin

clean:
	rm *.gcda *.gcno
