#ifndef LEXER_INCLUDED
#define LEXER_INCLUDED

#include <string>
#include <vector>

/// @brief Contains the data of the lexical data.
struct lexical_node {
    // Initialize the vector of the strings.
    std::vector<std::string> lexicalNodes;
    // The constructor should be explicit.
    explicit lexical_node(const std::vector<std::string>& _lexicalNodes){
        // Set it.
        lexicalNodes = _lexicalNodes;
    }
    
    ~lexical_node(){
        lexicalNodes.clear();
    }
};

int parseArgument(const char *arg);
lexical_node *analyzeSource(const char *source);

#endif