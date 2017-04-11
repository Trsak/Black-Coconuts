/**
 * @file math_lib.cpp
 * @author Tomas Odehnal xodehn08
 */

#include "math_lib.h"
#include <string>
#include "exceptions.cpp"


double Math_lib::sum(double operand1, double operand2) {
    return operand1 + operand2;
}

double Math_lib::sub(double operand1, double operand2){
    return operand1 - operand2;
}

double Math_lib::mul(double operand1, double operand2) {
    return operand1 * operand2;
}

double Math_lib::div(double operand1, double operand2) {
    if(operand2 == 0.0) {
        throw DivideByZeroException();
    }
    return operand1 / operand2;
}

double Math_lib::natural_power(double operand, int exp) {

}

double Math_lib::general_sqrt(double base, double exponent) {

}

long Math_lib::factorial(int n) {

}

string Math_lib::bin_or(string first, string second) {

}

string Math_lib::bin_and(string first, string second) {

}

string Math_lib::bin_nor(string first, string second) {

}

string Math_lib::bin_nand(string first, string second) {

}

string Math_lib::bin_xor(string first, string second) {

}

string Math_lib::bin_xnor(string first, string second) {

}

string Math_lib::bin_not(string operand) {

}