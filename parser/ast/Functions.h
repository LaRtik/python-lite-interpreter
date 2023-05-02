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
#include "ArrayValue.h"
#include "IntValue.h"
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

    class FUNCTION_list : public Function {
        Value * execute(std::vector<Value*> args) override {
            return new ArrayValue(args);
        }
        std::string str(int tabs = 0) override {
            return "[FUNCTION_list (any)]";
        }
    };

    class FUNCTION_range : public Function {
        Value * execute(std::vector<Value*> args) override {
            if (args.size() == 1) {
                std::vector <Value*> arr;
                for (int i = 0; i < (int)args[0]->asDouble(); i++) arr.push_back(new NumberValue(double(i)));
                return new ArrayValue(arr);
            }
            if (args.size() == 2) {
                std::vector <Value*> arr;
                for (int i = (int)args[0]->asDouble(); i < (int)args[1]->asDouble(); i++) arr.push_back(new NumberValue(double(i)));
                return new ArrayValue(arr);
            }
            else throw std::runtime_error("Expected 1 (2) argument(s) in RANGE function");
        }
        std::string str(int tabs = 0) override {
            return "[FUNCTION_range (start: int [optional], end: int)]";
        }
    };

    class FUNCTION_input : public Function {
        Value * execute(std::vector<Value*> args) override {
            std::string input;
            std::cin >> input;
            return new StringValue(input);
        }
        std::string str(int tabs = 0) override {
            return "[FUNCTION_input (none)]";
        }
    };

    class FUNCTION_int : public Function {
        Value * execute(std::vector<Value*> args) override {
            if (args.size() != 1) throw std::runtime_error("Expected 1 argument in INT function");
            return new IntValue(args[0]->asInt());
        }
        std::string str(int tabs = 0) override {
            return "[FUNCTION_int (any)]";
        }
    };

    class FUNCTION_float : public Function {
        Value * execute(std::vector<Value*> args) override {
            if (args.size() != 1) throw std::runtime_error("Expected 1 argument in FLOAT function");
            return new NumberValue(args[0]->asDouble());
        }
        std::string str(int tabs = 0) override {
            return "[FUNCTION_float (any)]";
        }
    };

    class FUNCTION_len : public Function {
        Value * execute(std::vector<Value*> args) override {
            try {
                ArrayValue *arr = dynamic_cast<ArrayValue *>(args[0]);
                return new IntValue(arr->size());
            } catch (std::exception) {
                throw std::runtime_error("Expected array in LEN arguments");
            }
        }
        std::string str(int tabs = 0) override {
            return "[FUNCTION_len (array)]";
        }
    };



    class Functions {

        inline static std::map <std::string, Function*> functions {
                {"sqrt", new FUNCTION_sqrt()},
                {"print", new FUNCTION_print()},
                {"list", new FUNCTION_list()},
                {"range", new FUNCTION_range()},
                {"input", new FUNCTION_input()},
                {"int", new FUNCTION_int()},
                {"float", new FUNCTION_float()},
                {"len", new FUNCTION_len()},
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
