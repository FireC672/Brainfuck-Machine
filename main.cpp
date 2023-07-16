#include <iostream>
#include "include/lexer.hpp"

int main(){
    lexical_tree *t = analyzeSource("mov           $ff\n");
    for(auto& node : t->abstractNodes){
        std::cout << node.first << " | " << node.second << '\n';
    }
    delete t;
    return 0;
}