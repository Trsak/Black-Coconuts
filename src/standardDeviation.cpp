/**
 * @file standardDeviation.h
 * @author Petr Sopf (xsopfp00)
 * @brief Standard Deviation
 * Program used for profiling of math library. Calculates Standard Deviation of 10, 100 and 1000 elements.
 */
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <math_lib.h>

using namespace std;

/**
     * @brief Function for random float
     * @param fMin Min value of float
     * @param fMax Max value of float
     * @return Returns random float
     */
double fRand(double fMin, double fMax) {
    double f = (double) rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

/**
     * @brief Calculates Standard Deviation
     * @param m Number of elements
     */
void calculateStandardDeviation(int n) {
    float elements[n];
    float sum = 0.0, mean = 0.0, s = 0.0;

    for (unsigned int i = 0; i < n; ++i) {
        elements[i] = fRand(0.0, 1000.0);
        mean += elements[i];
    }

    mean /= n;


    for (unsigned int i = 0; i < n; i++) {
        sum += Math_lib::natural_power(elements[i] - mean, 2);
    }

    s = sum / (n - 1);
    s = Math_lib::general_sqrt(s, 0.5);
}

/**
     * @Main class
     * Calls function to calculate Standard Deviation of 10, 100 and 1000 elements.
     */
int main() {
    calculateStandardDeviation(10);
    calculateStandardDeviation(100);
    calculateStandardDeviation(1000);

    return 0;
}