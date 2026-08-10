#include<bits/stdc++.h>
using namespace std;
int fib(int n){
    if(n <= 1) return n;
    else 
    return fib(n - 2) + fib(n - 1);
}
int main(){
    int n = 0; 
    cout << "Enter n" << endl;
    cin >> n;
    cout << fib(n);
    return 0;
}