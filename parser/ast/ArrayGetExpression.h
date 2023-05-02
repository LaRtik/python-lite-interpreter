//
// Created by ilazu on 02.05.2023.
//

#ifndef PYTHON_LITE_2_ARRAYGETEXPRESSION_H
#define PYTHON_LITE_2_ARRAYGETEXPRESSION_H

#include "Expression.h"
#include <iostream>
#include "ConstantExpression.h"
#include "ArrayValue.h"

namespace parser {

    class ArrayGetExpression : public Expression{
        std::string variable;
        Expression *index = 0;

    public: ArrayGetExpression(std::string variable, Expression *index) {
            this->variable = variable;
            this->index = index;
        }

        Value * eval() const override {
            Value *var = Variables::get(variable);
            if (typeid(*var) == typeid(ArrayValue)) {
                ArrayValue *array = dynamic_cast<ArrayValue*> (var);
                return array->get((int)index->eval()->asDouble());
            }
            else {
                throw std::runtime_error("Array expected");
            }
        }

        std::string str(int tab = 0) const override {
            return "[ARRAY] " + variable + " [" + index->str(tab) + "] ";
        }

    };

} // parser

#endif //PYTHON_LITE_2_ARRAYGETEXPRESSION_H
