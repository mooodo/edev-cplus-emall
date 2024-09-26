#ifndef VALID_EXCEPTION_H
#define VALID_EXCEPTION_H
#include <iostream>
#include <string>
#include <exception>
using namespace std;
class ValidException: exception
{
private:
    string msg;
public:
    ValidException(string msg) {
        this->msg = ">>>error: "+msg;
        cout << this->msg << endl;
    }
    ~ValidException() throw() {}
    const char* what() const throw() {
        return msg.c_str();
    }
};

#endif