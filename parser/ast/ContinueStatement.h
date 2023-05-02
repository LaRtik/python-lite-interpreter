//
// Created by ilazu on 02.05.2023.
//

#ifndef PYTHON_LITE_2_CONTINUESTATEMENT_H
#define PYTHON_LITE_2_CONTINUESTATEMENT_H

#include "Statement.h"
#include <iostream>

namespace parser {

class ContinueStatement : public Statement, std::exception{
    void execute() override {
        throw this;
    }

    std::string str(int tabs = 0) override {
        return "[CONTINUE]";
    }


    };

} // parser

#endif //PYTHON_LITE_2_CONTINUESTATEMENT_H
