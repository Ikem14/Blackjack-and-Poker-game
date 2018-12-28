//CardGame.cpp declares card game functions
#include "Project.h"
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <array>
using namespace std;



//SWAP THE TEMPORARY ARRAY WITH THE ORIGINAL ONE
void swap(DeckCard arrCards[],DeckCard arrCardstemp[]){
  int count = 0;
  while(count<52){
    arrCards[count] = arrCardstemp[count];
    count++;
  }
}
//CONSTRUCTOR FOR THE CARD CLASS
Card::Card(){
  //  Card newCard;
  nextCounter = 0; //sets nextCard counter to zero
    int count1 = 0;
    int count2=1;
    //ASSIGNS A VALUE TO EACH OF THE 52 CARDS BEFORE USE
    while(count1 < 52){
      //spade
      SetCardNum(count1, count2);
      SetPic(count1, spade);
      SetCardID(count1, 1);//1 for spades
      //cout<<arrCards[count1].num<<endl;
      //cout<<arrCards[count1].pic<<endl;
      count1++;
      //club
      SetCardNum(count1, count2);
      SetPic(count1, club);
      SetCardID(count1, 2);//2 for clubs
      //cout<<arrCards[count1].num<<endl;
      //cout<<arrCards[count1].pic<<endl;
      count1++;
      //heart
      SetCardNum(count1, count2);
      SetPic(count1, heart);
      SetCardID(count1, 3);//3 for hearts
      //cout<<arrCards[count1].num<<endl;
      //cout<<arrCards[count1].pic<<endl;
      count1++;
      //diamond
      SetCardNum(count1, count2);
      SetPic(count1, diamond);
      SetCardID(count1, 4);//4 for diamonds
      //cout<<arrCards[count1].num<<endl;
      //cout<<arrCards[count1].pic<<endl;
      count1++;
      count2++;
    }
}

//displays ace
void Card ::CardAce(const char n[]){
  cout<<" ------- "<<endl;
  cout<<"|"<<" A"<<setw(6)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(6)<<n<<setw(4)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(6)<<n<<setw(4)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(7)<<"A "<<"|"<<endl;
  cout<<" ------- "<<endl;
}

//displays two
void Card ::CardTwo(const char n[]){
  cout<<" ------- "<<endl;
  cout<<"|"<<" 2"<<setw(6)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(6)<<n<<setw(4)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(6)<<n<<setw(4)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(7)<<"2 "<<"|"<<endl;
  cout<<" ------- "<<endl;
}


//displays three
void Card :: CardThree(const char n[]){
  cout<<" ------- "<<endl;
  cout<<"|"<<" 3"<<setw(6)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(6)<<n<<setw(4)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(6)<<n<<setw(4)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(7)<<"3 "<<"|"<<endl;
  cout<<" ------- "<<endl;
}

//displays four
void Card ::CardFour(const char n[]){
  cout<<" ------- "<<endl;
  cout<<"|"<<" 4"<<setw(6)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(6)<<n<<setw(4)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(6)<<n<<setw(4)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(7)<<"4 "<<"|"<<endl;
  cout<<" ------- "<<endl;
}

//displays five
void Card ::CardFive(const char n[]){
  cout<<" ------- "<<endl;
  cout<<"|"<<" 5"<<setw(6)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(6)<<n<<setw(4)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(6)<<n<<setw(4)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(7)<<"5 "<<"|"<<endl;
  cout<<" ------- "<<endl;
}

//displays six
void Card ::CardSix(const char n[]){
  cout<<" ------- "<<endl;
  cout<<"|"<<" 6"<<setw(6)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(6)<<n<<setw(4)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(6)<<n<<setw(4)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(7)<<"6 "<<"|"<<endl;
  cout<<" ------- "<<endl;
}

//displays seven
void Card ::CardSeven(const char n[]){
  cout<<" ------- "<<endl;
  cout<<"|"<<" 7"<<setw(6)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(6)<<n<<setw(4)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(6)<<n<<setw(4)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(7)<<"7 "<<"|"<<endl;
  cout<<" ------- "<<endl;
}

//displays eight
void Card ::CardEight(const char n[]){
  cout<<" ------- "<<endl;
  cout<<"|"<<" 8"<<setw(6)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(6)<<n<<setw(4)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(6)<<n<<setw(4)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(7)<<"8 "<<"|"<<endl;
  cout<<" ------- "<<endl;
}

