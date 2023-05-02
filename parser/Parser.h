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
#include "ast/BlockStatement.h"
#include "ast/WhileStatement.h"
#include "ast/FunctionalExpression.h"
#include "ast/FunctionStatement.h"

namespace parser {

    class Parser {

        std::vector <Token> tokens;
        Token eof = Token(TokenType::EOFF, "");
        int pos = 0;
        int size = 0;
        int indent = 0;
        std::vector <std::string> text;
        int current_line = 0;

        // START PARSING EXPRESSIONS ******

        FunctionalExpression *function () {
            std::string name = consume(TokenType::WORD).getText();
            consume(TokenType::LPAREN);
            auto *function = new FunctionalExpression(name);
            while (!match(TokenType::RPAREN)) {
                function->addArgument(expression());
                match(TokenType::COMMA);
            }
            return function;
        }

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
            if (current.getType() == TokenType::WORD && get(1).getType() == TokenType::LPAREN){
                return function();
            }
            if (match(TokenType::WORD))
            {
                return new ConstantExpression(current.getText());
            }

            switch (get(-1).getType()) {
                case TokenType::IF:
                    std::cout << text[current_line] << std::endl;
                    std::cout << "Expected STATEMENT after " << get(-1).getType() << " at pos " << pos << std::endl;
                    throw std::runtime_error("Unknown expression");
                case TokenType::WHILE:
                    std::cout << text[current_line] << std::endl;
                    std::cout << "Expected STATEMENT after " << get(-1).getType() << " at pos " << pos << std::endl;
                    throw std::runtime_error("Unknown expression");
            }
            std::cout << text[current_line] << std::endl;
            std::cout << "Unknown expression after " << get(-1).getType() << " at pos " << pos << std::endl;
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

        Statement *block() {
            BlockStatement *block = new BlockStatement();
            consume(TokenType::LBRACE);
            while (!match(TokenType::RBRACE)) {
                block->add(statement());
            }
            return block;

        }

        Statement *statement() {
          //  if (match(TokenType::PRINT)) return new PrintStatement(expression());
            if (get(0).getType() == TokenType::WORD && get(1).getType() == TokenType::LPAREN)
                return new FunctionStatement(function());
            if (match(TokenType::IF)) return ifElse();
            if (match(TokenType::WHILE)) return whileStatement();
            if (match(TokenType::BREAK)) return new BreakStatement();
            if (match(TokenType::CONTINUE)) return new ContinueStatement();
            if (match(TokenType::TAB)) { indent++; return statement();}
            if (match(TokenType::EOL)) { indent = 0; return statement();}
            return assignmentStatement();
        }

        Statement *assignmentStatement() {
            // WORD = EXPRESSION
            Token current = get(0);
            if (match(TokenType::WORD) && get(0).getType() == TokenType::ASSIGN) {
                const std::string& variable = current.getText();
                consume(TokenType::ASSIGN);
                return new AssignmentStatement(variable, expression());
            }
            switch (tokens[pos].getType()) {
                case TokenType::LBRACE:
                    std::cout << text[current_line] << std::endl;
                    throw std::runtime_error("Unknown indentation at line " + std::to_string(current_line + 1));
                case TokenType::LPAREN:
                    std::cout << text[current_line - 1] << std::endl;
                    throw std::runtime_error("Inconsistent braces at line " + std::to_string(current_line));
                case TokenType::RPAREN:
                    std::cout << text[current_line - 1] << std::endl;
                    throw std::runtime_error("Inconsistent braces at line " + std::to_string(current_line));
            }
            std::cout << tokens[pos].getType() << std::endl;
            throw std::runtime_error("Unknown statement ");
        }

        Statement *whileStatement() {
            // WHILE STATEMENT { BLOCK }
            Expression *condition = expression();
            Statement *statement = block();
            return new WhileStatement(condition, statement);
        }

        Statement *ifElse() {
            // IF CONDITION {BLOCK} ELSE {BLOCK}
            Expression *condition = expression();
            Statement *ifStatement = block();
            Statement *elseStatement = nullptr;
            if (match(TokenType::ELSE)) elseStatement = block();
            return new IfStatement(condition, ifStatement, elseStatement);
        }

        // END PARSING STATEMENTS *****


    public:
        Statement *parse() {
            BlockStatement *result = new BlockStatement();
            while (!match(TokenType::EOFF)) {
                result->add(statement());
                current_line++;
            }
            return result;
        }

        Parser(std::vector <Token> tokens, std::string text) {
            this->tokens = tokens;
            size = tokens.size();
            std::string buffer;
            for (auto c : text) {
                if (c == '\n') {
                    this->text.push_back(buffer);
                    buffer = "";
                }
                else buffer += c;
            }
        }
    };

} // parser

#endif //PYTHON_LITE_2_PARSER_H
