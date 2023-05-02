//
// Created by ilazu on 02.05.2023.
//

#ifndef PYTHON_LITE_2_FUNCTIONALEXPRESSION_H
#define PYTHON_LITE_2_FUNCTIONALEXPRESSION_H
#include "Expression.h"
#include <iostream>
#include <vector>
#include "Functions.h"

namespace parser {

    class FunctionalExpression : public Expression {
        std::string name;
        std::vector <Expression*> args;

        FunctionalExpression (std::string name, std::vector <Expression*> args) {
            this->name = name;
            this->args = args;
        }

    public:
        FunctionalExpression (std::string name) {
            this->name = name;
        }

        void addArgument(Expression* arg) {
            args.push_back(arg);
        }

        Value * eval() const override {
            std::vector <Value*> values;
            for (auto argument : args) {
                values.push_back(argument->eval());
            }
            return Functions::get(name)->execute(values);
        }

        std::string str(int tab = 0) const override {
            std::string res = "[FUNCTIONALEXPR] " + name + " args: (";
            for (auto arg : args) res += arg->str(tab + 1) + ", ";
            return res + ")";
        }
    };

} // parser

#endif //PYTHON_LITE_2_FUNCTIONALEXPRESSION_H
