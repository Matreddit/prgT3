// переписаний код з документу

#include<iostream>

using namespace std;

class A{
    protected:
    int x, y;
    public:
    int a, b;
    int f1(int x,int y){
        return (x-y);
    }
};

int main(){

    A min;
    min.a = 20;
    min.b = 50;
    int x1 = min.f1(min.a, min.b);

    cout << x1 << endl;
    

    return 0;

}