
#include "LargeInt.h"
#include <iostream>
#include <algorithm>
using namespace std;
int zero = 0;
LargeInt::LargeInt() {
    number;
    isNegative;
}
LargeInt::LargeInt(LargeInt &copy) {
    number = copy.number;
    isNegative = copy.isNegative;
}

LargeInt LargeInt::operator=(LargeInt other) {
    number = other.number;
    isNegative = other.isNegative;
}
void LargeInt::clear()
{
    number.clear();
}
LargeInt LargeInt::operator+( LargeInt &other)
{
    LargeInt result;
    int tempResult;
    bool carry;
    if (isNegative == other.isNegative)
    {
        while (number.reverseCheckNext() && other.number.reverseCheckNext())
        {
            if (!carry)
            {
                tempResult = number.reverseBark() + other.number.reverseBark();
            }
            else
            {
                tempResult = number.reverseBark() + other.number.reverseBark() + 1;
                carry = false;
            }
            if (tempResult >= 10)
            {
                tempResult -= 10;
                carry = true;
            }
            result.number.pushFront(tempResult);
            number.reverseWalk();
            other.number.reverseWalk();
            tempResult = 0;
        }
        while (carry && number.reverseCheckNext())
        {
            number.reverseWalk();
            tempResult= number.reverseBark() + 1;
            if (tempResult >= 10) {
                tempResult -= 10;
            }
            else
            {
                carry = false;
            }
            result.number.pushFront(tempResult);
        }

        while (carry && other.number.reverseCheckNext())
        {
            other.number.reverseWalk();
            tempResult= other.number.reverseBark() + 1;
            if (tempResult >= 10)
            {
                tempResult -= 10;
            }
            else
            {
                carry = false;
            }
            result.number.pushFront(tempResult);
        }
        while (number.reverseCheckNext())
        {
            number.reverseWalk();
            tempResult = number.reverseBark();
            result.number.pushFront(tempResult);
        }
        while (other.number.reverseCheckNext())
        {
            other.number.reverseWalk();
            tempResult = other.number.reverseBark();
            result.number.pushFront(tempResult);
        }
        result.isNegative = isNegative;
    }
    else if(isNegative)
    {
        isNegative = false;
        result = other - *this;
        isNegative = true;
    }
    else
    {
        other.isNegative = false;
        result = *this - other;
        other.isNegative = true;
    }
    number.resetIterators();
    other.number.resetIterators();
    return result;
}

LargeInt LargeInt::operator-(LargeInt &other)
{
    LargeInt result;
    int tempResult;
    bool carry;
    if (isNegative == other.isNegative)
    {

        if (*this < other)
        {
            result = other - *this;
            result.isNegative = true;
        }
        else if (*this == other)
        {
            result.number.pushFront(zero);
        }
        else
        {
            while (number.reverseCheckNext() && other.number.reverseCheckNext())
            {
                if (!carry)
                {
                    tempResult = number.reverseBark() - other.number.reverseBark();
                }
                else
                {
                    tempResult = number.reverseBark() - other.number.reverseBark() - 1;
                    carry = false;
                }
                if (tempResult <= -1)
                {
                    tempResult += 10;
                    carry = true;
                }
                result.number.pushFront(tempResult);
                number.reverseWalk();
                other.number.reverseWalk();
                tempResult = 0;
            }
            while (carry && number.reverseCheckNext())
            {
                number.reverseWalk();
                tempResult = number.reverseBark() - 1;
                if (tempResult <= -1)
                {
                    tempResult += 10;
                }
                else
                {
                    carry = false;
                }
                result.number.pushFront(tempResult);
            }

            while (number.reverseCheckNext())
            {
                number.reverseWalk();
                tempResult = number.reverseBark();
                result.number.pushFront(tempResult);
            }
            // remove leading zeros, if any
            while (!result.number.isEmpty() && result.number.bark() == 0)
            {

                result.number.deleteItem(zero);
            }
            result.isNegative = isNegative;
            return result;
        }
    }
    else if (isNegative)
    {
        isNegative = false;
        result = other - *this;
        isNegative = true;
    }
    else
    {
        other.isNegative = false;
        result = *this + other;
        other.isNegative = true;
    }
    return result;
}

