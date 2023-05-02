//
// Created by ilazu on 02.05.2023.
//

#ifndef PYTHON_LITE_2_FUNCTIONS_H
#define PYTHON_LITE_2_FUNCTIONS_H
#include <map>
#include <iostream>
#include "Function.h"
#include "NumberValue.h"
#include "StringValue.h"
#include <memory>
#include <cmath>

namespace parser {
    class FUNCTION_sqrt : public Function {
        Value * execute(std::vector<Value*> args) override {
            if (args.size() != 1) throw std::runtime_error("Expected 1 argument in SQRT function");
            return new NumberValue(sqrt(args[0]->asDouble()));
        }
        std::string str(int tabs = 0) override {
            return "[FUNCTION_sqrt (n: double)]";
        }
    };

    class FUNCTION_print : public Function {
        Value * execute(std::vector<Value*> args) override {
            std::string result;
            for (auto arg : args) result += arg->asString() + " ";
            std::cout << result << std::endl;
            return new StringValue(result);
        }
        std::string str(int tabs = 0) override {
            return "[FUNCTION_print (any)]";
        }
    };



    class Functions {

        inline static std::map <std::string, Function*> functions {
                {"sqrt", new FUNCTION_sqrt()},
                {"print", new FUNCTION_print()},
        };


    public: static bool isExists(const std::string& key) {
            return Functions::functions.find(key) != Functions::functions.end();
        }

    public: static Function * get(const std::string& key) {
            if (!isExists(key)) throw std::runtime_error("Function " + key + "does not exists");
            return Functions::functions[key];
        }

    public: static void set(const std::string& key, Function *function) {
            if (isExists(key)) Functions::functions[key] = function;
            else functions.insert({key, function});
        }
    };

} // parser

#endif //PYTHON_LITE_2_FUNCTIONS_H
