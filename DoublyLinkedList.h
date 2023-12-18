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
    // checking the iterator equality
    bool operator==( DoublyLinkedList &other);
    bool operator!=( DoublyLinkedList &other);
    void deleteItem(const T& val);
    bool search(const T& val) const;
    bool isEmpty() const;
    int getLength() const;
    void pushFront(const T& val);
    void pushBack(const T& val);
    int Bark();
    int reverseBark();
    bool checkNext();
    bool reverseCheckNext();
    void reverseWalk();
    void walk();
    //void trimLeadingZeros();

    class Iterator
    {
    private:
        Node<T>* current;

    public:

        T& operator*();
        Iterator& operator++();
        bool operator!=(const Iterator& other);
        void checkNext();
    };

    class ReverseIterator
    {
    private:
        Node<T>* current;

    public:

        T& operator*();
        ReverseIterator& operator++();
        bool operator!=(const ReverseIterator& other);
        void checkNext();

    };
    Node<T>* getLastNode();
    void clear();
};


#endif // DOUBLYLINKEDLIST_H

