#include<bits/stdc++.h>
using namespace std;


int sumOfMinimumOfSubArrays(int array[], int n) {
    int sum = 0; 
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            int min = array[j];
            for(int k = j; k < n; k++) {
                if(array[k] < min) {
                    min = array[k];
                }
            }
            sum += min;
            
        }
    }
}
int main(){
    
    return 0;
}