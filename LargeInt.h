#ifndef LARGEINT_H
#define LARGEINT_H

#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;

class LargeInt
{
private:
    DoublyLinkedList<int> number;
    bool isNegative; // New member to store the sign

public:
    LargeInt();
    LargeInt(LargeInt &copy);
    LargeInt& operator=( LargeInt &&other) ;
    LargeInt operator=( LargeInt &other) ;
    LargeInt operator+( LargeInt &other) ;
    LargeInt operator-( LargeInt &other) ;
    LargeInt operator*( LargeInt &other) ;
    LargeInt operator/( LargeInt &other) ;
    LargeInt operator%( LargeInt &other) ;

    bool operator==( LargeInt &other) ;
    bool operator!=( LargeInt &other) ;
    bool operator<( LargeInt &other) ;
    bool operator<=( LargeInt &other) ;
    bool operator>( LargeInt &other) ;
    bool operator>=( LargeInt &other) ;
    void clear();


    friend ostream& operator<<(ostream &os,  LargeInt &largeInt);
    friend istream& operator>>(istream &is, LargeInt &largeInt);
};

#endif // LARGEINT_H

