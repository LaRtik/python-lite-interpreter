#include <iostream>
#include <fstream>
#include "windows.h"
#include "parser/Lexer.h"
#include "parser/Parser.h"

int main() {
    std::fstream fin("../input.txt");
    std::string text;
    std::string s;
    while (getline(fin, s)) text += s + '\n';
   // std::cout << text << std::endl;
    Sleep(1000);
    parser::Lexer lexer = parser::Lexer(text);
    auto tokens = lexer.tokenize();
   // for (const auto& token : tokens) std::cout << token << std::endl;
   // Sleep(1000);
    lexer.check();
    tokens = lexer.fix_scopes();
   // for (const auto& token : tokens) std::cout << token << std::endl;
   // Sleep(1000);




    parser::Parser pars = parser::Parser(tokens, text);
    auto expressions = pars.parse();
    std::cout << expressions->str() << std::endl;
    expressions->execute();

    return 0;
}
