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
        std::string OPERATOR_CHARS = "+-*/()=";
        std::vector <TokenType> OPERATOR_TOKENS {
            TokenType::PLUS,
            TokenType::MINUS,
            TokenType::MUL,
            TokenType::DIV,
            TokenType::LPAREN,
            TokenType::RPAREN,
            TokenType::ASSIGN,
        };
        std::string input;
        std::vector <Token> tokens;
        int pos = 0;
        int length = 0;

    public: void error(const std::string& text) const {
            for (int i = 0; i < pos; i++) std::cout << " ";
            std::cout << "^" << std::endl;
            throw std::runtime_error(text + " at pos " + std::to_string(pos));
        }


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
            while (true) {
                if (current == '.') {
                    if (buffer.find('.') != std::string::npos) error("Invalid float number");
                }
                else if (!std::isdigit(current)) break;
                buffer += current;
                current = next();
            }
            addToken(TokenType::NUMBER, buffer);
        }

        void tokenizeWord() {
            std::string buffer;
            char current = peek(0);
            while (true) {
                if (!std::isalpha(current) && !std::isdigit(current) && current != '_') break;
                buffer += current;
                current = next();
            }
            if (buffer == "print") addToken(TokenType::PRINT);
            else addToken(TokenType::WORD, buffer);
        }

        void tokenizeString() {
            std::string buffer;
            next();
            char current = peek(0);
            while (true) {
                if (current == '\\') {
                    current = next();
                    switch (current) {
                        case '"': current = next(); buffer += '"'; break;
                        case 'n': current = next(); buffer += '\n'; break;
                        case 't': current = next(); buffer += '\t'; break;
                    }
                    buffer += '\\';
                    continue;
                }
                if (current == '"') break;
                buffer += current;
                current = next();
            }
            next();
            addToken(TokenType::STR, buffer);
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
                else if (std::isalpha(current)) tokenizeWord();
                else if (OPERATOR_CHARS.find(current) != std::string::npos) tokenizeOperator();
                else if (current == '"') tokenizeString();
                else next(); // spaces
            }
            return tokens;
        }



    };

} // parser

#endif //PYTHON_LITE_2_LEXER_H
