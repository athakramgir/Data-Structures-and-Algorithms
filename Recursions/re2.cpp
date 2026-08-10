#include<iostream>
using namespace std;

void printName(int i, int n){
    if(i > n) return;
    else 
    cout << "Athak Ramgir" << endl;
    printName(i + 1, n);
}
void print1_n(int i, int n){
    if(i > n) return;
    else 
    printf("%d ", i);
    print1_n(i + 1, n);
}
void printn_1(int i, int n){
    if(i <= 0) return;
    else
    cout << i << " ";
    printn_1(i - 1, n);
}
void print1_n_backtracking(int i, int n){
    if(i < 1) return; 
    else 
    print1_n_backtracking(i - 1, n);
    cout << i << " ";
}
void printn_1_backtracking(int i, int n){
    if(i > n) return;
    else 
    printn_1_backtracking(i + 1, n);
    cout << i << " ";
}

int main(){
    int n = 0;
    cin >> n;
    printn_1_backtracking(1, n);
    return 0;
}