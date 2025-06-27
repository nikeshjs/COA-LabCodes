#include<iostream>
#include<string>
using namespace std;
int main(){
    string A,B;
    cout << "Enter 4-bit binary Minuend (A): ";
    cin >> A;
    cout << "Enter 4-bit binary Subtrahend (B): ";
    cin >> B;
    cout << "Minuend (A): " << A << endl;
    cout << "Subtrahend (B): " << B << endl;

    //Step1: 1's complement of B
    string B_1s = "";
    for(int i=0;i<4;++i){
        B_1s += (B[i] == '0') ? '1':'0';
    }
    cout << "1's complement of B: " << B_1s << endl;

    //Step2: 2's complement of B (B_1s + 1) using full adder logic
    string one = "0001";
    string result_2s = "";
    int carry = 0;

    //Binary addition
    for(int i=3;i>=0;--i){
        int a = B_1s[i] - '0';
        int b = one[i] - '0';
        int sum_bit = (a^b)^carry;
        int carry_out = (a & b) | (b & carry) | (a & carry);
        result_2s = char(sum_bit + '0') + result_2s;
        carry = carry_out;
    }
    cout << "2's complement of B: " << result_2s << endl;

    //Step3: Add A and 2's complement of B using full adder logic
    string result_sum = "";
    carry = 0;
    for(int i=3;i>=0;--i){
        int a = A[i] - '0';
        int b = result_2s[i] - '0';
        int sum_bit = (a^b)^carry;
        int carry_out = (a & b) | (b & carry) | (a & carry);
        result_sum = char(sum_bit + '0') + result_sum;
        carry = carry_out;
    }
    cout << "Sum (A+B): " << result_sum << "Carry-out: " << carry << endl;

    if(carry == 1){
        cout << "Result (A-B): " << result_sum << " (Positive)" << endl;
        cout << "Result (A-B) in decimal: " << stoi(result_sum,nullptr,2) << " (Positive)" << endl;
    }
    else{
        //Negative result, find magnitude by 1's complement of result_sum
        string result_1s = "";
        for(int i=0;i<4;++i){
            result_1s += (result_sum[i] == '0') ? '1':'0';}

        string magnitude = "";
        carry = 0;
        for(int i=3;i>=0;--i){
            int a = result_1s[i] - '0';
            int b = one[i] - '0';
            int sum_bit = (a^b)^carry;
            int carry_out = (a & b) | (b & carry) | (a & carry);
            magnitude = char(sum_bit + '0') + magnitude;
            carry = carry_out;
        }
        cout << "Result (A-B): " << magnitude << " (Negative)" << endl;
        cout << "Result (A-B) in decimal: " << stoi(magnitude,nullptr,2) << " (Negative)" << endl;
    }
    return 0;
 }