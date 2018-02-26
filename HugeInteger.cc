#include "HugeInteger.h"
#include <cctype>

//constructor
HugeInteger::HugeInteger(){
    digits = {0};
}

//copy constructor
HugeInteger::HugeInteger(const HugeInteger &other){
   digits = other.digits;
}

//single argument constructor
HugeInteger::HugeInteger(const string &s){
    
    for(int i = 0; i < s.length(); i++){
        if(isdigit(s.at(i))){
            digits.push_back(s.at(i)-'0'); //subtracting the askii values of the string represenations of the number
        }
    }
}

//overloading the operator ==
bool HugeInteger::operator==(const HugeInteger &rightSide){
    if(this->digits == rightSide.digits)
    return true;
}


//overloading the operator + (works, but not quite)
const HugeInteger HugeInteger::operator+(const HugeInteger &rightSide){
	vector<int> max = this->digits;
	vector<int> min = rightSide.digits;

	if (max.size() < min.size()) {
		max.swap(min);
	}
	
	//vector holding the sum
	HugeInteger sum;
	int holdingItem = 0;

	for (int i = 0; i < min.size(); i++) {
		int c = min[i] + max[i] + holdingItem;
		sum.digits.push_back(c % 10);
		holdingItem = c / 10;
	}

	for (int i = min.size(); i < max.size(); i++) {
		int c = max[i] + holdingItem;
		sum.digits.push_back(c % 10);
		holdingItem = c / 10;
	}
	while (holdingItem > 0) {
		sum.digits.push_back(holdingItem % 10);
		holdingItem /= 10;
	}

	return sum;
}


//overloading the operator >
bool HugeInteger::operator>(const HugeInteger &rightSide){
    if(this->digits.size() > rightSide.digits.size()){
        return true;
    }

    if(this->digits.size() == rightSide.digits.size()){
        for(int i = 0; i < this->digits.size(); i++){
            if(this->digits.at(i) > rightSide.digits.at(i)){
                return true;
            }
        }
    }

    return false;
}


//method that checks if the vector is empty
bool HugeInteger::isZero() const{
    if(this->digits[0] == 0){
        return true;
    }
}


//method that prints the elements in the vector
string HugeInteger::toString() const{
    stringstream stream;
    for(int i = 0; i < digits.size(); i++){
        stream << digits.at(i);
    }
    string result = stream.str(); //converts stream to c++ string object
    return result;
}

