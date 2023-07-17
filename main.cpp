#include <iostream>
#include "include/lexer.hpp"
#include "include/parser.hpp"

// +.[+.]
int main(){
    lexical_tree *t = analyzeSource("sup $01a\nout $01\npsh\nsup $01\nout $01\npop\n");
    lexical_tree *ct = concretiztaion(t);
    std::string outfuck = alterBrainfuck(ct);
    std::cout << outfuck;
    delete t;
    delete ct;
    return 0;
}