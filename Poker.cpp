//Poker
#include "Project.cpp"
#include <iostream>
#include <string>
using namespace std;


//function prototypes
bool RoyalFlush(DeckCard drawn[]);
//straight flush function
bool StraightFlush(DeckCard drawn[]);
//four of a kind function
bool Four(DeckCard drawn[]);
//full house function
bool Full(DeckCard drawn[]);
//flush function
bool Flush(DeckCard drawn[]);
//straight function
bool Straight(DeckCard drawn[]);
//triple function
bool Triple(DeckCard drawn[]);
//two pair function
bool TPair(DeckCard drawn[]);
//Jack or better function
bool JorB(DeckCard drawn[]);

//poker class
class Poker : public Card{
private:
  int betAmount;
  int currentBalance;
public:
  Poker(){
    betAmount = 0;
    currentBalance = 0;
  }
  void setAmount(int n); //sets bet amount
  int getAmount(); //returns bet amount
  void setCurrentBalance(int n); //sets current balance
  int getCurrentBalance(); //gets current balance
};

//setAmount function
void Poker::setAmount(int n){
  betAmount = n;
}

//getAmount function
int Poker::getAmount(){
  return betAmount;
}

//setCurrentBalance function
void Poker::setCurrentBalance(int n){
currentBalance = n;
}

//getCurrentBalance function
int Poker::getCurrentBalance(){
  return currentBalance;
}

