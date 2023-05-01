//
// Created by ilazu on 01.05.2023.
//

#ifndef PYTHON_LITE_2_TOKEN_H
#define PYTHON_LITE_2_TOKEN_H

#include <iostream>
#include "TokenType.h"

namespace parser {

    class Token {
        TokenType type;
    public:
        TokenType getType() const {
            return type;
        }

        void setType(TokenType type) {
            Token::type = type;
        }

        const std::string &getText() const {
            return text;
        }

        void setText(const std::string &text) {
            Token::text = text;
        }

    private:
        std::string text;


    public:
        Token(TokenType type, const std::string &text) : type(type), text(text) {}

        Token() {}

        friend std::ostream &operator<<(std::ostream &os, const Token &token) {
            os << token.type << " " << token.text;
            return os;
        }

    };


} // parser

#endif //PYTHON_LITE_2_TOKEN_H
