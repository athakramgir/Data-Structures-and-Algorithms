#include<iostream>
using namespace std;

int main(){
    int n = 0;
    cout<< " Enter a number \n";
    cin >> n; 
    int count = 0; 
    if(n == 0){
        count = 1; 
    } 
    while(n != 0){
        n /= 10;
        count ++;
    }
    
    cout << count; 
}