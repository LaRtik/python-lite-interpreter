//
// Created by ilazu on 02.05.2023.
//

#ifndef PYTHON_LITE_2_BREAKSTATEMENT_H
#define PYTHON_LITE_2_BREAKSTATEMENT_H
#include "Statement.h"
#include <iostream>

namespace parser {

class BreakStatement : public Statement, std::exception {
        void execute() override {
            throw this;
        }

        std::string str(int tab = 0) override {
            return "[BREAK]";
        }


    };

} // parser

#endif //PYTHON_LITE_2_BREAKSTATEMENT_H