//Poker game function
void PokerGame(){
  Poker game;
  int choice1 = 0;
  int choice2 = 0;
  int size = 5;
  int bet = 0;
  int cb = 0; //current balance
  int cb2 = 0; // keeps track of the current balance for display after the game
  bool test = false;
  bool test2 = false; //stops the game from checking for other conditions when the a value has been assigned
  DeckCard drawn[5];
  DeckCard redraw[5];
  cout<<endl<<endl;
  cout<<"|---------------------WELCOME TO IKEM'S POKER---------------------|"<<endl;
  cout<<endl;
  cout<<" __________________________________________"<<endl;
  cout<<"| Enter (1) to continue game or (0) to exit|"<<endl;
  cout<<" ------------------------------------------"<<endl;
  cout<<"Choice: ";
  cin>>choice1;
  cout<<endl;
  while(choice1 != 1 && choice1 != 0){
    cout<<" __________________________________________"<<endl;
    cout<<"| Error: Invalid Entry!!!------------------|"<<endl;
    cout<<"| Enter (1) to continue game or (0) to exit|"<<endl;
    cout<<" ------------------------------------------"<<endl;
    cout<<"Choice: ";
    cin>>choice1;
    cout<<endl;
  }
  do{
    cb2 = 0;
    test2 = false;
    if(choice1 == 1){
      cout<<"Enter bet amount: $";
      cin>>bet;
      cout<<endl; cout<<endl;
      while(bet <= 0){
        cout<<"Error: Bet must be greater than 0"<<endl;
        cout<<"Enter bet amount: $";
        cin>>bet;
        cout<<endl; cout<<endl;
      }
      game.setAmount(bet);
      game.setCurrentBalance(cb);
      game.ShuffleCard(game.arrCards);
      //draw 5 cards
      size = 5;
      for(int i = 0; i<size; i++){
        drawn[i] = game.arrCards[i];
      }
      for(int i = 0; i<size; i++){
        redraw[i] = drawn[i];
      }
      game.nextCounter = 5;

    //displays 5 cards
    PrintCard(drawn, size);
    //hold or redraw
    cout<<"HOLD OR REDRAW"<<endl;
    //first card
    PrintCard(redraw, 1);
    cout<<endl;
    cout<<"Enter (0) to HOLD or (1) to REDRAW: ";
    cin>>choice2;
    cout<<endl;
    while(choice2 != 0 && choice2 != 1){
      cout<<"Invalid Entry!!!"<<endl;
      cout<<"Enter (1) to HOLD or (0) to REDRAW: ";
      cin>>choice2;
      cout<<endl;
    }
    if( choice2 == 1){
      drawn[0] = game.arrCards[game.nextCounter];
      game.nextCounter++;
    }
    //second card
    redraw[0] = redraw[1];
    PrintCard(redraw, 1);
    cout<<endl;
    cout<<"Enter (0) to HOLD or (1) to REDRAW: ";
    cin>>choice2;
    cout<<endl;
    while(choice2 != 0 && choice2 != 1){
      cout<<"Invalid Entry!!!"<<endl;
      cout<<"Enter (1) to HOLD or (0) to REDRAW: ";
      cin>>choice2;
      cout<<endl;
    }
    if( choice2 == 1){
      drawn[1] = game.arrCards[game.nextCounter];
      game.nextCounter++;
    }
    //third card
    redraw[0] = redraw[2];
    PrintCard(redraw, 1);
    cout<<endl;
    cout<<"Enter (0) to HOLD or (1) to REDRAW: ";
    cin>>choice2;
    cout<<endl;
    while(choice2 != 0 && choice2 != 1){
      cout<<"Invalid Entry!!!"<<endl;
      cout<<"Enter (1) to HOLD or (0) to REDRAW: ";
      cin>>choice2;
      cout<<endl;
    }
    if( choice2 == 1){
      drawn[2] = game.arrCards[game.nextCounter];
      game.nextCounter++;
    }
    //fourth card
    redraw[0] = redraw[3];
    PrintCard(redraw, 1);
    cout<<endl;
    cout<<"Enter (0) to HOLD or (1) to REDRAW: ";
    cin>>choice2;
    cout<<endl;
    while(choice2 != 0 && choice2 != 1){
      cout<<"Invalid Entry!!!"<<endl;
      cout<<"Enter (1) to HOLD or (0) to REDRAW: ";
      cin>>choice2;
      cout<<endl;
    }
    if( choice2 == 1){
      drawn[3] = game.arrCards[game.nextCounter];
      game.nextCounter++;
    }
    //fifth card
    redraw[0] = redraw[4];
    PrintCard(redraw, 1);
    cout<<endl;
    cout<<"Enter (0) to HOLD or (1) to REDRAW: ";
    cin>>choice2;
    cout<<endl;
    while(choice2 != 0 && choice2 != 1){
      cout<<"Invalid Entry!!!"<<endl;
      cout<<"Enter (1) to HOLD or (0) to REDRAW: ";
      cin>>choice2;
      cout<<endl;
      }
      if( choice2 == 1){
        drawn[4] = game.arrCards[game.nextCounter];
        game.nextCounter++;
      }
      //display newly drawn cards
      //sort cards
      DeckCard swap;
      for(int i = 0; i<size; i++){
        for(int p = 0; p<size; p++){
          if(drawn[i].num < drawn[p].num){
            swap = drawn[i];
            drawn[i] = drawn[p];
            drawn[p] = swap;
          }
        }
      }
      PrintCard(drawn, size);
      cout<<endl;cout<<endl;
      //if hand was a royal flush
      test = RoyalFlush(drawn);
      if( test == true && test2 == false){
        cout<<"ROYAL FLUSH   \\ ^_^ /    $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
        cb = (game.getAmount() * 10000) + game.getCurrentBalance();
        cb2 = game.getAmount() * 10000;
        game.setCurrentBalance(cb);
        test2 = true;
      }
      if(test == false){ //check if test is false before resetting it
        test = StraightFlush(drawn);
      }
      else test = false; //else make it false so it doesn't assign another balance to the card
      //if hand was a straight flush
      if( test == true && test2 == false){
        cout<<"STRAIGHT FLUSH   \\ ^_^ /    $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
        cb = (game.getAmount() * 1000) + game.getCurrentBalance();
        cb2 = game.getAmount() * 1000;
        game.setCurrentBalance(cb);
        test2 = true;
      }

      //if hand was a four of a kind
      if(test == false){ //check if test is false before resetting it
        test = Four(drawn);
      }
      else test = false; //else make it false so it doesn't assign another balance to the card
      if( test == true && test2 == false){
        cout<<"FOUR OF A KIND   \\ ^_^ /    $$$$$$$$$$$$$$"<<endl;
        cb = (game.getAmount() * 20) + game.getCurrentBalance();
        cb2 = game.getAmount() * 20;
        game.setCurrentBalance(cb);
        test2 = true;
      }

      //if hand was a full house
      if(test == false){ //check if test is false before resetting it
        test = Full(drawn);
      }
      else test = false; //else make it false so it doesn't assign another balance to the card
      if( test == true && test2 == false){
        cout<<"FULL HOUSE   \\ ^_^ /    $$$$$$$$"<<endl;
        cb = (game.getAmount() * 10) + game.getCurrentBalance();
        cb2 = game.getAmount() * 10;
        game.setCurrentBalance(cb);
        test2 = true;
      }

      //if hand was a flush
      if(test == false){ //check if test is false before resetting it
        test = Flush(drawn);
      }
      else test = false; //else make it false so it doesn't assign another balance to the card
      if( test == true && test2 == false){
        cout<<"FLUSH   \\ ^_^ /    $$$$$$"<<endl;
        cb = (game.getAmount() * 8) + game.getCurrentBalance();
        cb2 = game.getAmount() * 8;
        game.setCurrentBalance(cb);
        test2 = true;
      }

      //if hand was a straight
      if(test == false){ //check if test is false before resetting it
        test = Straight(drawn);
      }
      else test = false; //else make it false so it doesn't assign another balance to the card
      if( test == true && test2 == false){
        cout<<"STRAIGHT   \\ ^_^ /    $$$$$$"<<endl;
        cb = (game.getAmount() * 6) + game.getCurrentBalance();
        cb2 = game.getAmount() * 6;
        game.setCurrentBalance(cb);
        test2 = true;
      }

      //if hand was a triple
      if(test == false){ //check if test is false before resetting it
        test = Triple(drawn);
      }
      else test = false; //else make it false so it doesn't assign another balance to the card
      if( test == true && test2 == false){
        cout<<"TRIPLE   \\ ^_^ /    $$$$$$"<<endl;
        cb = (game.getAmount() * 4) + game.getCurrentBalance();
        cb2 = game.getAmount() * 4;
        game.setCurrentBalance(cb);
        test2 = true;
      }

      //if hand was a two pair
      if(test == false){ //check if test is false before resetting it
        test = TPair(drawn);
      }
      else test = false; //else make it false so it doesn't assign another balance to the card
      if( test == true && test2 == false){
        cout<<"TWO PAIRS   \\ ^_^ /   $$$$$$"<<endl;
        cb = (game.getAmount() * 2) + game.getCurrentBalance();
        cb2 = game.getAmount() * 2;
        game.setCurrentBalance(cb);
        test2 = true;
      }

      //if hand was jack or better
      if(test == false){ //check if test is false before resetting it
        test = JorB(drawn);
      }
      else test = false; //else make it false so it doesn't assign another balance to the card
      if( test == true && test2 == false){
        cout<<"JACK OR BETTER   \\ ^_^ /   $$$$$$"<<endl;
        cb = (game.getAmount() * 1) + game.getCurrentBalance();
        cb2 = game.getAmount() * 1;
        game.setCurrentBalance(cb);
        test = true;
      }

      //else sorry you lost
      else if(test == false && test2 == false){
        cout<<"                           __"<<endl;
        cout<<"SORRY YOU LOST YOUR BET   |@@|"<<endl;
        cout<<"                          |~~|"<<endl;
        cout<<"                           --"<<endl;
      }

    //display game summary
    cout<<endl;cout<<endl;
    cout<<" _________________________________________"<<endl;
    cout<<"| Initial bet: $"<<game.getAmount()<<endl;
    cout<<"| Current Balance: $"<<game.getCurrentBalance()<<endl;
    cout<<"| Earnings: $"<<cb2-game.getAmount()<<endl;
    cout<<"|_________________________________________"<<endl;

    cout<<endl;
    cout<<" __________________________________________"<<endl;
    cout<<"| Enter (1) to continue game or (0) to exit|"<<endl;
    cout<<" ------------------------------------------"<<endl;
    cout<<"Choice: ";
    cin>>choice1;
    cout<<endl;
    while(choice1 != 1 && choice1 != 0){
      cout<<" __________________________________________"<<endl;
      cout<<"| Error: Invalid Entry!!!------------------|"<<endl;
      cout<<"| Enter (1) to continue game or (0) to exit|"<<endl;
      cout<<" ------------------------------------------"<<endl;
      cout<<"Choice: ";
      cin>>choice1;
      cout<<endl;
    }
    }//end if statement
  }while(choice1 == 1);
  cout<<endl;
  cout<<"THANKS FOR PLAYING!!!"<<endl;
  cout<<endl<<endl;
}

