//
// Created by ilazu on 02.05.2023.
//

#ifndef PYTHON_LITE_2_BLOCKSTATEMENT_H
#define PYTHON_LITE_2_BLOCKSTATEMENT_H

#include "Statement.h"
#include <vector>
#include <iostream>

namespace parser {

    class BlockStatement : public Statement {
        std::vector <Statement*> statements;

    public: void add(Statement *statement) {
            statements.push_back(statement);
        }

        void execute() override {
            for (auto statement : statements) {
                statement->execute();
            }
        }

        std::string str() override {
            std::string res;
            for (auto statement : statements) res += statement->str() + "\n";
            return res;
        }

    };

} // parser

#endif //PYTHON_LITE_2_BLOCKSTATEMENT_H
