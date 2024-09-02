#include<iostream>

using namespace std;

class produce{
    int modelNum, partNum;
    float cost;

    public:
    void setPart(int mn, int pn, float c){
        modelNum = mn;
        partNum = pn;
        cost = c;
    }
    void show(){
        printf("The Number of the Model is %d\n",modelNum);
        printf("The Number of the Part is %d\n",partNum);
        printf("The Number of the Cost is %.2f\n ",cost);
    }
};

int main(){

    produce izd;
    izd.setPart(200, 300, 350.55);
    izd.show();



    return 0;

}