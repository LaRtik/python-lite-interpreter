//
// Created by ilazu on 01.05.2023.
//

#ifndef PYTHON_LITE_2_BINARYEXPRESSION_H
#define PYTHON_LITE_2_BINARYEXPRESSION_H

#include <ostream>
#include <string>
#include "Expression.h"
#include "NumberValue.h"

namespace parser {

    class BinaryExpression : public Expression {
        Expression* expr1, *expr2;
        char operation;

    public: BinaryExpression(char operation, Expression *expr1, Expression *expr2) {
            this->expr1 = expr1;
            this->expr2 = expr2;
            this->operation = operation;
        }

        Value *eval() const override {
            // todo: add string concatenation

            double number1 = expr1->eval()->asDouble();
            double number2 = expr2->eval()->asDouble();
            switch (operation) {
                case '-': return new NumberValue(number1 - number2);
                case '*': return new NumberValue(number1 * number2);
                case '/': return new NumberValue(number1 / number2);
                default:
                    return new NumberValue(number1 + number2);
            }
        }

        friend std::ostream &operator<<(std::ostream &os, const BinaryExpression &expression) {
            os << "BinaryExpression -> " << " expr1: " << expression.expr1->eval() << " expr2: "
               << expression.expr2->eval() << " operation: " << expression.operation;
            return os;
        }

        std::string str(int tab = 0) const override {
            std::string res;
            res += "[BINARYEXPR]\n ";
            for (int i = 0; i < tab + 1; i++) res += '\t';
            return res + "[" + expr1->str(tab + 1) + "] " + operation + " [" + expr2->str(tab + 1) + "]";
        }


    };

} // parser

#endif //PYTHON_LITE_2_BINARYEXPRESSION_H
