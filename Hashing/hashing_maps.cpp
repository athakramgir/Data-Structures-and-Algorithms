#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    // pre compute
    // map<int, int> mpp;
    unordered_map<int, int> mpp;// time complexity using unordered map in best and average case is O(1) but O(N) in worst case
    // for characters
    map<char, int> mppc; // <character, frequency>  : time complexity using map is O(log N) in best, average and worst cases
    for(int i = 0; i < n; i++){
        mpp[arr[i]] ++;
    }
    // to iterate in the map
    for(auto it : mpp){
        cout << it.first << " --> " << it.second << endl;
    }
    int q;
    while(q--){
        int number;
        cin >> number;
        // fetch
        cout << mpp[number] << endl;
    }
    return 0;
}