#include "DoublyLinkedList.h"
#include "LargeInt.h"
#include <iostream>
#include <algorithm>

using namespace std;

LargeInt::LargeInt() : isNegative(false) {}

LargeInt LargeInt::operator+( LargeInt &other) 
{
    LargeInt result;
    int tempResult;
    bool carry;
    if (isNegative == other.isNegative)
    {
        while (number.reverseCheckNext() && other.number.reverseCheckNext())
        {
            if (!carry){
                tempResult = number.reverseBark() + other.number.reverseBark();
            }
            else {
                tempResult = number.reverseBark() + other.number.reverseBark() + 1;
                carry = false;
            }
            if (tempResult >= 10){
                tempResult -= 10;
                carry = true;
            }
            result.number.pushFront(tempResult);
            number.reverseWalk();
            other.number.reverseWalk();
            tempResult = 0;
        }
        while (carry && number.reverseCheckNext()){
            number.reverseWalk();
            tempResult= number.reverseBark() + 1;
            if (tempResult >= 10) {
                tempResult -= 10;
            }
            else {
                carry = false;
            }
            result.number.pushFront(tempResult);
        }

        while (carry && other.number.reverseCheckNext()){
            other.number.reverseWalk();
            tempResult= other.number.reverseBark() + 1;
            if (tempResult >= 10) {
                tempResult -= 10;
            }
            else {
                carry = false;
            }
            result.number.pushFront(tempResult);
        }
        while (number.reverseCheckNext()){
            number.reverseWalk();
            tempResult = number.reverseBark();
            result.number.pushFront(tempResult);
        }
        while (other.number.reverseCheckNext()){
            other.number.reverseWalk();
            tempResult = other.number.reverseBark();
            result.number.pushFront(tempResult);
        }
        result.isNegative = isNegative;
    }
    else if(isNegative){
        isNegative = false;
        result = other - *this;
        isNegative = true;
    }
    else {
        other.isNegative = false;
        result = *this - other;
        other.isNegative = true;
    }
    number.resetIterators();
    other.number.resetIterators();
    return result;
}

LargeInt LargeInt::operator-(LargeInt &other) {
    LargeInt result;
    int tempResult;
    bool carry;
    if (isNegative == other.isNegative) {

        if (*this < other) {
            result = other - *this;
            result.isNegative = true;
        }
        else if (*this == other) {
            result.number.pushFront(0);
        }
        else {
            while (number.reverseCheckNext() && other.number.reverseCheckNext()) {
                if (!carry) {
                    tempResult = number.reverseBark() - other.number.reverseBark();
                } else {
                    tempResult = number.reverseBark() - other.number.reverseBark() - 1;
                    carry = false;
                }
                if (tempResult <= -1) {
                    tempResult += 10;
                    carry = true;
                }
                result.number.pushFront(tempResult);
                number.reverseWalk();
                other.number.reverseWalk();
                tempResult = 0;
            }
            while (carry && number.reverseCheckNext()) {
                number.reverseWalk();
                tempResult = number.reverseBark() - 1;
                if (tempResult <= -1) {
                    tempResult += 10;
                } else {
                    carry = false;
                }
                result.number.pushFront(tempResult);
            }

            while (number.reverseCheckNext()) {
                number.reverseWalk();
                tempResult = number.reverseBark();
                result.number.pushFront(tempResult);
            }
            // remove leading zeros, if any
            while (!result.number.isEmpty() && result.number.bark() == 0) {
                result.number.deleteItem(0);
            }
            result.isNegative = isNegative;
            return result;
        }
    }
    else if (isNegative) {
        isNegative = false;
        result = other - *this;
        isNegative = true;
    }
    else {
        other.isNegative = false;
        result = *this + other;
        other.isNegative = true;
    }
    return result;
}

LargeInt LargeInt::operator*( LargeInt &other) 
{
    LargeInt result;
    result.isNegative = (isNegative != other.isNegative);
    result.number = number * other.number;

    // Remove leading zeros
    while (!result.number.isEmpty() && result.number.bark() == 0)
    {
        result.number.deleteItem(0);
    }

    return result;
}

LargeInt LargeInt::operator/( LargeInt &other) 
{
    LargeInt result;
    result.isNegative = (isNegative != other.isNegative);
    result.number = number / other.number;

    // Remove leading zeros
    while (!result.number.isEmpty() && result.number.bark() == 0)
    {
        result.number.deleteItem(0);
    }

    return result;
}

LargeInt LargeInt::operator%( LargeInt &other) 
{
    LargeInt result;
    result.isNegative = isNegative;
    result.number = number % other.number;

    // Remove leading zeros
    while (!result.number.isEmpty() && result.number.bark() == 0)
    {
        result.number.deleteItem(0);
    }

    return result;
}

bool LargeInt::operator==( LargeInt &other) 
{
    while (number.reverseCheckNext() && other.number.reverseCheckNext()){
        if (number.reverseBark() != other.number.reverseBark()){
            number.resetIterators();
            other.number.resetIterators();
            return false;
        }
        number.reverseWalk();
        other.number.reverseWalk();
    }
    if (number.reverseCheckNext() != other.number.reverseCheckNext()) {
        number.resetIterators();
        other.number.resetIterators();
        return false;
    }
    else {
        return number.reverseBark() == other.number.reverseBark();
    }
}

bool LargeInt::operator!=( LargeInt &other)
{
  return !(*this == other);
}

bool LargeInt::operator<( LargeInt &other) 
{
    if (number.getLength() < other.number.getLength()) {
        number.resetIterators();
        other.number.resetIterators();
        return true;
    }
    if (number.getLength() > other.number.getLength()) {
        number.resetIterators();
        other.number.resetIterators();
        return false;
    }
    else {
        while (number.checkNext()){
            if (number.bark() < other.number.bark()) {
                number.resetIterators();
                other.number.resetIterators();
                return true;
            }
            if (number.bark() > other.number.bark()){
                number.resetIterators();
                other.number.resetIterators();
                return false;
            }
            else {
                number.walk();
                other.number.walk();
            }
        }
        return number.bark() < other.number.bark();
    }
}

bool LargeInt::operator<=( LargeInt &other) 
{
    return (*this < other) || (*this == other);
}

bool LargeInt::operator>( LargeInt &other) 
{
    return !(*this <= other);
}

bool LargeInt::operator>=( LargeInt &other) 
{
    return !(*this < other);
}
// have it so it's printing ur number, basically the print func of the DLL
ostream &operator<<(std::ostream &os,  LargeInt &largeInt)
{
    if (largeInt.isNegative)
    {
        os << '-';
    }
    os << largeInt.number;
    return os;
}
// have it so it's inputting your number, only check the first char to set is negative
// if first char is negative sign, set isNegative & skip to next and just input each using DLL pushBack
/* if it isn't, just input every char using DLL pushBack all integers so really easy, just make sure ur casting
 * each char to int */
istream &operator>>(istream &is, LargeInt &largeInt)
{
    char sign;
    is >> sign;
    largeInt.isNegative = (sign == '-');
    is >> largeInt.number;
    while (!largeInt.number.isEmpty() && largeInt.number.bark()== 0)
    {
        largeInt.number.deleteItem(0);
    }
    return is;
}
