#include "linkedlist.h"

linkedlist* newLinkedlist(){
    linkedlist* list = malloc(sizeof(linkedlist));
    list->head = malloc(sizeof(node));
    list->tail = malloc(sizeof(node));
    testNull(list->head, "newLinkedlist() head");
    testNull(list->tail, "newLinkedlist() tail");
    list->head->next = list->tail;
    list->head->prev = NULL;
    list->tail->prev = list->head;
    list->tail->next = NULL;
    return list;
}

void testNull(node* node, char* location){
    if(node == NULL){
    	// Serial.println("error: malloc failed to allocate for something involving linkedlist");
    	while(1);
    }
}

void printList(node* head){
    Serial.print("[");
    Serial.print(head->path);
    Serial.print("], ");
    if(head->next != NULL){
	printList(head->next);
    }
}

linkedlist* insertTail(linkedlist* list, char* path){
    node* temp = malloc(sizeof(node));
    testNull(temp, "addTail() temp");
    //temp->path = path;
    temp->path = strdup(path);
    temp->next = list->tail; // TMP > TAIL
    temp->prev = list->tail->prev; // n-1 < TMP
    list->tail->prev->next = temp; // n-1 > TMP
    list->tail->prev = temp; // TMP < TAIL
    return list;
}

linkedlist* insertHead(linkedlist* list, char* path){
    node* temp = malloc(sizeof(node));
    testNull(temp, "addHead() temp");
    //temp->path = path;
    temp->path = strdup(path);
    temp->prev = list->head;
    temp->next = list->head->next;
    list->head->next->prev = temp;
    list->head->next = temp;
    return list;
}

node* getNext(node* currentnode){
    return currentnode->next;
}

node* getPrev(node* currentnode){
    return currentnode->prev;
}
