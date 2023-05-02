//
// Created by ilazu on 01.05.2023.
//

#ifndef PYTHON_LITE_2_LEXER_H
#define PYTHON_LITE_2_LEXER_H

#include <string>
#include "Token.h"
#include <vector>
#include <map>

namespace parser {

    class Lexer {
        std::string OPERATOR_CHARS = "+-*/()=<>!&|{},";
        std::map <std::string, TokenType> OPERATORS {
                {"+", TokenType::PLUS},
                {"-", TokenType::MINUS},
                {"*", TokenType::MUL},
                {"/", TokenType::DIV},
                {"(", TokenType::LPAREN},
                {")", TokenType::RPAREN},
                {"=", TokenType::ASSIGN},
                {"==", TokenType::EQ},
                {"<", TokenType::LT},
                {"<=", TokenType::LTEQ},
                {">", TokenType::GT},
                {">=", TokenType::GTEQ},
                {"!", TokenType::EXCL},
                {"!=", TokenType::EXCLEQ},
                {"&", TokenType::AMP},
                {"&&", TokenType::AMPAMP},
                {"|", TokenType::BAR},
                {"||", TokenType::BARBAR},
                {"{", TokenType::LBRACE},
                {"}", TokenType::RBRACE},
                {",", TokenType::COMMA},
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

    public: std::vector <Token> fix_scopes() {
            std::vector <Token> new_tokens;
            int last_indent = 0;
            int indent = 0;
            for (int i = 0; i < this->tokens.size(); i++) {
                if (this->tokens[i].getType() == TokenType::EOL) {
                    last_indent = indent;
                    indent = 0;
                    i++;

                    while (i < this->tokens.size() && this->tokens[i].getType() == TokenType::TAB) {
                        indent++;
                        i++;
                    }
                    if (indent > last_indent)
                    {
                        for (int j = 0; j < indent - last_indent; j++) new_tokens.emplace_back(TokenType::LBRACE, "");
                    }
                    else if (indent < last_indent) {
                        for (int j = 0; j < last_indent - indent; j++) new_tokens.emplace_back(TokenType::RBRACE, "");
                    }
                    if (i < this->tokens.size() && tokens[i].getType() != TokenType::COLON) new_tokens.push_back(tokens[i]);
                }
                else if (tokens[i].getType() != TokenType::COLON) new_tokens.push_back(tokens[i]);
            }
            this->tokens = new_tokens;
            return tokens;
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
            //if (buffer == "print") addToken(TokenType::PRINT);
            if (buffer == "if") addToken(TokenType::IF);
            else if (buffer == "else") addToken(TokenType::ELSE);
            else if (buffer == "for") addToken(TokenType::FOR);
            else if (buffer == "def") addToken(TokenType::DEF);
            else if (buffer == "while") addToken(TokenType::WHILE);
            else if (buffer == "break") addToken(TokenType::BREAK);
            else if (buffer == "return") addToken(TokenType::RETURN);
            else if (buffer == "continue") addToken(TokenType::CONTINUE);
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
            char current = peek(0);
            std::string buffer;
            while (true) {
                if (!buffer.empty() && OPERATORS.find(buffer + current) == OPERATORS.end()){
                    addToken(OPERATORS[buffer]);
                    return;
                }
                buffer += current;
                current = next();
            }
        }

        bool lookMatch(TokenType need, TokenType block) {
            int i = pos;
            while (i < tokens.size()) {
                if (tokens[i].getType() == need) return true;
                if (tokens[i].getType() == block) return false;
                i++;
            }
            return false;
        }

        void check() {
            while (pos < tokens.size()) {
                // CHECK COMMA BEFORE IF ELSE WHILE FOR
                TokenType type = tokens[pos].getType();
                if (type == TokenType::IF || type == TokenType::ELSE || type == TokenType::WHILE || type == TokenType::FOR) {
                    if (!lookMatch(TokenType::COLON, TokenType::LBRACE)) error("Expected colon after STATEMENT");
                }
                pos++;
            }
        }


        std::vector <Token> tokenize() {
            while (pos < length){
                char current = peek(0);
                if (current == '\n') { addToken(TokenType::EOL); pos++;
                    continue;}
                else if (current == '\t') { addToken(TokenType::TAB); pos++;
                    continue; }
                else if (current == ':') { addToken(TokenType::COLON); pos++;
                    continue; }
                else if (std::isdigit(current)) tokenizeNumber();
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
