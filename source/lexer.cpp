#include "../include/lexer.hpp"
#include <vector>
#include <string>
#include <cctype>
#include <cmath>

/// @brief Turns the abstract argument element to a number.
/// @param arg The argument to parse and analyze.
/// @return The argument into a B16 to B10 number.
int parseArgument(const char *arg){
    // Calculate the length of 'arg', substracted by one.
    // for B16 to B10 conversion reasons, we will see next.
    int j = strlen(arg)-2;
    // The total is kept in memory in this variable.
    int total = 0; 
    // Go to the nearest '$' dollar to find the argument symbol.
    while( *arg && *arg != '$' )
          // While going to each character, deincrementing 'j'.
          arg++,j--;
    // Skip the dollar sign, to the nearest digit.
    arg++; 
    // Go through each character in the string, until a line feed of null terminator.
    while( *arg && *arg != '\n' ){
        // If the character is not a digit or a character, then ignore it.
        if(!isalnum(*arg) && (*arg >= 'a' || *arg <= 'f') && (*arg >= 'A' || *arg <= 'F'))break; 
        // If the character is a digit, then change behaviour of conversion.
        if(isdigit(*arg)){
            // The behaviour is: 
            // 1. Convert the character into a number.
            // 2. Multiply it by 16^j
            // 3. Decrement 'j'.
            total += (*arg-'0') * static_cast<int>(pow(16,j));
            j--;
        }else{
            // The behaviour is: 
            // 1. Determine if the character is lower or upper.
            // 2. Convert the character into a number.
            // 3. Multiply it by 16^j.
            // 4. Decrement 'j'.
            total += (*arg - (isupper(*arg)?'A':'a')+10) * static_cast<int>(pow(16,j));
            j--;
        }
        // Skip to the next character.
        arg++;
    }
    // Return the total.
    return total;
}

/// @brief This function examines the 'source' and parses everything into a tree's node.
/// @param source The source to examine and analyze.
/// @return The abstract syntax tree with abstract opcodes and operands.
lexical_tree *analyzeSource(const char *source){
    // Initialize the vector containing the elements of the abstract tree nodes.
    std::vector< std::pair<std::string, std::string> > analyzed; 
    // While we don't reach the end of the 'source', then we procedure with...
    while( *source ){
        // Storing the abstract opcode in this string 'stAbstractArg',
        // and storing the abstract string argument in the string 'stAbstractArg'.
        std::string stAbstractOpcode;
        std::string stAbstractArg;
        // While we don't reach a blank space. then treat anything that comes after as opcode.
        while ( *source != ' ' && *source ){
            // If we reach a null terminator, then break.
            if( *source == '\0' || *source == ' ' )break;
            // Push every character in this loop as a abstract opcode's element.
            stAbstractOpcode.push_back(*source);
            source++;
        }
        source++;
        // Then, while we don't reach a line feed or a null terminator.
        while( *source != '\n' && *source ){
            if( !(*source) || *source == '\n')break; 
            // then treat everything after as an abstract argument.
            stAbstractArg.push_back(*source);
            source++;
        }
        // Then, push the pair.
        analyzed.push_back(std::make_pair(stAbstractOpcode, stAbstractArg));
        source++;
    }
    // Parse it as an abstract syntax tree.
    lexical_tree *abstractTree = new lexical_tree(analyzed);
    return abstractTree;
}