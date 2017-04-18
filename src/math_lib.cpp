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
        return 1;
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
    return Math_lib::general_pow(base, exponent, 10000);
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

double Math_lib::general_pow(double x, double y, unsigned int n) {
    double taylor = 1.0;
    double old_taylor = 1.0;

    /* Limits */
    if(x == 0.0 && y == 0.0)
        return 1.0;
    else if(x == 1.0 || y == 0.0 || y == -0.0)
        return 1.0;
    else if(x == -0.0 || x == 0.0) {
        if(y < 0)
            return INFINITY;
        else if((int)y % 2 == 0 || (int)y < y)
            return fabs(x);
        else
            return x;
    }
    else if(x < 0)
        return NAN;
    else if(x == -1.0 && isinf(y))
        return 1.0;
    else if(fabs(x) < 1 && isinf(y) < 0)
        return INFINITY;
    else if(fabs(x) > 1 && isinf(y) < 0)
        return 0.0;
    else if(fabs(x) < 1 && isinf(y) > 0)
        return 0.0;
    else if(fabs(x) > 1 && isinf(y) > 0)
        return INFINITY;
    else if(y < 0 && isinf(x) > 0)
        return 0.0;
    else if(y > 0 && isinf(x) > 0)
        return INFINITY;

    /* Main calculation */
    for(unsigned int i = 1; i <= n; i++) {
        old_taylor *= y * Math_lib::cfrac_log(x, 2200) / i;

        taylor += old_taylor;

        if(isinf(taylor))
            return INFINITY;
        else if(isnan(taylor))
            return NAN;
    }
    return taylor;
}

double Math_lib::cfrac_log(double x, unsigned int n) {
    unsigned int a = 1 + 2 * (n-1);
    double cf = 0.0;
    double z = (1-x)/(-x-1);
    double pow_z = z * z;

    /* Limits */
    if(isinf(x) > 0)
        return INFINITY;
    else if(x < 0 || isnan(x))
        return NAN;
    else if(x == 0)
        return -INFINITY;
    else if(x == 1)
        return 0;

    /* Main calculation */
    for(n = n-1; n; n--) {
        cf = (n*n * pow_z) / (a - cf);
        a -= 2;
        if(isinf(cf))
            return INFINITY;
        else if(isnan(cf))
            return NAN;
    }
    cf = (2*z)/(1-cf);

    return cf;
}