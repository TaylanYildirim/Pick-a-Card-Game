/*
BLG252E - Object Oriented Programming
        Homework2
Ozbil Taylan Yildirim - 150130063
*/
#ifndef DARKRED_H
#define DARKRED_H
#include "Base.h"
class DarkRed:public Red{
    protected:
    public:
    DarkRed(int initialize,char mType,Base *init):Red(initialize,mType,init){}
    int compare(char)const;
};
int DarkRed::compare(char comparison)const{
    if(comparison == 'D') return 1;
    else if(comparison == 'G') return 0;
    else if(comparison == 'R') return 2;
    else return 2;
}
#endif // DARKRED_H
