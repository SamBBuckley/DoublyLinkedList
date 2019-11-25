#include <iostream>
#include "Node.h"

//////////////////////////////////////////////////////////////////////////////
//  This is the general style for a simple DoublyLinkedList it should       //
//  Be considered as such. Much functionality could be added to it to make  //
//  it ore versatile and complete inluding using 'typing' to abstract it    //
//////////////////////////////////////////////////////////////////////////////
class DoublyLinkedList {
public:
    DoublyLinkedList();
    DoublyLinkedList(int value);
    //Big Three
    DoublyLinkedList(const DoublyLinkedList& dll); // Where dll is a DoublyLinkedList
    DoublyLinkedList& operator=(const DoublyLinkedList& rhs); // Where rhs is the right hand side of the =
    ~DoublyLinkedList();
    // Functions to facilitate the creation and initialization of a DoublyLinkedList
    void pushBack(int value);
    //Functions to facility the BigThree for the DoublyLinkedList
    void clear();
    void append(const DoublyLinkedList& rhs);
    //Functions to access the private members of the DoublyLinkedList
    Node* getFront() { return this->head;}
    Node* getBack() { return this->tail; }
    unsigned int getSize() { return this->size; }

private: // There are the actual values/variables of the DoublyLinkedList
    Node *head;
    Node *tail;
    unsigned int size; // We cannot have size be less than 0, so unsigned
};

///////////////////////////////////////////////////////////////////////////////////
//      Definition of all the Standard functions for a DoublyLinkedList         //
/////////////////////////////////////////////////////////////////////////////////


//Constructors
DoublyLinkedList::DoublyLinkedList() :
  head(nullptr), tail(nullptr), size(0) {}

DoublyLinkedList::DoublyLinkedList(int value) :
    head(nullptr), tail(nullptr), size(0) {
      Node n = Node(value);
      head = &n;
      tail = &n;
      size = 1;
    }

//Big Three
DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& dll) {
  append(dll);
}

DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList &rhs) {
  clear();
  append(rhs);
  return *this;
}

DoublyLinkedList::~DoublyLinkedList() {
  clear(); // Defined in this file in the Helper functions section.
}



///////////////////////////////////////////////////////////////////////////////////
//    Helper functions to facilitate the Standard Functions defined above        //
///////////////////////////////////////////////////////////////////////////////////
void DoublyLinkedList::pushBack(int value) {
  Node* n = new Node(value); // See constructor in Node.h line 13
  if(this->head != NULL) {
    n->next = nullptr;
    n->prev = this->tail;
    tail->next = n;
  } else {
    this->head = n;
  }
  this->tail = n;
  this->size += 1;
}

void DoublyLinkedList::clear() {
  Node* node = head;
    while(node != NULL) { // To do this you must define the operator for struct Node. See Node.h line 23
        Node* nextNode = node->next;
        delete node;
        node = nextNode;
    }
    size = 0;
    head = nullptr;
    tail = nullptr;
}

void DoublyLinkedList::append(const DoublyLinkedList& dll) {
  Node* current = dll.head;
  while(current != NULL) {
    this->pushBack(current->data);
    current = current->next;
  }
}

