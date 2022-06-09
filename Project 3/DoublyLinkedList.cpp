//Name: Adam Samulak
//Class: CSCI 235
//Instructor: Oyewole Oyekoya
//Assignment: Project 3
//Date: 04/04/20

/** @file DoublyLinkedList.cpp **/

#include "DoubleNode.hpp"
#include "DoublyLinkedList.hpp"
#include <iostream>

template<class ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList() : headPtr(nullptr), itemCount(0)
{
} // end default constructor

template<class ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList(DoubleNode<ItemType>* headPointer) : headPtr(headPointer), itemCount(1)
{
} // end copy constructor

template<class ItemType>
DoublyLinkedList<ItemType>::~DoublyLinkedList(){
  clear();
} // end destructor

template<class ItemType>
bool DoublyLinkedList<ItemType>::insert(const ItemType& Item, const int& position)
{
  // checks if the position is in a given range
  // if position exceeds itemCount+1 it returns false to indicate
  // that the insert failed
  bool positionCheck = (position >= 1) && (position <= itemCount+1);
  if(positionCheck){
  // create a new node with the new item
  DoubleNode<ItemType>* newNodePointer = new DoubleNode<ItemType>(Item);
  if(headPtr == nullptr){
    // assign the new node to the head pointer
    headPtr = newNodePointer;
    // increase itemCount
    itemCount++;
  }else if (position == 1) {
    // link the original node as a next pointer to the new node
    newNodePointer->setNextPointer(headPtr);
    // link the original node to the previous new node
    headPtr->setPreviousPointer(newNodePointer);
    // link the new node to the head pointer
    headPtr = newNodePointer;
    // increase itemCount
    itemCount++;
  }else if (position == itemCount+1) {
    // create a new current pointer
    DoubleNode<ItemType>* currentPtr = headPtr;
    // advance current pointer to the end of the list
    while (currentPtr->getNext() != nullptr) {
      currentPtr = currentPtr->getNext();
    }// end while
      // link the last node to the new node
      currentPtr->setNextPointer(newNodePointer);
      // link the new node back to the previous node
      newNodePointer->setPreviousPointer(currentPtr);
      // increase itemCount
      itemCount++;
  }else{
    // create a new previous pointer
    DoubleNode<ItemType>* previousPtr = headPtr;
    // advance current pointer to the position-1
    for (int i = 1; i < position-1; i++) {
      // advance the currentPtr to the next node
      previousPtr = previousPtr->getNext();
    }// end for
    // create a new next pointer
    DoubleNode<ItemType>* nextPointer;
    // get the position pointer
    nextPointer = previousPtr->getNext();
    // link previous pointer to the new node
    previousPtr->setNextPointer(newNodePointer);
    // link the new node to the previous pointer
    newNodePointer->setPreviousPointer(previousPtr);
    // link the new node to the next pointer
    newNodePointer->setNextPointer(nextPointer);
    // link the next pointer back to the new node
    nextPointer->setPreviousPointer(newNodePointer);
    // increase itemCount
    itemCount++;
  } // end if
} // endl if
  return positionCheck;
} // end of insert

template<class ItemType>
void DoublyLinkedList<ItemType>::display(){

  // copy headPtr to currentPtr
  DoubleNode<ItemType>* currentPtr = headPtr;

  // loop prints out all the nodes from the list
  for (int i = 0; i < itemCount; i++) {
    // print out the new node and start a new line
    std::cout << currentPtr->getItem();
    // advance currentPtr to the next node
    currentPtr = currentPtr->getNext();
    // prevents printing of space at the end of loop
    // this is necessary for gradescope grader
    if ( i < itemCount-1) {
      std::cout << ' ';
    }// end if
  } // end for

  // new line at the end of printout
  // this is necessary for gradescope grader
  std::cout << '\n';
}// end of display

