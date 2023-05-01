//
// Created by ilazu on 01.05.2023.
//

#ifndef PYTHON_LITE_2_UNARYEXPRESSION_H
#define PYTHON_LITE_2_UNARYEXPRESSION_H

#include "Expression.h"

namespace parser {

    class UnaryExpression : public Expression {
        Expression *expr1;
        char operation;

    public: UnaryExpression(char operation, Expression *expr1) {
            this->expr1 = expr1;
            this->operation = operation;
        }

        double eval() const override {
            switch (operation) {
                case '-': return -expr1->eval();
                default:
                    return expr1->eval();
            }
        }






    };

} // parser

#endif //PYTHON_LITE_2_UNARYEXPRESSION_H
