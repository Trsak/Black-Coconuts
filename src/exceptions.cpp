/**
 * @file exceptions.cpp
 * @author Tomas Odehnal xodehn08
 */


using namespace std;

class DivideByZeroException: public exception{
public:
    const char* what() const throw() override  {
        return "Cannot divide by zero!";
    }
};