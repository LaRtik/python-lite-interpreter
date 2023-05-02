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
            else if (elseStatement) elseStatement->execute();
        }

        std::string str(int tab = 0) override {
            std::string res;
            for (int i = 0; i < tab; i++) res += '\t';
            res += "[IF]\n ";
            for (int i = 0; i < tab + 1; i++) res += '\t';
            res += expression->str(tab + 1) + " -> " + ifStatement->str(tab + 1);
            if (elseStatement)
            {
                res += "[ELSE]\n";
                for (int i = 0; i <= tab + 1; i++) res += '\t';
                res += elseStatement->str(tab + 1);
            }
            return res;
        }


    };

} // parser

#endif //PYTHON_LITE_2_IFSTATEMENT_H
