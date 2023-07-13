#include "../include/lexer.hpp"

#include <vector>
#include <string>
#include <cctype>

int parseArgument(const char *arg){
    while( *arg != '$' && *arg ){
        arg++;
    }

    while( *arg && *arg != '\n' && isalnum(*arg) ){
        
        arg++;
    }

    return -1;
}

lexical_node *analyzeSource(const char *source){
    std::vector<std::string> analyzed; 
    while( *source ){
        source++;
    }
}