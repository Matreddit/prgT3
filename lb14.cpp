#include<iostream>
#include<string>
#include<vector>
using namespace std;

/* V13-10 -> V3
3. Створити клас Файл, який містить дані про файл: назву, розмір, дату та
час створення, атрибути. Створити клас Каталог, що містить масив
об’єктів класу Файл. Визначити необхідні конструктори, деструктори,
методи роботи з файлами та каталогами.  */

class File{
    string name;
    int size;
    string date;
    string time;
    string attributes;

    public:
    File() : name("new_file"), size(0), date("0000.00.00"), time("00:00:00"), attributes("none") {}

    File(const string& name, int size, const string& date, const string& time, const string& attributes)
    : name(name), size(size), date(date), time(time), attributes(attributes) {}
    
    void printInfo(){
        cout << "Name: " << name << "\n- Size: " << size << "\n- Created: "
            << date << "\t" << time << "\n- Attributes: " << attributes << endl;
    }

    string getName() {return name;}
    int getSize() {return size;}
    string getDate() {return date;}
    string getTime() {return time;}
    string getAttributes() {return attributes;}

    void setName(const string& Name) {name = Name;}
    void setSize(int Size) {size = Size;}
    void setDate(const string& Date) {date = Date;}
    void setTime(const string& Time) {time = Time;}
    void setAttributes(const string& Attributes) {attributes = Attributes;}

};

class Catalog{
    vector<File> files;

    public:


    void addFile(const File& file){
        files.push_back(file);
    }

    void removeFile(const string& fileName){
        for (int i = 0; i < files.size(); i++)
        {
            if(files[i].getName() == fileName){
                files.erase(files.begin() + i);
            }
        }
        
    }

    void printFiles(){
        if (files.size() == 0){
            cout << "No files in catalog.\n";
            return;
        } else{
            for (int i = 0; i < files.size(); i++)
            {
                files[i].printInfo();
            }
            cout << endl;
        }
    }
};

int main(){

    Catalog docs;
    for (int i = 0; i < 20; i++)
    {
        File file("my file " + to_string(i+1), 40+i, "20.11.2024", "10:44:" + to_string(i+1), "Hidden, Read-Only");
        docs.addFile(file);
    }

    docs.printFiles();
    cout << "\n\n";
    
    docs.removeFile("my file 6");
    
    docs.printFiles();
    


    return 0;
}