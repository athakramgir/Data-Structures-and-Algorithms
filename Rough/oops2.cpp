#include<bits/stdc++.h>
using namespace std;

class abc {
    private:
    static int count ;
    public:
    abc(){
        count++;
    }
    void getCount(){
        cout << count;
    }
};
int abc :: count = 0;
int main(){
    abc a1;
    abc a2;
    abc a3;
    abc a4;
    abc a5;
    a1.getCount();
    return 0;
}