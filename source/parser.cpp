#include "../include/parser.hpp"
#include "../include/lexer.hpp"
#include <vector>
#include <string>

lexical_tree *concretiztaion(lexical_tree *rawTree){
    std::vector< std::pair<std::string, std::string> > concretizedTree; 

    for(auto& abstractNode : rawTree->abstractNodes){
        std::string& a(abstractNode.first);
        std::string& b(abstractNode.second);
        
        // Abstract instruction #1 (Clear -)
        if(a.compare("clr")){
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

        concretizedTree.push_back(std::make_pair(a,b));
    }
}