//diplays nine
void Card ::CardNine(const char n[]){
  cout<<" ------- "<<endl;
  cout<<"|"<<" 9"<<setw(6)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(6)<<n<<setw(4)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(6)<<n<<setw(4)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(7)<<"9 "<<"|"<<endl;
  cout<<" ------- "<<endl;
}

//displays ten
void Card ::CardTen(const char n[]){
  cout<<" ------- "<<endl;
  cout<<"|"<<"10"<<setw(6)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(6)<<n<<setw(4)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(6)<<n<<setw(4)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(7)<<"10 "<<"|"<<endl;
  cout<<" ------- "<<endl;
}

//displays jack
void Card ::CardJack(const char n[]){
  cout<<" ------- "<<endl;
  cout<<"|"<<" J"<<setw(6)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(6)<<n<<setw(4)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(6)<<n<<setw(4)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(7)<<"J "<<"|"<<endl;
  cout<<" ------- "<<endl;
}

//displays queen
void Card ::CardQueen(const char n[]){
  cout<<" ------- "<<endl;
  cout<<"|"<<" Q"<<setw(6)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(6)<<n<<setw(4)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(6)<<n<<setw(4)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(7)<<"Q "<<"|"<<endl;
  cout<<" ------- "<<endl;
}

//displays king
void Card ::CardKing(const char n[]){
  cout<<" ------- "<<endl;
  cout<<"|"<<" K"<<setw(6)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(6)<<n<<setw(4)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(6)<<n<<setw(4)<<"|"<<endl;
  cout<<"|"<<setw(8)<<"|"<<endl;
  cout<<"|"<<setw(7)<<"K "<<"|"<<endl;
  cout<<" ------- "<<endl;
}

