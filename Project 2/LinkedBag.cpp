//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT bag: Link-based implementation.
    @file LinkedBag.cpp */

#include "LinkedBag.h"
#include "Node.h"
#include <cstddef>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
template<class ItemType>
LinkedBag<ItemType>::LinkedBag() : headPtr(nullptr), itemCount(0)
{
}  // end default constructor

template<class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& aBag)
{
	itemCount = aBag.itemCount;
   Node<ItemType>* origChainPtr = aBag.headPtr;  // Points to nodes in original chain

   if (origChainPtr == nullptr)
      headPtr = nullptr;  // Original bag is empty
   else
   {
      // Copy first node
      headPtr = new Node<ItemType>();
      headPtr->setItem(origChainPtr->getItem());

      // Copy remaining nodes
      Node<ItemType>* newChainPtr = headPtr;      // Points to last node in new chain
      origChainPtr = origChainPtr->getNext();     // Advance original-chain pointer

      while (origChainPtr != nullptr)
      {
         // Get next item from original chain
         ItemType nextItem = origChainPtr->getItem();

         // Create a new node containing the next item
         Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);

         // Link new node to end of new chain
         newChainPtr->setNext(newNodePtr);

         // Advance pointer to new last node
         newChainPtr = newChainPtr->getNext();

         // Advance original-chain pointer
         origChainPtr = origChainPtr->getNext();
      }  // end while

      newChainPtr->setNext(nullptr);              // Flag end of chain
   }  // end if
}  // end copy constructor

template<class ItemType>
LinkedBag<ItemType>::LinkedBag(ItemType entries[], int entryCount)
{
	headPtr = nullptr;
	itemCount = 0;

	for (int i = 0; i < entryCount; i++) {
		add(entries[i]);
	}
} // end array constructor

template<class ItemType>
LinkedBag<ItemType>::~LinkedBag()
{
   clear();
}  // end destructor

template<class ItemType>
bool LinkedBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
std::vector<ItemType> LinkedBag<ItemType>::toVector() const
{
   std::vector<ItemType> bagContents;
   Node<ItemType>* curPtr = headPtr;
   int counter = 0;
	while ((curPtr != nullptr) && (counter < itemCount))
   {
		bagContents.push_back(curPtr->getItem());
      curPtr = curPtr->getNext();
      counter++;
   }  // end while

   return bagContents;
}  // end toVector

template<class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& anEntry)
{
   Node<ItemType>* entryNodePtr = getPointerTo(anEntry);
   bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);
   if (canRemoveItem)
   {
      // Copy data from first node to located node
      entryNodePtr->setItem(headPtr->getItem());

      // Delete first node
      Node<ItemType>* nodeToDeletePtr = headPtr;
      headPtr = headPtr->getNext();

      // Return node to the system
      nodeToDeletePtr->setNext(nullptr);
      delete nodeToDeletePtr;
      nodeToDeletePtr = nullptr;

      itemCount--;
   } // end if

	return canRemoveItem;
}  // end remove

template<class ItemType>
void LinkedBag<ItemType>::clear()
{
   Node<ItemType>* nodeToDeletePtr = headPtr;
   while (headPtr != nullptr)
   {
      headPtr = headPtr->getNext();

      // Return node to the system
      nodeToDeletePtr->setNext(nullptr);
      delete nodeToDeletePtr;

      nodeToDeletePtr = headPtr;
   }  // end while
   // headPtr is nullptr; nodeToDeletePtr is nullptr

	itemCount = 0;
}  // end clear

template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
	int frequency = 0;
   int counter = 0;
   Node<ItemType>* curPtr = headPtr;
   while ((curPtr != nullptr) && (counter < itemCount))
   {
      if (anEntry == curPtr->getItem())
      {
         frequency++;
      } // end if

      counter++;
      curPtr = curPtr->getNext();
   } // end while

	return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
	return (getPointerTo(anEntry) != nullptr);
}  // end contains

/* ALTERNATE 1
template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
   return getFrequencyOf(anEntry) > 0;
}
*/
/* ALTERNATE 2
template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
   bool found = false;
   Node<ItemType>* curPtr = headPtr;
   int i = 0;
   while (!found && (curPtr != nullptr) && (i < itemCount))
   {
      if (anEntry == curPtr-<getItem())
      {
         found = true;
      }
      else
      {
         i++;
         curPtr = curPtr->getNext();
      }  // end if
   }  // end while

   return found;
}  // end contains
*/

/***************** FUNCTIONS ADDED FOR THE PROJECT 2 *************************/

