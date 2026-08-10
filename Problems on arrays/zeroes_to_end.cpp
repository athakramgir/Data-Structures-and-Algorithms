#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 0; 
    cout << "Enter n " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array" << endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> temp;
    for(int i = 0; i < n; i++) {
        if(arr[i] != 0) {
            temp.push_back(arr[i]);
        }
    }

    for(int i = 0; i < temp.size(); i ++ ){
        arr[i] = temp[i];
    }
    for(int i = temp.size(); i < n; i++) {
        arr[i] = 0; 
    }

    for(int i = 0; i < n; i++ ){
        cout << arr[i] << " ";
    }
    return 0;
}