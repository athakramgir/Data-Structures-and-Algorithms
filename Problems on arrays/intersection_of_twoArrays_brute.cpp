#include<bits/stdc++.h>
using namespace std;

int main(){
    int n1, n2 = 0;
    cout << "Enter n1 and n2" << endl;
    cin >> n1 >> n2;
    int arr1[n1];
    int arr2[n2];

    cout << "Enter the elements of first array " << endl;
    for(int i = 0 ; i < n1; i++) {
        cin >> arr1[i];
    }
    cout << "Enter the elements of the second array " << endl;
    for(int i = 0 ; i < n2; i++) {
        cin >> arr2[i];
    }

    int vis[n2] = {0};
    vector<int> ans;
    for(int i = 0 ; i < n1; i++) {
        for(int j = 0; j < n2; j++) {
            if(arr1[i] == arr2[j] && vis[j] == 0) {
                ans.push_back(arr1[i]);
                vis[j] = 1;
                break;
            }
            if(arr2[j] > arr1[i]) break;
        }
    }

    for(auto it : ans) {
        cout << it << " ";
    }
    return 0;
}