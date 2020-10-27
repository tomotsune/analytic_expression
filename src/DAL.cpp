//
// Created by tomot on 2020/10/26.
//

#include "DAL.h"

#include <utility>

DAL::DAL(std::string expression) : expression(std::move(expression)) {}

RPN DAL::parseRPN() const {
    std::stack<char> s;
    std::string rpn{};
    for (const auto &item : expression) {
        if (isalnum(item)) {

            rpn.push_back(item);
        } else {
            if (item == '(') {
                s.push(item);
            } else if (item == ')') {
                while (!s.empty() && s.top() != '(') {
                    rpn.push_back(s.top());
                    s.pop();
                }
                s.pop();
            } else if (item == '+' || item == '-') {
                while (!s.empty() && s.top() != '(') {
                    rpn.push_back(s.top());
                    s.pop();
                }
                s.push(item);
            } else {
                while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
                    rpn.push_back(s.top());
                    s.pop();
                }
                s.push(item);


            }
        }

    }
    while (!s.empty()) {
        rpn.push_back(s.top());
        s.pop();
    }
    return RPN{rpn};
}

double DAL::evaluate() const {
    std::stack<int> num_stack;
    std::stack<char> oper_stack;
    for (const auto &item : expression) {
        if (isdigit(item)) {
            num_stack.push(std::stoi(std::string{item}));
        } else {
            if (item == '(') {
                oper_stack.push(item);
            } else if (item == ')') {
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
            } else if (item == '+' || item == '-') {
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
                oper_stack.push(item);
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
                oper_stack.push(item);

            }

        }
    }
        return num_stack.top();
}