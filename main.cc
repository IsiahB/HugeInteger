#include "HugeInteger.h"

int main(){
    HugeInteger smallNum1("345678");
    HugeInteger smallNum2("123");
    HugeInteger smallSum;

    HugeInteger big;
    cout << "big: " << big.toString() << endl;

    HugeInteger num1(big);
    cout << "num1(testing copy constr): " << num1.toString() << endl;

    HugeInteger num2("123abc456");
    cout << "num2: " << num2.toString() << endl;

    HugeInteger num3("123456");
    cout << "num3: " << num3.toString() << endl;

    //testing great than
    if(num2 > num1){
        cout << "num2 is greater than num1" << endl;
    }

    //testing equality 
    if(num2 == num3){
        cout << "theSE ARE THE SAME!" << endl;
    }


    if(big.isZero()){
        cout << "The value is 0!!!!!!!!!!!!!!!!" << endl;
    }

    //testing the + operator
    smallSum = smallNum1 + smallNum2;
    cout << smallSum.toString() << endl;



    return 0;
}