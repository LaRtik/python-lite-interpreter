//
// Created by ilazu on 01.05.2023.
//

#ifndef PYTHON_LITE_2_LEXER_H
#define PYTHON_LITE_2_LEXER_H

#include <string>
#include "Token.h"
#include <vector>

namespace parser {

    class Lexer {
        std::string OPERATOR_CHARS = "+-*/()";
        std::vector <TokenType> OPERATOR_TOKENS {
            TokenType::PLUS,
            TokenType::MINUS,
            TokenType::MUL,
            TokenType::DIV,
            TokenType::LPAREN,
            TokenType::RPAREN,
        };
        std::string input;
        std::vector <Token> tokens;
        int pos = 0;
        int length = 0;


        void addToken(TokenType type) {
            addToken(type, "");
        }

        char peek(int relativePosition) {
            int position = pos + relativePosition;
            if (position >= length) return '\0';
            return input[position];
        }

        char next() {
            pos++;
            return peek(0);
        }

        void addToken(TokenType type, const std::string& text) {
            tokens.emplace_back(type, text);
        }


    public:
        explicit Lexer(const std::string &input) {
            this->input = input;
            this->length = int(input.size());
        }

        void tokenizeNumber() {
            std::string buffer;
            char current = peek(0);
            while (isdigit(current)) {
                buffer += current;
                current = next();
            }
            addToken(TokenType::NUMBER, buffer);
        }

        void tokenizeOperator() {
            int position = OPERATOR_CHARS.find(peek(0));
            addToken(OPERATOR_TOKENS[position]);
            next();
        }

        std::vector <Token> tokenize() {
            while (pos < length){
                char current = peek(0);
                if (std::isdigit(current)) tokenizeNumber();
                else if (OPERATOR_CHARS.find(current) != std::string::npos) tokenizeOperator();
                else next(); // spaces
            }
            return tokens;
        }



    };

} // parser

#endif //PYTHON_LITE_2_LEXER_H
