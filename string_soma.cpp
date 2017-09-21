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
* newlines.
* @param my_string string for removal of newlines
* @return string without newlines
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
* @param my_string string used to make vector
* @return vector with all numbers in string if string is valid
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

/** @brief Function for finding special delimiters.
*
* Also checks if all characters are valid.
* @param my_string string to be checked
* @return string with all delimiters changed to comma
*/
std::string find_delimiters(std::string my_string){
    std::vector<std::string> delimiters;

    // Find all delimiters
    std::size_t f_odel = my_string.find("["); // Finds start of a delimiter
    std::size_t f_cdel = my_string.find("]"); // Finds end of a delimiter
    while(f_odel != std::string::npos &&
                f_cdel != std::string::npos){
        std::string new_delimiter = my_string.substr(f_odel+1,
                                            (f_cdel-f_odel-1));
        delimiters.push_back(new_delimiter);
        my_string.replace(0, f_cdel+1, "");
        f_odel = my_string.find("[");
        f_cdel = my_string.find("]");
    }
    my_string.replace(0, 1, "");

    // Concatenate all delimiters
    std::string all_del = "[^\\d";
    for(int md = 0; md < delimiters.size(); md++){
        all_del += delimiters[md];
    }
    all_del += "\n]";

    // Check if all characters are valid
    std::regex not_valids (all_del);
    if(std::regex_search(my_string, not_valids)){
        return("-1\n");
    }

    // Change all delimiters to comma
    for(int md = 0; md < delimiters.size(); md++){
        std::size_t find_del = my_string.find(delimiters[md]);
        while(find_del != std::string::npos && delimiters[md] != ","){
            my_string.replace(find_del,delimiters[md].size(),",");
            find_del = my_string.find(delimiters[md]);
        }
    }
    return my_string;
}

/** @brief Main function, responsible for delegating tasks and show the result.
*
* Once it reaches the end, it gives the result of a string sum.
* @param my_string string for summing up
* @return sum of string or error
*/
int soma_string(std::string my_string){
    std::regex endfile ("\\d+\n+$"); // REGEX correct end
    std::regex not_so_empty_string ("^\n+$");
    std::regex not_valids ("[^\\d,\n]"); // REGEX char not valid
    std::regex beginfile ("^//\\[.*\\]\n"); // REGEX personalized delimiters
    std::regex doublecomma (",,"); // REGEX double commas
    std::regex commainit ("^,"); // REGEX breaking comma at beginning
    std::regex fournumbers ("\\d+,\\d+,\\d+,\\d+"); // four numbers, same line

    if(!my_string.empty()){
        if(std::regex_search(my_string, endfile)){
            // Check for different delimiters
            if(std::regex_search(my_string, beginfile)){
                my_string = find_delimiters(my_string);
            }

            // Check for negative number, white spaces in string, double commas
            // breaking commas or four numbers in line
            if(my_string[my_string.find('-')] == '-' ||
                    my_string[my_string.find(' ')] == ' '||
                        std::regex_search(my_string, doublecomma) ||
                            std::regex_search(my_string, commainit) ||
                                std::regex_search(my_string, fournumbers)){
                return(-1);
            }

            // Remove all newlines once they are checked for correctness
            my_string = remove_newlines(my_string);
            std::vector<int> my_string_vector = vectorize(my_string);

            // Check if all characters are valid
            if(std::regex_search(my_string, not_valids)){
                return -1;
            }

            // Sums up the numbers
            int total_sum = 0;
            for(int my_number = 0; my_number < my_string_vector.size(); my_number++) {
                total_sum += (my_string_vector[my_number] < 1001 ?
                                    my_string_vector[my_number] : 0);
            }
            return(total_sum);
        }
        else if(std::regex_search(my_string, not_so_empty_string)){
            return(0);
        }
        return(-1);
    }
    return(-1);
}
