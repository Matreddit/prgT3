#include<iostream>
#include<cstring>

using namespace std;

/*Створити клас, членами якого будуть дані відповідно до варіанту
(варіант відповідає номеру студента у списку групи) та описати методи,
які будуть: присвоювати самостійно задані значення відповідним членам
класу; виводити на екран присвоєні значення; виконувати дії за
варіантом індивідуального завдання.*/

/*  V10:
class: tvaryna
class members: type, texture, avarageWeight
class methods: cout << avarageWeight * 2;
*/
/*  V11:
class: exam
class members: studentName, date, examScore
class methods: cout << 100 - examScore;
*/

// V10
class Animal{
    string type, texture;
    float avarageWeight;
    public:
    void printWeightX2(){
        cout << "avarageWeight * 2 = " << avarageWeight * 2 << endl;
    }
    void setAnimal(string type_, string texture_, float mass){
        type = type_; texture = texture_; avarageWeight = mass;
    }
} Frog; // tse ja vyjobujus shcho pamjataju jak global objects oholoshuvat

// V11
class Exam{
    // sting name, time_t date, int score
    // public:
    // void set(string int int){zxczxczxc}
    // void printShit(){cout << "projebav " 100 - score << " baliv, loh jebanyj"<<endl;}
};


int main(){
    // V10
    Frog.setAnimal("Zhaba", "green", 14.88);
    Frog.printWeightX2();

    // V11
    Exam philosophy;
    //set
    //print

    return 0;
}
