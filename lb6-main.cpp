#include<iostream>
#include<cstring>

using namespace std;

/*  V13.
Створіть базовий клас "Техніка" і "Функція" зі змінними для функції
техніки та її назви. Створіть клас "Техніка_з_функцією", який
успадковує властивості обох базових класів. */

class Tech{
    public:
    string techName;
    Tech(string name) {techName = name;}
};
class Funk{
    public:
    string funkName;
    Funk(string name) {funkName = name;}
};

class TechNFunk : public Tech, public Funk{
    public:
    string techNFunkName;

    TechNFunk(string nameTnF, string nameTech, string nameFunk) 
        : Tech(nameTech), Funk(nameFunk){
            techNFunkName = nameTnF;
        }
};

int main(){


    TechNFunk computer("PC", "CPU", "booting");

    cout << computer.techName << "    " << computer.funkName 
        << "    " << computer.techNFunkName << endl;


    return 0;
}