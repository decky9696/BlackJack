#include <iostream>
#include <cstring>
#include <array>
#include "include/Card.h"
#include "include/deck.h"
#include <algorithm>    // std::shuffle

#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock
#include <stack>
//#include "src/deck.cpp"


using namespace std;
// Make deck of cards
int size = 52;

int main (){

    //Card playCards[52];
    int gameOn= 1;
while(gameOn){
    deck newDeck;
    newDeck.createDeck();
    //cout<<"Before shuffle: \n"<<newDeck.playCards[1].name<<endl<<newDeck.playCards[1].suit<<endl<<newDeck.playCards[1].value<<endl;
    newDeck.shuffle();
    //cout<<"After shuffle: \n"<<newDeck.playCards[1].name<<endl<<newDeck.playCards[1].suit<<endl<<newDeck.playCards[1].value<<endl;
    int dc = 0;
    int pc = 0;
// Initialize deal
    // dealer deals
    int dScore = 0;
    Card dealerCard[10];

    dealerCard[dc] = newDeck.deckStack.top();
    dScore = dScore + dealerCard[dc].value;
    dc++;
    newDeck.deckStack.pop();


    dealerCard[dc] = newDeck.deckStack.top();
    dScore = dScore + dealerCard[dc].value;
    dc++;
    newDeck.deckStack.pop();

    // Player deals

    int pScore = 0;
    Card playerCard[10];

    playerCard[pc] = newDeck.deckStack.top();
    pScore = pScore + playerCard[pc].value;
    pc++;
    newDeck.deckStack.pop();

    playerCard[pc] = newDeck.deckStack.top();
    pScore = pScore + playerCard[pc].value;
    pc++;
    newDeck.deckStack.pop();

    cout<<"\nFirst dealer card: "<<endl<< dealerCard[0].name+ " "<< dealerCard[0].suit<<endl<<endl;
    cout<<"Player cards: "<<endl<< playerCard[0].name+ " "<< playerCard[0].suit<<endl<< playerCard[1].name+ " "<< playerCard[1].suit<<endl<<endl;
   int call = 1;
    if (pScore ==21){
        cout<<"Congrats you win!";
        call = 0;
    }



    // Gameplay
int WL = 1;
    while(call){
        cout<<" Hit? (Y/N) \n";

        char hit;
        cin>>hit;

        if (hit == 'Y'){
            playerCard[pc] = newDeck.deckStack.top();
            pScore = pScore + playerCard[pc].value;
            pc++;
            newDeck.deckStack.pop();
        }

        if(hit == 'N'){
            call = 0;
        }
        for(int i=0; i< pc;i++){
            cout<< playerCard[i].name + " "<<playerCard[i].suit + "  "<<playerCard[i].value<<endl;
        }
// chekc ace if over 21
int aceVal = 0;
    if (pScore >= 21){
        for(int i=0; i< pc;i++){

                if (playerCard[i].name == "Ace" && playerCard[i].value == 11){
                    playerCard[i].value = 1;
                    aceVal = 1;
                    pScore = pScore-10;
                }

        }
    }
// check if over 21 and declare loser

    if(pScore > 21){

        if(aceVal == 1){
                call = 1;
            break;
        }
            cout<< "Bust! You lose! Dealer wins \n";
            WL = 0;
            call = 0;
        }


    }


    // Dealers turn
while(WL){
    if(dScore> 21){
        cout<<"player wins \n";
        WL = 0;
        break;

    }
    if( pScore < dScore){
        cout<<"Dealer wins!"<<endl;
        WL = 0;

    }

    if(pScore > dScore){
    dealerCard[dc] = newDeck.deckStack.top();
    dScore = dScore + dealerCard[dc].value;
    dc++;
    newDeck.deckStack.pop();

    }

}
    cout<<"\n \nDealer hand: \n";
        for(int i = 0; i< dc; i++){
            cout<<dealerCard[i].name + " "<<dealerCard[i].suit<<endl;
        }

    // Ask if they want to play again
    char playQ;
    cout<<endl<<"Play again?: (Y/N)"<<endl;
    cin>>playQ;
    if (playQ == 'N'){
        gameOn = 0;
    }
}
return 0;
}
