#include<iostream>
#include<cstring>

using namespace std;


class Art{
    public:
    string name, nazv, date;
    virtual void Print(){
        cout << "author: "<<name<<", nazva: "<<nazv<<", date: "<< date<<endl;
    }

    Art(){name = "Donald"; nazv = "zxc"; date = "04.05.1844";}
    Art(string author, string nazva, string date_){name = author; nazv = nazva; date = date_;}
};

class Picture : public Art{
    public:
    float h, w;
    void Print(){
        cout << "author: "<<name<<", nazva: "<<nazv<<", date: "<< date<<endl;
        cout << "height: " << h << ", width: " << w << endl;
    }

    Picture() : Art() {h = 30; w = 40;}
    Picture(float height, float width, string author, string nazva, string date_) : Art(author,nazva,date_) {
        h = height; w = width;
    }
};

class Music: public Art{
    public:
    string ton;
    void Print(){
        cout << "author: "<<name<<", nazva: "<<nazv<<", date: "<< date<<endl;
        cout << "Ton: " << ton << endl;
    }

    Music() : Art() {ton = "high";}
    Music(string ton_, string author, string nazva, string date_) : Art(author,nazva,date_) {ton = ton_;}
};

class Music_orkestr : public Music{
    public:
    int numberOfMusicians;
    void Print(){
        cout << "author: "<<name<<", nazva: "<<nazv<<", date: "<< date<<endl;
        cout << "Ton: " << ton << endl;
        cout << "number of musicians: " << numberOfMusicians << endl;
    }

    Music_orkestr() : Music() {numberOfMusicians = 25;}
    Music_orkestr(int num, string ton_, string author, string nazva, string date_) : Music(ton_, author, nazva, date_)
    {numberOfMusicians = num;}
};


int main(){
    
    cout << "\nArt:\n";
    Art a1;
    a1.Print();
    cout << "\nPic:\n";
    Picture p1(12,15, "Vova", "TheWall", "20.02.2020");
    p1.Print();
    cout << "\nMusic:\n";
    Music m1("low", "Misha", "Sonne", "05.05.1993");
    m1.Print();
    cout << "\nMusic Orcestr:\n";
    Music_orkestr o1(11, "very Low", "Mycola", "The MOBA", "14.03.2023");
    o1.Print();



    return 0;
}