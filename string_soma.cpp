#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <regex>

/** @brief Function responsible for the removal of newlines in the string to be
* treated.
*
* Particularly useful when the string in question is filled with non-breaking
* newlines
*/
std::string remove_newlines(std::string my_string){
    for(int pos = 0; pos < my_string.length(); pos++){
        my_string.erase(std::remove(my_string.begin(), my_string.end(), '\n'), my_string.end());
    }
    return(my_string);
}

/** @brief Function to make the process of summing up the numbers in the string
* truly simple.
*
* Once vectorized, all kinds of operations become possible to be done.
*/
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
    return(vectorized);
}

std::string find_delimiters(std::string my_string){
    std::regex beginfile ("^//\\[.*\\]\n");
    std::vector<std::string> delimiters;
    std::string open_del = "[";
    std::string close_del = "]";

    std::size_t f_odel = my_string.find("["); // Finds start of a delimiter
    std::size_t f_cdel = my_string.find("]"); // Finds end of a delimiter
    while(f_odel != std::string::npos &&
                f_cdel != std::string::npos){
        std::string new_delimiter = my_string.substr(f_odel+1,
                                            (f_cdel-f_odel-1));
        delimiters.push_back(new_delimiter);
        my_string.replace(0, f_cdel+2, "");
        std::cout<<my_string;
        f_odel = my_string.find("[");
        f_cdel = my_string.find("]");
    }



    for(int md = 0; md < delimiters.size(); md++){
        std::size_t find_del = my_string.find(delimiters[md]);
        std::cout << md << '\n';
        while(find_del != std::string::npos){
            my_string.replace(find_del,delimiters[md].size(),",");
            std::size_t find_del = my_string.find(delimiters[md]);
            std::cout << my_string << '\n';
        }
    }
    return my_string;
}

/** @brief Main function, responsible for delegating tasks
*
* Once it reaches the end, it gives the result of a string sum.
*/
int soma_string(std::string my_string){
    std::regex endfile ("\\d+\n+$"); //
    std::regex not_valids ("[^\\d,\n]");
    std::regex beginfile ("^//\\[.*\\]\n");

    if(!my_string.empty()){
        // Check for negative number or withespaces in string
        if(my_string[my_string.find('-')] == '-' ||
                my_string[my_string.find(' ')] == ' '){
            return(-1);
        }
        else{
            if(std::regex_search(my_string, endfile)){
                // Check for different delimiters
                if(std::regex_search(my_string, beginfile)){
                    my_string = find_delimiters(my_string);
                }


                // Remove all newlines once they are checked for correctness
                my_string = remove_newlines(my_string);
                std::vector<int> my_string_vector = vectorize(my_string);

                if(std::regex_search(my_string, not_valids)){
                    return -1;
                }
                
                int total_sum = 0;
                for(int my_number = 0; my_number < my_string_vector.size(); my_number++) {
                    total_sum += (my_string_vector[my_number] < 1001 ?
                                        my_string_vector[my_number] : 0);
                }
                return(total_sum);
            }
            return(-1);
        }
        return(-1);
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
