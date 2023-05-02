//
// Created by ilazu on 02.05.2023.
//

#ifndef PYTHON_LITE_2_FUNCTIONSTATEMENT_H
#define PYTHON_LITE_2_FUNCTIONSTATEMENT_H
#include "Statement.h"
#include "FunctionalExpression.h"

namespace parser {

    class FunctionStatement: public Statement{
        FunctionalExpression *function;
    public: explicit FunctionStatement(FunctionalExpression *function) {
            this->function = function;
        }

        void execute() override {
            function->eval();
        }

        std::string str(int tabs = 0) override {
            return function->str(tabs);
        }

    };

} // parser

#endif //PYTHON_LITE_2_FUNCTIONSTATEMENT_H
