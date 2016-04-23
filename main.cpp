/*
BLG252E - Object Oriented Programming
        Homework2
Ozbil Taylan Yildirim - 150130063
*/

#include <iostream>
#include <string.h>
#include <stdio.h>
#include "myClass.h"
#include "Blue.h"
#include "Green.h"
#include "Red.h"
#include "DarkRed.h"

using namespace std;

typedef Hetlist objectArray;

void addHetList(Hetlist&,char [][20],int,int);
void display(Hetlist&,Hetlist&,int);
int main(){
    objectArray *hList = new objectArray();//Heterogeneous list#1
    objectArray *hList1 = new objectArray();////Heterogeneous list#2
    FILE *DeckFile = fopen("deck.txt","r");
  	if (!(DeckFile = fopen("deck.txt", "r+"))){
		if (!(DeckFile = fopen("deck.txt", "w+"))){
			cerr << "File cannot be opened" << endl;
			return -1;
		}
	}
    char line[10][50];//char array to read one line
	char tokens[10][20];//char array to split a line to many chars
	char *token;
	int i = 0;
	int counter = 0;
    fseek(DeckFile, 0, SEEK_SET);
    while (!feof(DeckFile)){
		fscanf(DeckFile, "%[^\n]", line[i]);//reading a line except new line charater('\n')
		fgetc(DeckFile);//reading \n
		token = strtok(line[i], " ");//splitting an array based on white space
		while (token != NULL){
			strcpy(tokens[counter], token);
			token = strtok(NULL, " ");
			counter++;
		}
		i++;//new line in deck.txt file
    }
    addHetList(*hList1,tokens,0,(counter)/2);//Inserting heterogeneous list
    addHetList(*hList,tokens,(counter)/2,counter);//Inserting heterogeneous list


    display(*hList,*hList1,counter/2);
    return 0;
}
void addHetList(Hetlist& hList1,char tokens[][20],int start,int finish){// Adding heterogeneous list
        for(int i = start; i < finish;i++){
        if(*tokens[i] == 'B'){//Insert function for Blue
            Blue* asd = new Blue(0,'B',NULL);
            Base *tempBase =asd;
            hList1.add(*tempBase);
        }
        else if(*tokens[i] == 'R'){
            Red* asd = new Red(54,'R',NULL);//Insert function for Red
            Base *tempBase = asd;
            hList1.add(*tempBase);
        }
        else if(*tokens[i] == 'G'){
            Green* asd =  new Green(5,'G',NULL);//Insert function for Green
            Base *tempBase = asd;
            hList1.add(*tempBase);
        }
        else{
            DarkRed* asd = new DarkRed(0,'D',NULL);//Insert function for DarkRed
            Base *tempBase = asd;
            hList1.add(*tempBase);
        }
    }
}
void display(Hetlist& hList,Hetlist& hList1,int counter){

    Base *tail =hList1.head;
    cout << endl<<"Player1:";
    for(int i=0;i <counter;i++){
        cout<<tail->getMoveType()<<" ";//printing moving type of player1
        tail= tail->next;
    }
    Base *temp=hList.head;
    cout<<endl<<"Player2:";
    for(int i=0;i <counter;i++){
        cout <<temp->getMoveType()<<" ";//printing moving type of player2
        temp =temp->next;
    }
    tail = hList.head;
    temp = hList1.head;
    cout << endl <<"Score1: ";
    int tie=0,lose=0,win=0;
    for(int i = 0; i < counter; i++){
        if(tail->compare(temp->getMoveType())==2)win++;//calculating number of win for first player
        else if(tail->compare(temp->getMoveType()) == 1) tie++;//calculating number of tie for first player
        else lose++;//calculating number of lose for first player
        cout <<tail->compare(temp->getMoveType())<<" ";//printing 0,1 or 2
        tail = tail->next;
        temp = temp->next;
    }
    tail = hList1.head;
    temp = hList.head;
    cout<<endl<<"Score2: ";
    int tie1=0,lose1=0,win1=0;
    for(int i = 0; i < counter; i++){
        if(tail->compare(temp->getMoveType())==2)win1++;
        else if(tail->compare(temp->getMoveType()) == 1) tie1++;
        else lose1++;
        cout <<tail->compare(temp->getMoveType())<<" ";
        tail = tail->next;
        temp = temp->next;
    }
    cout<<endl<<"Total Score1: Lose:"<<lose<<" Tie: "<<tie<<" Win: "<<win;
    cout<<endl<<"Total Score2: Lose:"<<lose1<<" Tie: "<<tie1<<" Win: "<<win1;
    if(win>win1)
        cout << endl<<"Winner: Player1"<<endl;
    else
        cout <<endl <<"Winner: Player2"<<endl;
}
