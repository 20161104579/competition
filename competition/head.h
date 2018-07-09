#include <iostream>
#include <fstream>

using namespace std;

class entertain
{
private:
    string type;
    string name;
    string number;
    char sex;
    int score;
public:
    entertain()
    {
    }
    void menue();
    void Adde();
    void Dele();
    void Query();
    void Change();
    void Show1();
    void Sort();
    void Copy1();
    void Load1();
    void Grade();
};
class judge
{
private:
    string name;
    string number;
    char sex;
public:
    void menu();
    void add();
    void Copy();
    void Load();
    void Show();
    void Query();
};

void menu();

