//
// Created by ilazu on 02.05.2023.
//

#ifndef PYTHON_LITE_2_WHILESTATEMENT_H
#define PYTHON_LITE_2_WHILESTATEMENT_H
#include "Statement.h"
#include "Expression.h"

namespace parser {

    class WhileStatement : public Statement{
        Expression *condition;
        Statement *statement;

        void execute() override {
            while (condition->eval()->asDouble() != 0) {
                statement->execute();
            }
        }

        std::string str(int tab = 0) override {
            std::string res = "[WHILE]\n ";
            for (int i = 0; i < tab + 1; i++) res += '\t';
            return res + condition->str(tab + 1) + " statement " + statement->str(tab + 1);
        }


    public:
        WhileStatement (Expression *condition, Statement *statement) {
            this->condition = condition;
            this->statement = statement;
        }
    };

} // parser

#endif //PYTHON_LITE_2_WHILESTATEMENT_H
