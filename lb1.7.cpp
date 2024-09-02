// переписаний код з документу в довільній формі

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

    // A *min=(A *) new A(); // так в документі, але я не зрозумів на кой чорт цей крінж 
    A *min = new A; // того буде по нормальному
    min->a = 20;
    min->b = 50;
    int x1 = min->f1(min->a, min->b);

    printf("x1= %d\nx2= %d\n",x1);    

    delete min;

    return 0;

}