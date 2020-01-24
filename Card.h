#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <cstring>

using namespace std;

class Card
{
    public:
    string name;
    int value;
    int value_Ace;
    string suit;
    int countValue();
    Card();
    void addCard();

    virtual ~Card();

    protected:
    private:
};

#endif // CARD_H
