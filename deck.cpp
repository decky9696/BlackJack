#include "../include/deck.h"
#include "../include/Card.h"
#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>
#include <random>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <stack>
#include <array>
deck::deck()
{
    //ctor
}
/*Card deck::dealPlayer(){

//int sizeOfDeck = size(deck.playCards)

}*/

void deck::shuffle(){
    srand (time(NULL));
    Card temp;
    int len =52;
    int randIndex = 0;
    for (int i =0; i < len; i++){
        randIndex = rand() % len;
        temp = playCards[i];

        playCards[i] = playCards[randIndex];
        playCards[randIndex] = temp;
      //  cout << i << "\n";
        //cout<< "Index " << randIndex << "\n";
        }
            for(int i = 0; i<52; i++){
        deckStack.push(playCards[i]);
    }
}

void deck::createDeck(){
    string nameCards[] = { "King", "Queen", "Jack", "Ten", "Nine", "Eight",
                        "Seven", "Six", "Five", "Four", "Three", "Two", "Ace"};
    int valueCards[] = {10, 10, 10, 10, 9, 8,7,6,5,4,3,2,11};
    string suitCards[] = {"Hearts", "Diamonds", "Spades", "Clubs"};

    int count = 0;
    for (int j = 0; j<4; j++){
        for (int i =0; i <13; i++){
            playCards[count].name = nameCards[i];
            playCards[count].value = valueCards[i];
            playCards[count].suit = suitCards[j];
            count++;
                }
            }



}

deck::~deck()
{
    //dtor
}
