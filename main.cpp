#include <iostream>
#include <fstream>
#include "parser/Lexer.h"
#include "parser/Parser.h"

int main() {
    std::fstream fin("../input.txt");
    std::string text;
    std::string s;
    while (getline(fin, s)) text += s + '\n';
    std::cout << text << std::endl;
    parser::Lexer lexer = parser::Lexer(text);
    auto tokens = lexer.tokenize();
    tokens = lexer.fix_scopes();
   // for (const auto& token : tokens) std::cout << token << std::endl;


    parser::Parser pars = parser::Parser(tokens);
    auto expressions = pars.parse();
    std::cout << expressions->str() << std::endl;
    expressions->execute();

    return 0;
}