//poker game test function
void PokerGameTest(){
  Poker game;
  DeckCard drawn[5];
  int size = 5;
  int bet;
  int cb = 0;
  int cb2 = 0;
  int card;
  int choice;
  int choice2;
  bool test = false;
  bool test2 = false;
  cout<<"--------WELCOME TO IKEM'S POKER TEST--------"<<endl<<endl;
  do{
    test = false;
    test2 = false;
    cout<<"Enter bet amount: $";
    cin>>bet;
    while(bet<=0){
      cout<<"ERROR: Bet must be more than $0"<<endl;
      cout<<"Enter bet amount: $";
      cin>>bet;
    }
    game.setAmount(bet);
      for(int i = 0; i<size; i++){
        cout<<"Enter card number of choice for card " <<i+1<<": ";
        cin>>card;
        while(card<=0 && card > 13){
          cout<<"ERROR: Card cannot be less than 0 or more than 13"<<endl;
          cout<<"Enter card number of choice for card " <<i+1<<": ";
          cin>>card;
        }
        cout<<endl;cout<<endl;
        cout<<"Enter (1) for Spade"<<endl;
        cout<<"Enter (2) for Heart"<<endl;
        cout<<"Enter (3) for Diamond"<<endl;
        cout<<"Enter (4) for Club"<<endl;
        cin>>choice2;
        while(choice2 != 1 && choice2 != 2 && choice2 != 3 && choice2 != 4){
          cout<<"ERROR: Invalid entry"<<endl;
          cout<<"Enter (1) for Spade"<<endl;
          cout<<"Enter (2) for Heart"<<endl;
          cout<<"Enter (3) for Diamond"<<endl;
          cout<<"Enter (4) for Club"<<endl;
          cin>>choice2;
        }
        drawn[i].num = card;
        if(choice2 == 1){
          for(int p = 0; p < 4; p++){
            drawn[i].pic[p] = spade[p];
          }
          drawn[i].id = 1;
        }
        else if(choice2 == 2){
          for(int p = 0; p < 4; p++){
            drawn[i].pic[p] = heart[p];
          }
          drawn[i].id = 3;
        }

        else if(choice2 == 3){
          for(int p = 0; p < 4; p++){
            drawn[i].pic[p] = diamond[p];
          }
          drawn[i].id = 4;
        }
        else if(choice2 == 4){
          for(int p = 0; p < 4; p++){
            drawn[i].pic[p] = club[p];
          }
          drawn[i].id = 2;
        }
      }
      //display newly drawn cards
      //sort cards
      DeckCard swap;
      for(int i = 0; i<size; i++){
        for(int p = 0; p<size; p++){
          if(drawn[i].num < drawn[p].num){
            swap = drawn[i];
            drawn[i] = drawn[p];
            drawn[p] = swap;
          }
        }
      }
      PrintCard(drawn, 5);
      cout<<endl;cout<<endl;
      //if hand was a royal flush
      test = RoyalFlush(drawn);
      if( test == true && test2 == false){
        cout<<"ROYAL FLUSH   \\ ^_^ /    $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
        cb = (game.getAmount() * 10000) + game.getCurrentBalance();
        cb2 = game.getAmount() * 10000;
        game.setCurrentBalance(cb);
        test2 = true;
      }
      if(test == false){ //check if test is false before resetting it
        test = StraightFlush(drawn);
      }
      else test = false; //else make it false so it doesn't assign another balance to the card
      //if hand was a straight flush
      if( test == true && test2 == false){
        cout<<"STRAIGHT FLUSH   \\ ^_^ /    $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
        cb = (game.getAmount() * 1000) + game.getCurrentBalance();
        cb2 = game.getAmount() * 1000;
        game.setCurrentBalance(cb);
        test2 = true;
      }

      //if hand was a four of a kind
      if(test == false){ //check if test is false before resetting it
        test = Four(drawn);
      }
      else test = false; //else make it false so it doesn't assign another balance to the card
      if( test == true && test2 == false){
        cout<<"FOUR OF A KIND   \\ ^_^ /    $$$$$$$$$$$$$$"<<endl;
        cb = (game.getAmount() * 20) + game.getCurrentBalance();
        cb2 = game.getAmount() * 20;
        game.setCurrentBalance(cb);
        test2 = true;
      }

      //if hand was a full house
      if(test == false){ //check if test is false before resetting it
        test = Full(drawn);
      }
      else test = false; //else make it false so it doesn't assign another balance to the card
      if( test == true && test2 == false){
        cout<<"FULL HOUSE   \\ ^_^ /    $$$$$$$$"<<endl;
        cb = (game.getAmount() * 10) + game.getCurrentBalance();
        cb2 = game.getAmount() * 10;
        game.setCurrentBalance(cb);
        test2 = true;
      }

      //if hand was a flush
      if(test == false){ //check if test is false before resetting it
        test = Flush(drawn);
      }
      else test = false; //else make it false so it doesn't assign another balance to the card
      if( test == true && test2 == false){
        cout<<"FLUSH   \\ ^_^ /    $$$$$$"<<endl;
        cb = (game.getAmount() * 8) + game.getCurrentBalance();
        cb2 = game.getAmount() * 8;
        game.setCurrentBalance(cb);
        test2 = true;
      }

      //if hand was a straight
      if(test == false){ //check if test is false before resetting it
        test = Straight(drawn);
      }
      else test = false; //else make it false so it doesn't assign another balance to the card
      if( test == true && test2 == false){
        cout<<"STRAIGHT   \\ ^_^ /    $$$$$$"<<endl;
        cb = (game.getAmount() * 6) + game.getCurrentBalance();
        cb2 = game.getAmount() * 6;
        game.setCurrentBalance(cb);
        test2 = true;
      }

      //if hand was a triple
      if(test == false){ //check if test is false before resetting it
        test = Triple(drawn);
      }
      else test = false; //else make it false so it doesn't assign another balance to the card
      if( test == true && test2 == false){
        cout<<"TRIPLE   \\ ^_^ /    $$$$$$"<<endl;
        cb = (game.getAmount() * 4) + game.getCurrentBalance();
        cb2 = game.getAmount() * 4;
        game.setCurrentBalance(cb);
        test2 = true;
      }

      //if hand was a two pair
      if(test == false){ //check if test is false before resetting it
        test = TPair(drawn);
      }
      else test = false; //else make it false so it doesn't assign another balance to the card
      if( test == true && test2 == false){
        cout<<"TWO PAIRS   \\ ^_^ /   $$$$$$"<<endl;
        cb = (game.getAmount() * 2) + game.getCurrentBalance();
        cb2 = game.getAmount() * 2;
        game.setCurrentBalance(cb);
        test2 = true;
      }

      //if hand was jack or better
      if(test == false){ //check if test is false before resetting it
        test = JorB(drawn);
      }
      else test = false; //else make it false so it doesn't assign another balance to the card
      if( test == true && test2 == false){
        cout<<"JACK OR BETTER   \\ ^_^ /   $$$$$$"<<endl;
        cb = (game.getAmount() * 1) + game.getCurrentBalance();
        cb2 = game.getAmount() * 1;
        game.setCurrentBalance(cb);
        test = true;
      }

      //else sorry you lost
      else if(test == false && test2 == false){
        cout<<"                           __"<<endl;
        cout<<"SORRY YOU LOST YOUR BET   |@@|"<<endl;
        cout<<"                          |~~|"<<endl;
        cout<<"                           --"<<endl;
      }

    //display game summary
    cout<<endl;cout<<endl;
    cout<<" _________________________________________"<<endl;
    cout<<"| Initial bet: $"<<game.getAmount()<<endl;
    cout<<"| Current Balance: $"<<game.getCurrentBalance()<<endl;
    cout<<"| Earnings: $"<<cb2-game.getAmount()<<endl;
    cout<<"|_________________________________________"<<endl;
    cout<<endl;
    cout<<"Do you want to continue testing the Poker game?"<<endl;
    cout<<"Enter (1) for yes or (0) for NO"<<endl;
    cout<<"Choice: ";
    cin>>choice;
    while(choice != 1 && choice != 0){
      cout<<"ERROR: Invalid entry"<<endl;
      cout<<"Enter (1) for yes or (0) for NO"<<endl;
      cout<<"Choice: ";
      cin>>choice;
    }
  }while(choice==1);
}

