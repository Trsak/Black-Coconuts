#include <iostream>
#include <stdio.h>
#include <cstdlib>

using namespace std;

double fRand(double fMin, double fMax) {
    double f = (double) rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

void doProfiling(int n) {
    float elements[n];

    for (int i = 0; i < n; ++i) {
        elements[i] = fRand(0.0, 1000.0);
    }
}

int main() {
    doProfiling(10);
    doProfiling(100);
    doProfiling(1000);

    return 0;
}