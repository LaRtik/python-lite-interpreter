//
// Created by ilazu on 01.05.2023.
//

#ifndef PYTHON_LITE_2_PRINTSTATEMENT_H
#define PYTHON_LITE_2_PRINTSTATEMENT_H
#include "Expression.h"
#include "Statement.h"
#include <iostream>

namespace parser {

    class PrintStatement : public Statement {
        Expression *expression;

    public: PrintStatement(Expression *expression) {
            this->expression = expression;
        }

        void execute() override {
            std::cout << expression->eval()->asString() << std::endl;
        }

        std::string str(int tab = 0) override {
            std::string res = "[PRINT]\n ";
            for (int i = 0; i < tab + 1; i++) res += '\t';
            return res + expression->str(tab + 1);
        }




    };

} // parser

#endif //PYTHON_LITE_2_PRINTSTATEMENT_H
