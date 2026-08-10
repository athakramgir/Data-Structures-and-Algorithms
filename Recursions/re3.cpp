#include<iostream>
using namespace std;


void sumN(int i, int sum){
    if(i < 1){
        cout << sum << endl;
        return;
    }
    sumN(i - 1, sum + i);
}
int sum(int n){
    if(n == 0) return 0;
    else return n + sum(n - 1);
}
int factorial(int n){
    if(n <= 1){
        return 1;
    }
    else {
        return n*factorial(n - 1);
    }
}
void factorial_parametrised(int i, int fact){
    if(i <= 1){
        cout << fact << endl;
        return;
    }
    factorial_parametrised(i - 1, fact*i);
}


int main(){
    int n = 0; 
    cout <<"Enter n" << endl;
    cin >> n;
    factorial_parametrised(5, 1);
    return 0;
}