//Jack or better function
bool JorB(DeckCard drawn[]){
  DeckCard temp[10];
  int size = 5;
  bool result = false;
  for(int i = 0; i<size; i++){
    temp[i] = drawn[i];
  }
  int i = 0;
  while(i < size){
    if(temp[i].num > 10){
      return true;
    }
    else i++;
  }
  return false;
}

//two pair function
bool TPair(DeckCard drawn[]){
  DeckCard temp[10];
  int size = 5;
  for(int i = 0; i<size; i++){
    temp[i] = drawn[i];
  }
  if(temp[0].num == temp[1].num && temp[2].num == temp[3].num){
    return true;
  }
  else if(temp[0].num == temp[1].num && temp[3].num == temp[4].num){
    return true;
  }
  else if(temp[1].num == temp[2].num && temp[3].num == temp[4].num){
    return true;
  }
  else return false;
}

//triple function
bool Triple(DeckCard drawn[]){
  DeckCard temp[10];
  int size = 5;
  for(int i = 0; i<size; i++){
    temp[i] = drawn[i];
  }
  if(temp[1].num == temp[0].num && temp[2].num == temp[0].num){
    return true;
  }
  else if(temp[2].num == temp[1].num && temp[3].num == temp[1].num){
    return true;
  }
  else if(temp[3].num == temp[2].num && temp[2].num == temp[4].num){
    return true;
  }
  else return false;
}

