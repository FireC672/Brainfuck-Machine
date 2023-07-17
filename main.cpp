#include <iostream>
#include <fstream>
#include <string>
#include "include/lexer.hpp"
#include "include/parser.hpp"

int main(int argc, char **argv){
    std::ifstream source; 
    std::ofstream produced;

    source.open(argv[1], std::ios_base::in);
    produced.open(argv[2], std::ios_base::out);

    std::string content; 
    while(!source.eof()){
        content.push_back(source.get());
    }
    
    lexical_tree *abstractTree = analyzeSource(content.c_str());
    lexical_tree *concretTree = concretiztaion(abstractTree);
    std::string translatedSource = alterBrainfuck(concretTree);

    delete abstractTree, concretTree;

    produced << translatedSource;

    source.close();
    produced.close();
    return 0;
}