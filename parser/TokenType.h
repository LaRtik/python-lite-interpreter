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
        POW,
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
        FORIN,
        WHILE,
        BREAK,
        CONTINUE,
        DEF,
        RETURN,

        LPAREN,
        RPAREN,

        BAR,
        BARBAR,
        AMP,
        AMPAMP,

        EOFF,
        TAB,
        EOL,
        COLON, // :
        LBRACE, // }
        RBRACE, // {
        LBRACKET, // [
        RBRACKET, // ]
        COMMA, // ,
    };

    static std::string str(TokenType type) {
        switch (type) {
            case TokenType::NUMBER:
                return "NUMBER";
                break;
            case TokenType::MUL:
                return "MUL";
                break;
            case TokenType::DIV:
                return "DIV";
                break;
            case TokenType::PLUS:
                return "PLUS";
                break;
            case TokenType::MINUS:
                return "MINUS";
                break;
            case TokenType::EOFF :
                return "EOF";
                break;
            case TokenType::LPAREN:
                return "LPAREN";
                break;
            case TokenType::RPAREN:
                return "RPAREN";
                break;
            case TokenType::WORD:
                return "WORD";
                break;
            case TokenType::ASSIGN:
                return "ASSIGN";
                break;
            case TokenType::PRINT:
                return "PRINT";
                break;
            case TokenType::STR:
                return "STR";
                break;
            case TokenType::EQ:
                return "EQ";
                break;
            case TokenType::GT:
                return "GT";
                break;
            case TokenType::GTEQ:
                return "GTEQ";
                break;
            case TokenType::LT:
                return "LT";
                break;
            case TokenType::LTEQ:
                return "LTEQ";
                break;
            case TokenType::IF:
                return "IF";
                break;
            case TokenType::ELSE:
                return "ELSE";
                break;
            case TokenType::EXCL:
                return "EXCL";
                break;
            case TokenType::EXCLEQ:
                return "EXCLEQ";
                break;
            case TokenType::BAR:
                return "BAR";
                break;
            case TokenType::BARBAR:
                return "BARBAR";
                break;
            case TokenType::AMP:
                return "AMP";
                break;
            case TokenType::AMPAMP:
                return "AMPAMP";
                break;
            case TokenType::TAB:
                return "TAB";
                break;
            case TokenType::EOL:
                return "EOL";
                break;
            case TokenType::COLON:
                return "COLON";
                break;
            case TokenType::LBRACE:
                return "LBRACE";
                break;
            case TokenType::RBRACE:
                return "RBRACE";
                break;
            case TokenType::FOR:
                return "FOR";
                break;
            case TokenType::WHILE:
                return "WHILE";
                break;
            case TokenType::BREAK:
                return "BREAK";
                break;
            case TokenType::CONTINUE:
                return "CONTINUE";
                break;
            case TokenType::COMMA:
                return "COMMA";
                break;
            case TokenType::DEF:
                return "DEF";
                break;
            case TokenType::RETURN:
                return "RETURN";
                break;
            case TokenType::LBRACKET:
                return "LBRACKET";
                break;
            case TokenType::RBRACKET:
                return "RBRACKET";
                break;
            case TokenType::FORIN:
                return "FORIN";
                break;
            case TokenType::POW:
                return "POW";
                break;
        }
        return "";

    }

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
            case TokenType::BREAK:
                os << "BREAK";
                break;
            case TokenType::CONTINUE:
                os << "CONTINUE";
                break;
            case TokenType::COMMA:
                os << "COMMA";
                break;
            case TokenType::DEF:
                os << "DEF";
                break;
            case TokenType::RETURN:
                os << "RETURN";
                break;
            case TokenType::LBRACKET:
                os << "LBRACKET";
                break;
            case TokenType::RBRACKET:
                os << "RBRACKET";
                break;
            case TokenType::FORIN:
                os << "FORIN";
                break;
            case TokenType::POW:
                os << "POW";
                break;
        }
        return os;
    }

} // parser

#endif //PYTHON_LITE_2_TOKENTYPE_H
