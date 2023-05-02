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

        std::string str() override {
            return "while " + condition->str() + " statement " + statement->str();
        }


    public:
        WhileStatement (Expression *condition, Statement *statement) {
            this->condition = condition;
            this->statement = statement;
        }
    };

} // parser

#endif //PYTHON_LITE_2_WHILESTATEMENT_H
