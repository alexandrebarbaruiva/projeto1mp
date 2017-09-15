#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <regex>

std::string remove_newlines(std::string my_string){
    for(int pos = 0; pos < my_string.length(); pos++){
        my_string.erase(std::remove(my_string.begin(), my_string.end(), '\n'), my_string.end());
    }
    return(my_string);
}

std::vector<int> vectorize(std::string my_string){
    std::vector<int> vectorized;
    std::stringstream string_operator(my_string);
    int a;
    while(string_operator >> a){
        vectorized.push_back(a);
        if (string_operator.peek() == ','){
            string_operator.ignore();
        }
    }
    std::cout << "v3" << std::endl;
    return(vectorized);
}

int soma_string(std::string my_string){
    std::regex endfile ("\\d+\n+$");

    if(!my_string.empty()){
        // Check for negative number or withespaces in string
        if(my_string[my_string.find('-')] == '-' ||
                my_string[my_string.find(' ')] == ' '){
            return(-1);
        }
        else{
            if(std::regex_search(my_string, endfile)){
                my_string = remove_newlines(my_string);
                std::vector<int> my_string_vector = vectorize(my_string);

                std::cout<<my_string<<std::endl;
                std::cout<<"SIZE: " + std::to_string(my_string_vector.size())<<std::endl;

                int total_sum = 0;
                for(int my_number = 0; my_number < my_string_vector.size(); my_number++) {
                    total_sum += (my_string_vector[my_number] < 1001 ?
                                        my_string_vector[my_number] : 0);
                }
                return(total_sum);
            }
            return(-1);
        }
        return(-2);
    }
    return(-1);



  // if (std::regex_match ("subject", std::regex("(sub)(.*)")))
  //   std::cout << "string literal matched\n";
  //
  // const char cstr[] = "subject";
  // std::string s ("subject");
  // std::regex e ("(sub)(.*)");
  //
  // if (std::regex_match (s,e))
  //   std::cout << "string object matched\n";
  //
  // if ( std::regex_match ( s.begin(), s.end(), e ) )
  //   std::cout << "range matched\n";
  //
  // std::cmatch cm;    // same as std::match_results<const char*> cm;
  // std::regex_match (cstr,cm,e);
  // std::cout << "string literal with " << cm.size() << " matches\n";
  //
  // std::smatch sm;    // same as std::match_results<string::const_iterator> sm;
  // std::regex_match (s,sm,e);
  // std::cout << "string object with " << sm.size() << " matches\n";
  //
  // std::regex_match ( s.cbegin(), s.cend(), sm, e);
  // std::cout << "range with " << sm.size() << " matches\n";
  //
  // // using explicit flags:
  // std::regex_match ( cstr, cm, e, std::regex_constants::match_default );
  //
  // std::cout << "the matches were: ";
  // for (unsigned i=0; i<cm.size(); ++i) {
  //   std::cout << "[" << cm[i] << "] ";
  // }
  //
  // std::cout << std::endl;
  //
  // return 0;
}
