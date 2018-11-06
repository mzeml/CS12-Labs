// This program implements the Monte Carlo Method for estimating the value of PI.
	   
#include <iostream>
#include <cstdlib>
#include <cmath>
   
using namespace std;
   
// given the coordinates of a point (x,y) computes if the point is inside the circle 
// centered at origin with radius r. Returns 'true' if it is inside, 'false' otherwise.
bool isInside(double x, double y, double r)
{

if (sqrt(pow(x,2) + pow(y,2)) <= r)
{
   //is inside circle
   return true;
}
else
{
   //in square
   return false;
}
}

// given s, the size of the side of a square that is centered at the origin, 
// chooses a random coordinates inside the square, and calls isInside function 
// to test if the point is inside the circle or not.
bool throwDart(int s)
{
   int x, y, r; 
   bool tempBool = false;
   // assign x and y to two random integers between -s/2 and s/2 
  x = ((rand() % (s + 1)) - s/2);
  y = ((rand() % (s + 1)) - s/2);
  r = s/2;
   
   tempBool = isInside(x,y,r);
   if (tempBool != false)
   {
      return true;
   }
   else
   {
      return false;
   }
   
   
   //Call the isInside function and return its output. 
   //You do not have to cast x & y to doubles, it is done automatically.
 
}

int main()
{
   srand(333);
   int side; // this is the side of the square and is also our resolution. 
   int tries;  // this is the number of tries.

   //Ask the user for the size (integer) of a side of the square
   cout << "What size should the square side be? ";
   cin >> side;
   cout << endl;
   //Get the users input using cin

   //Ask the user for the number of tries using cout.
   cout << "How many tries? ";
   cin >> tries;
   cout << endl;
   
   //Get the users input using cin.
 
 
   int inCount = 0; //counter to track number of throws that fall inside the circle

   for(int i = 0; i < tries; ++i)
   {
      //throw a dart using throwDart method and increment the counter depending on its output.
      //throwDart(side);
      if (throwDart(side) == true)
      {
         ++inCount;
      }
      
   }

   //Compute and display the estimated value of PI. Make sure you are not using integer division.
   cout << "Pi = " << 4*(static_cast<double>(inCount) / static_cast<double>(tries)) << endl;
   
   
   

   return 0;
}