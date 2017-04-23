/**
 * @file binaryParser.h
 * @author Petr Sopf (xsopfp00)
 */
#include <binaryParser.h>
#include <math_lib.h>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>

binaryParser::binaryParser(std::string str) {
    operations = split(str, ' ');
}


template<typename Out>
void binaryParser::split(const std::string &s, char delim, Out result) {
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}

std::vector<std::string> binaryParser::split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

bool binaryParser::isBinaryNumber(std::string str) {
    for (unsigned int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (c != '0' && c != '1' && c != ' ') {
            return false;
        }
    }

    return true;
}

bool binaryParser::isOperator(std::string str) {
    if (str == "OR" || str == "NOR" || str == "AND" || str == "NAND" || str == "XOR" || str == "XNOR") {
        return true;
    }

    return false;
}

std::string binaryParser::doOperation(std::string op, std::string res, std::string num) {
    if (op == "OR") return Math_lib::bin_or(res, num);
    else if (op == "NOR") return Math_lib::bin_nor(res, num);
    else if (op == "AND") return Math_lib::bin_and(res, num);
    else if (op == "NAND") return Math_lib::bin_nand(res, num);
    else if (op == "XOR") return Math_lib::bin_xor(res, num);
    else if (op == "XNOR") return Math_lib::bin_xnor(res, num);
}

template<typename T, typename P>
T binaryParser::remove_if(T beg, T end, P pred)
{
    T dest = beg;
    for (T itr = beg;itr != end; ++itr)
        if (!pred(*itr))
            *(dest++) = *itr;
    return dest;
}

std::string binaryParser::removeSpaces(std::string input) {
    input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());
    return input;
}

std::string binaryParser::getResult() {
    std::string res = "";
    bool err = false;

    unsigned int i = 0;
    for (std::string s : operations) {
        operations[i] = removeSpaces(s);
        ++i;
    }

    if (!isBinaryNumber(operations[0])) {
        res = "ERROR: Only binary mode!";
        err = true;
    } else {
        res = operations[0];
    }

    if (!err) {
        for (unsigned int i = 1; i < operations.size(); i += 2) {
            if (!isOperator(operations[i])) {
                res = "ERROR: Bad input format!";
                err = true;
                break;
            } else {
                if (!isBinaryNumber(operations[i + 1])) {
                    res = "ERROR: Only binary mode!";
                    err = true;
                    break;
                } else {
                    res = doOperation(operations[i], res, operations[i + 1]);
                }
            }
        }
    }

    return res;
}
