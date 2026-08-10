#include<bits/stdc++.h>
using namespace std;

vector<int> nge2(vector<int> arr) {// O(n^2);
    vector<int> nge(arr.size(), -1);
    for(int i = 0; i < arr.size(); i++){
        for(int j = i + 1; j < arr.size() - 1 + i; j++) {
            int index = j % arr.size();
            if(arr[index] > arr[i]) {
                nge[i] = arr[index];
                break;
            }
        }
    }
    return nge;
}

vector<int> nge2Opt(vector<int> arr) {
    
}
int main(){
    
    return 0;
} 