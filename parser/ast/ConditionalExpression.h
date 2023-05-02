//
// Created by ilazu on 01.05.2023.
//

#ifndef PYTHON_LITE_2_CONDITIONALEXPRESSION_H
#define PYTHON_LITE_2_CONDITIONALEXPRESSION_H

#include <ostream>
#include <iostream>
#include <string>
#include "Expression.h"
#include "NumberValue.h"

namespace parser {

    class ConditionalExpression : public Expression {
    public: enum Operator {
            PLUS,
            MINUS,
            MULTIPLY,
            DIVIDE,

            EQUALS,
            NOT_EQUALS,

            LT,
            LTEQ,
            GT,
            GTEQ,

            AND,
            OR,


        };

        Expression* expr1, *expr2;
        Operator operation;


    public: ConditionalExpression(Operator operation, Expression *expr1, Expression *expr2) {
            this->expr1 = expr1;
            this->expr2 = expr2;
            this->operation = operation;
        }

        Value *eval() const override {
            // todo: add string concatenation

            double number1 = expr1->eval()->asDouble();
            double number2 = expr2->eval()->asDouble();
            switch (operation) {
                case EQUALS: return new NumberValue(number1 == number2);
                case NOT_EQUALS: return new NumberValue(number1 != number2);
                case LT: return new NumberValue(number1 < number2);
                case LTEQ: return new NumberValue(number1 <= number2);
                case GT: return new NumberValue(number1 > number2);
                case GTEQ: return new NumberValue(number1 >= number2);
                case AND: return new NumberValue(number1 != 0 && number2 != 0);
                case OR: return new NumberValue(number1 != 0 || number2 != 0);
                default:
                    return new NumberValue(number1 == number2);
            }
        }

        friend std::ostream &operator<<(std::ostream &os, const ConditionalExpression &expression) {
            os << "if condition " + expression.expr1->str() << " else condition" + expression.expr2->str();
            return os;
        }

        std::string str(int tab = 0) const override {
            std::string res = "[CONDITIONAL]\n ";
            for (int i = 0; i < tab + 1; i++) res += '\t';
            return res + expr1->str(tab + 1) + " " + std::to_string(operation) + " " + expr2->str(tab + 1);
        }


    };

} // parser

#endif //PYTHON_LITE_2_CONDITIONALEXPRESSION_H
