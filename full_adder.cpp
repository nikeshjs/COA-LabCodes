#include<iostream>
#include<conio.h>
using namespace std;
int main(){
    int a,b,c;  // 3-bit Input bits
    int sum,carry;

    //Take inputs of the input bits a,b and c
    cout << "Enter input bits a,b and c: " << endl;
    cin >> a >> b >> c;

    cout << "The required value is: " << endl;
    sum = (a^b)^c;  //sum = A⊕B⊕C
    carry = c&(a^b) | (a&b);    //carry = C(A⊕B)+AB

    cout << "Sum is: " << sum << endl;
    cout << "Carry is: " << carry << endl;

    getch();
    return 0;
}