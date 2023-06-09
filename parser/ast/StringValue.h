//
// Created by ilazu on 01.05.2023.
//

#ifndef PYTHON_LITE_2_STRINGVALUE_H
#define PYTHON_LITE_2_STRINGVALUE_H

#include "Expression.h"
#include <iostream>

namespace parser {

    class StringValue : public Value {
        std::string value;

    public: explicit StringValue(std::string value) {
            this->value = value;
        }

        std::string asString() override {
            return value;
        }

        double asDouble() override {
            try {
                return std::stod(value);
            }
            catch (std::invalid_argument) {
                throw std::runtime_error("Inconsistent types");
            }
        }

        /*Value eval() const override

        friend std::ostream &operator<<(std::ostream &os, const StringValue &expression) {
            os << expression.value;
            return os;
        }*/

        std::string str() const  {
            return value;
        }

        int asInt() override {
            return std::stoi(value);
        }
    };

} // parser

#endif //PYTHON_LITE_2_STRINGVALUE_H
