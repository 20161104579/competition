#include <iostream>

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
    void getScore();
    void showScore();
};
class judge
{
private:
    string name;
    string number;
    char sex;
public:
    void setData();
    void showData();
};

void menu();
