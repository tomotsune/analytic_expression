//
// Created by tomot on 2020/10/25.
//

#ifndef ANALYTIC_EXPRESSION_REVERSE_POLISH_NOTATION_H
#define ANALYTIC_EXPRESSION_REVERSE_POLISH_NOTATION_H
#include <iostream>

class reverse_polish_notation {
private:
    std::string expression;
public:
    explicit reverse_polish_notation(const std::string &expression);
    double eval()const;
};


#endif //ANALYTIC_EXPRESSION_REVERSE_POLISH_NOTATION_H
