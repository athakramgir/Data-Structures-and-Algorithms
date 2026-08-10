#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 0, m = 0;
    cout << "Enter m and n" << endl;
    cin >> m;
    cin >> n;
    
    int arrm[m], arrn[n];

    cout << "Enter the elements in the first array " << endl;
    for(int i = 0; i < m; i++) {
        cin >> arrm[i];
    }
    cout << "Enter the elements of the second array  " << endl;
    for(int i = 0; i < n; i++) {
        cin >> arrn[i];
    }


    vector<int> ans;
    int i = 0, j = 0;
    while(i < m && j < n) 
    {
        if(arrm[i] < arrn[j]) {
            i++;
        }
        else if(arrm[i] > arrn[j]) {
            j++;
        }
        else{
            ans.push_back(arrm[i]);
            i++;
            j++;
        }
    }

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}