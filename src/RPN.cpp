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

double RPN::evaluate() const {
    std::stack<double> s;
    std::istringstream expressionStream{expression};
    std::string out;
    while(expressionStream>>out){
        if(isdigit(out.at(0))){
            s.push(stod(out));
        }else{
            auto right{s.top()};
            s.pop();
            auto left{s.top()};
            s.pop();
            switch (out.at(0)) {
                case '+':
                    s.push(left + right);
                    break;
                case '-':
                    s.push(left - right);
                    break;
                case '*':
                    s.push(left * right);
                    break;
                case '/':
                    s.push(left / right);
                    break;
            }
        }

    }

    return s.top();
}
