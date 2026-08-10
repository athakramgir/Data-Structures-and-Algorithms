#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 0; 
    cout << "Enter n" << endl;
    cin >> n;
    int array[n];
    cout << "Enter the elements of the array" << endl;
    for(int i = 0; i < n; i++){
        cin >> array[i];
    }
    // linear search 
    int target = 0; 
    cout << "Enter the target " << endl;
    cin >> target;
    for(int i = 0; i < n; i++){
        if(array[i] == target){
            cout << array[i] << " " << i;
        }
    }
    return 0;
}