//straight function
bool Straight(DeckCard drawn[]){
  DeckCard temp[10];
  int size = 5;
  for(int i = 0; i<size; i++){
    temp[i] = drawn[i];
  }
  if(temp[1].num == temp[0].num+1 && temp[2].num == temp[1].num+1 && temp[3].num == temp[2].num+1 && temp[4].num == temp[3].num+1){
    return true;
  }

  else return false;
}

//flush function
bool Flush(DeckCard drawn[]){
  DeckCard temp[10];
  int size = 5;
  for(int i = 0; i<size; i++){
    temp[i] = drawn[i];
  }
  if(temp[1].id == temp[0].id && temp[2].id == temp[0].id && temp[3].id == temp[0].id && temp[4].id == temp[0].id){
    return true;
  }
  else return false;
}

//full house function
bool Full(DeckCard drawn[]){
  DeckCard temp[10];
  int size = 5;
  for(int i = 0; i<size; i++){
    temp[i] = drawn[i];
  }
  if(temp[1].num == temp[0].num && temp[2].num == temp[3].num && temp[3].num == temp[4].num){
    return true;
  }
  else if(temp[0].num == temp[1].num && temp[1].num == temp[2].num && temp[3].num == temp[4].num){
      return true;
  }
  else return false;
}


//four of a kind function
bool Four(DeckCard drawn[]){
  DeckCard temp[10];
  int size = 5;
  for(int i = 0; i<size; i++){
    temp[i] = drawn[i];
  }
  if(temp[1].num == temp[0].num && temp[2].num == temp[0].num && temp[3].num == temp[0].num){
    return true;
  }
  else if(temp[1].num == temp[4].num && temp[2].num == temp[4].num && temp[3].num == temp[4].num){
      return true;
  }
  else return false;
}

