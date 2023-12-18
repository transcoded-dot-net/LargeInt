#include "DoublyLinkedList.h"

// DoublyLinkedList implementation
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : first(nullptr), last(nullptr), size_(0) {}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    clear();
}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList& other)
{
    first = last = nullptr;
    size_ = 0;

    Node<T>* current = other.first;
    while (current)
    {
        pushBack(current->data);
        current = current->next;
    }
}

template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList& other)
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
void DoublyLinkedList<T>::deleteItem(const T& val)
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
        size_--;
    }
}

template <typename T>
bool DoublyLinkedList<T>::search(const T& val) const
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
bool DoublyLinkedList<T>::isEmpty() const
{
    return size_ == 0;
}

template <typename T>
int DoublyLinkedList<T>::getLength() const
{
    return size_;
}

template <typename T>
void DoublyLinkedList<T>::pushFront(const T& val)
{
    Node<T>* newNode = new Node<T>(val);
    newNode->next = first;
    newNode->prev = nullptr;

    if (first)
        first->prev = newNode;

    first = newNode;

    if (!last)
        last = first;

    size_++;
}

template <typename T>
void DoublyLinkedList<T>::pushBack(const T& val)
{
    Node<T>* newNode = new Node<T>(val);
    newNode->next = nullptr;
    newNode->prev = last;

    if (last)
        last->next = newNode;

    last = newNode;

    if (!first)
        first = last;

    size_++;
}

template <typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::begin()
{
    return Iterator(first);
}

template <typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::end()
{
    return Iterator(nullptr);
}

template <typename T>
typename DoublyLinkedList<T>::ReverseIterator DoublyLinkedList<T>::rbegin()
{
    return ReverseIterator(last);
}

template <typename T>
typename DoublyLinkedList<T>::ReverseIterator DoublyLinkedList<T>::rend()
{
    return ReverseIterator(nullptr);
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
    size_ = 0;
}
