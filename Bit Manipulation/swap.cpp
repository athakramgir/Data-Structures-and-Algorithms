#include<bits/stdc++.h>
using namespace std;

int main(){
    int a = 10;
    int b = 12;
    a = a^b;
    b = a^b;
    a = a^b;

    cout << a;
    cout << endl << b;
    return 0;
}