//for displaying Cards
void PrintCard(DeckCard p[], int k){
  for(int i = 0; i < k; i++){
    cout<<" _______ ";
    cout<<" ";
  }
  cout<<endl;
  for(int i = 0; i < k; i++){
    if(p[i].num == 1){
      cout<<"|"<<"A"<<setw(7)<<"|";
      cout<<" ";
    }
    else if(p[i].num == 11){
      cout<<"|"<<"J"<<setw(7)<<"|";
      cout<<" ";
    }
    else if(p[i].num == 12){
      cout<<"|"<<"Q"<<setw(7)<<"|";
      cout<<" ";
    }
    else if(p[i].num == 13){
      cout<<"|"<<"K"<<setw(7)<<"|";
      cout<<" ";
    }
    else if(p[i].num == 10){
    cout<<"|"<<p[i].num<<setw(6)<<"|";
    cout<<" ";
    }
    else{
      cout<<"|"<<p[i].num<<setw(7)<<"|";
      cout<<" ";
    }
  }
  cout<<endl;
  //first suite
  for(int i = 0; i < k; i++){
    if(p[i].num==3){
      cout<<"|"<<setw(6)<<p[i].pic<<setw(4)<<"|";
      cout<<" ";
    }
    else if(p[i].num==4){
      cout<<"|"<<setw(4)<<p[i].pic<<setw(6)<<p[i].pic<<setw(2)<<"|";
      cout<<" ";
    }
    else if(p[i].num==5){
      cout<<"|"<<setw(4)<<p[i].pic<<setw(6)<<p[i].pic<<setw(2)<<"|";
      cout<<" ";
    }
    else if(p[i].num==6){
      cout<<"|"<<setw(4)<<p[i].pic<<setw(6)<<p[i].pic<<setw(2)<<"|";
      cout<<" ";
    }
    else if(p[i].num==7){
      cout<<"|"<<setw(4)<<p[i].pic<<setw(6)<<p[i].pic<<setw(2)<<"|";
      cout<<" ";
    }
    else if(p[i].num==8){
      cout<<"|"<<setw(4)<<p[i].pic<<setw(6)<<p[i].pic<<setw(2)<<"|";
      cout<<" ";
    }
    else if(p[i].num==9){
      cout<<"|"<<setw(4)<<p[i].pic<<setw(6)<<p[i].pic<<setw(2)<<"|";
      cout<<" ";
    }
    else if(p[i].num==10){
      cout<<"|"<<setw(4)<<p[i].pic<<setw(6)<<p[i].pic<<setw(2)<<"|";
      cout<<" ";
    }
    else{
      cout<<"|"<<setw(8)<<"|";
      cout<<" ";
    }
  }
  cout<<endl;
  //2nd suite
  for(int i = 0; i < k; i++){
    if(p[i].num==2){
      cout<<"|"<<setw(6)<<p[i].pic<<setw(4)<<"|";
      cout<<" ";
    }
    else if(p[i].num==7){
      cout<<"|"<<setw(6)<<p[i].pic<<setw(4)<<"|";
      cout<<" ";
    }
    else if(p[i].num==8){
      cout<<"|"<<setw(6)<<p[i].pic<<setw(4)<<"|";
      cout<<" ";
    }
    else if(p[i].num==9){
      cout<<"|"<<setw(6)<<p[i].pic<<setw(4)<<"|";
      cout<<" ";
    }
    else if(p[i].num == 10){
      cout<<"|"<<setw(6)<<p[i].pic<<setw(4)<<"|";
      cout<<" ";
    }
    else{
      cout<<"|"<<setw(8)<<"|";
      cout<<" ";
    }
  }
  cout<<endl;
  //third suite
  for(int i = 0; i < k; i++){
    if(p[i].num==9){
      cout<<"|"<<setw(4)<<p[i].pic<<setw(6)<<p[i].pic<<setw(2)<<"|";
      cout<<" ";
    }
    else if(p[i].num==10){
      cout<<"|"<<setw(4)<<p[i].pic<<setw(6)<<p[i].pic<<setw(2)<<"|";
      cout<<" ";
    }
    else{
      cout<<"|"<<setw(8)<<"|";
      cout<<" ";
    }
  }
  cout<<endl;
  //middle suite
  for(int i = 0; i < k; i++){
    if(p[i].num==1){
      cout<<"|"<<setw(6)<<p[i].pic<<setw(4)<<"|";
      cout<<" ";
    }
    else if(p[i].num==3){
      cout<<"|"<<setw(6)<<p[i].pic<<setw(4)<<"|";
      cout<<" ";
    }
    else if(p[i].num==5){
      cout<<"|"<<setw(6)<<p[i].pic<<setw(4)<<"|";
      cout<<" ";
    }
    else if(p[i].num==6){
      cout<<"|"<<setw(4)<<p[i].pic<<setw(6)<<p[i].pic<<setw(2)<<"|";
      cout<<" ";
    }
    else if(p[i].num==7){
      cout<<"|"<<setw(4)<<p[i].pic<<setw(6)<<p[i].pic<<setw(2)<<"|";
      cout<<" ";
    }
    else if(p[i].num==8){
      cout<<"|"<<setw(4)<<p[i].pic<<setw(6)<<p[i].pic<<setw(2)<<"|";
      cout<<" ";
    }
    else if(p[i].num==11){
      cout<<"|"<<setw(6)<<p[i].pic<<setw(4)<<"|";
      cout<<" ";
    }
    else if(p[i].num==12){
      cout<<"|"<<setw(6)<<p[i].pic<<setw(4)<<"|";
      cout<<" ";
    }
    else if(p[i].num==13){
      cout<<"|"<<setw(6)<<p[i].pic<<setw(4)<<"|";
      cout<<" ";
    }
    else{
      cout<<"|"<<setw(8)<<"|";
      cout<<" ";
    }
  }
  cout<<endl;
  //fifth suite
  for(int i = 0; i < k; i++){
    if(p[i].num==9){
      cout<<"|"<<setw(4)<<p[i].pic<<setw(6)<<p[i].pic<<setw(2)<<"|";
      cout<<" ";
    }
    else if(p[i].num==10){
      cout<<"|"<<setw(4)<<p[i].pic<<setw(6)<<p[i].pic<<setw(2)<<"|";
      cout<<" ";
    }
    else{
      cout<<"|"<<setw(8)<<"|";
      cout<<" ";
    }
  }
  cout<<endl;
  //sixth suite
  for(int i = 0; i < k; i++){
    if(p[i].num == 1){
      cout<<"|"<<setw(8)<<"|";
      cout<<" ";
    }
    else if(p[i].num == 2){
      cout<<"|"<<setw(6)<<p[i].pic<<setw(4)<<"|";
      cout<<" ";
    }
    else if(p[i].num == 8){
      cout<<"|"<<setw(6)<<p[i].pic<<setw(4)<<"|";
      cout<<" ";
    }
    else if(p[i].num == 10){
      cout<<"|"<<setw(6)<<p[i].pic<<setw(4)<<"|";
      cout<<" ";
    }
    else{
      cout<<"|"<<setw(8)<<"|";
      cout<<" ";
    }
  }
  cout<<endl;
  //seventh suite
  for(int i = 0; i < k; i++){
    if(p[i].num==3){
      cout<<"|"<<setw(6)<<p[i].pic<<setw(4)<<"|";
      cout<<" ";
    }
    else if(p[i].num==4){
      cout<<"|"<<setw(4)<<p[i].pic<<setw(6)<<p[i].pic<<setw(2)<<"|";
      cout<<" ";
    }
    else if(p[i].num==5){
      cout<<"|"<<setw(4)<<p[i].pic<<setw(6)<<p[i].pic<<setw(2)<<"|";
      cout<<" ";
    }
    else if(p[i].num==6){
      cout<<"|"<<setw(4)<<p[i].pic<<setw(6)<<p[i].pic<<setw(2)<<"|";
      cout<<" ";
    }
    else if(p[i].num==7){
      cout<<"|"<<setw(4)<<p[i].pic<<setw(6)<<p[i].pic<<setw(2)<<"|";
      cout<<" ";
    }
    else if(p[i].num==8){
      cout<<"|"<<setw(4)<<p[i].pic<<setw(6)<<p[i].pic<<setw(2)<<"|";
      cout<<" ";
    }
    else if(p[i].num==9){
      cout<<"|"<<setw(4)<<p[i].pic<<setw(6)<<p[i].pic<<setw(2)<<"|";
      cout<<" ";
    }
    else if(p[i].num==10){
      cout<<"|"<<setw(4)<<p[i].pic<<setw(6)<<p[i].pic<<setw(2)<<"|";
      cout<<" ";
    }
    else{
      cout<<"|"<<setw(8)<<"|";
      cout<<" ";
    }
  }
  cout<<endl;
  for(int i = 0; i < k; i++){
    if(p[i].num == 1){
      cout<<"|"<<"A"<<setw(7)<<"|";
      cout<<" ";
    }
    else if(p[i].num == 11){
      cout<<"|"<<"J"<<setw(7)<<"|";
      cout<<" ";
    }
    else if(p[i].num == 12){
      cout<<"|"<<"Q"<<setw(7)<<"|";
      cout<<" ";
    }
    else if(p[i].num == 13){
      cout<<"|"<<"K"<<setw(7)<<"|";
      cout<<" ";
    }
    else if(p[i].num == 10){
    cout<<"|"<<p[i].num<<setw(6)<<"|";
    cout<<" ";
    }
    else{
      cout<<"|"<<p[i].num<<setw(7)<<"|";
      cout<<" ";
    }
  }
  cout<<endl;
  for(int i = 0; i < k; i++){
    cout<<" ------- ";
    cout<<" ";
  }
  cout<<endl;

}

