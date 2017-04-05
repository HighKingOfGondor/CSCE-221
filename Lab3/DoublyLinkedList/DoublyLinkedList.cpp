#include "DoublyLinkedList.h"
#include <stdexcept>
// extend range_error from <stdexcept>
struct EmptyDLinkedListException : std::range_error {
    explicit EmptyDLinkedListException(char const* msg=NULL): range_error(msg) {}
};
// copy constructor
DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& dll)
{
    // Initialize the list
    header.next = &trailer;
    trailer.prev = &header;
    if(dll.isEmpty())
    {
        DListNode* new_node = dll.getFirst();
        while(new_node != dll.getAfterLast())
        {
            insertLast(new_node->getElem());
            new_node = new_node->getNext();
        }
    }
    // Copy from dll
    /* Complete this function */
}
// assignment operator
DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& dll)
{
    // Delete the whole list
    /* Complete this function */
    DListNode *prev_n;
    DListNode *node = header.next;
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
    //return this;
    // Copy from dll
    /* Complete this function */
}
// insert the object to the first of the linked list
void DoublyLinkedList::insertFirst(int newobj)
{
    DListNode *newNode = new DListNode(newobj, &header, header.next);
    header.next->prev = newNode;
    header.next = newNode;
}
// insert the object to the last of the linked list
void DoublyLinkedList::insertLast(int newobj)
{
    DListNode *newNode = new DListNode(newobj, trailer.prev,&trailer);
    trailer.prev->next = newNode;
    trailer.prev = newNode;
}
// remove the first object of the list
int DoublyLinkedList::removeFirst()
{
    if (isEmpty())
        throw EmptyDLinkedListException("Empty Doubly Linked List");
    DListNode *node = header.next;
    node->next->prev = &header;
    header.next = node->next;
    int obj = node->obj;
    delete node;
    return obj;
}
// remove the last object of the list
int DoublyLinkedList::removeLast()
{
    if (isEmpty())
        throw EmptyDLinkedListException("Empty Doubly Linked List");
    DListNode *node = trailer.prev;
    node->prev->next = &trailer;
    trailer.prev = node->prev;
    int obj = node->obj;
    delete node;
    return obj;
}
// destructor
DoublyLinkedList::~DoublyLinkedList()
{
    DListNode *prev_node, *node = header.next;
    while (node != &trailer) {
        prev_node = node;
        node = node->next;
        delete prev_node;
    }
    header.next = &trailer;
    trailer.prev = &header;
}
// return the first object
int DoublyLinkedList::first() const
{
    if (isEmpty())
        throw EmptyDLinkedListException("Empty Doubly Linked List");
    return header.next->obj;
}
// return the last object
int DoublyLinkedList::last() const
{
    if (isEmpty())
        throw EmptyDLinkedListException("Empty Doubly Linked List");
    return trailer.prev->obj;
}
// return the list length
int DoublyLinkedListLength(DoublyLinkedList& dll) {
    DListNode *current = dll.getFirst();
    int count = 0;
    while(current != dll.getAfterLast()) {
        count++;
        current = current->getNext(); //iterate
    }
    return count;
}
// output operator
ostream& operator<<(ostream& out, const DoublyLinkedList& dll) {
    /* Complete this function */
    DListNode* temp = dll.getFirst();
    while (temp != dll.getAfterLast())
    {
        out << temp->getElem() << " ";
        temp = temp->getNext();
    }
    return out;
}
