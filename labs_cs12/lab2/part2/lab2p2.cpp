#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

// Place charCnt prototype (declaration) here
int charCnt(string myFile,char ch);

int main() {
   string filename;
   char ch;
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << "Enter a character: ";
   cin >> ch;
   
   cout << "# of " << ch << "'s: " << charCnt(filename, ch) << endl;
   
   return 0;
}

// Place charCnt implementation here
int charCnt(string myFile, char ch)
{
   ifstream inFS;
   inFS.open(myFile.c_str());
   int total = 0;
   char k;
   
   if (!inFS.is_open())
   {
      cout << "Error";
      exit(1);
   }
   else
   {
      while (inFS >> k)
      {
         if (k == ch)
         ++total;
      }
   }
   return total;
}