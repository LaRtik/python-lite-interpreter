//
// Created by ilazu on 02.05.2023.
//

#ifndef PYTHON_LITE_2_IFSTATEMENT_H
#define PYTHON_LITE_2_IFSTATEMENT_H

#include "Statement.h"
#include "Expression.h"

namespace parser {

    class IfStatement : public Statement {
        Expression *expression;
        Statement *ifStatement, *elseStatement;

    public: IfStatement(Expression *expression, Statement *ifStatement, Statement *elseStatement) {
            this->expression = expression;
            this->ifStatement = ifStatement;
            this->elseStatement = elseStatement;
        }

        void execute() override {
            double result = expression->eval()->asDouble();
            if (result != 0) ifStatement->execute();
            else elseStatement->execute();
        }

        std::string str() override {
            std::string res = "if " + expression->str() + " -> " + ifStatement->str();
            if (elseStatement) res += "\nelse -> " + elseStatement->str();
            return res;
        }


    };

} // parser

#endif //PYTHON_LITE_2_IFSTATEMENT_H
