#include <fstream>
#include <iostream>
#include <cstdlib> //needed for exit function

using namespace std;

// Place fileSum prototype (declaration) here
int fileSum(string myFile);

int main() {
   string filename;
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << "Sum: " << fileSum(filename) << endl;
   
   return 0;
}

// Place fileSum implementation here
int fileSum(string myFile)
{
   ifstream inFS;
   inFS.open(myFile.c_str());
   int num = 0;
   int sum = 0;
   
   if (inFS.is_open())
   {
      while (inFS >> num)
      {
         sum = sum + num;
      }
      inFS.close();
   }
   else
   {
      cout << "Error opening " << myFile << endl;
      exit(1);
   }
return sum;
}
   
   
   
   
   