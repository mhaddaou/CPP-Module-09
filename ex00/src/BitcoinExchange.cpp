/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:38:40 by mhaddaou          #+#    #+#             */
/*   Updated: 2023/03/15 11:23:37 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

std::string _err;

BitcoinExchange::BitcoinExchange(const char * fileName):_csvLines(0), _inputLines(0), _value(0){
    readCsvFile("data/data.csv");
    readInputFile(fileName);
    // for alloc 
    // char * buffer = new char [length];

}


const char* BitcoinExchange::NotEnoughtParam::what() const throw(){
    return ("Error: could not open file.");
}
const char *BitcoinExchange::BadInput::what() const throw(){
    return "Error: bad input => ";
}

void BitcoinExchange::readCsvFile(const char * csvFile){
    std::string line;
    std::ifstream _file(csvFile);
    while (std::getline(_file, line)){
        storeCsvLines(line);
    }
}

void BitcoinExchange::storeCsvLines(std::string line){
    std::string str = "";

    if (_csvLines != 0){
        std::string date = line.substr(0, line.find(','));
        std::string price = line.substr(line.find(',') + 1, line.length());
        _data.insert(std::pair<std::string, double>(date, std::atof(price.c_str())));
    }
    _csvLines++;
}

void BitcoinExchange::readInputFile(const char * file){
    std::string line;
    std::ifstream _file(file);
    if (id_empty(_file))
        throw EmptyFile();
    while(std::getline(_file, line)){
        checkInpuFile(line);
    }
}
bool BitcoinExchange::id_empty(std::ifstream& pFile)
{
    return pFile.peek() == EOF;
}

int BitcoinExchange::checkYear(int num){
    if (num >= 2009 && num <= 2023)
        return (EXIT_SUCCESS);
    return (EXIT_FAILURE);
}

int BitcoinExchange::checkMonth(int num){
    if (num >= 01 && num <= 12)
        return (EXIT_SUCCESS);
    return (EXIT_FAILURE);
}
int BitcoinExchange::checkDay(int day, int month){
    if (day >= 01 && day <= 31){
        if ((month == 2) && day > 28)
            return (EXIT_FAILURE);
        if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
            return (EXIT_FAILURE);
        return (EXIT_SUCCESS);
    }
    return (EXIT_FAILURE);
}


void BitcoinExchange::checkDate(std::string date){
    
    std::vector<std::string> vec = spliteLine(date, '-');
    std::vector<int> intvec;
    intvec.push_back(atof(vec[0].c_str()));
    intvec.push_back(atof(vec[1].c_str()));
    intvec.push_back(atof(vec[2].c_str()));
    if (checkYear(intvec[0]) == EXIT_FAILURE || checkMonth(intvec[1]) == EXIT_FAILURE || checkDay(intvec[2], intvec[1]) == EXIT_FAILURE){
        _err = date;
        throw BadInput();
    }
    _date = date;
}
const char* BitcoinExchange::Npn::what() const throw() {
    return ("Error: not a positive number.");
}

std::string BitcoinExchange::removeSpace(std::string line){
    std::string _line;
    for(size_t i = 0; i < line.length(); i++){
        if (line[i] != ' '){
            _line.push_back(line[i]);
        }
    }
    return _line;
}


int BitcoinExchange::check(std::string value){
    int plus = 0;
    int camas = 0;
    int point = 0;
    if (value[0] == '-')
        throw Npn();
    for (size_t i = 0; i < value.length(); i++){
        if (!isdigit(value[i]))
            if (value[i] != ',')
                if (value[i] != '.')
                    if (value[i] != '+'){
                        _err  = value;
                        throw BadInput();
                    }
        if (value[i] == '+')
            plus++;
        else if (value[i] == ',')
            camas++;
        else if (value[i] == '.')
            point++;
    }
    
    if ((plus != 0 && plus != 1) || !(((camas == 0 && point == 1) || (point == 0 && camas == 1) || (point == 0 && camas == 0)))){
        _err = value;
        throw BadInput();
    }
    if (!plus)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

const char* BitcoinExchange::ToLarg::what() const throw(){
    return ("Error: too large a number.");
}

void BitcoinExchange::checkValue(std::string value){
    
    if (check(value) == EXIT_SUCCESS)
        value.erase(0,1);
        
    int found = value.find(',');
    
    if (found > 0){
        value[found ] = '.';
    }
    _value = atof(value.c_str());
    if (_value < 0 || _value >  1000)
        throw ToLarg();
}

void BitcoinExchange::checkResultAndPrint(std::string date, double result){
    std::string rslt;
    std::stringstream ss;
    ss << result;
    ss >> rslt;
    if (rslt.length() > 4)
        std::cout << std::setprecision(10) << date << " => " << _value << " = "<< result << std::endl;
    else
        std::cout << date << " => " << _value << " = "<< result << std::endl;
}

void BitcoinExchange::PurePrice(std::string date){
    std::map<std::string, double>::iterator it = _data.find(date);
    if (it != _data.end())
        checkResultAndPrint(date, it->second * _value);
    else{
        // int i = 0;
        std::vector<float> fv; 

        for(std::map<std::string, double>::iterator it = _data.begin(); it != _data.end(); it++){
            std::vector<std::string> input = spliteLine(date, '-');
            std::vector<std::string> data = spliteLine(it->first, '-');
            if (data[0] == input[0] && data[1] == input[1]){
                if (atof(input[2].c_str()) > atof(data[2].c_str()))
                    fv.push_back(atof(data[2].c_str()));
            }
        }
        int tmp = fv[0];
        for (size_t i = 1; i < fv.size(); i++){
            if (tmp < fv[i])
                tmp = fv[i];
        }
        std::stringstream ss;  
        ss<<tmp;  
        std::string s;  
        ss>>s;
        std::string str;
        if (s.length() == 2)
            str = date.substr(0,8) + s;
        else
            str = date.substr(0,8) + "0" + s;
        checkResultAndPrint(date, _data[str] * _value);
    }
        
}

void BitcoinExchange::checkPipe(std::string line){
    int pipe = 0;
    for (size_t i = 0; i < line.length(); i++){
        if (line[i] == '|')
            pipe++;
    }
    if (pipe != 1){
        _err = line;
        throw BadInput();
    }
}

void BitcoinExchange::checkInpuFile(std::string line){
    // std::cout << line << std::endl;
    try{
        if (_inputLines == 0){
            if (line != "date | value")
                _inputLines++;
        }
        if (_inputLines != 0){
            std::string _line = removeSpace(line);
            checkPipe(line);
            std::vector<std::string> vec= spliteLine(_line, '|');
            checkDate(vec[0]);
            checkValue(vec[1]);
            PurePrice(_date);
        }
        
    }
    catch (std::exception & e){
        const char * r = "Error: bad input => ";
        std::cout << e.what();
        if (e.what() == r)
            std::cout << _err ;
        std::cout << std::endl;
    }
    _inputLines++;
}

const char* BitcoinExchange::EmptyFile::what() const throw(){
    return ("ERROR: \n\t The file is empty or didn't has permission or is not find it!");
}


std::vector<std::string> BitcoinExchange::spliteLine(std::string line, char sp){
    std::string _line;
    std::vector<std::string> vec;
    std::stringstream ss;
    ss << line;
    while (std::getline(ss, _line, sp)){
        vec.push_back(_line);
    }
    return (vec);
}

