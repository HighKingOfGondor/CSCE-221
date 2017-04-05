#include <cstdlib>
#include <iostream>
#include "Record.h"
using namespace std;
template <typename T>
class DoublyLinkedList; // class declaration

// list node
template <typename T>
class DListNode {
private: T obj;
    DListNode<T> *prev, *next;
    friend class DoublyLinkedList<T>;
public:
    DListNode<T>(T e=T(), DListNode<T> *p = NULL, DListNode<T> *n = NULL)
    : obj(e), prev(p), next(n) {}
    T getElem() const { return obj; }
    DListNode<T> * getNext() const { return next; }
    DListNode<T> * getPrev() const { return prev; }
};

// doubly linked list
template <typename T>
class DoublyLinkedList {
protected: DListNode<T> header, trailer;
public:
    DoublyLinkedList() : header(T()), trailer(T())  //constructor
    { header.next = &trailer; trailer.prev = &header; }
    DoublyLinkedList<T>(const DoublyLinkedList<T>& dll); //copy constructor
    ~DoublyLinkedList<T>();                         // destructor
    DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& dll); // assignment operator
    // return the pointer to the first node
    DListNode<T> *getFirst() const { return header.next; }
    // return the pointer to the trailer
    const DListNode<T> *getAfterLast() const { return &trailer; }
    // return if the list is empty
    bool isEmpty() const { return header.next == &trailer; }
    T first() const;                                // return the first object
    T last() const;                                 // return the last object
    void insertFirst(T newobj);                     // insert to the first of the list
    T removeFirst();                                // remove the first node
    void insertLast(T newobj);                      // insert to the last of the list
    T removeLast();                                 // remove the last node
    DListNode<T>* insert(const T& obj);
    T operator[](T &i){}
    
};
// output operator
template <typename T>
ostream& operator<<(ostream& out, const DoublyLinkedList<T>& dll);



// extend range_error from <stdexcept>

struct EmptyDLinkedListException : std::range_error {
    explicit EmptyDLinkedListException(char const* msg=NULL): std::range_error(msg) {}
};

// copy constructor
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& dll)
{
    // Initialize the list
    header.next = &trailer;
    trailer.prev = &header;
    if(dll.isEmpty())
    {
        DListNode<T>* new_node = dll.getFirst();
        while(new_node != dll.getAfterLast())
        {
            insertLast(new_node->getElem());
            new_node = new_node->getNext();
        }
    }
    // Copy from dll
}
// assignment operator
template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& dll)
{
    // Delete the whole list
    DListNode<T> *prev_n;
    DListNode<T> *node = header.next;
    while(node != &trailer)
    {
        prev_n = node;
        node = node->next;
        delete prev_n;
    }
    header.next = &trailer;
    trailer.prev = &header;
    if(!dll.isEmpty())
    {
        node = dll.getFirst();
        while(node != dll.getAfterLast())
        {
            insertLast(node->getElem());
            node = node->getNext();
        }
    }
    return *this;
    // Copy from dll
}
// insert the object to the first of the linked list
template <typename T>
void DoublyLinkedList<T>::insertFirst(T newobj)
{
    DListNode<T> *newNode = new DListNode<T>(newobj, &header, header.next);
    header.next->prev = newNode;
    header.next = newNode;
}
// insert the object to the last of the linked list
template <typename T>
void DoublyLinkedList<T>::insertLast(T newobj)
{
    DListNode<T> *newNode = new DListNode<T>(newobj, trailer.prev,&trailer);
    trailer.prev->next = newNode;
    trailer.prev = newNode;
}
// remove the first object of the list
template <typename T>
T DoublyLinkedList<T>::removeFirst()
{
    if (isEmpty())
        throw EmptyDLinkedListException("Empty Doubly Linked List");
    DListNode<T> *node = header.next;
    node->next->prev = &header;
    header.next = node->next;
    T obj = node->obj;
    delete node;
    return obj;
}
// remove the last object of the list
template <typename T>
T DoublyLinkedList<T>::removeLast()
{
    if (isEmpty())
        throw EmptyDLinkedListException("Empty Doubly Linked List");
    DListNode<T> *node = trailer.prev;
    node->prev->next = &trailer;
    trailer.prev = node->prev;
    T obj = node->obj;
    delete node;
    return obj;
}
// destructor
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    DListNode<T> *prev_node, *node = header.next;
    while (node != &trailer) {
        prev_node = node;
        node = node->next;
        delete prev_node;
    }
    header.next = &trailer;
    trailer.prev = &header;
}
// return the first object
template <typename T>
T DoublyLinkedList<T>::first() const
{
    if (isEmpty())
        throw EmptyDLinkedListException("Empty Doubly Linked List");
    return header.next->obj;
}
// return the last object
template <typename T>
T DoublyLinkedList<T>::last() const
{
    if (isEmpty())
        throw runtime_error("Empty Doubly Linked List");
    return trailer.prev->obj;
}
// return the list length
template <typename T>
int DoublyLinkedListLength(DoublyLinkedList<T>& dll) {
    DListNode<T> *current = dll.getFirst();
    int count = 0;
    while(current != dll.getAfterLast())
    {
        count++;
        current = current->getNext(); //iterate
    }
    return count;
}
// output operator
template <typename T>
ostream& operator<<(ostream& out, const DoublyLinkedList<T>& dll)
{
    DListNode<T>* temp = dll.getFirst();
    while (temp != dll.getAfterLast())
    {
        out << temp->getElem() << " ";
        temp = temp->getNext();
    }
    return out;
}
//runtime O(n)=n
template <class T> DListNode<T>* DoublyLinkedList<T>::insert(const T& obj)
{
    DListNode<T>* node = new DListNode<T>(obj);     //create node from object
    
    DListNode<T>* temp = getFirst();
    
    while(temp->getElem() < node->getElem()&&temp!=getAfterLast())  //find correct nodde
        temp = temp->getNext(); //insert before
    node->prev = temp->prev;
    node->next = temp;
    temp->prev->next=node;
    temp->prev = node;
    
    return node;
}

// output operator
template <class T>
ostream& operator<<(ostream& out, DoublyLinkedList<T>& dll)
{
    DListNode<T>* temp = dll.getFirst();
    while (temp != dll.getAfterLast()) //use address to compare pointers
    {
        T object = temp->getElem();
        out << object << endl;       //O(n)=n
        temp = temp->getNext();
    }
    return out;
}