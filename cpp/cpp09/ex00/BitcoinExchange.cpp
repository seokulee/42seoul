#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::readData(const std::string &filename)
{
    std::ifstream fs;
    char *endptr = NULL;
    std::string date;
    std::string str_value;
    double value;

    fs.open(filename.c_str());
    if (!fs.is_open())
    {
        throw std::invalid_argument("Could not open file");
    }

    std::string format = "date | value";
    std::string line;
    std::getline(fs, line);
    if (strcmp(line.c_str(), format.c_str()))
    {
        throw std::invalid_argument("Invalid file format. Missing 'date | value'");
    }
    while (std::getline(fs, line))
    {
        date = line.substr(0, line.find(" | "));
        str_value = line.substr(line.find(" | ") + 3);
        value = std::strtod(str_value.c_str(), &endptr);
        std::cout << date << " | " << value << std::endl;
        std::cout <<  endptr << std::endl;

        if (endptr != NULL)
        {
            std::cout << "Error: not a positive number" << std::endl;
            continue;
        }
        checkDate(date);
        checkValue(value);
    }
}

void BitcoinExchange::printData() const
{
    for (std::map<std::string, double>::const_iterator it = mData.begin(); it != mData.end(); ++it)
    {
        std::cout << it->first << " | " << it->second << std::endl;
    }
}

void BitcoinExchange::checkDate(const std::string &date) const
{
    size_t pos1;
	size_t pos2;
	std::string date_day;
	std::string date_month;
	std::string date_year;

	pos1 = date.find("-");
    date_year = date.substr(0, pos1);
    pos2 = date.find("-", pos1 + 1);
    date_month = date.substr(pos1 + 1, pos2 - pos1 - 1);
    date_day = date.substr(pos2 + 1);
	if(date_year.length() == 4 || date_month.length() == 2 || date_day.length() == 2)
	{
		if(std::atoi(date_year.c_str()) <= 2008)
            throw std::invalid_argument("Invalid date");
		else if(std::atoi(date_month.c_str()) > 12 || std::atoi(date_month.c_str()) < 1)
            throw std::invalid_argument("Invalid date");
        else if(std::atoi(date_day.c_str()) > 31 || std::atoi(date_day.c_str()) < 1)
            throw std::invalid_argument("Invalid date");
        else if(std::atoi(date_year.c_str()) == 2009 && std::atoi(date_month.c_str()) == 1 && std::atoi(date_day.c_str()) == 1)
            throw std::invalid_argument("Invalid date");
        else if(std::atoi(date_year.c_str()) > 2022)
            throw std::invalid_argument("Invalid date");
        else
            return ;
	}
	else
		throw std::invalid_argument("Invalid date");
}

void BitcoinExchange::checkValue(const double &value) const
{
    if (value <= 0 || value > 1000)
    {
        throw std::invalid_argument("Invalid value");
    }
}