template<class ItemType>
bool LinkedBag<ItemType>::add(const ItemType& newEntry)
{
	 // create a new node cotaining the new entry and sets it's pointer to nullptr
	 Node<ItemType>* nextNodePtr = new Node<ItemType>();
	 nextNodePtr->setItem(newEntry);
	 nextNodePtr->setNext(nullptr);

	 // copy head pointer to current pointer
	 Node<ItemType>* currentPtr = headPtr;

	 if (headPtr == nullptr) {
		 headPtr = nextNodePtr; // link new node to head pointer
		 itemCount++;
		 return true;
	 }else if(currentPtr->getNext() == nullptr){
		 currentPtr->setNext(nextNodePtr); // link new node to the first node
		 itemCount++;
		 return true;
	 }else{
		 while (currentPtr->getNext() != nullptr) {
			 currentPtr = currentPtr->getNext();
			 if(currentPtr->getNext() == nullptr){
				 currentPtr->setNext(nextNodePtr); // link new node to the last node with nullptr
				 itemCount++;
				 return true;
			 }
	 	 } // end while
	} // end if
	return false;
} // end add

template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const
{
	int numberOfNodes = 0;
	// copy headPtr to current pointer
	Node<ItemType>* currentPtr = headPtr;
	// loop itterating through the bag
	while(currentPtr != nullptr){
		numberOfNodes++;
		currentPtr = currentPtr->getNext();
	}
	return numberOfNodes;
}  // end getCurrentSize

template<class ItemType>
int LinkedBag<ItemType>::getCurrentSizeRecursive() const
{
	int numberOfNodes = 0;
	// create a temporary Linked Bag and copy headPtr to tempPtr
	LinkedBag<ItemType>* tempBag = new LinkedBag<ItemType>;
	Node<ItemType>* tempPtr = headPtr;

	if(tempPtr == nullptr){
		return numberOfNodes;
	}else{
		tempPtr = tempPtr->getNext();
		while (tempPtr != nullptr) {
			tempBag->add(tempPtr->getItem());
			tempPtr = tempPtr->getNext();
		}
		numberOfNodes = tempBag->getCurrentSizeRecursive();
		numberOfNodes++;
		return numberOfNodes;
	} // end if
} // end getCurrentSizeRecursive

template<class ItemType>
void LinkedBag<ItemType>::deleteSecondNode()
{
	// copy head pointer to a curent pointer
	Node<ItemType>* currentPtr = headPtr;

	// copy head pointer to a previous pointer
	Node<ItemType>* previousPtr = headPtr;

	if (currentPtr != nullptr && currentPtr->getNext() != nullptr) {
		currentPtr = currentPtr->getNext(); // move to the next node
		Node<ItemType>* nodeToDeletePtr = currentPtr; // create a new pointer and
																								 // copy current pointer

		currentPtr = currentPtr->getNext(); // move to the next node

		//delete and dealocate the node
		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
		nodeToDeletePtr = nullptr;

		//point the first node to the third node
		previousPtr->setNext(currentPtr);
		itemCount--;
	}// end if
} // end deleteSecondNode

template<class ItemType>
ItemType LinkedBag<ItemType>::removeRandom()
{
	ItemType item;
	// copy head pointer to a curent pointer
	Node<ItemType>* curentPtr = headPtr;

	// copy head pointer to a previous pointer
	Node<ItemType>* previousPtr = headPtr;

	// clock is reset to produce a randomPosition
	srand (time(NULL));
	int randomPosition = rand()%itemCount+1;

	// moves the current pointer to the node before the node that will be removed
	for (int i = 0; i<randomPosition-2; i++){
		curentPtr = curentPtr->getNext();
		previousPtr = curentPtr;
	}

	if (curentPtr != nullptr && curentPtr->getNext() != nullptr) {
		curentPtr = curentPtr->getNext(); // move to the next node
		Node<ItemType>* nodeToDeletePtr = curentPtr; // create a new pointer and
																								 // copy current pointer
		item = curentPtr->getItem();

		curentPtr = curentPtr->getNext(); // move to the next node

		//delete and dealocate the node
		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
		nodeToDeletePtr = nullptr;

		//point the first node to the third node
		previousPtr->setNext(curentPtr);
		itemCount--;
	}// end if
	return item;
} // end removeRandom
/****************************** END OF ***************************************/

/***************** FUNCTIONS ADDED FOR THE PROJECT 2 *************************/

// private
// Returns either a pointer to the node containing a given entry
// or the null pointer if the entry is not in the bag.
template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::getPointerTo(const ItemType& anEntry) const
{
   bool found = false;
   Node<ItemType>* curPtr = headPtr;

   while (!found && (curPtr != nullptr))
   {
      if (anEntry == curPtr->getItem())
         found = true;
      else
         curPtr = curPtr->getNext();
   } // end while

   return curPtr;
} // end getPointerTo
