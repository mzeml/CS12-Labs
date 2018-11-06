#include "Card.h"
#include "Deck.h"
#include <iostream>
#include <cctype>

using namespace std;

Card::Card() //THIS CONSTRUCTOR WORKS
{
    suit = 'c';
    rank = 2;
    return;
}
Card::Card(char cs, int cv) //WORKS
{
    cs = tolower(cs);
    
    if(cs != 'c' && cs != 'd' && cs != 'h' && cs != 's')
    {
        suit = 'c';
    }
    else 
    {
        suit = cs;
    }
    
    if(cv < 14 && cv > 0)
    {
        rank = cv;
    }
    else if (cv > 13 || cv < 1)
    {
        rank = 2;
    }
    return;
}
char Card::getSuit() const
{
    return suit;
}
int Card::getRank() const
{
    return rank;
}
ostream & operator<<(ostream &out, const Card &rhs) //DONE
{
    if(rhs.suit == 'c' || rhs.suit == 'C')
    {
        if(rhs.rank == 1)
        {
            out << "Ace of Clubs";
        }
        else if(rhs.rank == 11)
        {
            out << "Jack of Clubs";
        }
        else if(rhs.rank == 12)
        {
            out << "Queen of Clubs";
        }
        else if(rhs.rank == 13)
        {
            out << "King of Clubs";
        }
        else
        {
            out << rhs.rank << " of Clubs";
        }
        return out;
    }
    if(rhs.suit == 'd' || rhs.suit == 'D')
    {
        if(rhs.rank == 1)
        {
            out << "Ace of Diamonds";
        }
        else if(rhs.rank == 11)
        {
            out << "Jack of Diamonds";
        }
        else if(rhs.rank == 12)
        {
            out << "Queen of Diamonds";
        }
        else if(rhs.rank == 13)
        {
            out << "King of Diamonds";
        }
        else
        {
            out << rhs.rank << " of Diamonds";
        }
        return out;
    }
    if(rhs.suit == 'h' || rhs.suit == 'H')
    {
        if(rhs.rank == 1)
        {
            out << "Ace of Hearts";
        }
        else if(rhs.rank == 11)
        {
            out << "Jack of Hearts";
        }
        else if(rhs.rank == 12)
        {
            out << "Queen of Hearts";
        }
        else if(rhs.rank == 13)
        {
            out << "King of Hearts";
        }
        else
        {
            out << rhs.rank << " of Hearts";
        }
        return out;
    }
    if(rhs.suit == 's' || rhs.suit == 'S')
    {
        if(rhs.rank == 1)
        {
            out << "Ace of Spades";
        }
        else if(rhs.rank == 11)
        {
            out << "Jack of Spades";
        }
        else if(rhs.rank == 12)
        {
            out << "Queen of Spades";
        }
        else if(rhs.rank == 13)
        {
            out << "King of Spades";
        }
        else
        {
            out << rhs.rank << " of Spades";
        }
        return out;
    }
    return out;
}