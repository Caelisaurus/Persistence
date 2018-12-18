#include <Arduino.h>

#ifndef linkedlist_h
#define linkedlist_h

typedef struct node {
        char* path;
        struct node *prev, *next;
} node;

typedef struct linkedlist {
        node* head;
        node* tail;

} linkedlist;

linkedlist* newLinkedlist(); // Creates a new linked tree
void printList(node* head); // Prints the top level of the linked tree
linkedlist* insertTail(linkedlist* list, char* path); // Adds a node to the linkedlist (top level of the tree)
linkedlist* insertHead(linkedlist* list, char* path); // Adds a node to the linkedlist (top level of the tree)
void testNull(node* node, char* location); // Checks if malloc failed
node* getNext(node* node);
node* getPrev(node* node);

#endif
