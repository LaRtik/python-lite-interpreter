//
// Created by ilazu on 01.05.2023.
//

#ifndef PYTHON_LITE_2_CONSTANTEXPRESSION_H
#define PYTHON_LITE_2_CONSTANTEXPRESSION_H

#include "Expression.h"
#include "NumberValue.h"
#include <iostream>
#include <map>
#include <utility>
#include <memory>
#include <stack>

namespace parser {
    class Variables {
        inline static NumberValue *NULL_NUMBER = new NumberValue(0.0);

        inline static std::stack <std::map <std::string, Value*> > stack;

        inline static std::map <std::string, Value*> variables {
                {"PI", new NumberValue(3.14)}
        };


    public: static bool isExists(const std::string& key) {
            return Variables::variables.find(key) != Variables::variables.end();
        }

    public: static Value * get(const std::string& key) {
            if (!isExists(key)) return NULL_NUMBER;
            return Variables::variables[key];
        }

    public: static void set(const std::string& key, Value *value) {
            if (isExists(key)) variables[key] = value;
            else variables.insert({key, value});
        }

        static void push() {
            stack.emplace(variables);
        }

        static void pop() {
            variables = stack.top();
            stack.pop();
        }

    };



    class ConstantExpression : public Expression {
        std::string name;

        Value *eval() const override {
            if (!Variables::isExists(name))
                throw std::runtime_error("Variable " + name + " does not exists");
            return Variables::get(name);
        }

        friend std::ostream &operator<<(std::ostream &os, const ConstantExpression &expression) {
            os << expression.name << " " << Variables::get(expression.name);
            return os;
        }

        std::string str(int tab = 0) const override {
            std::string res = "[VARIABLE] ";
            return res + name;
        }

    public:
        explicit ConstantExpression(std::string name) {
            this->name = std::move(name);
        }
    };

} // parser

#endif //PYTHON_LITE_2_CONSTANTEXPRESSION_H
