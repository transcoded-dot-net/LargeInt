#include "DoublyLinkedList.h"
#include "LargeInt.h"
#include <iostream>
using namespace std;

int main()
{
    LargeInt num1, num2, result;

    // Input numbers
    cout << "Enter the first Large Integer number: ";
    cin >> num1;

    cout << "Enter the second Large Integer number: ";
    cin >> num2;

    // Perform operations
    result = num1 + num2;
    cout << "Sum: " << result << endl;

    result = num1 - num2;
    cout << "Difference: " << result << endl;

    result = num1 * num2;
    cout << "Product: " << result << endl;

    result = num1 / num2;
    cout << "Quotient: " << result << endl;

    result = num1 % num2;
    cout << "Remainder: " << result << endl;

    // Perform logical operations
    if (num1 == num2)
    {
        cout << "Both numbers are equal." << endl;
    }
    else if (num1 < num2)
    {
        cout << "The first number is less than the second." << endl;
    }
    else
    {
        cout << "The first number is greater than the second." << endl;
    }

    return 0;
}