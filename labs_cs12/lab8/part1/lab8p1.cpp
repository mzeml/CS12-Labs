#include <iostream>
#include <string>

using namespace std;

void flipString(string &s);

//void _flipString(string &s, unsigned ind); //method works as well, but wanted to be safe

int main() {
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;

   return 0;
}
void flipString(string &s)
{
    //_flipString(s, 0);
    
    if (s.size() <= 1)
    {
        return;
    }
    else
    {
        char tail = s.at(s.size() - 1);
        s = s.substr(0, s.size() - 1);
        flipString(s);
        s = tail + s;
    }
}
// void _flipString(string &s, unsigned ind)
// {
//     if(ind == s.size() / 2 || s.size() == 0)
//     {
//         return;
//     }
//     else
//     {
//          char temp = s.at(ind);
//          int placeHold = s.size() - 1 - ind;
         
//          s.at(ind) = s.at(placeHold);
//          s.at(placeHold) = temp;
         
//          _flipString(s, ind + 1);
         

//     }
// }