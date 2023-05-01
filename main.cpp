#include <iostream>
#include "parser/Lexer.h"
#include "parser/Parser.h"

int main() {
    std::string text = "word = PI + 3.14 * 2\nword2 = PI * word";
    std::cout << text << std::endl;
    parser::Lexer lexer = parser::Lexer(text);
    auto tokens = lexer.tokenize();
    for (const auto& token : tokens) std::cout << token << std::endl;

    parser::Parser pars = parser::Parser(tokens);
    auto expressions = pars.parse();
    for (auto statement : expressions)
    {
        std::cout << statement->str() << std::endl;
        statement->execute();
    }

    return 0;
}
