/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:33:49 by mhaddaou          #+#    #+#             */
/*   Updated: 2023/03/15 11:10:17 by mhaddaou         ###   ########.fr       */
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
        int _csvLines;
        int _inputLines;
        float _value;
        std::map<std::string, double> _data;
        std::string _date;
    public:
        BitcoinExchange(const char * fileName);
        void readCsvFile(const char * csvFile);
        void storeCsvLines(std::string line);
        void PurePrice(std::string date);
        void readInputFile(const char * file);
        void checkInpuFile(std::string line);
        void checkDate(std::string date);
        std::vector<std::string> spliteLine(std::string line, char sp);
        int checkYear(int num);
        int checkMonth(int num);
        int checkDay(int day,int month);
        void checkValue(std::string value);
        bool id_empty(std::ifstream& file);
        void checkLine(std::string line);
        std::string removeSpace(std::string line);
        void checkAnotherChar(std::string line);
        void checkPipe(std::string line);
        void checkResultAndPrint(std::string date, double result);
        int check(std::string value);
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