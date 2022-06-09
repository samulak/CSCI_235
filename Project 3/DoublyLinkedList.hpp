//Name: Adam Samulak
//Class: CSCI 235
//Instructor: Oyewole Oyekoya
//Assignment: Project 3
//Date: 04/04/20

/** @file DoublyLinkedList.hpp **/

#ifndef DOUBLY_LINKED_LIST_
#define DOUBLY_LINKED_LIST_

#include "DoubleNode.hpp"

template<class ItemType>
class DoublyLinkedList : public DoubleNode<ItemType>
{
private:
  DoubleNode<ItemType>* headPtr; // Pointer to the first DoubleNode
  int itemCount; // Number of nodes in a DoublyLinkedList
public:
  /** Default constructor: Creates an DoublyLinkedList and initializes head
  pointer to null and item count to 0.
  Precondition: None
  Postcondition: A DoublyLinkedList with null head pointer and item cout at
  0 exists. */
  DoublyLinkedList();

  /** Constructor: Creates an DoublyLinkedList and initializes head pointer to
  the specified headPointer and item count to 1.
  Precondition: headPointer is linked to the desired DoubleNode.
  Postcondition: A DoublyLinkedList with assigned head pointer and item cout at
  1 exists. */
  DoublyLinkedList(DoubleNode<ItemType>* headPointer);

  /** Destructor: Destroys the DoublyLinkedList and dealocates all nodes.
  Precondition: DoublyLinkedList exists.
  Postcondition: No object exists. */
  virtual ~DoublyLinkedList();

  /** Inserts a new node with specified Item at specified position.
  Precondition: A DoublyLinkedList exists with no more than itemCount+1 items.
  Postcondition: Returns true or false depending if the insertion was successful.*/
  bool insert(const ItemType& Item, const int& position);

  /** Displays contents of the DoublyLinkedList.
  Precondition: A DoublyLinkedList exists with at least 1 node.
  Postcondition: Prints items from consecutive nodes.*/
  void display();

  /** Removes nodes at specified position.
  Precondition: A DoublyLinkedList exists with itemCount >= position.
  Postcondition: A DoublyLinkedList exists with one less node.*/
  void remove(const int& position);

  /** Gets the current number of nodes in the bag.
  Precondition: DoublyLinkedList exists.
  Postcondition: Returns the integer with number of nodes in the bag.*/
  int getSize() const;

  /** Gets the head pointer of the DoublyLinkedList object.
  Precondition: DoublyLinkedList exists.
  Postcondition: Returns a pointer to the firs node in the DoublyLinkedList object.*/
  DoubleNode<ItemType>* getHeadPtr() const;

  /** Gets the pointer to the node at specified position.
  Precondition: DoublyLinkedList exists with number of nodes at least equal to pos.
  Postcondition: Returns a pointer to the node at pos.*/
  DoubleNode<ItemType>* getAtPos(const int& pos) const;

  /** Returns a bool value to indicate if DoublyLinkedList is empty or not.
  Precondition: DoublyLinkedList object exists.
  Postcondition: Returns true if DoublyLinkedList empty and false if it is not.*/
  bool isEmpty() const;

  /** Removes all nodes from DoublyLinkedList.
  Precondition: DoublyLinkedList object exists.
  Postcondition: DoublyLinkedList object doesn't exists.*/
  void clear();

  /** Displays contents of the DoublyLinkedList in reverse order.
  Precondition: A DoublyLinkedList exists with at least 1 node.
  Postcondition: Prints items starting from last node to the first*/
  void displayBackwards() const;

  /** Creates a DoublyLinkedList that is formed from two lists.
  First list is the list that calls the function and the second is passed as
  a parameter.
  Precondition: A DoublyLinkedList exists with at least 1 node.
  Postcondition: Outputs a DoublyLinkedList with nodes that switch
  between list one and list two.*/
  DoublyLinkedList<ItemType> interleave(const DoublyLinkedList<ItemType>& a_list);
};

#include "DoublyLinkedList.cpp"
#endif
