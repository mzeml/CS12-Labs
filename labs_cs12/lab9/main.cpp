#include "Card.h"
#include "Deck.h"

#include <fstream>
#include <cstdlib> 
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

/* Sorts the contents of v into suit order,
   i.e., all clubs first (in numerically ascending order),
   then all diamonds (in ascending order),
   then all hearts (in ascending order),
   and finally all spades (in ascending order).
   Calls mergeSort recursive function to actually sort the vector.
*/
void sortBySuit(vector<Card> &v);

/* Uses the recursive merge sort algorithm to sort the contents
   of the vector from begin to end in suit order.
   (see above SortBySuit function for definition of suit order)
   Uses merge helper function to merge the two sorted
   halves.
*/
void mergeSort(vector<Card> &v, unsigned begin, unsigned end);

/* Assumes all values from begin to mid are in suit order,
   (see above SortBySuit function for definition of suit order)
   and all values from mid + 1 to end are in suit order.
   Merges the two halves so that all values from begin to end
   are in suit order.
*/
void merge(vector<Card> &v, unsigned begin, unsigned mid, unsigned end);

// /* Passes in a vector Cards and returns true if any 2 Cards have the same rank.
//   Otherwise returns false.
// */
bool hasPair(const vector<Card> &myDeck);

// /* Passes in a vector of Cards and outputs to the stream each Card
//   separated by a comma and a space, 
//   with no comma, space, or newline at the end.
// */
ostream & operator<<(ostream &out, const vector<Card> &v1);

void fillHand(vector<Card> &hand, Deck &d, unsigned handSize) {
   hand.resize(handSize);
   for (unsigned i = 0; i < hand.size(); ++i) {
      hand.at(i) = d.dealCard();
   }
}


int main() {
   vector<Card> hand;
   Deck deck;
   int handSize;
   int seed;
   cout << "Enter seed value: ";
   cin >> seed;
   cout << endl;
   cout << "Enter hand size: ";
   cin >> handSize;
   cout << endl;

   srand(seed);
   deck.shuffleDeck();
   fillHand(hand, deck, handSize);
   cout << hand << endl;
   sortBySuit(hand);
   cout << hand << endl;
   return 0;
}

bool hasPair(const vector<Card> &myDeck)
{
    for(unsigned i = 1; i < myDeck.size(); ++i)
    {
      if(myDeck.at(i - 1).getRank() == myDeck.at(i).getRank() ) 
      {
          return true;
      }
    }
    
    return false;
}
ostream & operator<<(ostream &out, const vector<Card> &v1)
{
    unsigned size = v1.size() - 1;
    
    if(size + 1 > 0)
    {
    for(unsigned i = 0; i < size; ++i)
    {
        out << v1.at(i) << ", ";
    }
    out << v1.at(size);
    }
  return out;
}

void sortBySuit(vector<Card> &v)
{
    if(!v.empty())
    {
    
    unsigned begin = 0; // or 1
    unsigned end = v.size() - 1;
    
    mergeSort(v, begin, end);
    }
}
void mergeSort(vector<Card> &v, unsigned begin, unsigned end)
{
    //RECURSIVE
//     all clubs first (in numerically ascending order),
//   then all diamonds (in ascending order),
//   then all hearts (in ascending order),
//   and finally all spades (in ascending order).
    
    //Three index variables used to keep track of elements for each recursive call

    int midpoint = 0; //midpoint
    
    if (begin < end) 
    {
      midpoint = (begin + end) / 2;  
  
      mergeSort(v, begin, midpoint);
      mergeSort(v, midpoint + 1, end);
    
      merge(v, begin, midpoint, end);
   }
}
void merge(vector<Card> &v, unsigned begin, unsigned mid, unsigned end)
{
    //c<d<h<s
    
    unsigned mergedSize = (end - begin) + 1;  
    vector<Card> tempVec(mergedSize);
    unsigned mergePos = 0;                 
    unsigned leftPos = 0;                  
    unsigned rightPos = 0;                 
   
    leftPos = begin;                      
    rightPos = mid + 1;                 
   
//  Add smallest element from left or right partition to merged numbers
    while (leftPos <= mid && rightPos <= end) 
    {
      if (v.at(leftPos).getSuit() < v.at(rightPos).getSuit()) 
      {
         tempVec.at(mergePos) = v.at(leftPos);
         ++leftPos;
      }
      else if(v.at(leftPos).getSuit() == v.at(rightPos).getSuit())
      {
          //compare rank
          if(v.at(leftPos).getRank() < v.at(rightPos).getRank())
          {
              tempVec.at(mergePos) = v.at(leftPos);
              ++leftPos;
          }
          else
          {
             tempVec.at(mergePos) = v.at(rightPos);
            ++rightPos;
          }
      }
      else 
      {
         tempVec.at(mergePos) = v.at(rightPos);
         ++rightPos;
         
      }
      ++mergePos;
  }
   
  while (leftPos <= mid) 
  {
      tempVec.at(mergePos) = v.at(leftPos);
      ++leftPos;
      ++mergePos;
  }
   

  while (rightPos <= end) 
  {
      tempVec.at(mergePos) = v.at(rightPos);
      ++rightPos;
      ++mergePos;
  }

  for (mergePos = 0; mergePos < mergedSize; ++mergePos) 
  {
      v.at(begin + mergePos) = tempVec.at(mergePos);
  }


}