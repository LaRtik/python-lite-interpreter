//
// Created by ilazu on 01.05.2023.
//

#ifndef PYTHON_LITE_2_CONDITIONALEXPRESSION_H
#define PYTHON_LITE_2_CONDITIONALEXPRESSION_H

#include <ostream>
#include <string>
#include "Expression.h"
#include "NumberValue.h"

namespace parser {

    class ConditionalExpression : public Expression {
        Expression* expr1, *expr2;
        char operation;

    public: ConditionalExpression(char operation, Expression *expr1, Expression *expr2) {
            this->expr1 = expr1;
            this->expr2 = expr2;
            this->operation = operation;
        }

        Value *eval() const override {
            // todo: add string concatenation

            double number1 = expr1->eval()->asDouble();
            double number2 = expr2->eval()->asDouble();
            switch (operation) {
                case '=': return new NumberValue(number1 == number2);
                case '<': return new NumberValue(number1 < number2);
                case '>': return new NumberValue(number1 > number2);
                default:
                    return new NumberValue(number1 == number2);
            }
        }

        friend std::ostream &operator<<(std::ostream &os, const ConditionalExpression &expression) {
            os << "if condition " + expression.expr1->str() << " else condition" + expression.expr2->str();
            return os;
        }

        std::string str() const override {
            return expr1->str() + " " + operation + " " + expr2->str();
        }


    };

} // parser

#endif //PYTHON_LITE_2_CONDITIONALEXPRESSION_H
