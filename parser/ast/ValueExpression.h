//
// Created by ilazu on 02.05.2023.
//

#ifndef PYTHON_LITE_2_VALUEEXPRESSION_H
#define PYTHON_LITE_2_VALUEEXPRESSION_H

#include "Expression.h"
#include "NumberValue.h"
#include "StringValue.h"

namespace parser {


    class ValueExpression : public Expression {
        Value *value;

        Value * eval() const override {
            return value;
        }

        std::string str() const override {
            return value->asString();
        }

    public:
        ValueExpression(double value){
            this->value = new NumberValue(value);
        }

        ValueExpression(std::string value) {
            this->value = new StringValue(value);
        }
    };

} // parser

#endif //PYTHON_LITE_2_VALUEEXPRESSION_H
