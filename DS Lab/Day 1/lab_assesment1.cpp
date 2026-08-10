#include<bits/stdc++.h>
using namespace std;
int findingMinimum(int array[], int n){
    int min = array[0];
    for(int i = 1; i < n; i ++){
        if(array[i] < min){
            min = array[i];
        }
    }
    return min; 
}
int findingMaximum(int array[], int n){
    int max = array[0];
    for(int i = 1; i < n; i++){
        if(array[i] > max){ 
            max = array[i];
        }
    }
    return max;
}
int duplicate(int array[], int n){// sort array in ascending order and then identify elements alike which are side by side
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(array[i] > array[i + 1]){
                swap(array[i], array[i + 1]);
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(array[i] == array[i + 1]){
            return array[i];
        }
    }

}
int sumOfAllElements(int array[], int n){
    int sum = 0; 
    for(int i = 0; i < n; i++){
        sum += array[i];
    }
    return sum;
}


int main(){
    int n = 0; 
    cout << "Enter the value of n" << endl;
    cin >> n;
    int array[n];
    for(int i = 0; i < n; i ++){
        cin >> array[i] ;
    }
    cout << "The minimum of the given array is " << findingMinimum(array, n) << endl;
    cout << "The maximum of the given array is " << findingMaximum(array, n) << endl;
    cout << "The duplicate element of the array is " << duplicate(array, n) << endl;
    return 0;

}