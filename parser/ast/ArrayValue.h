//
// Created by ilazu on 02.05.2023.
//

#ifndef PYTHON_LITE_2_ARRAYVALUE_H
#define PYTHON_LITE_2_ARRAYVALUE_H
#include "Value.h"
#include <vector>
#include <iostream>

namespace parser {

    class ArrayValue : public Value{
        std::vector <Value*> elements;

    public: ArrayValue (int size) {
            elements.resize(size);
        }
    public: ArrayValue (std::vector <Value*> elements){
            this->elements = elements;
        }

    public: Value *get(int index) {
            return  elements[index];
        }

    public: void set(int index, Value* value) {
            elements[index] = value;
        }

        double asDouble() override {
            throw std::runtime_error("Cannot cast array to number");
        }

        std::string asString() override {
            std::string result = "[";
            for (auto i : elements) result += i->asString() + ",";
            return result + "]";
        }

        std::string str() {
            return asString();
        }


    };


} // parser

#endif //PYTHON_LITE_2_ARRAYVALUE_H
