#include <iostream>
#include "parser/Lexer.h"
#include "parser/Parser.h"

int main() {
    std::string text = "PI + 3.14 * 2 * 10";
    std::cout << text << std::endl;
    parser::Lexer lexer = parser::Lexer(text);
    auto tokens = lexer.tokenize();
    for (const auto& token : tokens) std::cout << token << std::endl;

    parser::Parser pars = parser::Parser(tokens);
    auto expressions = pars.parse();
    for (auto expr : expressions) std::cout << expr->str() << " " << expr->eval() << std::endl;
    return 0;
}