//get next card function
DeckCard Card::GetNextCard(){
  DeckCard next = nextCard;
  //update nextCard
  nextCard = arrCards[nextCounter];
  return next;
}

//SHUFFLES CARDS BEFORE EVERY GAME
void Card::ShuffleCard(DeckCard arrCards[]){
  int rNum;
  int insert = 0;
  int size = 52;
  bool verify = false;
  int numVerification[52]; //TO VERIFY THAT NO RANDOM NUMBER GETS PICKED TWICE
  DeckCard arrCardstemp[52]; //TO TEMPORARILY STORE THE SORTED CARDS
  srand(time(0));
  srand((unsigned)time(NULL));
  rNum = rand()% 52; //GENERATES A RANDOM NUMBER FROM 1 TO 52
  numVerification[insert] = rNum;
  insert++;

  while(insert < size){
    verify = false;
    rNum = rand()% 52; //GENERATES A RANDOM NUMBER FROM 1 TO 52
    int i = 0;
    while(i <= insert){
      if(numVerification[i] == rNum){
        i = insert + 1;
        verify = true;
      }
      else i++;
    }
    if (verify == false){
      numVerification[insert]=rNum;
      insert++;
    }
  }

  for(int p = 0; p < size; p++){
    arrCardstemp[p] = arrCards[numVerification[p]];
  }
  swap(arrCards, arrCardstemp);
  nextCard.num = 0; //set nextCard to zero

}
