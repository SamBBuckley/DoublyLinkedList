#ifndef NODE_H
#define NODE_H
//////////////////////////////////////////////////////////////////////////////
//  Note this is just a simple version of a node which only allows          //
//  for the usage of integers as the value, you could use 'typeing'         //
//  to make a node not care what type of value is stored within it.         //
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//                         class template definition                        //
//////////////////////////////////////////////////////////////////////////////
struct Node {
    Node(int data): data(data), next(nullptr), prev(nullptr) {}
    int data; // Data for the node
    Node* next; // Value of the next node
    Node* prev; // Value of the previous node
};

//////////////////////////////////////////////////////////////////////////////
//                       helper function declarations                       //
//////////////////////////////////////////////////////////////////////////////
 bool operator==(const Node& rhs, const Node& lhs);
 bool operator!=(const Node& rhs, const Node& lhs);
 bool operator<(const Node& rhs, const Node& lhs);
 bool operator<=(const Node& rhs, const Node& lhs);
 bool operator>(const Node& rhs, const Node& lhs);
 bool operator>=(const Node& rhs, const Node& lhs);

#endif
