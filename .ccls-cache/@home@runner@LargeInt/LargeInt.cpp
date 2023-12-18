#include "DoublyLinkedList.h"
#include "LargeInt.h"
#include <iostream>
#include <algorithm>

using namespace std;

LargeInt::LargeInt() : isNegative(false) {}

LargeInt LargeInt::operator+(const LargeInt &other) const
{
    LargeInt result;

    if (!isNegative && !other.isNegative)
    {
        result.number = number + other.number;
        result.isNegative = false;
    }
    else if (isNegative && other.isNegative)
    {
        result.number = number + other.number;
        result.isNegative = true;
    }
    else
    {
        const bool thisIsLarger = (number.size_() > other.number.size_()) ||
                                  ((number.size_() == other.number.size_()) && (number >= other.number));

        if (thisIsLarger)
        {
            result.number = number - other.number;
            result.isNegative = isNegative;
        }
        else
        {
            result.number = other.number - number;
            result.isNegative = !other.isNegative;
        }
    }

    // Remove leading zeros
    while (!result.number.isEmpty() && result.number.begin()->data == 0)
    {
        result.number.deleteItem(0);
    }

    return result;
}

LargeInt LargeInt::operator-(const LargeInt &other) const
{
    LargeInt result;

    if (!isNegative && !other.isNegative)
    {
        const bool thisIsLarger = (number.size_() > other.number.size_()) ||
                                  ((number.size_() == other.number.size_()) && (number >= other.number));

        if (thisIsLarger)
        {
            result.number = number - other.number;
            result.isNegative = false;
        }
        else
        {
            result.number = other.number - number;
            result.isNegative = true;
        }
    }
    else if (isNegative && other.isNegative)
    {
        const bool thisIsLarger = (number.size_() > other.number.size_()) ||
                                  ((number.size_() == other.number.size_()) && (number <= other.number));

        if (thisIsLarger)
        {
            result.number = number - other.number;
            result.isNegative = true;
        }
        else
        {
            result.number = other.number - number;
            result.isNegative = false;
        }
    }
    else
    {
        result.number = number + other.number;
        result.isNegative = isNegative;
    }

    // Remove leading zeros
    while (!result.number.isEmpty() && result.number.begin()->data == 0)
    {
        result.number.deleteItem(0);
    }

    return result;
}

LargeInt LargeInt::operator*(const LargeInt &other) const
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

LargeInt LargeInt::operator/(const LargeInt &other) const
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

LargeInt LargeInt::operator%(const LargeInt &other) const
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

bool LargeInt::operator==(const LargeInt &other) const
{
    return (number == other.number) && (isNegative == other.isNegative);
}

bool LargeInt::operator<(const LargeInt &other) const
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

bool LargeInt::operator<=(const LargeInt &other) const
{
    return (*this < other) || (*this == other);
}

bool LargeInt::operator>(const LargeInt &other) const
{
    return !(*this <= other);
}

bool LargeInt::operator>=(const LargeInt &other) const
{
    return !(*this < other);
}

ostream &operator<<(std::ostream &os, const LargeInt &largeInt)
{
    if (largeInt.isNegative)
    {
        os << '-';
    }
    os << largeInt.number;
    return os;
}

istream &operator>>(istream &is, LargeInt &largeInt)
{
    char sign;
    is >> sign;
    largeInt.isNegative = (sign == '-');
    is >> largeInt.number;
    while (!largeInt.number.isEmpty() && largeInt.number.begin()->data == 0)
    {
        largeInt.number.deleteItem(0);
    }
    return is;
}
