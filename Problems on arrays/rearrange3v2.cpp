#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 0;
    cout << "Enter the value of n" << endl;
    cin >> n;
    int arr[n];
    cout <<"Enter the elements of the array" << endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> pos, neg;
    for(int i = 0; i < n; i++) {
        if(arr[i] < 0) {
            neg.push_back(arr[i]);
        }
        else{
            pos.push_back(arr[i]);
        }
    }

    int smaller = min(pos.size(), neg.size());
    for(int i = 0; i < smaller; i++) {
        arr[2*i] = pos[i];
        arr[2*i + 1] = neg[i];
    }

    int index = 2*smaller;
    if(smaller == neg.size()) {
        for(int i = smaller; i < pos.size(); i++) {
            arr[index++] = pos[i];
        }
    }
    else{
        for(int i = smaller; i < neg.size(); i++) {
            arr[index++] = neg[i];
        }
    }
    for(int i = 0; i < n ; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}