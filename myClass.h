/*
BLG252E - Object Oriented Programming
        Homework2
Ozbil Taylan Yildirim - 150130063
*/
#ifndef HETLIST_H
#define HETLIST_H
#include <iostream>
using namespace std;
#include "Base.h"
class Hetlist{
    private:
    public:
        Hetlist();//constructor
        ~Hetlist();//destructor
        int getNodeCount()const;//getter of
        Base *head;
        void add(Base&);//insert function
};


Hetlist::Hetlist(){head = NULL;}

Hetlist::~Hetlist(){
    Base *p;
    while(head){
        p = head;
        head = head->next;
        delete p;
    }
}

void Hetlist::add(Base& toAdd){//Insert funcion
    Base *tail = head;
    Base *newNode;
    newNode = &toAdd;
    newNode->next = NULL;
    if(head == NULL){//inserting to empty list
        head = newNode;
        return;
    }
    while(tail->next){//inserting after first Base object
        tail = tail->next;
    }
    if(!(tail->next)){
        tail->next = newNode;
    }
}
#endif
