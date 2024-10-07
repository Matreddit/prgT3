#include<iostream>
#include<string> // <cstring>
#include<ctime>
#include <cstdlib>  // rand()

using namespace std;

/*Написати код програми відповідно до варіанту (табл. 6). 
   +Створити абстрактний клас А з методом/методами, що вказані у варіанті.
    Створити похідні класи та передбачити члени даних класу. Кожен похідний клас має власні методи.
    Створити базу (на основі масиву) із n елементів, вивести повну інформацію із бази
        на екран, а також організувати пошук за вказаною умовою. 

V13 -> V3
Абстрактний клас
    Студенти
    Методи:
        виведення на екран інформації про персони;
        визначення їх віку на даний момент.

Похідні класи
    Абітурієнт  (ПІБ, Факультет, Дата народження, рік вступу);
    Студент     (ПІБ, Факультет, Дата народження, рік вступу, рік випуску бакалавра, Форма навчання);
    Магістрант  (ПІБ, Факультет, Дата народження, рік вступу, Курс магістратури).

Методи похідних класів
    Виведення даних.

Умова пошуку
    Персони, які навчаються (вступають) на (до) визначеному факультеті.

*/


class Interface{
    public:
    virtual void printInfo() const = 0;
    virtual int getAge() const = 0;
    virtual string getFaculty() const = 0;
    virtual string getFullName() const = 0;
};

class Appliciant : public Interface{
    protected:
    string fullName, faculty, birthDate;
    int yearOfEntry;
    
    public:
    Appliciant(const string& pib, const string& faculty_, const string& dateOfBirth, int entryYear) :
        fullName(pib), faculty(faculty_), birthDate(dateOfBirth), yearOfEntry(entryYear) {}

    void printInfo() const override{
        cout << "Appliciant: " << fullName << ", Faculty: " << faculty
            << ",\n\tDate of birth: " << birthDate << ", Year of entry: " << yearOfEntry << endl;
    }
    int getAge() const override{
        int pos = birthDate.find_last_of("0123456789");
        int year = stoi(birthDate.substr(pos-3, 4));
        time_t now = time(0);
        int currentYear = localtime(&now)->tm_year + 1900;
        return currentYear - year;
    }
    string getFaculty() const override{
        return faculty;
    }
    string getFullName() const override{
        return fullName;
    }

    // Кожен похідний клас має власні методи
    bool isEnrolled(){
        time_t now = time(0);
        int currentYear = localtime(&now)->tm_year + 1900;
        return currentYear >= yearOfEntry; // (currentYear >= yearOfEntry) ? true : false;
    }
};

class Student : public Appliciant {
    protected:
    int yearOfBaGrad;
    string educationForm;

    public:
    Student(const string& pib, const string& faculty_, const string& dateOfBirth,
        int entryYear, int BaGradYear, const string& educForm)
        : Appliciant(pib, faculty_, dateOfBirth, entryYear), yearOfBaGrad(BaGradYear), educationForm(educForm) {}

    void printInfo() const override{
        cout << "Bachelor: " << fullName << ", Faculty: " << faculty
            << ",\n\tDate of birth: " << birthDate << ", Year of entry: " << yearOfEntry
            << ",\n\tBachelor's year of graduation: " << yearOfBaGrad
            << ", Education form: " << educationForm << endl;
    }
    // Кожен похідний клас має власні методи
    bool isGraduated() const {
        time_t now = time(0);
        int currentYear = localtime(&now)->tm_year + 1900;
        return currentYear >= yearOfBaGrad;
    }
};

class Master : public Student {
    protected:
    int courseOfMAdeg;

    public:
    Master (const string& pib, const string& faculty_, const string& dateOfBirth,
        int entryYear, int BaGradYear, const string& educForm, int MAcourse)
        :   Student(pib, faculty_, dateOfBirth, entryYear, BaGradYear, educForm),
            courseOfMAdeg(MAcourse) {}
    void printInfo() const override{
        cout << "Master: " << fullName << ", Faculty: " << faculty
            << ",\n\tDate of birth: " << birthDate << ", Year of entry: " << yearOfEntry
            << ",\n\tBachelor's year of graduation: " << yearOfBaGrad
            << ", Education form: " << educationForm 
            << ",\n\tMaster's degree course: " << courseOfMAdeg << endl;
    }
    // Кожен похідний клас має власні методи
    int remainingSemesters() const {
        return 4 - courseOfMAdeg * 2;
    }
};

class Unik{

