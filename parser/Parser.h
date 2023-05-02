//
// Created by ilazu on 01.05.2023.
//

#ifndef PYTHON_LITE_2_PARSER_H
#define PYTHON_LITE_2_PARSER_H
#include <iostream>
#include <vector>
#include "Token.h"
#include "ast/Expression.h"
#include "ast/StringValue.h"
#include "ast/BinaryExpression.h"
#include "ast/UnaryExpression.h"
#include "ast/ConstantExpression.h"
#include "ast/Statement.h"
#include "ast/AssignmentStatement.h"
#include "ast/PrintStatement.h"
#include "ast/ValueExpression.h"
#include "ast/ConstantExpression.h"
#include "ast/ConditionalExpression.h"
#include "ast/IfStatement.h"

namespace parser {

    class Parser {

        std::vector <Token> tokens;
        Token eof = Token(TokenType::EOFF, "");
        int pos = 0;
        int size = 0;

        // START PARSING EXPRESSIONS ******

        Expression * expression() {
            return logical();
        }

        Expression *logical() {
            Expression *result = equality();
            while (true) {
                if (match(TokenType::BARBAR)) {
                    result = new ConditionalExpression(ConditionalExpression::Operator::OR, result, equality());
                    continue;
                }
                if (match(TokenType::AMPAMP)) {
                    result = new ConditionalExpression(ConditionalExpression::Operator::AND, result, equality());
                    continue;
                }
                break;
            }
            return result;
        }

        Expression *equality() {
            Expression *result = conditional();
            if (match(TokenType::EQ)) return new ConditionalExpression(ConditionalExpression::Operator::EQUALS, result, conditional());
            if (match(TokenType::EXCLEQ)) return new ConditionalExpression(ConditionalExpression::Operator::NOT_EQUALS, result, conditional());
            return result;
        }

        Expression *conditional() {
            Expression *result = additive();

            while (true) {
                if (match(TokenType::LT)) {
                    auto *expr = new ConditionalExpression(ConditionalExpression::Operator::LT, result, additive());
                    result = expr;
                    continue;
                }
                if (match(TokenType::LTEQ)) {
                    auto *expr = new ConditionalExpression(ConditionalExpression::Operator::LTEQ, result, additive());
                    result = expr;
                    continue;
                }
                if (match(TokenType::GT)) {
                    auto *expr = new ConditionalExpression(ConditionalExpression::Operator::GT, result, additive());
                    result = expr;
                    continue;
                }
                if (match(TokenType::GTEQ)) {
                    auto *expr = new ConditionalExpression(ConditionalExpression::Operator::GTEQ, result, additive());
                    result = expr;
                    continue;
                }
                break;
            }

            return result;
        }


        Expression * additive() {
            Expression *result = multiplicative();

            while (true) {
                if (match(TokenType::PLUS)) {
                    BinaryExpression *expr = new BinaryExpression('+', result, multiplicative());
                    result = expr;
                    continue;
                }
                if (match(TokenType::MINUS)) {
                    BinaryExpression *expr = new BinaryExpression('-', result, multiplicative());
                    result = expr;
                    continue;
                }
                break;
            }

            return result;
        }


        Expression * multiplicative() {
            Expression *result = unary();

            while (true) {
                if (match(TokenType::MUL)) {
                    BinaryExpression *expr = new BinaryExpression('*', result, unary());
                    result = expr;
                    continue;
                }
                if (match(TokenType::DIV)) {
                    BinaryExpression *expr = new BinaryExpression('/', result, unary());
                    result = expr;
                    continue;
                }
                break;
            }

            return result;
        }


        Expression *unary() {
            if (match(TokenType::MINUS)) {
                return new UnaryExpression('-', primary());
            }
            return primary();
        }

        Expression *primary() {
            Token current = get(0);
            if (match(TokenType::NUMBER))
            {
                return new ValueExpression(std::stod(current.getText()));
            }
            if (match(TokenType::LPAREN))
            {
                Expression *result = expression();
                match(TokenType::RPAREN);
                return result;
            }
            if (match(TokenType::STR))
            {
                return new ValueExpression(current.getText());
            }
            if (match(TokenType::WORD))
            {
                return new ConstantExpression(current.getText());
            }
            std::cout << "Unknown expression at pos " << pos << std::endl;
            throw std::runtime_error("Unknown expression");
        }

        // END PARSING EXPRESSIONS ********


        bool match(TokenType type) {
            Token current = get(0);
            if (type != current.getType()) return false;
            pos++;
            return true;
        }

        Token get(int relativePosition) {
            int position = pos + relativePosition;
            if (position >= size) return eof;
            return tokens[position];
        }

        Token consume(TokenType type) {
            Token current = get(0);
            if (type != current.getType())
                throw std::runtime_error("Token " + current.getText() + " does not match token type");
            pos++;
            return current;
        }


        // PARSING STATEMENTS *****

        Statement *statement() {
            if (match(TokenType::PRINT)) return new PrintStatement(expression());
            if (match(TokenType::IF)) return ifElse();
            return assignmentStatement();
        }

        Statement *assignmentStatement() {
            // WORD ASSIGN
            Token current = get(0);
            if (match(TokenType::WORD) && get(0).getType() == TokenType::ASSIGN) {
                const std::string& variable = current.getText();
                consume(TokenType::ASSIGN);
                return new AssignmentStatement(variable, expression());
            }
            throw std::runtime_error("Unknown statement");
        }

        Statement *ifElse() {
            // IF STATEMENT ELSE STATEMENT
            Expression *condition = expression();
            Statement *ifStatement = statement();
            Statement *elseStatement = nullptr;
            if (match(TokenType::ELSE)) elseStatement = statement();
            return new IfStatement(condition, ifStatement, elseStatement);
        }

        // END PARSING STATEMENTS *****


    public:
        std::vector <Statement*> parse() {
            std::vector <Statement*> result;
            while (!match(TokenType::EOFF)) {
                result.push_back(statement());
            }
            return result;
        }

        Parser(std::vector <Token> tokens) {
            this->tokens = tokens;
            size = tokens.size();
        }
    };

} // parser

#endif //PYTHON_LITE_2_PARSER_H
