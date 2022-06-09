//Name: Adam Samulak
//Class: CSCI 235
//Instructor: Oyewole Oyekoya
//Assignment: Project 3
//Date: 04/04/20

/** @file DoubleNode.cpp **/

#include "DoubleNode.hpp"

template<class ItemType>
DoubleNode<ItemType>::DoubleNode() : nextPointer(nullptr), previousPointer(nullptr)
{
} // end default constructor

template<class ItemType>
DoubleNode<ItemType>::DoubleNode(const ItemType& anItem) : item(anItem), nextPointer(nullptr), previousPointer(nullptr)
{
} // end constructor

template<class ItemType>
DoubleNode<ItemType>::DoubleNode(const ItemType& anItem, DoubleNode<ItemType>* nextNodePtr, DoubleNode<ItemType>* previousNodePtr) : item(anItem), nextPointer(nextNodePtr), previousPointer(previousNodePtr)
{
} // end constructor

template<class ItemType>
ItemType DoubleNode<ItemType>::getItem() const
{
  return item;
}// end getItem

template<class ItemType>
DoubleNode<ItemType>* DoubleNode<ItemType>::getNext() const
{
  return nextPointer;
} // end getNext

template<class ItemType>
DoubleNode<ItemType>* DoubleNode<ItemType>::getPrevious() const
{
  return previousPointer;
} // end getPrevious

template<class ItemType>
void DoubleNode<ItemType>::setItem(const ItemType& anItem)
{
  item = anItem;
} // end setItem

template<class ItemType>
void DoubleNode<ItemType>::setNextPointer(DoubleNode<ItemType>* nextNodePtr)
{
  nextPointer = nextNodePtr;
} // end setNextPointer

template<class ItemType>
void DoubleNode<ItemType>::setPreviousPointer(DoubleNode<ItemType>* previousNodePtr)
{
  previousPointer = previousNodePtr;
} // end setPreviousPointer
