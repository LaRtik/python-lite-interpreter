//
// Created by ilazu on 02.05.2023.
//

#ifndef PYTHON_LITE_2_RETURNSTATEMENT_H
#define PYTHON_LITE_2_RETURNSTATEMENT_H

#include "Statement.h"
#include "Expression.h"
#include "Value.h"
#include <iostream>

namespace parser {

class ReturnStatement : public Statement, std::exception {
    Expression *expression;

public: explicit ReturnStatement(Expression *expression) {
        this->expression = expression;
    }


        void execute() override {
            result = expression->eval();
            throw this;
        }

        std::string str(int tabs = 0) override {
            return "[RETURN] " + expression->str(tabs);
        }

    Value* result{};
};

} // parser

#endif //PYTHON_LITE_2_RETURNSTATEMENT_H
