#include <iostream>
#include <fstream>
#include <string>
#include "include/lexer.hpp"
#include "include/parser.hpp"

int main(int argc, char **argv){
    
    if(argc < 2){
        std::cerr << "\033[1m\033[31merror:\033[0m no source file.\n";
        return 1;
    }

    std::ifstream source; 
    std::ofstream produced;

    source.open(argv[1], std::ios_base::in);
    if(!(argc < 3)){
       produced.open(argv[2], std::ios_base::out);
    }else {
       produced.open(strcat(argv[1], "out.bf"), std::ios_base::out);
    }

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