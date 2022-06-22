#include <stdio.h>
#include <string.h>
#include "linkedlist.h"

#define ARRAY_LEN_LIMIT 10

/*
 * Function: CreateLinkedList
 * --------------------------
 * creates a linked list struct and returns a pointer to it
 *
 * @returns a pointer to the newly created linked list
 */
LinkedListPtr CreateLinkedList() {
    LinkedListPtr ll_ptr = (LinkedListPtr)malloc(sizeof(LinkedList));
    if (ll_ptr == NULL) {
        return NULL;
    }
    ll_ptr->num_elements = 0;
    ll_ptr->head = NULL;
    ll_ptr->tail = NULL;
    return ll_ptr;
}

/*
 * Function: DestroyLinkedList 
 * ---------------------------
 * frees the memory associated with a linked list and its nodes
 *
 * @param list, the pointer to the linked list to be destroyed
 */
void DestroyLinkedList(LinkedListPtr list) {
    if (list == NULL || list->head == NULL) {
        return;
    }
    
    LinkedListNode* cur_node = list->head;
    while (cur_node != NULL) {
        LinkedListNode* next_node = cur_node->next;
        DestroyLinkedListNode(cur_node);
        cur_node = next_node;
    }

    free(list);
}

/*
 * Function: NumElementsInLinkedList 
 * ---------------------------------
 * returns the number of elements in the linked list 
 *
 * @param list, the pointer to the linked list
 * @returns the number of elements in the linked list
 */
unsigned int NumElementsInLinkedList(LinkedListPtr list) {
    if (list->head == NULL) {
        return 0;
    }
    
    return list->num_elements;
}

/*
 * Function: AppendLinkedList 
 * --------------------------
 * inserts a node containing the data argument at the end of the linked list
 *
 * @param ll_ptr, the pointer to the linked list
 * @param data, the data associated with the new node
 * @returns 0 if successful
 */
int AddRight(LinkedListPtr ll_ptr, char* data) {
    if (ll_ptr == NULL) {
        return 1;
    }

    LinkedListNode* ll_node = CreateLinkedListNode(data);

    if (ll_node == NULL) {
        return 1;
    } else {
        if (ll_ptr->head == NULL) {
            ll_ptr->head = ll_node;
            ll_ptr->tail = ll_node;
        } else {
            LinkedListNode* cur_tail;
            cur_tail = ll_ptr->tail;  // get reference to current tail
            cur_tail->next = ll_node; // assign new node to cur_tail.next
            ll_node->prev = cur_tail; // assign cur_tail to ll_node.prev

            ll_ptr->tail = ll_node;   // assign ll_node as the new tail node
        }
        ll_ptr->num_elements++;
        return 0;
    }
}

/*
 * Function: PrintLinkedList
 * -------------------------
 * prints the values associated with each node of the given linked list
 *
 * @param ll_ptr, the pointer to the linked list
 * @returns 0 if successful
 */
int PrintLinkedList(LinkedListPtr ll_ptr) {
    if (ll_ptr->head == NULL) {
        return 1;
    } else {
        LinkedListNode* cur_node = ll_ptr->head;
        int node_count = 0;
        while (cur_node != NULL) {
            if (node_count % ARRAY_LEN_LIMIT == 0) {
                printf("\n");
            }
            printf("%s -> ", cur_node->data);
            cur_node = cur_node->next;

            node_count++;
            }
        }
        printf("NULL\n");
    return 0;
}

/*
 * Function: CreateLinkedListNode
 * ------------------------------
 * creates a linked list node containing the given data 
 *
 * @param data, the data to associate with the node linked list node
 * @returns LinkedListNodePtr, pointer to the new node
 */
LinkedListNode* CreateLinkedListNode(char* data) {
    LinkedListNode* ll_node = (LinkedListNodePtr)malloc(sizeof(LinkedListNode));
    if (ll_node != NULL) {
        
        strcpy(ll_node->data, data);
        ll_node->next = NULL;
        ll_node->prev = NULL;
        return ll_node;
    } else {
        return NULL;
    }
}

/*
 * Function: DestroyLinkedListNode
 * -------------------------------
 * frees the memory of the given linked list node 
 *
 * @param ll_node, the node to free
 * @returns 0 if successful
 */
int DestroyLinkedListNode(LinkedListNode* ll_node) {
    if (ll_node == NULL) {
        return 1;
    }

    free(ll_node);
    return 0;
}

/*                                                                              
 * Function: RemoveRight                                                        
 * ---------------------                                                        
 * removes the left-most element of the linked list                             
 *                                                                              
 * @param ll_ptr, the pointer to the linked list                                
 * @returns 0 if removal was successful / 1 if not                              
 */                                                                             
int RemoveRight(LinkedListPtr ll_ptr) {                                         
    if (ll_ptr == NULL || ll_ptr->head == NULL) {                               
        return 1;                                                               
    }                                                                           

    if (ll_ptr->head == ll_ptr->tail) {
        ll_ptr->head = NULL;
        ll_ptr->tail = NULL;
        return 0;
    }
                                                                                 
    LinkedListNode* cur_tail = ll_ptr->tail;                                    
    LinkedListNode* next_tail = cur_tail->prev;                                 
                                                                                 
    ll_ptr->tail = next_tail;                                                   
    next_tail->next = NULL;                                                     
    
    DestroyLinkedListNode(cur_tail);

    ll_ptr->num_elements--;                                                     
    return 0;                                                                   
} 
