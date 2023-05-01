//
// Created by ilazu on 01.05.2023.
//

#ifndef PYTHON_LITE_2_NUMBEREXPRESSION_H
#define PYTHON_LITE_2_NUMBEREXPRESSION_H

#include "Expression.h"

namespace parser {

    class NumberExpression : public Expression {
        double value = 0;

    public: NumberExpression(double value) {
            this->value = value;
        }

        double eval() const override {
            return value;
        }

        friend std::ostream &operator<<(std::ostream &os, const NumberExpression &expression) {
            os << expression.value;
            return os;
        }

        std::string str() const override {
            return std::to_string(value);
        }
    };

} // parser

#endif //PYTHON_LITE_2_NUMBEREXPRESSION_H
