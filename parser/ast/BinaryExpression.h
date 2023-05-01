//
// Created by ilazu on 01.05.2023.
//

#ifndef PYTHON_LITE_2_BINARYEXPRESSION_H
#define PYTHON_LITE_2_BINARYEXPRESSION_H

#include <ostream>
#include "Expression.h"

namespace parser {

    class BinaryExpression : public Expression {
        Expression* expr1, *expr2;
        char operation;

    public: BinaryExpression(char operation, Expression *expr1, Expression *expr2) {
            this->expr1 = expr1;
            this->expr2 = expr2;
            this->operation = operation;
        }

        double eval() const override {
            switch (operation) {
                case '-': return expr1->eval() - expr2->eval();
                case '*': return expr1->eval() * expr2->eval();
                case '/': return expr1->eval() / expr2->eval();
                default:
                    return expr1->eval() + expr2->eval();
            }
        }

        friend std::ostream &operator<<(std::ostream &os, const BinaryExpression &expression) {
            os << "BinaryExpression -> " << " expr1: " << expression.expr1->eval() << " expr2: "
               << expression.expr2->eval() << " operation: " << expression.operation;
            return os;
        }


    };

} // parser

#endif //PYTHON_LITE_2_BINARYEXPRESSION_H
