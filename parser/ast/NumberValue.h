//
// Created by ilazu on 02.05.2023.
//

#ifndef PYTHON_LITE_2_NUMBERVALUE_H
#define PYTHON_LITE_2_NUMBERVALUE_H

#include "Value.h"
#include <string>

namespace parser {

    class NumberValue : public Value {
        double value = 0;

    public: NumberValue(double value) {
            this->value = value;
        }

        double asDouble() override {
            return value;
        }

        std::string asString() override {
            return std::to_string(value);
        }

    };

} // parser

#endif //PYTHON_LITE_2_NUMBERVALUE_H
