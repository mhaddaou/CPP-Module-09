/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 01:32:01 by mhaddaou          #+#    #+#             */
/*   Updated: 2023/03/15 22:49:08 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(char **av, int ac){
    std::vector<std::string> str = retAll(av, ac);
    for (std::vector<std::string>::iterator it = str.begin() ; it != str.end(); it++){
        if (checkValues(*it) == EXIT_FAILURE)
            throw BadValue();
    }
    checkDuplicate(str);
    convert(str);
}

void PmergeMe::checkIntMax(std::list<int> lst){
    for (std::list<int>::iterator it = lst.begin() ; it != lst.end(); it++){
        if (*it < 0)
            throw BadValue();
    }
}

void PmergeMe::convert(std::vector<std::string> str){
    std::vector<int> vec;
    for (std::vector<std::string>::iterator it = str.begin() ; it != str.end(); it++){
        _lst.push_back(atoi((*it).c_str()));
        _dqe.push_back(atoi((*it).c_str()));
    }
    checkIntMax(_lst);
}

void PmergeMe::checkDuplicate(std::vector<std::string> str){
    for (size_t i = 0; i < str.size(); i++){
        for(size_t j = i + 1; j < str.size(); j++){
            if (str[i] == str[j])
                throw DuplicateValue();
        }
    }
}

int PmergeMe::checkSpace(char * str){
    int check = 0;
    for (int i = 0; str[i]; i++){
        if (str[i] == ' ')
            check++;
    }
    if (check != 0)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

PmergeMe::~PmergeMe(){}

std::vector<std::string> PmergeMe::retAll(char ** av, int ac){
    std::vector<std::string> pur;
    std::string ret ;
    for (int i = 1; i < ac; i++){
        if (checkSpace(av[i]) == EXIT_FAILURE){
            std::vector<std::string> vec = splitee(av[i], ' ');
            for (std::vector<std::string>::iterator it = vec.begin() ; it != vec.end(); it++){
                pur.push_back(*it);
            }
        }
        else
            pur.push_back(av[i]);
    }
   
    return pur;
}

std::vector<std::string> PmergeMe::splitee(char * line, char sp){
    std::string _line;
    std::vector<std::string> vec;
    std::stringstream ss;
    ss << line;
    while (std::getline(ss, _line, sp)){
        vec.push_back(_line);
    }
    return (vec);
}

const char *PmergeMe::BadValue::what() const throw(){
    return "Error: Bad Inpute";
}

int PmergeMe::checkValues(std::string str){
    for (size_t i = 0; i < str.length() ; i++){
        if (!isdigit(str[i]))
            if (str[i] != ' ')
                if (str[i] != '+')
                    return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

const char * PmergeMe::BadInput::what() const throw(){
    return "Error:  Usage: ./PmergeMe [int] [int] ...";
}
bool PmergeMe::inRange(unsigned low, unsigned high, unsigned x)         
{
    high = 2147483647;
    low = -2147483648;             
 return (low <= x && x <= high);         
}

const char * PmergeMe::DuplicateValue::what() const throw(){
    return "Error: Duplicate Number";
}