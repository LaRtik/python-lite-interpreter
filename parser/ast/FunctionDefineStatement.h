//
// Created by ilazu on 02.05.2023.
//

#ifndef PYTHON_LITE_2_FUNCTIONDEFINESTATEMENT_H
#define PYTHON_LITE_2_FUNCTIONDEFINESTATEMENT_H
#include "Statement.h"
#include "Functions.h"
#include <iostream>
#include <vector>

namespace parser {

    class FunctionDefineStatement: public Statement {
        std::string name;
        std::vector <std::string> argNames;
        Statement *body;

        void execute() override {
            Functions::set(name, new UserDefineFunction(argNames, body));
        }

        std::string str(int tabs = 0) override {
            std::string res = "[FUNCDEF] " + name + "(";
            for (auto names : argNames) res += names + ',';
            res += ")\n";
            for (int i = 0; i <= tabs; i++) res += '\t';
            res += body->str();
            return res;
        }

    public:
        FunctionDefineStatement(std::string name, std::vector <std::string> argNames, Statement *body) {
            this->name = name;
            this->argNames = argNames;
            this->body = body;
        }
    };

} // parser

#endif //PYTHON_LITE_2_FUNCTIONDEFINESTATEMENT_H
