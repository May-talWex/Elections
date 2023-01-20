#ifndef ASSIGNMENT5_ERROR_H
#define ASSIGNMENT5_ERROR_H

#include <iostream>
using namespace std;

class Error {
public:
    virtual ~Error(){}
    virtual void handle()const = 0;
};

class dataErr: public Error{
public:
    virtual ~dataErr(){}
    virtual void handle()const{ cout << "Please enter valid details" << endl;}
};


#endif //ASSIGNMENT5_ERROR_H
