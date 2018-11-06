#include "Deck.h"
#include "Card.h"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

Deck::Deck()
{
   //We have vectors of type Card. That means we can only popualte this vector with Objects of class Card. However, those objects can contain the information we need.
   //In this case it's chars and ints. Clever! Took me forever to figure this out. Thank god for youtube tutorials. Beats zyBooks at times
   
   //Due to the fact that we need to build the deck in "reverse" we start at i = 13. Weird wording in the assignment but whatever
   
   //Classes are very intresting, but man, are they confusing as you go deeper
   
   int i = 0;
   
   for(i = 13; i > 0; --i)
   {
       Card myDeck('s', i);
       theDeck.push_back(myDeck);
       
   }
   for(i = 13; i > 0; --i)
   {
       Card myDeck('h', i);
       theDeck.push_back(myDeck);
   }
   for(i = 13; i > 0; --i)
   {
       Card myDeck('d', i);
       theDeck.push_back(myDeck);
   }
   for(i = 13; i > 0; --i)
   {
       Card myDeck('c', i);
       theDeck.push_back(myDeck);
   }
    
    
    //Failed attempt below. I am keeping it as a way to learn from my mistakes. I had gotten the first part right mostly, but I made too many Card objects. They wouldn't be connected and be their own decks
    //My attempt at vector popululation was heavily flawed. This way would make far too many decks as it'd populate 13 spots in the vector with 13 decks of Class Clubs/Spades/Diamonds/Hearts
    // each deck would only have one card inside
    
    
    // int k = 0;
    
    // for (int m = 52; m > 0; --m) //This is the loop resposonsible for creating the deck size of 52 cards
    // {
    //     while(m > 39)
    //     {
    //         Card deckClubs('c', k);
    //         theDeck.at(m) =  deckClubs;
    //         ++k;
    //     }
    //     k = 1;
    //     while(m > 26 && m < 39)
    //     {
    //         Card deck('d', k);
    //         theDeck.at(m) =  deckDiamonds;
    //         ++k;
    //     }
    //     k = 1;
    //     while(m > 13 && m < 26)
    //     {
    //         Card deckHearts('h', k);
    //         theDeck.at(m) =  deckHearts;
    //         ++k;
    //     }
    //     k = 1;
    //     while(m > 1 && m < 13)
    //     {
    //         Card deckSpades('s', k);
    //         theDeck.at(m) =  deckSpades;
    //         ++k;
    //     }
    //     k = 1;
    // }
}



//     /* Deals (returns) the top card on the deck. 
//       Removes this card from theDeck and places it in the dealtCards.
//     */
//     Card dealCard();
Card Deck:: dealCard()
{
    unsigned vSize = 0;
    
    
    dealtCards.push_back(theDeck.back() );
    theDeck.pop_back();
    vSize = dealtCards.size() - 1;
    

    return dealtCards.at(vSize);
}

//     /* Places all cards back into theDeck and shuffles them into random order.
//       Uses random_shuffle function from algorithm standard library.
//     */
   
void Deck::shuffleDeck()
{
   //Place orginal cards back
   unsigned vecSize = 0;
   unsigned i = 0;
   
   vecSize = dealtCards.size();
   
   for(i = 0; i < vecSize; ++i)
   {
       theDeck.push_back(dealtCards.at(i) );
   }
   
   random_shuffle(theDeck.begin(), theDeck.end() );
}

//     /* returns the size of the Deck (how many cards have not yet been dealt).
//     */

unsigned Deck::deckSize() const
{
    return theDeck.size();
}
