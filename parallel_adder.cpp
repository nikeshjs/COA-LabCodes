//Program to find the sum of 4-bit binary numbers
#include<iostream>
#include<string>
#include<conio.h>
using namespace std;
int main(){
    string a_bin, b_bin;
    int carry = 0;  //Input and output variables can be of bool type.
    string result = "";

    //Get 4-bit binary numbers
    cout << "Enter first 4-bit binary number: ";
    cin >> a_bin;
    cout << "Enter second 4-bit binary number: ";
    cin >> b_bin;

    //Ripple adder logic
    for(int i=3;i>=0;i--){
        int a_bit = a_bin[i] - '0';     //Converts char to int
        int b_bit = b_bin[i] - '0';

        //Full adder logic
        int sum_bit = (a_bit ^ b_bit) ^ carry;
        int new_carry = (a_bit & b_bit) | (carry & (a_bit ^ b_bit));
        result = to_string(sum_bit) + result;
        carry = new_carry;
    }

    bool overflow = carry;
    if(overflow){
        result = "1" + result;     //Show extended 5-bit result
    }

    //Convert binary string to decimal
    int decimal_sum = stoi(result,nullptr,2);

    //Output results
    cout << "Sum (in Binary): " << result << endl;
    cout << "Sum (in Decimal): " << decimal_sum << endl;
    cout << ((overflow) ? "Overflow occured!" : "No overflow.") << endl;

    getch();
    return 0;
}