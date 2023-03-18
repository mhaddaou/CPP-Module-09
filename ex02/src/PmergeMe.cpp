/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 01:32:01 by mhaddaou          #+#    #+#             */
/*   Updated: 2023/03/18 13:07:56 by mhaddaou         ###   ########.fr       */
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
    convert(str);
    before('b');
    gettimeofday(&_start, NULL);
    mergeSortList(_lst);
    gettimeofday(&_end, NULL);
    before('a');
    calculeTime('l');
    gettimeofday(&_start, NULL);
    mergeSortDeque(_dqe);
    gettimeofday(&_end, NULL);
    calculeTime('d');
    
    
    
}

void PmergeMe::calculeTime(char c){
    long sec = _end.tv_sec - _start.tv_sec;
    long usec = ((sec * 1000000) + _end.tv_usec) - _start.tv_usec;
    if (c == 'l')
        std::cout << "Time to process a range of " << _lst.size() << " elements with std::list[..] : " << usec << " us" << std::endl;
    else
        std::cout << "Time to process a range of " << _dqe.size() << " elements with std::deque[..] : " << usec << " us" << std::endl;
        
}
void PmergeMe::before(char c){
    if (c == 'b')
        std::cout << "Before: ";
    else
        std::cout << "After: ";
    for(std::list<int>::iterator it = _lst.begin(); it != _lst.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
void PmergeMe::merge(std::list<int> left, std::list<int> right, std::list<int> &lst){
    std::list<int>::iterator iter_left = left.begin();
    std::list<int>::iterator iter_right = right.begin();
    std::list<int>::iterator it = lst.begin();
    
    while (iter_left != left.end() && iter_right != right.end()){
        if (*iter_left < *iter_right)
            *it++ = *iter_left++;
        else
            *it++ = *iter_right++;
    }
    while (iter_left != left.end()){
        *it++ = *iter_left++;
    }
    while (iter_right != right.end()){
        *it++ = *iter_right++;
    }
}
template<typename iter>
void PmergeMe::insertion_sort(iter begin, iter end){
    iter tmp;
    iter r = begin;
    for (; begin != end; ++begin){
        iter check = begin;
        tmp = check;
        for (; check != r && (*--check) > *tmp;){
            std::swap(*check, *tmp);
            tmp--;
        }
    }
}



void PmergeMe::mergeSortList(std::list<int> &lst){
    if (lst.size() <= 50){
        std::list<int>::iterator it = lst.begin();
        std::list<int>::iterator end = lst.end();
        insertion_sort(it, end);
        return;
    }
    size_t middle = lst.size() / 2;
    std::list<int> left;
    std::list<int> right;
    size_t i = 0; // left
    for(std::list<int>::iterator it = lst.begin() ; it != lst.end() ; it++){
        if (i < middle){
            left.push_back(*it);
            i++;
        }
        else
            right.push_back(*it);
    }
    mergeSortList(left);
    mergeSortList(right);
    merge(left, right, lst);
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

const char * PmergeMe::DuplicateValue::what() const throw(){
    return "Error: Duplicate Number";
}

void PmergeMe::mergeSortDeque(std::deque<int> & dqe){
    if (dqe.size() <= 50){
        std::deque<int>::iterator it = dqe.begin();
        std::deque<int>::iterator end = dqe.end();
        insertion_sort(it, end);
        return;
    }
    size_t middle = dqe.size() / 2;
    std::deque<int> left;
    std::deque<int> right;
    size_t l = 0;
    for (std::deque<int>::iterator it = dqe.begin(); it != dqe.end(); it++){
        if (l < middle){
            left.push_back(*it);
            l++;
        }
        else
            right.push_back(*it);
    }
    mergeSortDeque(left);
    mergeSortDeque(right);
    mergeDqe(left, right, dqe);
}

void PmergeMe::mergeDqe(std::deque<int> left, std::deque<int> right, std::deque<int> &dqe){
    std::deque<int>::iterator iter_left = left.begin();
    std::deque<int>::iterator iter_right = right.begin();
    std::deque<int>::iterator it = dqe.begin();
    while (iter_left != left.end() && iter_right != right.end()){
        if (*iter_left < *iter_right)
            *it++ = *iter_left++;
        else
            *it++ = *iter_right++;
    }
    while (iter_left != left.end()){
        *it++ = *iter_left++;
    }
    while (iter_right != right.end()){
        *it++ = *iter_right++;
    }
}