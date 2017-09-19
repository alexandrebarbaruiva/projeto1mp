#include <iostream>
#include <fstream>
#include <string>
#include "string_soma.cpp"

int main(){
    std::string my_string = "";
    std::string temp;
    std::vector<std::string> my_string_array;
    std::getline(std::cin, my_string, '\0');
    std::cout << soma_string(my_string);
}
