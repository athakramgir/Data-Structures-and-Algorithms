#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 0 ;
    cout << "Enter n " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array " << endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

     
    unordered_set<int> s;
    for(int i = 0; i < n; i++) {
        s.insert(arr[i]);
    }
    int longest = 1;
    int count = 0;
    int x = 0;
    for(auto it : s) {
        if(s.find(it - 1) == s.end()) {
            count = 1;
            x = it;
        }
        while(s.find(x + 1) != s.end()){
            count ++;
            x = x + 1;
        }
        longest = max(count, longest);
    }

    cout << longest;
    return 0;
}