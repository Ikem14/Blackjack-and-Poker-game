//Header file for Card game
#ifndef project1_H
#define project1_H
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;


//UNICODE DECLARATION OF CARD SYMBOLS
const char spade[4] = "\xe2\x99\xa0";
const char club[4] = "\xe2\x99\xa3";
const char heart[4] = "\xe2\x99\xa5";
const char diamond[4] = "\xe2\x99\xa6";

class DeckCard{
  public:
    int num;
    int id;
    char pic[4];
    DeckCard(){
      num = 0;
    }

};

//Card class defines the structure and creates the deck of cards
class Card{
public:
    DeckCard arrCards[52]; //CREATES AN ARRAY WITH 52 CARDS
    DeckCard nextCard; //HOLDS THE INDEX OF THE NEXT AVAILABLE CARD
    int nextCounter;
  public:
    //sets the card number
    void SetCardNum(int arrIndex,int n){
      arrCards[arrIndex].num = n;
    }
    //returns card number
    int GetCardNum(int arrIndex){
      return arrCards[arrIndex].num;
    }
    //sets the card id
    void SetCardID(int arrIndex,int n){
      arrCards[arrIndex].id = n;
    }
    //set the pic
    void SetPic(int arrIndex, const char n[]){
      for (int i =0; i<4; i++){
        arrCards[arrIndex].pic[i] = n[i];
      }
    }

    //get the pic
    /*const char GetPic(DeckCard *card){
      return card->GetDPic();
    }*/
    Card(); //CONSTRUCTOR FOR THE CARD CLASS
    void ShuffleCard(DeckCard arr[]); //USED TO SHUFFLE CARDS BEFORE ANY GAMES
    DeckCard GetNextCard(); //RETURNS INFO OF NEXTCARD, AND ALSO UPDATES NEXTCARD
    //VOID FUNCTIONS TO DISPLAY THE CARDS
    void CardAce(const char n[]);
    void CardTwo(const char n[]);
    void CardThree(const char n[]);
    void CardFour(const char n[]);
    void CardFive(const char n[]);
    void CardSix(const char n[]);
    void CardSeven(const char n[]);
    void CardEight(const char n[]);
    void CardNine(const char n[]);
    void CardTen(const char n[]);
    void CardJack(const char n[]);
    void CardQueen(const char n[]);
    void CardKing(const char n[]);

};

#endif
