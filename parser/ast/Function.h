//
// Created by ilazu on 02.05.2023.
//

#ifndef PYTHON_LITE_2_FUNCTION_H
#define PYTHON_LITE_2_FUNCTION_H
#include "Value.h"
#include <vector>

namespace parser {

    class Function {
    public:
        virtual Value* execute(std::vector <Value*> args) = 0;
        virtual std::string str(int tabs = 0) = 0;
    };

} // parser

#endif //PYTHON_LITE_2_FUNCTION_H
