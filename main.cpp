#include <iostream>
#include "string_soma.cpp"

int main(){
    std::string my_string = "1,2\n";
    // std::cin >> my_string;
    std::cout << soma_string(my_string) << std::endl;
}
