/**
 * @file binaryParser.h
 * @author Petr Sopf (xsopfp00)
 * @brief Binary parser for bitwise operations
 * Parse operations and operands from string and returns result of bitwise operations as string.
 */
#ifndef BINARYPARSER_H
#define BINARYPARSER_H

#include <string>
#include <vector>

using namespace std;

class binaryParser {
public:
    /**
     * @brief Vector of bitwise operations in string
     */
    std::vector <std::string> operations;

    /**
     * @brief Number of operations
     */
    unsigned int operationsN;

    /**
     * @brief Constructor, calls other functions
     * @param str Input string
     */
    binaryParser(std::string str);

    /**
     * @brief Checks if string contains only 0 and 1
     * @param str String to check
     * @return Returns result of checks
     */
    bool isBinaryNumber(std::string str);

    /**
     * @brief Checks if string is bitwise operator
     * @param str String to check
     * @return Returns result of checks
     */
    bool isOperator(std::string str);

    /**
     * @brief Calls math lib function for bitwise operation
     * @param op Bitwise operation
     * @param res First operand
     * @param num Second operand
     * @return Returns result of bitwise operation
     */
    std::string doOperation(std::string op, std::string res, std::string num);

    /**
     * @brief Removes spaces from string
     * @param input String to remove spaces in
     * @return Returns string String without spaces
     */
    std::string removeSpaces(std::string input);

    /**
     * @brief Splits string by delimeter
     * @param s String
     * @param delim delimeter
     * @param result vector where splitted strings will be
     * @return Returns splitted strings
     */
    template<typename Out>
    void split(const std::string &s, char delim, Out result);

    /**
     * @brief Foreach all elements, remove those for pred returns true
     * @param beg First position of elements
     * @param end Last position of elements
     * @param pred delimeter
     * @return Returns not removed elements
     */
    template<typename T, typename P>
    T remove_if(T beg, T end, P pred);

    /**
     * @brief Splits string by delimeter
     * @param s String
     * @param delim delimeter
     * @return Returns splitted strings
     */
    std::vector <std::string> split(const std::string &s, char delim);

    /**
     * @brief Calls other functions to get result from input
     * @return Returns result of input
     */
    std::string getResult();
};

#endif //BINARYPARSER_H