LargeInt LargeInt::operator*(LargeInt &other)
{
    LargeInt result;
    result.isNegative = (isNegative != other.isNegative);

    // Initialize variables to keep track of position and carry
    int position = 0;
    int carry = 0;

    // Iterate through each digit of the current LargeInt
    while (number.reverseCheckNext())
    {
        int currentDigit = number.reverseBark();
        other.number.resetIterators(); // Reset the iterator of the other LargeInt for each digit

        // Multiply the current digit with each digit of the other LargeInt
        while (other.number.reverseCheckNext())
        {
            int product = currentDigit * other.number.reverseBark() + carry;
            if (result.number.reverseCheckNext())
            {
                product += result.number.reverseBark(); // Add the current result digit
            }

            carry = product / 10; // Calculate carry
            result.number.pushFront(product % 10); // Add the current result digit
            other.number.reverseWalk();
        }

        // Add any remaining carry as a new digit
        while (carry > 0)
        {
            if (result.number.reverseCheckNext())
            {
                carry += result.number.reverseBark();
            }
            result.number.pushFront(carry % 10);
            carry /= 10;
        }

        number.reverseWalk();
        position++;
    }

    // Remove leading zeros
    while (!result.number.isEmpty() && result.number.bark() == 0)
    {
        result.number.deleteItem(zero);
    }

    return result;
}

LargeInt LargeInt::operator/(LargeInt &other)
{
    if (other.number.isEmpty() || (other.number.getLength() == 1 && other.number.bark() == 0))
    {
        cerr << "Error: Division by zero." << endl;
        exit(EXIT_FAILURE);
    }

    LargeInt result;
    result.isNegative = (isNegative != other.isNegative);

    LargeInt dividend(*this);
    dividend.isNegative = false; // Ensure the dividend is positive for the division process

    LargeInt currentDividend; // Partial dividend during the division process

    while (dividend >= other)
    {
        int quotientDigit = 0;

        // Keep subtracting the divisor from the current partial dividend
        while (currentDividend < other && !dividend.number.isEmpty())
        {
            currentDividend.number.pushBack(dividend.number.bark());
            dividend.number.walk();
            quotientDigit++;
        }

        // Subtract the divisor from the current partial dividend
        while (currentDividend >= other)
        {
            currentDividend = currentDividend - other;
            quotientDigit++;
        }

        result.number.pushBack(quotientDigit);
        currentDividend.clear();
    }

    // Remove leading zeros
    while (!result.number.isEmpty() && result.number.bark() == 0)
    {
        result.number.deleteItem(zero);
    }

    return result;
}


LargeInt LargeInt::operator%(LargeInt &other)
{
    // Create a temporary LargeInt to hold the result of the division
    LargeInt quotient = *this / other;

    // Multiply the divisor by the quotient
    LargeInt product = quotient * other;

    // Calculate the remainder by subtracting the product from the original number
    LargeInt remainder = *this - product;

    return remainder;
}

bool LargeInt::operator==( LargeInt &other)
{
    while (number.reverseCheckNext() && other.number.reverseCheckNext())
    {
        if (number.reverseBark() != other.number.reverseBark())
        {
            number.resetIterators();
            other.number.resetIterators();
            return false;
        }
        number.reverseWalk();
        other.number.reverseWalk();
    }
    if (number.reverseCheckNext() != other.number.reverseCheckNext())
    {
        number.resetIterators();
        other.number.resetIterators();
        return false;
    }
    else
    {
        return number.reverseBark() == other.number.reverseBark();
    }
}

bool LargeInt::operator!=( LargeInt &other)
{
    return !(*this == other);
}

bool LargeInt::operator<( LargeInt &other)
{
    if (number.getLength() < other.number.getLength())
    {
        number.resetIterators();
        other.number.resetIterators();
        return true;
    }
    if (number.getLength() > other.number.getLength())
    {
        number.resetIterators();
        other.number.resetIterators();
        return false;
    }
    else
    {
        while (number.checkNext())
        {
            if (number.bark() < other.number.bark())
            {
                number.resetIterators();
                other.number.resetIterators();
                return true;
            }
            if (number.bark() > other.number.bark())
            {
                number.resetIterators();
                other.number.resetIterators();
                return false;
            }
            else
            {
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

// ostream operator to print LargeInt
template <typename T>
ostream &operator<<(ostream &os, LargeInt &largeInt)
{
    if (largeInt.isNegative)
    {
        os << '-';
    }
    while (largeInt.number.check())
    {
        os << largeInt.number.bark();
        largeInt.number.walk();
    }
    largeInt.number.resetIterators();

    return os;
}


istream &operator>>(istream &is, LargeInt &largeInt)
{
    char sign;
    is >> sign;
    largeInt.isNegative = (sign == '-');

    char digit;
    while (isdigit(is.peek()))
    {
        is >> digit;
        largeInt.number.pushBack(digit - '0');  // Convert char to int and push to the linked list
    }

    while (!largeInt.number.isEmpty() && largeInt.number.bark() == 0)
    {
        largeInt.number.deleteItem(zero);
    }
    return is;
}



