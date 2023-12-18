#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

template <typename T>
class Node
{
public:
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node(const T& val);
};

template <typename T>
class DoublyLinkedList
{
private:
    Node<T>* first;
    Node<T>* last;
    int size_;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList& copy);
    DoublyLinkedList& operator=(const DoublyLinkedList& copy);

    void deleteItem(const T& val);
    bool search(const T& val) const;
    bool isEmpty() const;
    int getLength() const;
    void pushFront(const T& val);
    void pushBack(const T& val);
    //void trimLeadingZeros();

    class Iterator
    {
    private:
        Node<T>* current;

    public:
        Iterator(Node<T>* node);

        T& operator*();
        Iterator& operator++();
        bool operator!=(const Iterator& other);
    };

    class ReverseIterator
    {
    private:
        Node<T>* current;

    public:
        ReverseIterator(Node<T>* node);

        T& operator*();
        ReverseIterator& operator++();
        bool operator!=(const ReverseIterator& other);
    };

    Iterator begin();
    Iterator end();
    ReverseIterator rbegin();
    ReverseIterator rend();
    Node<T>* getLastNode();
    void clear();
};

template <typename T>
Node<T>::Node(const T& val) : data(val), next(nullptr), prev(nullptr) {}

// Iterator implementation
template <typename T>
DoublyLinkedList<T>::Iterator::Iterator(Node<T>* node) : current(node) {}

template <typename T>
T& DoublyLinkedList<T>::Iterator::operator*()
{
    return current->data;
}

template <typename T>
typename DoublyLinkedList<T>::Iterator& DoublyLinkedList<T>::Iterator::operator++()
{
    current = current->next;
    return *this;
}

template <typename T>
bool DoublyLinkedList<T>::Iterator::operator!=(const Iterator& other)
{
    return current != other.current;
}

// ReverseIterator implementation
template <typename T>
DoublyLinkedList<T>::ReverseIterator::ReverseIterator(Node<T>* node) : current(node) {}

template <typename T>
T& DoublyLinkedList<T>::ReverseIterator::operator*()
{
    return current->data;
}

template <typename T>
typename DoublyLinkedList<T>::ReverseIterator& DoublyLinkedList<T>::ReverseIterator::operator++()
{
    current = current->prev;
    return *this;
}

template <typename T>
bool DoublyLinkedList<T>::ReverseIterator::operator!=(const ReverseIterator& other)
{
    return current != other.current;
}
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
#endif // DOUBLYLINKEDLIST_H

