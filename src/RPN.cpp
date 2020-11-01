//
// Created by tomot on 2020/10/26.
//

#include "RPN.h"

#include <utility>


RPN::RPN(const std::string &exp) {
    std::regex reg{"\\d+|[*-/+]+"};
    for (std::sregex_token_iterator it{exp.begin(), exp.end(), reg}, end; it != end; ++it) {
        //std::cout<<it->str()<<std::endl;
        it->str().push_back(' ');
        expression.append(*it).push_back(' ');
    }
    expression.pop_back();
}

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
    while (expressionStream >> out) {
        if (isdigit(out.at(0))) {
            s.push(stod(out));
        } else {
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
