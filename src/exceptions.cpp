/**
 * @file exceptions.cpp
 * @author Tomas Odehnal xodehn08
 * @brief This file contains exceptions
 */

#include <stdexcept>

using namespace std;

class DivideByZeroException: public exception{
public:
    const char* what() const throw() override  {
        return "Cannot divide by zero!";
    }
};

/*** End of file exceptions.cpp ***/