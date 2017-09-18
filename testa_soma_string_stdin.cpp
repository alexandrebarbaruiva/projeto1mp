#include <iostream>
#include "string_soma.cpp"

int main(){
    std::string my_string;
    std::cin >> my_string;
    std::cout << my_string << std::endl;
    std::cout << soma_string(my_string);
}
