//
// Created by ilazu on 01.05.2023.
//

#ifndef PYTHON_LITE_2_TOKENTYPE_H
#define PYTHON_LITE_2_TOKENTYPE_H

#include <ostream>

namespace parser {

    enum class TokenType {
        // types
        NUMBER,
        WORD,
        STR,

        // keywords
        PRINT,

        MUL,
        DIV,
        PLUS,
        MINUS,

        ASSIGN,

        LPAREN,
        RPAREN,

        EOFF,
    };

    std::ostream &operator<<(std::ostream &os, const TokenType &type) {
        switch (type) {
            case TokenType::NUMBER: os << "NUMBER"; break;

            case TokenType::MUL:
                os << "MUL";
                break;
            case TokenType::DIV:
                os << "DIV";
                break;
            case TokenType::PLUS:
                os << "PLUS";
                break;
            case TokenType::MINUS:
                os << "MINUS";
                break;
            case TokenType::EOFF :
                os << "EOF";
                break;
            case TokenType::LPAREN:
                os << "LPAREN";
                break;
            case TokenType::RPAREN:
                os << "RPAREN";
                break;
            case TokenType::WORD:
                os << "WORD";
                break;
            case TokenType::ASSIGN:
                os << "ASSIGN";
                break;
            case TokenType::PRINT:
                os << "PRINT";
                break;
            case TokenType::STR:
                os << "STR";
                break;
        }
        return os;
    }

} // parser

#endif //PYTHON_LITE_2_TOKENTYPE_H
