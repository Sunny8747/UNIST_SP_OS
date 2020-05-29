#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int item;
    struct _Node* next;
    struct _Node* prev;
} Node;

typedef struct _Queue {
    int queue_size; // Capacity of Queue
    int count_;     // Count the number of elements in Queue
    Node *head, *tail;
} Queue;

Node* newNode(int item_);
Queue* createQueue(int size);
int isQueueEmpty(Queue* queue_);
void EnQueue(Queue* queue_, int item_);    //EnQueue item at head
void DeQueue(Queue* queue_);    
void ClearQueue(Queue* queue_);

void Reference(Queue* queue_, int item_);

void PrintQueue(Queue* queue_);
