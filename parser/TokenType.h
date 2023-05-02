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

        EQ,
        GT,
        GTEQ,
        LT,
        LTEQ,
        EXCL,
        EXCLEQ,
        IF,
        ELSE,
        FOR,
        WHILE,

        LPAREN,
        RPAREN,

        BAR,
        BARBAR,
        AMP,
        AMPAMP,

        EOFF,
        TAB,
        EOL,
        COLON,
        LBRACE,
        RBRACE,
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
            case TokenType::EQ:
                os << "EQ";
                break;
            case TokenType::GT:
                os << "GT";
                break;
            case TokenType::GTEQ:
                os << "GTEQ";
                break;
            case TokenType::LT:
                os << "LT";
                break;
            case TokenType::LTEQ:
                os << "LTEQ";
                break;
            case TokenType::IF:
                os << "IF";
                break;
            case TokenType::ELSE:
                os << "ELSE";
                break;
            case TokenType::EXCL:
                os << "EXCL";
                break;
            case TokenType::EXCLEQ:
                os << "EXCLEQ";
                break;
            case TokenType::BAR:
                os << "BAR";
                break;
            case TokenType::BARBAR:
                os << "BARBAR";
                break;
            case TokenType::AMP:
                os << "AMP";
                break;
            case TokenType::AMPAMP:
                os << "AMPAMP";
                break;
            case TokenType::TAB:
                os << "TAB";
                break;
            case TokenType::EOL:
                os << "EOL";
                break;
            case TokenType::COLON:
                os << "COLON";
                break;
            case TokenType::LBRACE:
                os << "LBRACE";
                break;
            case TokenType::RBRACE:
                os << "RBRACE";
                break;
            case TokenType::FOR:
                os << "FOR";
                break;
            case TokenType::WHILE:
                os << "WHILE";
                break;
        }
        return os;
    }

} // parser

#endif //PYTHON_LITE_2_TOKENTYPE_H
