/**
 * @file exceptions.cpp
 * @author Tomas Odehnal xodehn08
 */

#include <exception>

class DivideByZeroException: public exception {
    virtual const char* what() const throw() {
        return "Cannot divide by zero!";
    }
};