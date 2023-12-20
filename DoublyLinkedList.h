/**********************************************************************************************************************/
/* Programmer: Isabella A. Owusu */
/* Created on 9/20/2023 */
/* Title: Unsorted Doubly Linked List*/
/* Purpose: This is a menu-driven program that allows you to test all the functions of the DoublyLinkedList class,  */
/* including insertion at the front and back, deletion, searching, checking if the list is empty, */
/* including insertion at the front and back, deletion, searching, checking if the list is empty, */
/* getting the length of the list, and printing the list from front to back and back to front. It also */
/* provides an option to retrieve the last node in the list.*/
/**********************************************************************************************************************/


#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
using namespace std;
template <typename T>
class Node
{
public:
    T data;
    Node<T>* next;
    Node<T>* prev;
};

template <typename T>
class DoublyLinkedList
{
private:
    Node<T>* first;
    Node<T>* last;
    Node<T> *iterator = first;
    Node<T> *reverseIterator = last;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    DoublyLinkedList(class DoublyLinkedList& copy);
    DoublyLinkedList& operator=(class DoublyLinkedList& copy);

    void deleteItem( T& val);
    bool search( T& val) ;
    bool isEmpty();
    int getLength();
    void pushFront( T val);
    void pushBack( T val);
    void clear();
    Node<T>* getLastNode();
    // iterator functions
    int bark();
    int reverseBark();
    bool check();
    bool reverseCheck();
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
