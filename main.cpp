#include <iostream>
#include <fstream>
#include <string>

#include "include/lexer.hpp"
#include "include/parser.hpp"

int main(int argc, char **argv){
    // If there are not enough arguments, just throw a basic error message.
    // And return 1 as 'something wrong happend'.
    if(argc < 2){
        std::cerr << "\033[1m\033[31merror:\033[0m no source file.\n";
        return 1;
    }
    // Declare the file streams that will be used in this case.
    std::ifstream source; 
    std::ofstream produced;
    // Open the first file as 'input' by inserting its name in the first argument.
    source.open(argv[1], std::ios_base::in);
    // If there are no second argument.
    if(!(argc < 3)){
       produced.open(argv[2], std::ios_base::out);
    }else {
       // Then, take the source's name and 'cat' an 'out.bf'.
       produced.open(strcat(argv[1], "out.bf"), std::ios_base::out);
    }
    // Save the content of the source, in this string.
    std::string content; 
    // Go through each character in the source, and push the end as character.
    while(!source.eof()){
        content.push_back(source.get());
    }
    // Allocate the abstract syntax tree using Lexical analysis functions.
    lexical_tree *abstractTree = analyzeSource(content.c_str());
    // Concretize the tree (Removing abstractions).
    lexical_tree *concretTree = concretiztaion(abstractTree);
    // Translate the CST into brainfuck valid tokens.
    std::string translatedSource = alterBrainfuck(concretTree);
    // Delete the root and nodes of the two trees.
    delete abstractTree, concretTree;
    // Save the translated code into the output file.
    produced << translatedSource;
    // Close the source file, and close the output file.
    source.close();
    produced.close();
    // And halt.
    return 0;
}