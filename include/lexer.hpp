#ifndef LEXER_INCLUDED
#define LEXER_INCLUDED

#include <string>
#include <vector>

/// @brief Contains the data of the lexical data.
struct lexical_tree {
    // Initialize the vector of the strings.
    std::vector< std::pair<std::string, std::string> > abstractNodes;
    // The constructor should be explicit. or not.
    lexical_tree(const std::vector< std::pair<std::string, std::string> >& _lexicalNodes){
        // Set it.
        abstractNodes = _lexicalNodes;
    }
    
    ~lexical_tree(){
        abstractNodes.clear();
    }
};

int parseArgument(const char *arg);
lexical_tree *analyzeSource(const char *source);

#endif