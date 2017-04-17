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
    if(exp == 0) {
        if(operand != 0) return 1;
        else return numeric_limits<double>::quiet_NaN();
    }
    if(exp < 0) {
        throw invalid_argument("Exponent must be bigger or equal to 0.");
    }

    double result = 1;
    for(int i=1; i<=exp; i++) {
        result *= operand;
    }
    return result;
}

double Math_lib::general_sqrt(double base, double exponent) {

}

unsigned long long Math_lib::factorial(int n) {
    if(n>20) {
        throw overflow_error("Overflow of number in factorial!");
    }
    if(n < 0) {
        throw invalid_argument("Number must be bigger or equal to 0.");
    }
    unsigned long long factorial = 1;
    for(int i=1; i<=n; i++) {
        factorial *= i;
    }
    return factorial;
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