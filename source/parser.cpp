#include <vector>
#include <iostream>
#include <string>

#include "../include/parser.hpp"
#include "../include/lexer.hpp"

/// @brief This function reconstructs the lexical tree as a non-abstract syntax tree.
/// @param rawTree The original tree.
/// @return The reconstructed/transmuted tree.
/// @brief From 'parser.hpp'
lexical_tree *concretiztaion(lexical_tree *rawTree){
    // Initialize the vector that used to reconstruct the tree.
    std::vector< std::pair<std::string, std::string> > concretizedTree; 
    // Assuming each node is an abstract node, meaning it hides complexity from the usr.
    for(auto& abstractNode : rawTree->abstractNodes){
        // Save the opcode and operand in 'a' and 'b' (respctive).
        std::string a(abstractNode.first);
        std::string b(abstractNode.second);
        
        // Abstract instruction #1 (Clear -)
        if(!a.compare("clr")){
           // Push the existing brainfuck instructions, to result in the desired behaviour.
           // This operation better known as abstraction-mopping or concretization
           // Alters the Abstract Syntax Tree to result in a concret and possible alternative
           // That results in the same behaviour indeed.

           // Knowing this, we can make as much abstract instructions, and hiding complexity from
           // The user, because the compiler can transmute or concretize the abstract instruction into their respective alternative.
           concretizedTree.push_back(std::make_pair("psh", "$00"));
           concretizedTree.push_back(std::make_pair("sub", b));
           concretizedTree.push_back(std::make_pair("pop", "$00"));
           
        }else if(!a.compare("cla")){
           // Abstract instruction #2 (Clear +)
           concretizedTree.push_back(std::make_pair("psh", "$00"));
           concretizedTree.push_back(std::make_pair("add", b));
           concretizedTree.push_back(std::make_pair("pop", "$00"));
        }else if(!a.compare("btr")){
           // Abstract instruction #3 (Boolean true)
           concretizedTree.push_back(std::make_pair("psh", "$00"));
           concretizedTree.push_back(std::make_pair("sub", "$01"));
           concretizedTree.push_back(std::make_pair("pop", "$00"));
           concretizedTree.push_back(std::make_pair("sup", "$01"));
        }
        else{
           // If we don't meet a abstract instruction, then our assumption is false.
           // meaning this node is a concret node, and can be planted into the tree without any changes.
           concretizedTree.push_back(std::make_pair(a,b));        
        }
    }
    // The concret and free from abstract tree.
    lexical_tree *concretTree = new lexical_tree(concretizedTree);
    return concretTree;
}

/// @brief Transforms the AST/CST (Concret Syntax Tree) to brainfuck alternative code.
/// @param concretTree The concretized tree.
/// @return The final output in brainfuck.
/// @brief From 'parser.hpp'
std::string alterBrainfuck(lexical_tree *concretTree){
    std::string brainfuckOut = "";

    for(auto& concretNode : concretTree->abstractNodes){
        std::string a(concretNode.first);
        std::string b(concretNode.second);
        int nConcretB = parseArgument(b.c_str());
        
        // If there are no arguments, then treat it as a $01.
        if(nConcretB == -1)nConcretB = 1;
        
        char token = 0;
        // Logical instructions don't need an argument.
        bool isLogical = false;
        if(!a.compare("rsh"))token = '>', isLogical = false;
        if(!a.compare("lsh"))token = '<', isLogical = false;
        if(!a.compare("sup"))token = '+', isLogical = false;
        if(!a.compare("sub"))token = '-', isLogical = false;
        if(!a.compare("psh"))token = '[', isLogical = true;
        if(!a.compare("pop"))token = ']', isLogical = true;
        if(!a.compare("out"))token = '.', isLogical = false;
        // rcv = receive.
        if(!a.compare("rcv"))token = ',';
        // If the argument is '$00', then ignore the command.
        if(nConcretB == 0 && !isLogical)continue;

        if(!isLogical){
           for(int i = 0; i < nConcretB; i++)brainfuckOut.push_back(token);
        }else {
            brainfuckOut.push_back(token);
        }
    }
    return brainfuckOut;
}