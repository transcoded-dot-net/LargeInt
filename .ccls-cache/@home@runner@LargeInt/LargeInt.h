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

      LargeInt operator+(const LargeInt& other) const;
      LargeInt operator-(const LargeInt& other) const;
      LargeInt operator*(const LargeInt& other) const;
      LargeInt operator/(const LargeInt& other) const;
      LargeInt operator%(const LargeInt& other) const;

      bool operator==(const LargeInt& other) const;
      bool operator<(const LargeInt& other) const;
      bool operator<=(const LargeInt& other) const;
      bool operator>(const LargeInt& other) const;
      bool operator>=(const LargeInt& other) const;

      friend ostream& operator<<(ostream& os, const LargeInt& largeInt);
      friend istream& operator>>(istream& is, LargeInt& largeInt);
};

#endif // LARGEINT_H