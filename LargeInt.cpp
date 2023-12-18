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
        while (number.reverseCheckNext() || other.number.reverseCheckNext())
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
        result = *this - other;
    }
    else {
        other.isNegative = false;
        result = other - *this;
    }
}

LargeInt LargeInt::operator-(LargeInt &other)
{

    LargeInt result;

}

LargeInt LargeInt::operator*( LargeInt &other) 
{
    LargeInt result;
    result.isNegative = (isNegative != other.isNegative);
    result.number = number * other.number;

    // Remove leading zeros
    while (!result.number.isEmpty() && result.number.begin()->data == 0)
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
    while (!result.number.isEmpty() && result.number.begin()->data == 0)
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
    while (!result.number.isEmpty() && result.number.begin()->data == 0)
    {
        result.number.deleteItem(0);
    }

    return result;
}

bool LargeInt::operator==( LargeInt &other) 
{
    return (number == other.number) && (isNegative == other.isNegative);
}

bool LargeInt::operator<( LargeInt &other) 
{
    if (isNegative != other.isNegative)
    {
        return isNegative;
    }

    if (number.size_() != other.number.size_())
    {
        return (number.size_() < other.number.size_()) ^ isNegative;
    }

    return (number < other.number) ^ isNegative;
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
    while (!largeInt.number.isEmpty() && largeInt.number.begin()-> data == 0)
    {
        largeInt.number.deleteItem(0);
    }
    return is;
}
