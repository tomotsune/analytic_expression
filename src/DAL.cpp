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
            } else if(item==')'){
                while (!s.empty() && s.top() != '(') {
                    rpn.push_back(s.top());
                    s.pop();
                }
                s.pop();
            }
            else if (item == '+' || item == '-') {
                while (!s.empty() && s.top() != '(') {
                    rpn.push_back(s.top());
                    s.pop();
                }
                s.push(item);
            } else {
                while (!s.empty()&&(s.top() == '*' || s.top() == '/')) {
                        rpn.push_back(s.top());
                        s.pop();
                }
                s.push(item);


            }


        }

    }
    while(!s.empty()){
        rpn.push_back(s.top());
        s.pop();
    }
    return RPN{rpn};
}
