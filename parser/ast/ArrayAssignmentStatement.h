//
// Created by ilazu on 02.05.2023.
//

#ifndef PYTHON_LITE_2_ARRAYASSIGNMENTSTATEMENT_H
#define PYTHON_LITE_2_ARRAYASSIGNMENTSTATEMENT_H
#include "Statement.h"
#include "Expression.h"
#include "ArrayValue.h"
#include "ConstantExpression.h"
#include <iostream>
namespace parser {

    class ArrayAssignmentStatement : public Statement {
        std::string variable;
        Expression *index;
        Expression *expression;

    public: ArrayAssignmentStatement(std::string variable, Expression *index, Expression *expression) {
            this->variable = variable;
            this->index = index;
            this->expression = expression;
        }

        void execute() override {
            Value *var = Variables::get(variable);
            if (typeid(*var) == typeid(ArrayValue)) {
                ArrayValue *array = dynamic_cast<ArrayValue*> (var);
                array->set(int(index->eval()->asDouble()), expression->eval());
            }
            else {
                throw std::runtime_error("Array expected");
            }
        }

        std::string str(int tabs = 0) override {
            std::string result = "[ARRAYASSIGN] " + variable + " [" + index->str() + "] " + expression->str();
            return result;
        }





    };

} // parser

#endif //PYTHON_LITE_2_ARRAYASSIGNMENTSTATEMENT_H
