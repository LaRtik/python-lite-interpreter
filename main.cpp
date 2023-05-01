#include <iostream>
#include "parser/Lexer.h"
#include "parser/Parser.h"

int main() {
    std::string text = "(2 + 2) * 2";
    std::cout << text << std::endl;
    parser::Lexer lexer = parser::Lexer(text);
    auto tokens = lexer.tokenize();
    for (const auto& token : tokens) std::cout << token << std::endl;

    parser::Parser pars = parser::Parser(tokens);
    auto expressions = pars.parse();
    for (const auto& expr : expressions) std::cout << " " << expr->eval() << std::endl;
    return 0;
}
