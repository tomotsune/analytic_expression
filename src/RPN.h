//
// Created by tomot on 2020/10/26.
//

#ifndef ANALYTIC_EXPRESSION_RPN_H
#define ANALYTIC_EXPRESSION_RPN_H
#include <iostream>
#include <regex>
#include <stack>
class RPN {
public:
private:
    std::string exp;
public:
    explicit RPN(const std::string& exp);

    [[nodiscard]] double evaluate()const;

    [[nodiscard]] const std::string &getExpression() const;

    friend std::ostream &operator<<(std::ostream &os, const RPN &rpn);
};


#endif //ANALYTIC_EXPRESSION_RPN_H
