/*
BLG252E - Object Oriented Programming
        Homework2
Ozbil Taylan Yildirim - 150130063
*/
#ifndef BLUE_H
#define BLUE_H
#include "Base.h"
class Blue:public Base{
    protected:
    public:
    Blue(int initialize, char mType,Base *init):Base(initialize, mType,init){}
    int compare(char)const;
};
int Blue::compare(char comparison)const{
    if(comparison == 'B') return 1;
    else if(comparison == 'D') return 0;
    else if(comparison == 'G') return 0;
    else return 2;
}
#endif
