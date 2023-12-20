#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;

// DoublyLinkedList implementation
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : first(nullptr), last(nullptr){}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    clear();
}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList( DoublyLinkedList& other)
{
    first = last = nullptr;

    Node<T>* current = other.first;
    while (current)
    {
        pushBack(current->data);
        current = current->next;
    }
}

template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=( DoublyLinkedList& other)
{
    if (this == &other)
        return *this;

    // Clear existing elements
    clear();

    Node<T>* current = other.first;
    while (current)
    {
        pushBack(current->data);
        current = current->next;
    }

    return *this;
}

template <typename T>
void DoublyLinkedList<T>::deleteItem( T& val)
{
    Node<T>* current = first;
    Node<T>* prev = nullptr;

    while (current && current->data != val)
    {
        prev = current;
        current = current->next;
    }

    if (current)
    {
        if (prev)
            prev->next = current->next;
        else
            first = current->next;

        if (current->next)
            current->next->prev = prev;

        if (current == last)
            last = prev;

        delete current;
    }
}

template <typename T>
bool DoublyLinkedList<T>::search( T& val)
{
    Node<T>* current = first;
    while (current)
    {
        if (current->data == val)
            return true;

        current = current->next;
    }

    return false;
}

template <typename T>
bool DoublyLinkedList<T>::isEmpty()
{
    return getLength() == 0;
}

template <typename T>
int DoublyLinkedList<T>::getLength()
{
    int counter;
    while(this)
    {
        counter++;
    }
    return counter;
}

template <typename T>
void DoublyLinkedList<T>::pushFront( T& val)
{
    Node<T>* newNode = new Node<T>;
    newNode->data = val;
    newNode->next = first;
    newNode->prev = nullptr;

    if (first)
        first->prev = newNode;

    first = newNode;

    if (!last)
        last = first;
}

template <typename T>
void DoublyLinkedList<T>::pushBack( T& val)
{
    Node<T>* newNode = new Node<T>;
    newNode->data = val;
    newNode->next = nullptr;
    newNode->prev = last;

    if (last)
        last->next = newNode;

    last = newNode;

    if (!first)
        first = last;
}

template <typename T>
Node<T>* DoublyLinkedList<T>::getLastNode()
{
    return last;
}

template <typename T>
void DoublyLinkedList<T>::clear()
{
    Node<T>* current = first;
    while (current)
    {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }

    first = last = nullptr;
}


template <typename T>
bool DoublyLinkedList<T>::operator!=( DoublyLinkedList& other)
{
    return iterator->data != other.iterator->data;
}template <typename T>
bool DoublyLinkedList<T>::operator==( DoublyLinkedList& other)
{
    return iterator->data == other.iterator->data;
}

template<typename T>
int DoublyLinkedList<T>::bark()
{
    return iterator->data;
}

template<typename T>
int DoublyLinkedList<T>::reverseBark()
{
    return reverseIterator->data;
}
template<typename T>
bool DoublyLinkedList<T>::check()
{
    return iterator == nullptr;
}

template<typename T>
bool DoublyLinkedList<T>::reverseCheck()
{
    return reverseIterator == nullptr;
}

template<typename T>
bool DoublyLinkedList<T>::reverseCheckNext()
{
    return reverseIterator->prev == nullptr;
}

template<typename T>
bool DoublyLinkedList<T>::checkNext()
{
    return iterator->next == nullptr;
}

template<typename T>
void DoublyLinkedList<T>::reverseWalk()
{
    reverseIterator = reverseIterator->prev;
}

template<typename T>
void DoublyLinkedList<T>::walk()
{
    iterator = iterator->next;
}
template<typename T>
void DoublyLinkedList<T>::resetIterators()
{
    iterator = first;
    reverseIterator = last;
}

template class DoublyLinkedList<int>;
// Function to trim leading zeros in the list
/*template <typename T>
void DoublyLinkedList<T>::trimLeadingZeros()
{
    Node<T>* current = last;
    while (current && current->data == 0)
    {
        Node<T>* prev = current->prev;
        delete current;
        current = prev;
    }

    last = current;
    if (last)
        last->next = nullptr;

    if (!last)
        first = nullptr;

    size_ = 0;
    current = first;
    while (current)
    {
        size_++;
        current = current->next;
    }
}*/