//straight flush function
bool StraightFlush(DeckCard drawn[]){
  DeckCard temp[10];
  DeckCard swap; //for swapping during sorting
  DeckCard temp2[10];
  int size = 5;
  for(int i = 0; i<size; i++){
    temp2[i] = drawn[i];
  }
  int count = 0;
  bool test2 = false;
  temp[count] = drawn[count];
  count++;
  while(count < size && test2 == false){

    //while(count2 < size){

      //else if(drawn[count2].num == 10){
        for(int i = 0; i<size; i++){ //check for duplicates
          if(temp[i].num == drawn[count].num && test2 == false){
            test2 = true;
          }
        }
          if(test2 == false){
            temp[count] = drawn[count];
          }
        count++;
      }
  cout<<"This is temp"<<endl;
  PrintCard(temp, 5);
  //check for suites
  //check for spades
  if(temp[0].id == 1 && temp[1].id == 1 && temp[2].id == 1 && temp[3].id == 1 && temp[4].id == 1){
    if(temp[1].num == temp[0].num+1 && temp[2].num == temp[1].num+1 && temp[3].num == temp[2].num+1 && temp[4].num == temp[3].num+1){
      return true;
    }
  }
  //check for clubs
  else if(temp[0].id == 2 && temp[1].id == 2 && temp[2].id == 2 && temp[3].id == 2 && temp[4].id == 2){
    if(temp[1].num == temp[0].num+1 && temp[2].num == temp[1].num+1 && temp[3].num == temp[2].num+1 && temp[4].num == temp[3].num+1){
      return true;
    }
  }
  //check for hearts
  else if(temp[0].id == 3 && temp[1].id == 3 && temp[2].id == 3 && temp[3].id == 3 && temp[4].id == 3){
    if(temp[1].num == temp[0].num+1 && temp[2].num == temp[1].num+1 && temp[3].num == temp[2].num+1 && temp[4].num == temp[3].num+1){
      return true;
    }
  }
  //check for diamonds
  else if(temp[0].id == 4 && temp[1].id == 4 && temp[2].id == 4 && temp[3].id == 4  && temp[4].id == 4){
    if(temp[1].num == temp[0].num+1 && temp[2].num == temp[1].num+1 && temp[3].num == temp[2].num+1 && temp[4].num == temp[3].num+1){
      return true;
    }
  }

  else return false;
}

