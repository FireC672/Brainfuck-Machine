#include "../include/parser.hpp"
#include "../include/lexer.hpp"
#include <vector>
#include <string>

/// @brief This function reconstructs the lexical tree as a non-abstract syntax tree.
/// @param rawTree The original tree.
/// @return The reconstructed/transmuted tree.
lexical_tree *concretiztaion(lexical_tree *rawTree){
    // Initialize the vector that used to reconstruct the tree.
    std::vector< std::pair<std::string, std::string> > concretizedTree; 
    // Assuming each node is an abstract node, meaning it hides complexity from the usr.
    for(auto& abstractNode : rawTree->abstractNodes){
        // Save the opcode and operand in 'a' and 'b' (respctive).
        std::string& a(abstractNode.first);
        std::string& b(abstractNode.second);
        
        // Abstract instruction #1 (Clear -)
        if(a.compare("clr")){
           // Push the existing brainfuck instructions, to result in the desired behaviour.
           // This operation better known as abstraction-mopping or concretization
           // Alters the Abstract Syntax Tree to result in a concret and possible alternative
           // That results in the same behaviour indeed.

           // Knowing this, we can make as much abstract instructions, and hiding complexity from
           // The user, because the compiler can transmute or concretize the abstract instruction into their respective alternative.
           concretizedTree.push_back(std::make_pair("psh", "$00"));
           concretizedTree.push_back(std::make_pair("sub", b));
           concretizedTree.push_back(std::make_pair("pop", "$00"));
           continue;
        }

        // Abstract instruction #2 (Clear +)
        if(a.compare("cla")){
           concretizedTree.push_back(std::make_pair("psh", "$00"));
           concretizedTree.push_back(std::make_pair("add", b));
           concretizedTree.push_back(std::make_pair("pop", "$00"));
           continue;
        }
        // If we don't meet a abstract instruction, then our assumption is false.
        // meaning this node is a concret node, and can be planted into the tree without any changes.
        concretizedTree.push_back(std::make_pair(a,b));
    }
    // The concret and free from abstract tree.
    lexical_tree *concretTree = new lexical_tree(concretizedTree);
    return concretTree;
}