#include <iostream>
#include "include/lexer.hpp"
#include "include/parser.hpp"

int main(){
    lexical_tree *t = analyzeSource("clr           $ff\n");
    lexical_tree *ct = concretiztaion(t);
    for(auto& node : ct->abstractNodes){
        std::cout << node.first << " | " << node.second << '\n';
    }
    delete t;
    delete ct;
    return 0;
}