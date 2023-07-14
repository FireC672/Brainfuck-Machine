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

lexical_node *analyzeSource(const char *source){
    std::vector<std::string> analyzed; 
    while( *source ){
        source++;
    }
}