#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
    try
    {
        if (argc != 2)
        {
            throw std::invalid_argument("Usage: ./btc <filename>");
        }
        BitcoinExchange exchange;
        std::string filename = argv[1];
        exchange.readData(filename);
        exchange.printData();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
