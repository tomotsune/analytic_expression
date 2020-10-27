//
// Created by tomot on 2020/10/26.
//

#ifndef ANALYTIC_EXPRESSION_DAL_H
#define ANALYTIC_EXPRESSION_DAL_H

#include <iostream>
#include <stack>
#include <cctype>
#include "RPN.h"
class DAL {
    std::string expression;
public:
    explicit DAL(std::string expression);
    double evaluate()const;
    RPN parseRPN()const;
};


#endif //ANALYTIC_EXPRESSION_DAL_H
