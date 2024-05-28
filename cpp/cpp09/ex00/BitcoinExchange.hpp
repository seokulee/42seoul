#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <string>

class BitcoinExchange
{
private:
    std::map<std::string, double> mData;
public:
    BitcoinExchange();
    ~BitcoinExchange();
    void readData(const std::string &filename);
    void printData() const;
    void checkDate(const std::string &date) const;
    void checkValue(const double &value) const;
};

#endif
