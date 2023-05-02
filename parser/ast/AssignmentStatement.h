//
// Created by ilazu on 01.05.2023.
//

#ifndef PYTHON_LITE_2_ASSIGNMENTSTATEMENT_H
#define PYTHON_LITE_2_ASSIGNMENTSTATEMENT_H

#include "Statement.h"
#include <iostream>
#include <utility>
#include "ConstantExpression.h"

namespace parser {

    class AssignmentStatement : public Statement {

        std::string variable;
        Expression *expression;

        void execute() override {
            Value *result = expression->eval();
            Variables::set(variable, result);
        }

        std::string str(int tab = 0) override {
            std::string res;
            for (int i = 0; i < tab; i++) res += '\t';
            res += "[ASSIGNMENT]\n ";
            for (int i = 0; i < tab + 1; i++) res += '\t';
            return res + variable + " = [" + expression->str(tab + 1) + "]";
        }

    public:
        AssignmentStatement (std::string variable, Expression *expression)
        {
            this->variable = std::move(variable);
            this->expression = expression;
        }
    };

} // parser

#endif //PYTHON_LITE_2_ASSIGNMENTSTATEMENT_H
