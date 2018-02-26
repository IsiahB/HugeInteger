/**
* Isiah Behner
* Programming Assingment 1
* Due: 9/21/17
**/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>
using namespace std;

class HugeInteger{
private:
    vector<int> digits;
public:
    HugeInteger(); //constructor
    HugeInteger(const HugeInteger &); //copy constructor
    HugeInteger(const string &); //1 argument constructor

    bool operator==(const HugeInteger &);
    const HugeInteger operator+(const HugeInteger &);
    bool operator>(const HugeInteger &);

    bool isZero() const;
    string toString() const;
};