//
// Created by ilazu on 02.05.2023.
//

#ifndef PYTHON_LITE_2_FORSTATEMENT_H
#define PYTHON_LITE_2_FORSTATEMENT_H
#include "Statement.h"
#include "Expression.h"
#include "BreakStatement.h"
#include "ContinueStatement.h"
#include "ConstantExpression.h"
#include "ArrayValue.h"

namespace parser {

    class ForStatement : public Statement{
        std::string variable;
        Expression *condition;
        Statement *statement;

        void execute() override {
            double index = 0;
            Variables::set(variable, new NumberValue(index));
            Value *array = this->condition->eval();

            if (typeid(*array) == typeid(ArrayValue)) {
                ArrayValue *arr = dynamic_cast<ArrayValue*> (array);
                for (int i = 0; i < arr->size(); i++){
                    Variables::set(variable, arr->get(i));
                    try {
                        statement->execute();
                    }   catch (BreakStatement *e) {
                        break;
                    } catch (ContinueStatement *e) {
                        continue;
                    }
                }
            }
            else throw std::runtime_error("Expected array object in for");
        }

        std::string str(int tab = 0) override {
            std::string res = "[FOR]\n ";
            for (int i = 0; i < tab + 1; i++) res += '\t';
            return res + condition->str(tab + 1) + " statement " + statement->str(tab + 1);
        }


    public:
        ForStatement (std::string variable, Expression *condition, Statement *statement) {
            this->variable = variable;
            this->condition = condition;
            this->statement = statement;
        }
    };

} // parser

#endif //PYTHON_LITE_2_FORSTATEMENT_H
