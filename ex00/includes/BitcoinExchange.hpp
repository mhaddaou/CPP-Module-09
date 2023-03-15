/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:33:49 by mhaddaou          #+#    #+#             */
/*   Updated: 2023/03/15 11:44:42 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <cctype>
#include <map>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <filesystem>
#include <sstream>

class BitcoinExchange{
    protected:
        std::map<std::string, double> _data;
        int _csvLines;
        int _inputLines;
        float _value;
        std::string _date;
    public:
        BitcoinExchange(const char * fileName);
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();
        
        
        int checkYear(int num);
        int checkMonth(int num);
        int checkDay(int day,int month);
        int check(std::string value);
        
        void readCsvFile(const char * csvFile);
        void storeCsvLines(std::string line);
        void PurePrice(std::string date);
        void readInputFile(const char * file);
        void checkInpuFile(std::string line);
        void checkDate(std::string date);
        void checkValue(std::string value);
        void checkPipe(std::string line);
        void checkResultAndPrint(std::string date, double result);
        
        std::string removeSpace(std::string line);
        
        std::vector<std::string> spliteLine(std::string line, char sp);
        
        bool id_empty(std::ifstream& file);
        
        class NotEnoughtParam : public std::exception{
            public:
                virtual const char* what() const throw();
        };
        class BadInput: public std::exception{
            public:
                virtual const char* what() const throw();
        };
        class EmptyFile : public std::exception{
            public:
                virtual const char* what() const throw();
        };
        class Npn : public std::exception{
            public:
                virtual const char* what() const throw();
        };
        class ToLarg : public std::exception{
            public:
                virtual const char* what() const throw();
        };
};