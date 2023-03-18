/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:23:27 by mhaddaou          #+#    #+#             */
/*   Updated: 2023/03/18 11:43:54 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

RNP::RNP(){}

RNP::RNP(std::string str){
    for(size_t i = 0; i < str.size(); i++){
        if (isdigit(str[i]))
            _stack.push(str[i] - '0');
        else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/'){
            if (_stack.size() != 2)
                throw BadInput();
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
        else if (str[i] != ' ')
            throw BadInput();
    }
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