//
// Created by ilazu on 02.05.2023.
//

#ifndef PYTHON_LITE_2_USERDEFINEFUNCTION_H
#define PYTHON_LITE_2_USERDEFINEFUNCTION_H

#include "Function.h"
#include "Statement.h"
#include "NumberValue.h"
#include "ReturnStatement.h"

namespace parser {

    class UserDefineFunction : public Function{
        std::vector <std::string> args;
        Statement *body;

        std::string str(int tabs = 0) override {
            std::string res = "[DEF] (";
            for (auto names : args) res += names + ',';
            res += ")\n";
            for (int i = 0; i <= tabs; i++) res += '\t';
            res += body->str();
            return res;
        }

    public:
        int getArgsCount() {
            return args.size();
        }

        std::string getArgName(int index) {
            if (index < 0 || index >= getArgsCount()) return "";
            return args[index];
        }

        UserDefineFunction (std::vector <std::string> args, Statement *body) {
            this->args = args;
            this->body = body;
        }

        Value * execute(std::vector<Value *> args) override {
            try {
                body->execute();
            } catch (ReturnStatement *e) {
                return e->result;
            }

            return new NumberValue(0.0);
        }
    };

} // parser

#endif //PYTHON_LITE_2_USERDEFINEFUNCTION_H
