//
// Created by ilazu on 02.05.2023.
//

#ifndef PYTHON_LITE_2_VALUE_H
#define PYTHON_LITE_2_VALUE_H

#include <string>

namespace parser {

    class Value {

    public:
        virtual double asDouble() = 0;

        virtual std::string asString() = 0;
    };

} // parser

#endif //PYTHON_LITE_2_VALUE_H
