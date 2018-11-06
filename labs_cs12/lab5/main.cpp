#include <iostream>

using namespace std;

double mean(const double array[],int arraySize);

void remove(double array[], int arraySize, int index);

void display(const double array[], int arraySize);

int main()
{
//int userVal = 0;
int NUM_SIZE = 10;
double arrayH[NUM_SIZE];
int userRemove = 0;

    cout << "Enter 10 values:" << endl;
    cout << endl;
        
        for(int i = 0; i < NUM_SIZE; ++i)
        {
            cin >> arrayH[i];
        }
        cout << "Mean: " << mean(arrayH, NUM_SIZE) << endl;
        cout << endl;
        
        cout << "Enter index of value to be removed: ";
        cin >> userRemove;
        cout << endl;
        
        cout << "Before removing value: ";
        display(arrayH, NUM_SIZE);
        cout << endl;
        
        remove(arrayH, NUM_SIZE, userRemove);
        
        cout << "After removing value: ";
        display(arrayH, NUM_SIZE - 1);
        cout << endl;
        
    return 0;
}
double mean(const double array[],int arraySize)
{
    double totalVal = 0;
    
    for(int i = 0; i < arraySize; ++i)
    {
        totalVal = array[i] + totalVal;
    }
    return (totalVal)/static_cast<double>(arraySize);
}
void display(const double array[], int arraySize)
{
    
    for(int j = 0; j < arraySize - 1; ++j)
        {
           cout << array[j] << ", ";
        }
        cout << array[arraySize - 1];
    return;
}
void remove(double array[], int arraySize, int index)
{
    int j = 0;
    for(j = index; j < arraySize - 1; ++j)
        {
           array[j] = array[j + 1];
        }
        //array[j] = 0;
    return;
}