#ifndef LEXER_INCLUDED
#define LEXER_INCLUDED

#include <string>
#include <vector>

/// @brief Contains the data of the lexical data.
struct lexical_node {
    // 
    std::vector<std::string> lexical_strs;

    lexical_node(const std::vector<std::string>& lexstr){
        lexical_strs = lexstr;
    }

    ~lexical_node(){
        lexical_strs.clear();
    }
};

#endif