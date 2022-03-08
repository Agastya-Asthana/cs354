//
// Created by Agastya Asthana on 3/3/22.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
    int data;
    struct NODE *next;
} NODE;

void Print_List(NODE *head){
    NODE *current  = head;
    while (current != NULL){
        printf("%d\t", current->data);
        current = current->next;
    }
    printf("\n");
}

void Push_Front(NODE **head, int data){
    NODE *newNode = malloc(sizeof(NODE));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void Push_Back(NODE **head, int data) {
    // Beginning of the last
    NODE *current = *head;
    // Iterating to the end of the list
    while (current->next != NULL) current = current->next;
    // Creating the node ot be inserted
    NODE *newNode = malloc(sizeof(NODE));
    newNode->data = data;
    newNode->next = NULL;
    // Inserting new node into the linked list
    current->next = newNode;
    return;
}

int main(){
    NODE *head = NULL;
    NODE *first = malloc(sizeof(NODE));
    first->data = 10;
    first->next = NULL;
    head = first;

    NODE *second = malloc(sizeof(NODE));
    second->data = 20;
    second->next = NULL;
    first->next = second;

    Push_Front(&head, 30);
    Push_Front(&head, 40);
    Push_Back(&head, 69);

    Print_List(head);
}

