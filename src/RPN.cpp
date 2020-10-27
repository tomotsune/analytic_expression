//
// Created by tomot on 2020/10/26.
//

#include "RPN.h"

#include <utility>


RPN::RPN(std::string expression) : expression(std::move(expression)) {}

std::ostream &operator<<(std::ostream &os, const RPN &rpn) {
    os << "expression: " << rpn.expression;
    return os;
}

const std::string &RPN::getExpression() const {
    return expression;
}
