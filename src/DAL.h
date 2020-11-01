//
// Created by tomot on 2020/10/26.
//

#ifndef ANALYTIC_EXPRESSION_DAL_H
#define ANALYTIC_EXPRESSION_DAL_H

#include <ostream>
#include <regex>
#include "RPN.h"
class RPN;
class DAL {
    std::string expression;
public:
    explicit DAL(const std::string& expression);
    double evaluate()const;
    RPN parseRPN()const;

    friend std::ostream &operator<<(std::ostream &os, const DAL &dal);
};


#endif //ANALYTIC_EXPRESSION_DAL_H
