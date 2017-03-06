/*
   COPYRIGHT (C) 2016 Nicholas Gallimore (nfg3) All rights reserved.
   CSII assignment 5 A
   Author.  Nicholas Gallimore
            nfg3@zips.uakron.edu
   Version. 1.01 09.09.2017

*/
// Implementation file for the CharList class

// default constructor
#include "charList.hpp"
CharList::CharList()
{
   head = nullptr;
}

//**************************************************
// displayList shows the value                     *
// stored in each node of the linked list          *
// pointed to by head.                             *
// pre: an empty parameter list                    *
// post: standard output of the linked list        *
//**************************************************

void CharList::displayList() const
{
   Node *nodePtr;  // To move through the list

   // Position nodePtr at the head of the list.
   nodePtr = head;
   short count = 0;

   // While nodePtr points to a node, traverse
   // the list.
   while (nodePtr)
   {
      // Display the value in this node.
      std::cout << "[" << nodePtr->value << "] -> ";
      ++count;
      // Move to the next node.
      nodePtr = nodePtr->next;
      if (count % 10 == 0) {
        std::cout << std::endl;
        count = 0;
      }
   }
   std::cout << std::endl;
}


// appends node
template <class T>
bool CharList::appendNode(T const &value)
{
   try {
      Node* node = new Node;
      node -> value = value;
      node -> next = nullptr;

      // empty list
      if (!head) {
         head = node;

         return true;
      }
      else {
         Node* tmp = head;
         // find end of list
         while (!tmp) {
            tmp = tmp -> next;
         }
         // update "next" to node
         tmp -> next = node;
      }
      return true;
      // catch all
   } catch (...) {
      return false;
   }
}
void CharList::sort() 
{
   mergeSort(head);
}

// merge sort implementaiton
Node* CharList::mergeSort(Node* first)
{
   Node* second;
   return (!first) ? nullptr : (!first->next) ? first : { 
      second = split(first);
      return merge(mergeSort(first), mergeSort(second));
   }
}

Node* CharList::merge(Node* first, Node* second)
{
   return (!first) ? second : (!second) ? first : 
   (first -> value <= second-> value) ? {
      first -> next = merge(first -> next, second);
      return first;
   } : {
      second -> next = merge(first -> next, second);
      return second;
   }
}

Node* CharList::split(Node* node) {
   Node* second;
   return (!node) ? nullptr : (!node -> next) ? nullptr : {
      second = node -> next;
      node -> next = second -> next;
      second -> next = split(second -> next);
      return second;
   }
}

// inserts node
template <class T>
void CharList::insertNode(T const &value)
{
   appendNode(value);
   sort();
   reverse();
}

// reverses list
void CharList::reverse() {
   Node* prev = new Node();
   Node* curr = head;
   Node* next;
   while (!curr) {
      next = tmp -> next;
      curr -> next = prev;
      prev = curr;
      curr = next;
   }
   head = prev;
}

// deletes node
template <class T>
void CharList::deleteNode(T const &value)
{
   get(searchHelper(value, head) - 2) -> next = get(searchHelper(value, head));
}

// searches node
template <class T>
bool CharList::search(T const &value)
{
   sort();
   return (get(searchHelper(head))->next == value);
}

template <class T>
int CharList::searchHelper(T const &value, Node* node)
{
   Node* next = node->next;
   return 
      (node->next <= value && node->next => value)
         ? node->value
         : (tmp -> value >= value)
            ? searchHelper(value, get(length()/4))
            : searchHelper(value, get(length()*3/4));
}

template <class T>
int CharList::length()
{
   Node* tmp = head;
   int i = 0;
   while (!tmp) {
      i++;
   }
   return i;
}

template <class T>
Node* CharList::get(int index) {
   Node* tmp = head;
   for (int i = 0; i < index; i++) {
      tmp = tmp -> next;
   }
   return tmp;
}
//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
// pre: n/a                                        *
// post: destroyed object                          *
//**************************************************

CharList::~CharList()
{
   Node *nodePtr;   // To traverse the list
   Node *nextNode;  // To point to the next node

   // Position nodePtr at the head of the list.
   nodePtr = head;

   // While nodePtr is not at the end of the list...
   while (nodePtr != nullptr)
   {
      // Save a pointer to the next node.
      nextNode = nodePtr->next;

      // Delete the current node.
      delete nodePtr;

      // Position nodePtr at the next node.
      nodePtr = nextNode;
   }
}
