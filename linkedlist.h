#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// ======================================================
// LinkedList: A Doubly-Linked List 
// ======================================================

// STRUCT DEFINITIONS

// We have 2 structs: One is a LinkedListNode, and one is a LinkedListHead, 
// which we create an alias for the pointer. 

// This struct represents an individual node within a linked list.  A node
// contains next and prev pointers as well as a customer-supplied payload
// pointer.
typedef struct ll_node {
  char           data[100];       // Data this node holds 
  struct ll_node *next;     // next node in list, or NULL
  struct ll_node *prev;     // prev node in list, or NULL
} LinkedListNode, *LinkedListNodePtr;

// This struct represents the entire linked list.  We provided a struct
// declaration (but not definition) in LinkedList.h; this is the associated
// definition.  This struct contains metadata about the linked list.
typedef struct ll_head {
  uint64_t          num_elements;  //  # elements in the list
  LinkedListNodePtr head;  // head of linked list, or NULL if empty
  LinkedListNodePtr tail;  // tail of linked list, or NULL if empty
} LinkedList, *LinkedListPtr;


// ======================================================
// LinkedList: A Doubly-Linked List 
// ======================================================

// Creates a LinkedList.
// The customer is responsible for calling DestroyLinkedList()
// to destroy the LinkedList when done.
//
// Returns a LinkedList; NULL if there's an error. 
LinkedListPtr CreateLinkedList();

// Destroys a LinkedList.
// All structs associated with a LinkedList will be
// released and freed.
//
// INPUT: A pointer to a LinkedList.
void DestroyLinkedList(LinkedListPtr list);

// Returns the number of elements in the linked list. 
// 
// INPUT: A LinkedList 
// 
// Returns the number of elements in the list. 
unsigned int NumElementsInLinkedList(LinkedListPtr list); 

// Adds an element to the tail of a LinkedList, with the given value.
//
// INPUT: A pointer to the LinkedList that will be added to,
// INPUT: A value for a node in the linkedList.
//
// Returns 0 if the insertion was successful; non-zero for failure. 
int AddRight(LinkedListPtr, char*);

// Adds an element to the tail of a LinkedList, with the given value.
//
// INPUT: A pointer to the LinkedList that will be added to,
// INPUT: A value for a node in the linkedList.
//
// Returns 0 if the insertion was successful; non-zero for failure. 
int RemoveRight(LinkedListPtr);

// Prints out the given LinkedListPtr. 
//
// INPUT: A pointer to the LinkedList that will be printed out.
//
// Returns 0 if the insertion was successful; non-zero for failure. 
int PrintLinkedList(LinkedListPtr);

// Creates a LinkedListNode by malloc'ing the space.
//
// INPUT: A pointer that the payload of the returned LLNode will point to.
//
// Returns a pointer to the new LinkedListNode.
LinkedListNode* CreateLinkedListNode(char* data);

// Destroys and free's a provided LLNode.
//
// INPUT: A pointer to the node to destroy.
//
// Returns 0 if the destroy was successful.
int DestroyLinkedListNode(LinkedListNode *node);

#endif
