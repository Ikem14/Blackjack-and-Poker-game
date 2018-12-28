//Black Jack
#include "Project.h"
#include <iostream>
#include <string>
using namespace std;

//black jack class
class BlackJack : public Card{
private:
  int seedMoney;
  int betAmount;
  int currentBalance;
public:
  BlackJack(){ //constructor
    seedMoney = 0;
    betAmount = 0;
    currentBalance = 0;
  }
  void setSeedMoney(int n);
  void setBetAmount(int n);
  void setCurrentBalance(int n);
  int getSeedMoney();
  int getBetAmount();
  int getCurrentBalance();
};

//setSeedMoney function
void BlackJack::setSeedMoney(int n){
  seedMoney = n;
}

//setBetAmount function
void BlackJack::setBetAmount(int n){
  betAmount = n;
}

//setCurrentBalance function
void BlackJack::setCurrentBalance(int n){
  currentBalance = n;
}

//get seed Money function
int BlackJack::getSeedMoney(){
  return seedMoney;
}

//getBetAmount function
int BlackJack::getBetAmount(){
  return betAmount;
}

//getCurrentBalance function
int BlackJack::getCurrentBalance(){
  return currentBalance;
}

//black jack game function
void BlackJackGame(){
  BlackJack game;
  int choice1 = 0;
  int choice2; //for the menus
  int choice3;
  int seed = 0; //seed amount
  int bet = 0; //bet amount
  int cb = 0; //current balance
  int count1 = 0; //counts cards for dealer and player
  int dealerTotal = 0; //keeps track of the dealer's total
  int playerTotal = 0; //keeps track of the player's total
  int playerCard = 0; //keeps track of the player's array of cards
  int dealerCard = 0; //keeps track of the dealer's array of cards
  DeckCard player[10]; // for the player
  DeckCard dealer[10]; //for the dealer
  int insurance = 0; //for insurance amount
  cout<<"---------------WELCOME TO IKEM'S BLACK-JACK---------------"<<endl<<endl;
  do{
      cout<<"Enter (1) to CONTINUE game or (0) to QUIT"<<endl;
      cout<<"Choice: ";
      cin>>choice1;
      cout<<endl;
      while(choice1 != 1 && choice1 != 0){
        cout<<"ERROR: Invalid entry!!!"<<endl;
        cout<<"Enter (1) to CONTINUE game or (0) to QUIT"<<endl;
        cout<<"Choice: ";
        cin>>choice1;
        cout<<endl;
      }
    //get seed
    if(choice1 == 1){
      cout<<"Enter seed money to continue game"<<endl;
      cout<<"Seed: $";
      cin>>seed;
      cout<<endl;
      while(seed < 1){
        cout<<"ERROR: Seed amount must be greater than $0"<<endl;
        cout<<"Enter seed money to continue game"<<endl;
        cout<<"Seed: $";
        cin>>seed;
        cout<<endl;
      }
    }
      do{
        cout<<"Enter (1) to CONTINUE playing or (0) to quit"<<endl;
        cout<<"Choice: ";
        cin>>choice3;
        cout<<endl;
        while(choice3 != 1 && choice3 != 0){
          cout<<"ERROR: Invalid Entry!!!"<<endl;
          cout<<"Enter (1) to CONTINUE playing or (0) to quit"<<endl;
          cout<<"Choice: ";
          cin>>choice3;
          cout<<endl;
        }
        if(choice3 == 0){
          choice1 = 0;
          seed = 0;
        }
        else{
      //get bet
      cout<<"Enter bet to continue game"<<endl;
      cout<<"Bet: $";
      cin>>bet;
      cout<<endl;
      while(bet < 1 || bet > seed){
        cout<<"ERROR: bet must be greater than $0 and not more than seed"<<endl;
        cout<<"Enter bet to continue game"<<endl;
        cout<<"Bet: $";
        cin>>bet;
        cout<<endl;
      }
      game.setSeedMoney(seed);
      game.setBetAmount(bet);
      game.ShuffleCard(game.arrCards);
      //draw cards for the player
      for(int i = 0; i<2; i++){
        player[i] = game.arrCards[count1];
        count1++;
      }
      playerCard = 2;
      //draw cards for the dealer
      for(int i = 0; i<2; i++){
        dealer[i] = game.arrCards[count1];
        count1++;
      }
      dealerCard = 2;
      //display players cards
      cout<<"Your Cards: "<<endl;
      PrintCard(player, 2);
      //display one of dealer's cards
      cout<<"Dealer's current hand: "<<endl;
      PrintCard(dealer, 1);
      //if dealer's open card is ace, ask player for insurance
      if(dealer[0].num == 1){
        cout<<"Do you want INSURANCE? (Insurance is 50% of bet)"<<endl;
        cout<<"Enter (1) for YES or (0) for NO"<<endl;
        cin>>choice2;
        while(choice2 != 1 && choice2 != 0){
          cout<<"ERROR: Invalid Entry!!!"<<endl;
          cout<<"Do you want INSURANCE?"<<endl;
          cout<<"Enter (1) for YES or (0) for NO"<<endl;
          cin>>choice2;
        }
        //if yes, insurance is 50% of bet
        if(choice2 == 1){
          insurance = bet/2;
        }
        else insurance = 0; //else set insurance to zero
      }
      //check if dealer has black jack
      dealerTotal = dealer[0].num + dealer[1].num;
      if(dealerTotal == 21){
        PrintCard(dealer, 2);
        cout<<"Dealer got black jack"<<endl;
        cb = bet - insurance;
        game.setCurrentBalance(cb);
        //display game summary
        cout<<endl;
        cout<<" ___________GAME SUMMARY___________"<<endl;
        cout<<"| Bet: $"<<game.getBetAmount()<<endl;
        cout<<"| Current winnings: $"<<game.getCurrentBalance()<<endl;
        cout<<"| Remaining seed: $"<<game.getSeedMoney()<<endl;
        cout<<"|__________________________________"<<endl;
        }
      else{ //ask player if they want to hit or hold
        do{
          cout<<"Do you want to HIT or HOLD?"<<endl;
          cout<<"Enter (1) to HIT or (0) to HOLD"<<endl;
          cin>>choice2;
          while(choice2 != 1 && choice2 != 0){
            cout<<"ERROR: Invalid Entry!!!"<<endl;
            cout<<"Do you want to HIT or HOLD?"<<endl;
            cout<<"Enter (1) to HIT or (0) to HOLD"<<endl;
            cin>>choice2;
          }
          if(choice2 == 1){
            player[playerCard] = game.arrCards[count1];
            playerCard++;
            count1++;
          }
          cout<<"Your Current hand: "<<endl;
          PrintCard(player, playerCard);
          playerTotal = 0;
          for(int i = 0; i<playerCard; i++){
            playerTotal = playerTotal + player[i].num;
          }
          if(playerTotal > 21){
            cout<<"Your hands are over 21"<<endl;
            cout<<"Therefore, you lose your bet       __"<<endl;
            cout<<"                                  |@@|"<<endl;
            cout<<"                                  |~~|"<<endl;
            cout<<"                                   --"<<endl;
            cb = game.getCurrentBalance();
            seed = seed - bet;
            game.setCurrentBalance(cb);
            game.setSeedMoney(seed);
            choice2 = 0;
            //display game summary
            cout<<endl;
            cout<<" ___________GAME SUMMARY___________"<<endl;
            cout<<"| Bet: $"<<game.getBetAmount()<<endl;
            cout<<"| Current winnings: $"<<game.getCurrentBalance()<<endl;
            cout<<"| Remaining seed: $"<<game.getSeedMoney()<<endl;
            cout<<"|__________________________________"<<endl;
          }

        }while(choice2 != 0);
      }

      if(playerTotal<=21){
    //if dealer's hand is less than 16 keep hitting
    cout<<"Dealer's current hand: "<<endl;
    PrintCard(dealer, dealerCard);
    if(dealerTotal < 16){
      cout<<"Dealer's hand is less than 16, so dealer's HITTING"<<endl;
      while (dealerTotal < 16){
        dealer[dealerCard] = game.arrCards[count1];
        dealerTotal = dealerTotal + dealer[dealerCard].num;
        dealerCard++; count1++;
      }
      //display dealer's current hand
      PrintCard(dealer, dealerCard);
    }

    //check if player got black jack
    playerTotal = 0;
    for(int i = 0; i<playerCard; i++){
      playerTotal = playerTotal + player[i].num;
    }
    if(playerTotal == 21){
      cout<<"CONGRATULATIONS: YOU GOT BLACK JACK \\ ^_^ / $$$$$$$$$$$$$$"<<endl;
      cb = game.getCurrentBalance();
      cb = cb + (bet*1.5);
      game.setCurrentBalance(cb);
    }
    else if(dealerTotal > 21){
      cout<<"Dealer's hand is over 21: YOU WIN \\ ^_^ / $$$$"<<endl;
      cb = game.getCurrentBalance();
      cb = cb+bet;
      game.setCurrentBalance(cb);
    }
    //if player's hand is greater than dealer's
    else if(playerTotal>dealerTotal && playerTotal < 22){
      cout<<"Your card hand is greater than dealer's \\^_^/ "<<endl;
      cb = game.getCurrentBalance();
      cb = cb + bet;
      game.setCurrentBalance(cb);
    }
    //if player's total is less than dealer's total
    else if(playerTotal<dealerTotal && dealerTotal < 22){
      cout<<"Sorry, dealer's hand is greater than yours"<<endl;
      cout<<"Therefore, you lose your bet           __"<<endl;
      cout<<"                                      |@@|"<<endl;
      cout<<"                                      |~~|"<<endl;
      cout<<"                                       --"<<endl;
      cb = game.getCurrentBalance();
      seed = seed - bet;
      game.setCurrentBalance(cb);
      game.setSeedMoney(seed);
    }
    //if dealer's total is equal to player's total
    else if(dealerTotal == playerTotal && dealerTotal < 22){
      cout<<"Dealer and Player hands are equal. Therefore your bet remains intact"<<endl;
    }
    //display game summary
    cout<<endl;
    cout<<" ___________GAME SUMMARY___________"<<endl;
    cout<<"| Bet: $"<<game.getBetAmount()<<endl;
    cout<<"| Current winnings: $"<<game.getCurrentBalance()<<endl;
    cout<<"| Remaining seed: $"<<game.getSeedMoney()<<endl;
    cout<<"|__________________________________"<<endl;
    }
  }
  }while(seed != 0);
    if(seed == 0){
      cout<<"Seed is $0, therefore you cannot continue game"<<endl;
      cout<<"Enter (1) to start a new game or (0) to exit game"<<endl;
      cout<<"Choice: ";
      cin>>choice1;
      cout<<endl;
      while(choice1 != 1 && choice1 != 0){
        cout<<"ERROR: Invalid Entry!!!"<<endl;
        cout<<"Enter (1) to start a new game or (0) to exit game"<<endl;
        cout<<"Choice: ";
        cin>>choice1;
        cout<<endl;
      }
    }
  }while(choice1 == 1);
}
