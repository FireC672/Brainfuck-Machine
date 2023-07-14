#include "../include/lexer.hpp"

#include <vector>
#include <string>
#include <cctype>
#include <cmath>

int parseArgument(const char *arg){
    int j = strlen(arg)-1;
    int total = 0; 
    
    while( *arg && *arg != '$' )
          arg++,j--;
    arg++; 

    while( *arg && *arg != '\n' ){
        if(!isalnum(*arg))break; 

        if(isdigit(*arg)){
            total += (*arg-'0') * static_cast<int>(pow(10,j));
            j--;
        }else{
            total += (*arg - (isupper(*arg)?'A':'a')+10) * static_cast<int>(pow(10,j));
            j--;
        }

        arg++;
    }

    return total;
}

lexical_node *analyzeSource(const char *source){
    std::vector<std::string> analyzed; 
    while( *source ){
        source++;
    }
}