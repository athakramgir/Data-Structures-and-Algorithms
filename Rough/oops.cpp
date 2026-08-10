#include<bits/stdc++.h>
using namespace std;

class A{
    private: 
    int x; 
    public: 
    friend void printX(const A& a1);
    void set_data(int a){
        x = a;
    }
};

void printX(const A& a1) {
    cout << "The private value of x is " << a1.x << endl;
}
int main(){
    class A a1;
    a1.set_data(10);
    printX(a1);
    return 0;
}