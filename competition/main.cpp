#include "head.h"

int main()
{
    int flag;
    entertain team;


    while(menu(),cout<<"输入功能代表的数字："<<endl,cin>>flag)
    {
        switch(flag)
        {
        case 1:
            team.getScore();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        }
    }
    return 0;
}
