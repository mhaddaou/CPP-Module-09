/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 01:31:52 by mhaddaou          #+#    #+#             */
/*   Updated: 2023/03/15 22:45:56 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <list>
#include <cstdlib>
#include <deque>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>



class PmergeMe{
    private:
        std::list<int> _lst;
        std::deque<int> _dqe;
    public:
        PmergeMe();
        PmergeMe(char **av, int ac);
        PmergeMe(const PmergeMe & other);
        PmergeMe const & operator=(const PmergeMe& other);
        ~PmergeMe();
        std::vector<std::string> retAll(char ** av, int ac);
        std::vector<std::string> splitee(char *line , char sp);
        int checkSpace(char * str);
        int checkValues(std::string str);
        class BadValue: public std::exception{
            public:
                virtual const char * what() const throw();      
        };
        class BadInput: public std::exception{
            public:
                virtual const char * what() const throw();      
        };
        bool inRange(unsigned low, unsigned high, unsigned x);
        void convert(std::vector<std::string> str);
        void checkDuplicate(std::vector<std::string> str);
        void checkIntMax(std::list<int> lst);
        class DuplicateValue: public std::exception{
            public:
                virtual const char * what() const throw();      
        };
};