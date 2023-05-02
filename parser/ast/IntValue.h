//
// Created by ilazu on 01.05.2023.
//

#ifndef PYTHON_LITE_2_INTVALUE_H
#define PYTHON_LITE_2_INTVALUE_H

#include "Expression.h"
#include <iostream>

namespace parser {

    class IntValue : public Value {
        int value;

    public: explicit IntValue(int value) {
            this->value = value;
        }

        std::string asString() override {
            return std::to_string(value);
        }

        double asDouble() override {
            return double(value);
        }

        /*Value eval() const override

        friend std::ostream &operator<<(std::ostream &os, const StringValue &expression) {
            os << expression.value;
            return os;
        }*/

        std::string str() const  {
            return std::to_string(value);
        }

        int asInt() override {
            return value;
        }
    };

} // parser

#endif //PYTHON_LITE_2_INTVALUE_H
