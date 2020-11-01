//
// Created by tomot on 2020/10/26.
//

#ifndef ANALYTIC_EXPRESSION_DAL_H
#define ANALYTIC_EXPRESSION_DAL_H

#include <iostream>
#include <regex>
#include "RPN.h"
class RPN;
class DAL {
    std::string exp;
public:
    explicit DAL(const std::string& exp);
    double evaluate()const;
    RPN parseRPN()const;

    friend std::ostream &operator<<(std::ostream &os, const DAL &dal);
};


#endif //ANALYTIC_EXPRESSION_DAL_H
