#include <stdio.h>
#include <stdlib.h>

struct Node{
    float x;
    float y;
    struct Node *next;
} typedef Node;

Node* createNode(float xPos, float yPos){
    Node *newNode = malloc(sizeof(Node));
    newNode->x = xPos;
    newNode->y = yPos;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node *head, Node *node){
    while(head->next != NULL)
        head = head->next;

    head->next = node;
}

Node* popHead(Node *head){
    return head->next;
}

int len(Node* head){
    int i = 0;
    head = head->next;
    while(head != NULL){
        head = head->next;
        i++;
    }
    return i;
}
