#include "ScalarConverter.hpp"

// 98버전 CPP 사용해서 만들기
void ScalarConverter::convert(const std::string &input)
{
    // 입력 예외 처리
    double value;
    try
    {
        char *ptr = NULL;
        value = std::strtod(input.c_str(), &ptr);
        if (*ptr != '\0')
        {
            if (input.size() == 1 && !std::isdigit(input[0]))
                value = static_cast<double>(input[0]);
            else if (strcmp(ptr, "f") != 0 && strcmp(ptr, "F") != 0)
                throw std::invalid_argument("Invalid input");
        }
    } catch (const std::invalid_argument &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return;
    }

    // 특이 케이스 처리
    if (input == "inff" || input == "+inff" || input == "-inff" || input == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << input << std::endl;
        std::cout << "double: " << input.substr(0, input.size() - 1) << std::endl;
        return;
    }
    else if (input == "inf" || input == "+inf" || input == "-inf" || input == "nan")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << input << "f" << std::endl;
        std::cout << "double: " << input << std::endl;
        return;
    }

    // char
    std::cout << "char: ";
    std::isprint(static_cast<char>(value))
        ? std::cout << "'" << static_cast<char>(value) << "'" << std::endl : std::cout << "Non displayable" << std::endl;

    // int
    std::cout << "int: ";
    (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
        ? std::cout << "impossible" << std::endl : std::cout << static_cast<int>(value) << std::endl;

    // float
    std::cout << "float: ";
    (value > std::numeric_limits<float>::max() || value < -std::numeric_limits<float>::max())
        ? std::cout << "impossible" << std::endl : (static_cast<float>(value) - static_cast<int>(value) == 0)
        ? std::cout << static_cast<float>(value) << ".0f" << std::endl : std::cout << static_cast<float>(value) << "f" << std::endl;

    // double
    std::cout << "double: ";
    (value > std::numeric_limits<double>::max() || value < -std::numeric_limits<double>::max())
        ? std::cout << "impossible" << std::endl : (value - static_cast<int>(value) == 0)
        ? std::cout << value << ".0" << std::endl : std::cout << value << std::endl;
}
