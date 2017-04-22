#ifndef BINARYPARSER_H
#define BINARYPARSER_H

#include <string>
#include <vector>

using namespace std;

class binaryParser {
public:
    std::vector <std::string> operations;
    unsigned int operationsN;

    binaryParser(std::string str);

    bool isBinaryNumber(std::string str);

    bool isOperator(std::string str);

    std::string doOperation(std::string op, std::string res, std::string num);

    std::string removeSpaces(std::string input);

    unsigned int split(const std::string &txt, std::vector <std::string> &strs, char ch);

    std::string getResult();
};

#endif //BINARYPARSER_H