template<class ItemType>
void DoublyLinkedList<ItemType>::remove(const int& position){
  // copy headPtr to currentPtr
  DoubleNode<ItemType>* currentPtr = headPtr;
  // loop removes the first node
  if (position == 1) {
    // copy currentPtr to deleteNode
    DoubleNode<ItemType>* deleteNode = currentPtr;
    // point headPtr to the second node
    headPtr = currentPtr->getNext();
    // set the new first nodes' previousNode to nullptr
    currentPtr->setPreviousPointer(nullptr);
    // dealocate the deleteNode and set the pointer to nullptr
    delete deleteNode;
    deleteNode = nullptr;
    // decrease the itemCount
    itemCount--;
  }else if(position == itemCount){
    // advance the current pointer to position-1
    for (int i = 0; i < position-1; i++) {
      // advance the currentPtr to the next node
      currentPtr = currentPtr->getNext();
    }
    // create new delete node and link it to current pointer
    DoubleNode<ItemType>* deleteNode = currentPtr;
    // set next and previous pointer
    currentPtr->setNextPointer(nullptr);
    deleteNode->setPreviousPointer(nullptr);
    // dealocate tge deleteNode and set the pointer to nullptr
    delete deleteNode;
    deleteNode = nullptr;
    // decrease the itemCount
    itemCount--;
  }else{
  // loop advances the currentPtr to the node that is before the node that will
  // be deleted.
  for (int i = 0; i < position-2; i++) {
    // advance the currentPtr to the next node
    currentPtr = currentPtr->getNext();
  }
  // copy currentPtr to the previousNode
  DoubleNode<ItemType>* previousNode = currentPtr;
  // advance the currentPtr
  currentPtr = currentPtr->getNext();
  // copy currentPtr to deleteNode
  DoubleNode<ItemType>* deleteNode = currentPtr;
  // advance the currentPtr
  currentPtr = currentPtr->getNext();
  // link the previousNode to the currentPtr
  previousNode->setNextPointer(currentPtr);
  // link the currentPtr to the previousNode
  currentPtr->setPreviousPointer(previousNode);
  // set both: next and previous pointers to null in the deleteNode
  deleteNode->setNextPointer(nullptr);
  deleteNode->setPreviousPointer(nullptr);
  // dealocate deleteNode, set it to nullptr and decrease itemCount
  delete deleteNode;
  deleteNode = nullptr;
  itemCount--;
}// end else
} //end of remove

template<class ItemType>
int DoublyLinkedList<ItemType>::getSize() const{
  return itemCount;
} // end getSize

template<class ItemType>
DoubleNode<ItemType>* DoublyLinkedList<ItemType>::getHeadPtr() const{
  return headPtr;
} //end getHeadPtr

template<class ItemType>
DoubleNode<ItemType>* DoublyLinkedList<ItemType>::getAtPos(const int& pos) const{
  // copy headPtr to currentPtr
  DoubleNode<ItemType>* currentPtr = headPtr;
  // loop advances the currentPtr to the pos
  for (int i = 1; i < pos; i++) {
    // advance the currentPtr
    currentPtr = currentPtr->getNext();
  }// end for
  return currentPtr;
}// end getAtPos

template<class ItemType>
bool DoublyLinkedList<ItemType>::isEmpty() const{
  // function check if itemCount is 0 and returns coresponding bool value
  if (itemCount == 0) {
    return true;
  }else{
    return false;
  }// end if
} // end isEmpty

template<class ItemType>
void DoublyLinkedList<ItemType>::clear(){
  // copy headPtr to deleteNode
  DoubleNode<ItemType>* deleteNode = headPtr;
  // lop goes through each node and deltes it until headPtr is nullptr
  while (headPtr != nullptr)
  {
     // advance the headPtr
     headPtr = headPtr->getNext();
     // set both: next and previous pointers to null in the deleteNode
     deleteNode->setNextPointer(nullptr);
     deleteNode->setPreviousPointer(nullptr);
     // dealocate deleteNode, set it to nullptr
     delete deleteNode;
     deleteNode = nullptr;
     // copy headPtr to deleteNode
     deleteNode = headPtr;
  }  // end while
 // set itemCount to 0
 itemCount = 0;
}// end clear

