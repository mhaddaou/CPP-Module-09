/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:21:36 by mhaddaou          #+#    #+#             */
/*   Updated: 2023/03/15 16:00:31 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>


class RNP{
    private:
        std::stack<int> _stack;
    public:
        RNP();
        RNP(std::string str);
        RNP(const RNP& other);
        RNP const& operator=(const RNP& other);
        ~RNP();
        int stackTop();
        class BadInput: public std::exception{
            public:
                virtual const char* what() const throw();
        };
        class Brackets: public std::exception{
            public:
                virtual const char * what() const throw();
        };
};