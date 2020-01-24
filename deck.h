#ifndef DECK_H
#define DECK_H
#include <cstring>
#include <iostream>
#include "Card.h"
#include <stack>

using namespace std;


class deck
{
    public:
        stack <Card> deckStack;
        Card playCards[52];
        deck( );
        virtual ~deck();
        void shuffle();
        void createDeck();
        Card dealPlayer();
        Card dealDealer();

        //Card shuffle();

    protected:
    private:

};

#endif // DECK_H
