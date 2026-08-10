#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    // pre compute 
    int hash[26] = {0};
    for(int i = 0; i < s.size(); i++){
        hash[s[i] - 'a'] ++;// s[i] is auto casted to its ASCII value 
    }
    int queries; 
    cin >> queries;
    while(queries--){
        char c;
        cin >> c;
        // fetch 
        cout << hash[c - 'a'] << endl;
    }
    return 0;
}