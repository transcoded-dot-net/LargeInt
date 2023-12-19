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
    Node<T> *iterator = *first;
    Node<T> *reverseIterator = *last;

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
    void clear();
    Node<T>* getLastNode();
    // iterator functions
    int bark();
    int reverseBark();
    bool checkNext();
    bool reverseCheckNext();
    void reverseWalk();
    void walk();
    void resetIterators();
    // checking the iterator equality
    bool operator==( DoublyLinkedList &other);
    bool operator!=( DoublyLinkedList &other);
};

#endif // DOUBLYLINKEDLIST_H