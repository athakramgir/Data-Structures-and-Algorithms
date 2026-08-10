#include<iostream>
using namespace std;

int main(){
    int n; 
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    cout<<"Printing count from 1 to n"<<endl;
    
    // for(int i = 1; i <= n; i++){
    //     cout<< i <<endl;
    // }

    // int i = 1;
    // for(; ;){
    //     if(i <= n){
    //     cout<< i <<endl;
    //     i++;}
    //     else if ( i > n){
    //         break;
    //     }
    // }

    // Using multiple variables in for loops
    for(int a = 10, b = 11; a >= 0 && b >= 1; a--, b-- ){
        cout<<a <<" "<< b <<endl;
    }
    // return 0;
}