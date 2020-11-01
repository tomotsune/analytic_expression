//
// Created by tomot on 2020/10/26.
//

#include "RPN.h"

#include <utility>


RPN::RPN(const std::string &exp) {
    std::regex reg{"\\d+|[*-/+]+"};
    for (std::sregex_token_iterator it{exp.begin(), exp.end(), reg}, end; it != end; ++it) {
        it->str().push_back(' ');
        RPN::exp.append(*it).push_back(' ');
    }
    RPN::exp.pop_back();
}

std::ostream &operator<<(std::ostream &os, const RPN &rpn) {
    os << "exp: " << rpn.exp;
    return os;
}

const std::string &RPN::getExpression() const {
    return exp;
}

double RPN::evaluate() const {
    std::stack<double> s;
    std::regex reg{"\\s+"};
    for (std::sregex_token_iterator it{exp.begin(), exp.end(), reg,-1}, end; it != end; ++it) {
        if (std::regex_match(it->str(), std::regex{"\\d+"})) {
            s.push(stod(*it));
        } else {
            auto right{s.top()};
            s.pop();
            auto left{s.top()};
            s.pop();
            switch (it->str()[0]) {
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
