//
// Created by ilazu on 01.05.2023.
//

#ifndef PYTHON_LITE_2_CONSTANTEXPRESSION_H
#define PYTHON_LITE_2_CONSTANTEXPRESSION_H

#include "Expression.h"
#include <iostream>
#include <map>
#include <utility>

namespace parser {
    class Variables {
        inline static std::map <std::string, double> variables {
                {"PI", 3.14}
        };


    public: static bool isExists(const std::string& key) {
            return Variables::variables.find(key) != Variables::variables.end();
        }

    public: static double get(const std::string& key) {
            if (!isExists(key)) return 0;
            return Variables::variables[key];
        }

    public: static void set(const std::string& key, double value) {
            variables.insert({key, value});
        }
    };



    class ConstantExpression : public Expression {
        std::string name;

        double eval() const override {
            if (!Variables::isExists(name))
                throw std::runtime_error("Constant " + name + " does not exists");
            return Variables::get(name);
        }

        friend std::ostream &operator<<(std::ostream &os, const ConstantExpression &expression) {
            os << expression.name << " " << Variables::get(expression.name);
            return os;
        }

        std::string str() const override {
            return name + std::to_string(Variables::get(name));
        }

    public:
        explicit ConstantExpression(std::string name) {
            this->name = std::move(name);
        }
    };

} // parser

#endif //PYTHON_LITE_2_CONSTANTEXPRESSION_H