template<class ItemType>
void DoublyLinkedList<ItemType>::displayBackwards() const{
  // copy headPtr to currentPtr
  DoubleNode<ItemType>* currentPtr = headPtr;
  // loop advances the currentPtr to the the last node
  for (int i = 1; i < itemCount; i++) {
    // advance the currentPtr
    currentPtr = currentPtr->getNext();
  }// for loop
  // loop advances the currentPtr to the the first node
  for (int i = itemCount; i > 0 ; i--) {
    std::cout << currentPtr->getItem();
    currentPtr = currentPtr->getPrevious();
    if ( i-1 > 0) {
      std::cout << ' ';
    }
  }
  std::cout << '\n';
}
template<class ItemType>
DoublyLinkedList<ItemType> DoublyLinkedList<ItemType>::interleave(const DoublyLinkedList<ItemType>& a_list){
  // Get sizes of the two lists
  int itemCountListOne = itemCount;
  int itemCountListTwo = a_list.getSize();
  // Switch values for coping nodes from both lists
  bool ListOneSwitch = true;
  bool ListTwoSwitch = false;
  // new DoublyLinkedList
  DoublyLinkedList<ItemType>* newList = new DoublyLinkedList<ItemType>();
  // currentPtr for list one
  DoubleNode<ItemType>* currentPtrListOne = headPtr;
  // currentPtr for list two
  DoubleNode<ItemType>* currentPtrListTwo = a_list.getHeadPtr();
  // keeps track of position of nodes in the new list
  int i = 1;
  // loop sorts the two lists by number of items present in each list
  while (itemCountListOne != 0 || itemCountListTwo != 0) {
    // checks if both items have any nodes left to be copied
    if (itemCountListOne != 0 && itemCountListTwo != 0) {
      // inserts the node from the frist or second list to the new list
      if(ListOneSwitch){
        // inset the node from first list
        newList->insert( currentPtrListOne->getItem(),i);
        // increment position in the new list
        i++;
        // advance the node of the first list to the next node
        currentPtrListOne = currentPtrListOne->getNext();
        // decrement the itemCountListOne of the first list
        itemCountListOne--;
        // switch the order of lists that will be copied
        // this will cause second list to be used in next loop itteration
        ListOneSwitch = false;
        ListTwoSwitch = true;
      }else{
        // inset the node from second list
        newList->insert( currentPtrListTwo->getItem(),i);
        // increment position in the new list
        i++;
        // advance the node of the second list to the next node
        currentPtrListTwo = currentPtrListTwo->getNext();
        // decrement the itemCountListTwo of the second liste
        itemCountListTwo--;
        // switch the order of lists that will be copied
        // this will cause first list to be used in next loop itteration
        ListOneSwitch = true;
        ListTwoSwitch = false;
      }// end if
    }else if (itemCountListOne != 0 && itemCountListTwo == 0) {
      // inset the node from first list
      newList->insert( currentPtrListOne->getItem(),i);
      // increment position in the new list
      i++;
      // advance the node of the first list to the next node
      currentPtrListOne = currentPtrListOne->getNext();
      // decrement the itemCountListOne of the first list
      itemCountListOne--;
    }else if (itemCountListOne == 0 && itemCountListTwo != 0) {
      // inset the node from second list
      newList->insert( currentPtrListTwo->getItem(),i);
      // increment position in the new list
      i++;
      // advance the node of the second list to the next node
      currentPtrListTwo = currentPtrListTwo->getNext();
      // decrement the itemCountListTwo of the second liste
      itemCountListTwo--;
    }// end if
  }// end if
return *newList;
}// end interleave
