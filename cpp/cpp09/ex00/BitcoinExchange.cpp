#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : mData(other.mData) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this == &other)
        return *this;
    mData = other.mData;
    return *this;
}

void BitcoinExchange::run(std::string const &inputFile)
{
    try{
        readData();
        validateInputFile(inputFile);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    calculateValue(inputFile);
}

void BitcoinExchange::readData()
{
    std::ifstream file("data.csv");
    std::string line;
    std::string date;
    double value;
    char *end;

    if (!file.is_open())
        throw std::runtime_error("data.csv file not found");

    if (std::getline(file, line).eof())
        throw std::runtime_error("data.csv file is empty");
    while (std::getline(file, line))
    {
        date = line.substr(0, line.find(','));
        if (!isValidDate(date))
            throw std::runtime_error("Invalid date in data.csv");

        value = std::strtod(line.substr(line.find(',') + 1).c_str(), &end);
        if (!isValidValue(value, end))
            throw std::runtime_error("Invalid value in data.csv");

        mData[date] = value;
    }
    line.erase();
    file.close();
}

bool BitcoinExchange::isValidDate(std::string const &date)
{
    if (date.length() != 10)
        return false;

    int year;
    int month;
    int day;
    char *end;

    year = std::strtol(date.substr(0, 4).c_str(), &end, 10);
    if (*end != '\0' || year < 1000 || year > 2024)
        return false;
    month = std::strtol(date.substr(5, 2).c_str(), &end, 10);
    if (*end != '\0' || month < 1 || month > 12)
        return false;
    day = std::strtol(date.substr(8, 2).c_str(), &end, 10);
    if (*end != '\0' || day < 1 || day > 31)
        return false;

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
    {
        if (month == 2 && day > 29)
            return false;
    }
    else if (month == 2 && day > 28)
        return false;
    return true;
}

bool BitcoinExchange::isValidValue(double value, char *end)
{
    if (*end != '\0' || value < 0 || value > std::numeric_limits<int>::max())
        return false;
    return true;
}

void BitcoinExchange::validateInputFile(std::string const &inputFile)
{
    std::ifstream file;
    std::string line;

    file.open(inputFile, std::ifstream::in);
    if (!file.is_open())
        throw std::runtime_error("input.txt file not found");

    if (std::getline(file, line).eof())
        throw std::runtime_error("input.txt file is empty");

    if (line.compare("date | value") != 0)
        throw std::runtime_error("Wrong format in input.txt");

    line.erase();
    file.close();
}

void BitcoinExchange::calculateValue(std::string const &inputFile)
{
    std::ifstream file;
    std::string line;
    std::string date;
    double value;
    char *end;

    file.open(inputFile, std::ifstream::in);
    // for the first line
    std::getline(file, line);
    while (std::getline(file, line))
    {
        date = line.substr(0, line.find('|') - 1);
        if (!isValidDate(date))
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        value = std::strtod(line.substr(line.find('|') + 1).c_str(), &end);
        if (!isValidValue(value, end))
        {
            if (value <= 0)
                std::cerr << "Error: Not a positive number." << std::endl;
            else if (value > std::numeric_limits<int>::max())
                std::cerr << "Error: Too large a number" << std::endl;
            continue;
        }
        printResult(date, value);
    }
    line.erase();
    file.close();
}

void BitcoinExchange::printResult(std::string const &date, double value)
{
    std::map<std::string, double>::iterator it;
    double propValue;

    propValue = 0;
    it = this->mData.find(date);
    if (it == this->mData.end())
    {
        it = this->mData.upper_bound(date);
        if (it == this->mData.begin())
        {
            std::cerr << "Error: No data for this date." << std::endl;
            return;
        }
        --it;
    }
    propValue = it->second * value;
    std::cout << date << " => " << value << " = " << propValue << std::endl;
}
