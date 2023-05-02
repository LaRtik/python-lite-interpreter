//
// Created by ilazu on 02.05.2023.
//

#ifndef PYTHON_LITE_2_ARRAYEXPRESSION_H
#define PYTHON_LITE_2_ARRAYEXPRESSION_H
#include "Expression.h"
#include "ArrayValue.h"
#include <iostream>
#include <vector>
namespace parser {

    class ArrayExpression : public Expression{
        std::vector <Expression*> elements;

    public: ArrayExpression(std::vector <Expression*> elements){
            this->elements = elements;
        }

        Value * eval() const override {
            int size = elements.size();
            ArrayValue *array = new ArrayValue(size);
            for (int i = 0; i < size; i++) {
                array->set(i, elements[i]->eval());
            }
            return array;
        }

        std::string str(int tab = 0) const override {
            std::string result = "[ARRAYEXPR] [";
            for (auto i : elements) result += i->str(tab) + ",";
            return result + ']';
        }

    };

} // parser

#endif //PYTHON_LITE_2_ARRAYEXPRESSION_H
