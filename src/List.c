//@author Zach Sabin
//@author Kyle Zeller
//call in all the necessary libraries

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "List.h"

void removeLast(List *list) {
    Node *head = list->head;
    
    //if singleton, just remove it
    if (head->next == NULL) {
        free(head);
        return;
    }

    //get the last node
    Node *current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    
    //points at the last item
    //remove current->next
    free(current->next);
    current->next = NULL;
}

void removeFirst(List *list) {
	//set the pointers to the nodes
    Node *head = list->head;
    Node *next_node = NULL;

	//see if the list is empty
    if (head == NULL) {
        return;
    }

	//adjust the nodes and free the memory to the removed node
    next_node = head->next;
    free(head);
    list->head = next_node;
}

void removeNode(List *list, int n) {
    int i = 0;
	//set the pointers to the nodes
    Node *current = list->head;
    Node *temp_node = NULL;

	//see if the node specified it the front of the list
    if (n == 0) {
        return removeFirst(list);
    }

	//iterate till the next node is null
    for (int i = 0; i < n-1; i++) {
        if (current->next == NULL) {
            return;
        }
        current = current->next;
    }

	//adjust the nodes and free the memory to the removed node
    temp_node = current->next;
    current->next = temp_node->next;
    free(temp_node);
}

void print_list(List *list) {
	//set the pointer to the head of the list
    Node *current = list->head;

    printf("[");
	//iterate through the list
    while (current != NULL) {
        printf("%s", current->value);
        if (current->next) {
            printf(", ");
        }
		//adjust the current nodes
        current = current->next;
    }
    printf("]");
}

void pushToFront(List *list, char *value) {
	//allocates memory to the Node and returning a pointer to that memory
    Node *new_node = malloc(sizeof(Node));
	//set the value
    strcpy(new_node->value, value);
	//adjust the nodes
    new_node->next = list->head;
    list->head = new_node;
}

void pushToEnd(List *list, char *value) {
	//set the pointer to the head of the list
    Node *current = list->head;
    
	//allocates memory to the Node and returning a pointer to that memory
    Node *node = malloc(sizeof(Node));
    strcpy(node->value, value);
    node->next = NULL;
    
	//move the current node to the end of the list
    while (current->next != NULL) {
        current = current->next;
    }

    //add on the new node
    if (current) {
        current->next = node;
    } else {
        list->head = node;
    }
}

void addElement(List *list, char *value) {
	//Add Node to front of list
	
    //set the pointer to the head node
    Node *head = list->head;
	//see if the head node is not null OR if the values match or if the value passed into the method is less than the value at the head node of the list
    if (!head || strcasecmp(value, head->value) <= 0) {
        pushToFront(list, value);
        return;
    }
	
	//adjust the pointers
    Node *current = head;
    Node *next = current->next;
	//see if the next node is null AND if the value passed into the method is greater than the value at the next node of the list
    while (next && strcasecmp(value, next->value) > 0) {
		//adjust the nodes
        current = next;
        next = next->next;
    }
    
    //Add Node to end of list
	
	//see if the next node is not null AND if the value passed into the method is greater than the value at the next node of the list
    if (!next && strcasecmp(value, current->value) > 0) {
        pushToEnd(list, value);
        return;
    }
    
    //Create and insert Node
    Node *node = malloc(sizeof(Node));
    strcpy(node->value, value);

	//adjust the nodes
    current->next = node;
    node->next = next;
}

//initializes the head of the list
List *create_list() {
	//allocates memory to the List and returning a pointer to that memory
    List *list = malloc(sizeof(List));
	//sets the head of the list to null
    list->head = NULL;
	//returns the newly created list
    return list;
}