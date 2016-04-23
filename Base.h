/*
BLG252E - Object Oriented Programming
        Homework2
Ozbil Taylan Yildirim - 150130063
*/
#ifndef BASE_H
#define BASE_H
class Base{//Base Class
    protected:
        int result;//Result of
        char moveType;//Move Type of Player('D','R','B','G')
    public:
        Base(int initialize, char mType,Base* init):result(initialize),moveType(mType),next(init){};
        Base *next;
        int getResult()const;
        char getMoveType();
        virtual int compare(char)const=0;
};
char Base::getMoveType(){return moveType;}//getter of move type
int Base::getResult()const{return result;}
#endif
