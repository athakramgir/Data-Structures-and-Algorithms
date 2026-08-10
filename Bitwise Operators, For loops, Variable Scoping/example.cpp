#include<iostream>
using namespace std;

int main(){
    int a = 4;
    int b = 6;
    // Logical Bitwise
    cout<<" a&b "<< (a&b)<< endl;
    cout<<" a|b "<< (a|b)<< endl;
    cout<<" ~a "<< ~a <<endl;
    cout<<" a ^ b "<< (a^b) <<endl;
cout<<endl;
    // Left shift (x2) and right shift (/2) for small numbers 
    cout<< ( 17 >> 1) <<endl;
    cout<< ( 17 >> 2) <<endl;
    cout<< ( 19 << 1) <<endl;
    cout<< ( 21 << 2) <<endl;
cout<<endl;
    // Increment and Decrement Operators
    int i = 1; 
    cout<< i ++ <<endl;
    cout<< ++ i <<endl;
    cout<< i -- <<endl;
    cout<< -- i <<endl;

    return 0;
}