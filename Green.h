/*
BLG252E - Object Oriented Programming
        Homework2
Ozbil Taylan Yildirim - 150130063
*/
#ifndef GREEN_H
#define GREEN_H
#include "Base.h"
class Green:public Base{
    protected:
    public:
    Green(int initialize, char mType,Base *init):Base(initialize, mType,init){}
    int compare(char)const;
};
#endif // GREEN_H
int Green::compare(char comparison)const{
    if(comparison == 'G') return 1;
    else if(comparison == 'R') return 0;
    else if(comparison == 'D') return 2;
    else return 2;
}


