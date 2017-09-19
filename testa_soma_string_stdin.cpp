#include <iostream>
#include "string_soma.cpp"

int main(){
    std::string my_string;
    std::cin >> my_string;
    if(my_string == "3"){
        std::cout<<"YES"<<std::endl;
    }
    std::cout << my_string << std::endl;
    std::cout << soma_string(my_string);
}
