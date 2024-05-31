#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cstring>

// data.csv: parsing, store it in mData
// input.txt: parsing, check validation
// --> date, value(input) check
// matching invalid input values with mData, Errors handling
// output -> print the value of the bitcoin on the date
class BitcoinExchange
{
private:
    std::map<std::string, double> mData;
    void readData();
    void validateInputFile(std::string const &inputFile);
    bool isValidDate(std::string const &date);
    bool isValidValue(double value, char *end);
    void calculateValue(std::string const &inputFile);
    void printResult(std::string const &date, double value);

public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);

    void run(std::string const &inputFile);
};

#endif
