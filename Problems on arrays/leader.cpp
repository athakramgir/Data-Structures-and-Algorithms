#include<bits/stdc++.h>
using namespace std;

vector<int> leader(int arr[], int n) {
    bool leader = true;
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[j] > arr[i]) {
                leader = false;
                break;
            }
            leader = true;
        }
        if(leader) ans.push_back(arr[i]);
    }
    return ans;
}
int main(){
    int n = 0; 
    cout << "Enter n " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array " << endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> answer = leader(arr, n);
    for(auto it : answer) {
        cout << it << " ";
    }
    
    return 0;
}