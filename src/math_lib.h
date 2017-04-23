/**
 * @file math_lib.h
 * @author Tomas Odehnal xodehn08
 * @brief Math library that implements basic mathematical functions
 * Math library implements basic arithmetic operations (+,-,*,/), factorial, nth root of number (n is natural number),
 * basic binary operations, power with natural exponent.
 */

#ifndef BLACK_COCONUTS_MATH_LIB_H
#define BLACK_COCONUTS_MATH_LIB_H

#include <cmath>
#include <limits>
#include <string>
#include <stdexcept>

using namespace std;

class Math_lib
{
public:

    /**
     * @brief Sums operand1 and operand2 and return result.
     * @param operand1 First number to sum.
     * @param operand2 Second number to sum.
     * @return Returns result of sum.
     */
    static double sum(double operand1, double operand2);

    /**
     * @brief Subtracts operand2 from operand1 and return result.
     * @param operand1 Minuend from which is operand2 subtracted.
     * @param operand2 Subtrahend which is subtracted from operand1.
     * @return Returns result of subtraction.
     */
    static double sub(double operand1, double operand2);

    /**
     * @brief Multiplicates operand1 and operand2 and return result.
     * @param operand1 First number to multiplicated.
     * @param operand2 second number to be multiplicated.
     * @return Returns result of multiplication.
     */
    static double mul(double operand1, double operand2);

    /**
     * @brief Divides operand2 from operand1 and return result.
     * @param operand1 Divident from which is divided operand2 divided.
     * @param operand2 Divisor which is divided from operand1.
     * @return Returns result of division.
     * @throw DivideByZeroException When operand2 is equal to 0.
     */
    static double div(double operand1, double operand2);

    /**
     * @brief Makes operand to the power of exp and return result.
     * @param operand Base of power.
     * @param exp Natural exponent.
     * @return Returns result of power or NaN if operand and exp are equal to .
     * @throw invalid_argument When exp si smaller than 0.
     */
    static double natural_power(double operand, int exp);

    /**
     * @brief Multiplies base by itself for exponent values times.
     * @param operand Base of general square.
     * @param exponent Exponent of result.
     * @return Returns result of general square.
     */
    static double general_sqrt(double base, double exponent);

    /**
     * @brief Makes factorial from n and return result.
     * @param n The base of factorial.
     * @return Returns result of factorial.
     * @throw invalid_argument When n is smaller than 0.
     * @throw overflow_error When unsigned long long can't hold the result.
     */
    static unsigned long long factorial(int n);

    /**
     * @brief Makes OR operation with every bit (character) and return result.
     * @param first First operand.
     * @param second Second operand.
     * @return Returns the result of OR operation.
     */
    static string bin_or(string first, string second);

    /**
     * @brief Makes AND operation with every bit (character) and return result.
     * @param first First operand.
     * @param second Second operand.
     * @return Returns the result of AND operation.
     */
    static string bin_and(string first, string second);

    /**
     * @brief Makes NOR operation with every bit (character) and return result.
     * @param first First operand.
     * @param second Second operand.
     * @return Returns the result of NOR operation.
     */
    static string bin_nor(string first, string second);

    /**
     * Makes NAND operation with every bit (character) and return result.
     * @param first First operand.
     * @param second Second operand.
     * @return Returns the result of NAND operation.
     */
    static string bin_nand(string first, string second);

    /**
     * @brief Makes Exclusive OR operation with every bit (character) and return result.
     * @param first First operand.
     * @param second Second operand.
     * @return Returns result of Exclusive OR operation.
     */
    static string bin_xor(string first, string second);

    /**
     * @brief Makes Non Exclusive OR operation with every bit (character) and return result.
     * @param first First operand.
     * @param second Second operand.
     * @return Returns result of Non Exclusive OR operation.
     */
    static string bin_xnor(string first, string second);

    /**
     * @brief Makes NOT operation with every bit (character) and return result.
     * Inverts every bit in operand.
     * @param operand Input operand.
     * @return Returns result of NOT operation.
     */
    static string bin_not(string operand);

private:
    /**
     * Calculate an exponential function with general base (x).
     * This function using function general logarithm.
     *
     * NOTE: This function is used from IZP from second project and is my work (xodehn08).
     * @param x General base of exponential function.
     * @param y Exponent.
     * @param n Number of iterations to make.
     * @return Return the result of exponential function.
     */
    static double general_pow(double x, double y, unsigned int n);

    /**
     * Calculate a natural logarithm using continual fractions.
     *
     * NOTE: This function is used from IZP from second project and is my work (xodehn08).
     * @param x Number from which is calculated the logarithm.
     * @param n Number of iterations to make.
     * @return Return the result of general logarithm.
     */
    static double cfrac_log(double x, unsigned int n);
};

/*** End of file math_lib.h ***/

#endif //BLACK_COCONUTS_MATH_LIB_H