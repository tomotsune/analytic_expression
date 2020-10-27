//
// Created by tomot on 2020/10/26.
//

#ifndef ANALYTIC_EXPRESSION_RPN_H
#define ANALYTIC_EXPRESSION_RPN_H
#include <iostream>

class RPN {
public:
private:
    std::string expression;
public:
    explicit RPN(std::string expression);

    friend std::ostream &operator<<(std::ostream &os, const RPN &rpn);
};


#endif //ANALYTIC_EXPRESSION_RPN_H
