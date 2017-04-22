#include <binaryParser.h>
#include <math_lib.h>
#include <algorithm>

binaryParser::binaryParser(std::string str) {
    operationsN = split(str, operations, ' ');
}

unsigned int binaryParser::split(const std::string &txt, std::vector <std::string> &strs, char ch) {
    unsigned int pos = txt.find(ch);
    unsigned int initialPos = 0;
    strs.clear();

    // Decompose statement
    while (pos != std::string::npos) {
        strs.push_back(txt.substr(initialPos, pos - initialPos + 1));
        initialPos = pos + 1;

        pos = txt.find(ch, initialPos);
    }

    // Add the last one
    strs.push_back(txt.substr(initialPos, std::min(pos, txt.size()) - initialPos + 1));

    return strs.size();
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

std::string binaryParser::removeSpaces(std::string input) {
    input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end());
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
