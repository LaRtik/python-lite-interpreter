//
// Created by ilazu on 01.05.2023.
//

#ifndef PYTHON_LITE_2_STATEMENT_H
#define PYTHON_LITE_2_STATEMENT_H

namespace parser {

    class Statement {

    public:
        virtual void execute() = 0;

        virtual std::string str(int tab = 0) = 0;
    };

} // parser

#endif //PYTHON_LITE_2_STATEMENT_H
