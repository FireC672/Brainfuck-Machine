#include <iostream>
#include "include/lexer.hpp"
#include "include/parser.hpp"

int main(){
    lexical_tree *t = analyzeSource("clr $01\nsup $2f\n");
    lexical_tree *ct = concretiztaion(t);
    std::string outfuck = alterBrainfuck(ct);
    std::cout << outfuck;
    delete t;
    delete ct;
    return 0;
}