//royal flush function
bool RoyalFlush(DeckCard drawn[]){
  DeckCard temp[5];
  int size = 5;
  int count = 0;
  int count2 = 0;
  bool test = false;
  bool test2 = false;
  if(drawn[count].num == 1){
    temp[count] = drawn[count];
  }
  count++;
  while(count < size && test2 == false){

    //while(count2 < size){

      //else if(drawn[count2].num == 10){
        for(int i = 0; i<size; i++){ //check for duplicates
          if(temp[i].num == drawn[count].num && test2 == false){
            test2 = true;
          }
        }
          if(test2 == false){
            temp[count] = drawn[count];
          }
        count++;
      }
    //  }
    /*  else if(drawn[count2].num == 11){
        for(int i = 0; i<size; i++){ //check for duplicates
          if(temp[i].num == drawn[count2].num){
            count = size + 1;
          }
          else temp[count] = drawn[count2];
        }
      }
      else if(drawn[count2].num == 12){
        for(int i = 0; i<size; i++){ //check for duplicates
          if(temp[i].num == drawn[count2].num){
            count = size + 1;
          }
          else temp[count] = drawn[count2];
        }
      }
      else if(drawn[count2].num == 13){
        for(int i = 0; i<size; i++){ //check for duplicates
          if(temp[i].num == drawn[count2].num){
            count = size + 1;
          }
          else temp[count] = drawn[count2];
        }
      }
      count2++;
    }*/

  /*//display temp
  cout<<"This is temp"<<endl;
  PrintCard(temp, size);*/
  //check for suites
  if(temp[0].id == 1 && temp[1].id == 1 && temp[2].id == 1 && temp[3].id == 1 && temp[4].id == 1){
    test = true;
  }
  else if(temp[0].id == 2 && temp[1].id == 2 && temp[2].id == 2 && temp[3].id == 2 && temp[4].id == 2){
    test = true;
  }
  else if(temp[0].id == 3 && temp[1].id == 3 && temp[2].id == 3 && temp[3].id == 3 && temp[4].id == 3){
    test = true;
  }
  else if(temp[0].id == 4 && temp[1].id == 4 && temp[2].id == 4 && temp[3].id == 4 && temp[4].id == 4){
    test = true;
  }

  else {
    test = false;
  }
  return test;
}
