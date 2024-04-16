#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cout << "Usage: " << argv[0] << " <file_name> <old_value> <new_value>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string old_value = argv[2];
    std::string new_value = argv[3];
    std::string content;

    if (old_value.empty())
    {
        std::cerr << "Error: old_value is empty" << std::endl;
        return 1;
    }

    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open())
    {
        std::cerr << "Error: could not open file: " << filename << std::endl;
        return 1;
    }
    std::string outputFilename = filename + ".replace";
    std::ofstream outputFile(outputFilename.c_str());
    if (!outputFile.is_open())
    {
        std::cerr << "Error: could not create file: " << filename << std::endl;
        return 1;
    }

    std::stringstream buffer;
    // basic filebuf라는 객체 주소를 반환
    buffer << inputFile.rdbuf();
    // string으로 변환
    content = buffer.str();
    inputFile.close();

    size_t pos = 0;
    while ((pos = content.find(old_value, pos)) != std::string::npos)
    {
        content.erase(pos, old_value.length());
        content.insert(pos, new_value);
        pos += new_value.length();
    }
    outputFile << content;
    // 파일은 RAII로 자동으로 닫히므로 close()를 호출할 필요가 없다.
    outputFile.close();

    return 0;
}
