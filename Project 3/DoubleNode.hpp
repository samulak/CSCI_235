//Name: Adam Samulak
//Class: CSCI 235
//Instructor: Oyewole Oyekoya
//Assignment: Project 3
//Date: 04/04/20

/** @file DoubleNode.hpp **/

#ifndef DOUBLE_NODE_
#define DOUBLE_NODE_

template<class ItemType>
class DoubleNode
{
private:
  ItemType item; // Data item
  DoubleNode<ItemType>* nextPointer; // Pointer to the next node
  DoubleNode<ItemType>* previousPointer; // Pointer to the previous node

public:
  /** Default constructor: Creates an DoubleNode and initializes nextPointer and
  previousPointer to nullptr .
  Precondition: None
  Postcondition: A DoubleNode with null head pointers exists. */
  DoubleNode();

  /** Copy constructor: Creates an DoubleNode and initializes nextPointer and
  previousPointer to nullptr and the item to anItem.
  Precondition: None
  Postcondition: A DoubleNode with null pointers and Item as item exists.*/
  DoubleNode(const ItemType& anItem);

  /** Copy constructor: Creates an DoubleNode and initializes nextPointer and
  previousPointer to nextNodePtr and previousNodePtr, and the item to anItem.
  Precondition: None
  Postcondition: A DoubleNode with specified pointers and Item as item exists.*/
  DoubleNode(const ItemType& anItem, DoubleNode<ItemType>* nextNodePtr, DoubleNode<ItemType>* previousNodePtr);

  /** Gets the item from DoubleNode.
  Precondition: DoubleNode exists.
  Postcondition: Returns an item.*/
  ItemType getItem() const;

  /** Gets nextPointer to the following DoubleNode.
  Precondition: DoubleNode exists.
  Postcondition: Returns the next pointer.*/
  DoubleNode<ItemType>* getNext() const;

  /** Gets previousPointer to the previous DoubleNode.
  Precondition: DoubleNode exists.
  Postcondition: Returns the previous pointer.*/
  DoubleNode<ItemType>* getPrevious() const;

  /** Sets (alters) the item in DoubleNode.
  Precondition: DoubleNode exists.
  Postcondition: DoubleNode's item is anItem .*/
  void setItem(const ItemType& anItem);

  /** Sets (alters) nextPointer in DoubleNode.
  Precondition: DoubleNode exists.
  Postcondition: DoubleNode's nextPointer pointing to nextNodePtr .*/
  void setNextPointer(DoubleNode<ItemType>* nextNodePtr);

  /** Sets (alters) previousPointer in DoubleNode.
  Precondition: DoubleNode exists.
  Postcondition: DoubleNode's previousPointer pointing to previousNodePtr .*/
  void setPreviousPointer(DoubleNode<ItemType>* previousNodePtr);
}; // end DoubleNode

#include "DoubleNode.cpp"
#endif