    static string genFullName(){
        const int n(10);
        const string firstNames[n] = {
            "Olena", "Ivan", "Mykola", "Oksana", "Petro",
            "Anna", "Volodymyr", "Natalia", "Serhiy", "Viktoria"
        };

        const string middleNames[n] = {
            "Oleksandrivna", "Ivanovych", "Mykolayovych", "Petrovych", "Andriyovych",
            "Oleksiivna", "Yaroslavivna", "Borysivna", "Dmytrivna", "Volodymyrivna"
        };

        const string lastNames[n] = {
            "Shevchenko", "Petryk", "Kovalchuk", "Zinchenko", "Boyko",
            "Tkachenko", "Melnyk", "Shapoval", "Kryvets", "Hryhorenko"
        };
        string name = "";
        name += lastNames   [rand() % n]; name += " ";
        name += firstNames  [rand() % n]; name += " ";
        name += middleNames [rand() % n];
        return name;
    }
    static string genFaculty(){
        const int n(5);
        const string faculties[n] = {
            "DMNST", "DPPA", "DHBEL", "DUPFLSC", "DPE"
        };
        return faculties[rand() % n];
    }
    static string genBirthDate(int startYear = 1980, int endYear = 2010){
        string date = "";
        date += to_string(rand() % 30 + 1); date += ".";
        date += to_string(rand() % 12 + 1); date += ".";
        date += to_string( rand() % (endYear - startYear + 1) + startYear );
        return date;
    }
    static int genYear(int start = 1998, int end = 2024) {
        return rand() % (end - start + 1) + start;
    }
    static string genEduForm(){
        const string forms[3] = {"full-time", "distance", "part-time"};
        return forms[rand() % 3];
    }

    public:
    static Appliciant createAppliciant(){
        return Appliciant(genFullName(), genFaculty(), genBirthDate(), genYear());
    }
    static Student createStudent(){
        int yearOfEntry = genYear();
        return Student(genFullName(), genFaculty(), genBirthDate(), yearOfEntry, yearOfEntry+4, genEduForm());
    }
    static Master createMaster(){
        int yearOfEntry = genYear();
        return Master(genFullName(), genFaculty(), genBirthDate(),
            yearOfEntry, yearOfEntry+4, genEduForm(), rand()%2+1);
    }
    static void searchByFaculty(const string& faculty, Interface **students, int n){
        bool isExist = false;
        int num = 0;
        for (size_t i = 0; i < n; i++){
            if(students[i]->getFaculty() == faculty){
                num++;
                if(!isExist){
                    isExist = true; 
                    cout << "Students from " << faculty << ":\n";
                }
                cout << i << ".\t";
                students[i]->printInfo();
            }
        }
        if(isExist) cout << "(total " << num << ").\n";
    }
    static void searchByName(const string& name, Interface **students, int n){
        bool isExist = false;
        int num = 0;
        for (size_t i = 0; i < n; i++){
            if (students[i]->getFullName().find(name) != string::npos) {
                num++;
                if(!isExist){
                    isExist = true; 
                    cout << "Students with name \"" << name << "\":\n";
                }
                cout << i << ".\t";
                students[i]->printInfo();
            }
        }
        if(isExist) cout << "(total " << num << ").\n";
    }

    static void printAllStudents(Interface ** stds, int n){
        int i = 0;
        for (; i < n; i++)
        {   
            if(i == 0) { cout << "Students of Unik:\n"; }
            cout << i+1 << ".\t";
            stds[i]->printInfo();
        }
        cout << "(total students = " << i << ")\n";
    }

    static void deleteStudents(Interface ** students, int n) {
        for (size_t i = 0; i < n; i++){
            delete students[i];
        }
    }
};


void main1(){
    int n = 4;
    
    Interface *students[n];
    students[0] = new Master("Volodia Petrrnko", "FM", "20.12.2005", 2022, 2026, "ochno", 1);
    students[1] = new Student("Masha Romanenko", "FM", "11.02.2006", 2024, 2028, "zaochno");
    students[2] = new Appliciant("Volodia Petrrnko", "FL", "20.12.2005", 2024);
    Master masik("Masik D.", "FM", "20.12.2006", 2012, 2018, "ochno", 2);
    students[3] = new Master(masik);
    

    for (size_t i = 0; i < n; i++)
    {
        students[i]->printInfo();
        cout << "---\n";
    }

    // пошук за факультетом

    cout << "\n\nStudents from FM:\n";
    for (size_t i = 0; i < n; i++)
    {
        if(students[i]->getFaculty() == "FM"){
            students[i]->printInfo();
            cout << "---\n";
        }
    }


    for (size_t i = 0; i < n; i++){
        delete students[i];
    }
    
}

void mainMain(){
    int n = 20;
    Interface *students[n];

    for (size_t i = 0; i < n; i++) {
        int zxc = rand() % 3;
        if(zxc == 0){
            students[i] = new Appliciant(Unik::createAppliciant());
        } else if (zxc == 1) {
            students[i] = new Student(Unik::createStudent());
        } else {
            students[i] = new Master(Unik::createMaster());
        }
    }

    // "DMNST", "DPPA", "DHBEL", "DUPFLSC", "DPE"
    Unik::searchByFaculty("DMNST", students, n);
    
    cout << "\n--------------------\n\n";
    Unik::searchByName("Anna", students, n);

    cout << "\n--------------------\n\n";
    // Unik::printAllStudents(students, n);


    Unik::deleteStudents(students, n);
}

int main(){
    srand(time(NULL));

    // main1();

    mainMain();

    return 0;
}
