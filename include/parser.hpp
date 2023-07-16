#ifndef PARSER_INCLUDED
#define PARSER_INCLUDED

#include "lexer.hpp"
#include <vector>

lexical_tree *concretiztaion(lexical_tree *rawTree);
std::string alterBrainfuck(lexical_tree *concretTree);

#endif