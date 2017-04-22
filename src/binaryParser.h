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

    template<typename Out>
    void split(const std::string &s, char delim, Out result);

    template<typename T, typename P>
    T remove_if(T beg, T end, P pred);

    std::vector <std::string> split(const std::string &s, char delim);

    std::string getResult();
};

#endif //BINARYPARSER_H
