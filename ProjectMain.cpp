#include "Poker.cpp"
#include "BlackJack.cpp"
#include <iostream>
#include <string>
using namespace std;

int main(){
  int choice;
  do{
    cout<<" ------------CARD GAMES------------"<<endl;
    cout<<"|--Enter (1) to play Poker---------|"<<endl;
    cout<<"|--Enter (2) to play Black-Jack----|"<<endl;
    cout<<"|                                  |"<<endl;
    cout<<"|---------------TEST---------------|"<<endl;
    cout<<"|--Enter (3) to Test Poker---------|"<<endl;
    cout<<"|                                  |"<<endl;
    cout<<"|---------------EXIT---------------|"<<endl;
    cout<<"|--Enter (0) to exit game----------|"<<endl;
    cout<<"|__________________________________|"<<endl;
    cout<<"Enter choice: ";
    cin>>choice;
    while(choice != 1 && choice != 2 && choice != 0 && choice != 3){
      cout<<"ERROR: Invalid Entry!!!"<<endl;
      cout<<" __________________________________"<<endl;
      cout<<"|--Enter (1) to play Poker---------|"<<endl;
      cout<<"|--Enter (2) to play Black-Jack----|"<<endl;
      cout<<"|__________________________________|"<<endl;
      cout<<"Enter choice: ";
      cin>>choice;
      cout<<endl;
    }
    switch(choice){
      case 1: //poker game function
        PokerGame();
        break;

      case 2: //black-jack game function
        BlackJackGame();
        break;

      case 3: //test poker game function
        PokerGameTest();
        break;

      case 0: //exit software
        cout<<"Goodbye ";
        break;

      default: //default
        break;
    }
}while(choice != 0);
/*
  Card cardTest;
  //PrintCard(cardTest.arrCards, 5);
  cardTest.ShuffleCard(cardTest.arrCards);
  PrintCard(cardTest.arrCards, 5);*/
  return 0;
};
