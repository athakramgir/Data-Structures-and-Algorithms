#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 0;
    cout << "Enter n" << endl;
    cin >> n;
    int array[n];
    cout << "Enter the elements of the array " << endl;
    for(int i = 0; i < n; i++) {
        cin >> array[i];
    }
    int count = 0;
    int element;
    for(int i = 0; i < n; i++) {
        if(count == 0) {
            element = array[i];
            count = 1;
        }
        else if(element == array[i]) {
            count ++;
        }
        else{
            count --;
        }
    }
    cout << "Ans = " << element;
    //verification
    int count1 = 0;
    for(int i = 0; i < n; i++) {
        if(array[i] == element) {
            count1 += 1;
        }
    }
    if(count1 > n/2) {
        // cout << "Ans = " << element; 
    }


    return 0;
}