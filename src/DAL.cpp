//
// Created by tomot on 2020/10/26.
//

#include "DAL.h"

#include <utility>

DAL::DAL(const std::string &exp)
        : exp(std::regex_replace(exp, std::regex{"\\s"}, "")) {
}

RPN DAL::parseRPN() const {
    std::stack<char> s;
    std::string rpn{};

    std::regex reg{R"(\d+\.\d+|\d+|[*-/+])"};
    for (std::sregex_token_iterator it{exp.begin(), exp.end(), reg}, end; it != end; ++it) {
        if (std::regex_match(it->str(), std::regex{"[*-/+]"})) {
            auto first_char{it->str()[0]};
            if (first_char == '(') {
                s.push(first_char);
            } else if (first_char == ')') {
                while (!s.empty() && s.top() != '(') {
                    rpn.push_back(s.top());
                    s.pop();
                }
                s.pop();
            } else if (first_char == '+' || first_char == '-') {
                while (!s.empty() && s.top() != '(') {
                    rpn.push_back(s.top());
                    s.pop();
                }
                s.push(first_char);
            } else {
                while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
                    rpn.push_back(s.top());
                    s.pop();
                }
                s.push(first_char);
            }
        } else {
            rpn.append(*it).push_back(' ');
        }
    }

    while (!s.empty()) {
        rpn.push_back(s.top());
        s.pop();
    }
    //std::cout<<rpn<<std::endl;
    return RPN{rpn};
}


double DAL::evaluate() const {
    std::stack<double> num_stack;
    std::stack<char> oper_stack;

    std::regex reg{R"(\d+\.\d+|\d+|[*-/+])"};
    for (std::sregex_token_iterator it{exp.begin(), exp.end(), reg}, end; it != end; ++it) {
        if (std::regex_match(it->str(), std::regex{"[*-/+]"})) {
            auto first_char{it->str()[0]};
            if (first_char == '(') {
                oper_stack.push(first_char);
            } else if (first_char == ')') {
                while (!oper_stack.empty() && oper_stack.top() != '(') {
                    auto right{num_stack.top()};
                    num_stack.pop();
                    auto left{num_stack.top()};
                    num_stack.pop();
                    switch (oper_stack.top()) {
                        case '+':
                            num_stack.push(left + right);
                            break;
                        case '-':
                            num_stack.push(left - right);
                            break;
                        case '*':
                            num_stack.push(left * right);
                            break;
                        case '/':
                            num_stack.push(left / right);
                            break;
                    }
                    oper_stack.pop();
                }
                oper_stack.pop();
            } else if (first_char == '+' || first_char == '-') {
                while (!oper_stack.empty() && oper_stack.top() != '(') {

                    auto right{num_stack.top()};
                    num_stack.pop();
                    auto left{num_stack.top()};
                    num_stack.pop();
                    switch (oper_stack.top()) {
                        case '+':
                            num_stack.push(left + right);
                            break;
                        case '-':
                            num_stack.push(left - right);
                            break;
                        case '*':
                            num_stack.push(left * right);
                            break;
                        case '/':
                            num_stack.push(left / right);
                            break;
                    }
                    oper_stack.pop();
                }
                oper_stack.push(first_char);
            } else {

                while (!oper_stack.empty() && (oper_stack.top() == '*' || oper_stack.top() == '/')) {
                    auto right{num_stack.top()};
                    num_stack.pop();
                    auto left{num_stack.top()};
                    num_stack.pop();
                    switch (oper_stack.top()) {
                        case '*':
                            num_stack.push(left * right);
                            break;
                        case '/':
                            num_stack.push(left / right);
                            break;
                    }
                    oper_stack.pop();
                }
                oper_stack.push(first_char);

            }
        } else {
            std::cout<<*it<<std::endl;
            num_stack.push(std::stod(*it));
        }

    }
    while(!oper_stack.empty()){
        auto right{num_stack.top()};
        num_stack.pop();
        auto left{num_stack.top()};
        num_stack.pop();
        switch (oper_stack.top()) {
            case '+':
                num_stack.push(left + right);
                break;
            case '-':
                num_stack.push(left - right);
                break;
            case '*':
                num_stack.push(left * right);
                break;
            case '/':
                num_stack.push(left / right);
                break;
        }
        oper_stack.pop();
    }
    return num_stack.top();
}

std::ostream &operator<<(std::ostream &os, const DAL &dal) {
    os << "exp: " << dal.exp;
    return os;
}
