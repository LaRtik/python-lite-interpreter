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
            double result = expression->eval();
            Variables::set(variable, result);
        }

        std::string str() override {
            return variable + expression->str();
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
