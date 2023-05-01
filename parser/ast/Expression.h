//
// Created by ilazu on 01.05.2023.
//

#ifndef PYTHON_LITE_2_EXPRESSION_H
#define PYTHON_LITE_2_EXPRESSION_H

namespace parser {

    class Expression {


    public:
        virtual double eval() const {};
    };


} // parser

#endif //PYTHON_LITE_2_EXPRESSION_H
