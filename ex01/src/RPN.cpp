/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:23:27 by mhaddaou          #+#    #+#             */
/*   Updated: 2023/03/15 23:09:02 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

RNP::RNP(){}

RNP::RNP(std::string str){
    for(size_t i = 0; i < str.size(); i++){
        if (isdigit(str[i]))
            _stack.push(str[i] - '0');
        else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/'){
            int val1 = _stack.top();_stack.pop();
            int val2 = _stack.top();_stack.pop();
            switch (str[i]){
                case '+':
                    _stack.push(val2 + val1);break;
                case '-':
                    _stack.push(val2 - val1);break;
                case '*':
                    _stack.push(val2 * val1);break;
                case '/':
                    _stack.push(val2 / val1);break;
            }
        }
        if (str[i] == '(' || str[i] == ')')
            throw Brackets();
    }
}


const char *RNP::Brackets::what() const throw(){
    return ("Error");
}

RNP::RNP(const RNP& other){
    *this = other;
}

RNP const& RNP::operator=(const RNP& other){
    if (this != &other)
    {
        this->_stack = other._stack;
    }
    return *this;
}

RNP::~RNP(){
    
}

int RNP::stackTop(){
    return (_stack.top());
}

const char *RNP::BadInput::what() const throw(){
    return ("Bad Input");
}