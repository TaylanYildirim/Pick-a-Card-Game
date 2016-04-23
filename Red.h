/*
BLG252E - Object Oriented Programming
        Homework2
Ozbil Taylan Yildirim - 150130063
*/
#ifndef RED_H
#define RED_H
#include "Base.h"
class Red:public Base{
    protected:
    public:
    Red(int initialize, char mType,Base *init):Base(initialize, mType,init){}
    int compare(char)const;
};
int Red::compare(char comparison)const{
    if(comparison == 'R') return 1;
    else if(comparison == 'D') return 0;
    else if(comparison == 'B') return 0;
    else return 2;
}
#endif // RED_H
