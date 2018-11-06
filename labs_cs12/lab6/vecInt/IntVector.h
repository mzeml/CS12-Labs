#ifndef INTVECTOR_H
#define INTVECTOR_H

class IntVector
{
  private:
    //stores the size of the IntVector (the number of elements currently being used).
    unsigned sz; 
    //store the size of the array
    unsigned cap; 
    //stores the address of the dynamically-allocated array of integers
    int *data;
    
  public:
    IntVector();
    IntVector(unsigned size, int value = 0);
    ~IntVector();
    unsigned size() const;
    unsigned capacity() const;
    bool empty() const;
    const int & at(unsigned index) const;
    const int & front() const;
    const int & back() const;
};

#endif