#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {
	if (argc != 4) {
		std::cout << "./replace filename s1 s2" << std::endl;
		return (1);
	}

	std::string fileName = static_cast<std::string> (argv[1]);
	std::string s1 = static_cast<std::string> (argv[2]);
	std::string s2 = static_cast<std::string> (argv[3]);
	std::string line;
	std::string str;
	std::string tmp;
	std::size_t cur;
	std::size_t startPos;

	std::ifstream inputFile(argv[1]);
	if (!inputFile.is_open()) {
		std::cerr << "Error: could not open file" << std::endl;
		return (1);
	}
	std::ofstream outputFile(fileName.append(".replace").c_str());
	while (std::getline(inputFile, line)) {
		str = "";
		startPos = 0;
		cur = 0;
		cur = line.find(s1, startPos);
		while (cur != std::string::npos) {
			tmp = "";
			tmp = line.substr(startPos, cur - startPos);
			str.append(tmp).append(s2);
			startPos = cur + s1.length();
			cur = line.find(s1, startPos);
		}
		str.append(line , startPos);
		outputFile << str << '\n';
	}
	inputFile.close();
	outputFile.close();
	return (0);
}
