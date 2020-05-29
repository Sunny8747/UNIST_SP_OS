#include <stdio.h>
#include "LRU.h"

//This function makes new node contatining item_.
//It will return the new node.
Node* newNode(int item_) {
	Node* node;
	node = (Node*)malloc(sizeof(item_));
	node->item = item_;
	node->next = NULL;// 0-> NULL
	node->prev = NULL;
	return node;
	//TODO
}

//This function makes new empty queue with size.
//It will return empty queue which can contain items up to size.
Queue* createQueue(int size) {
	Queue* queue = (Queue*)malloc(sizeof(size));//delete //asdf
	queue->queue_size = size;
	queue->count_ = 0;
	queue->head = NULL;
	queue->tail = NULL;
	return queue;
	//TODO
}

//This function will check whether queue is empty or not.
int isQueueEmpty(Queue* queue_) {
	if (queue_->count_ == 0) {
		return 0;
	}
	else {
		return 1;
	}
    //TODO
}

//This function will remove last element(tail) in queue_.
void DeQueue(Queue* queue_) {
	queue_->count_ = queue_->count_ - 1;
	Node* it;
	it = queue_->tail;
	queue_->tail = queue_->tail->prev;
	queue_->tail->next = NULL;
	free(it);
	return;
    //TODO
}

//This function roles add the node containing item_ in queue_ at head.
void EnQueue(Queue* queue_, int item_) {

	if(queue_->count_ == 0) {
		
		Node* NNode;

		NNode = newNode(item_);
		queue_->head = NNode;
		queue_->tail = NNode;
		queue_->count_ = queue_->count_ +1;

		return;
	}
	else {
		if (queue_->queue_size == queue_->count_) {
			DeQueue(queue_);
		}
		queue_->count_ = queue_->count_ +1;
		Node* NNode;
		NNode = newNode(item_);
		Node* tempNode;
		tempNode = queue_->head;
		queue_->head->prev = NNode;
		queue_->head = NNode;
		NNode->next = tempNode;
		return;
	}
    //TODO
}

//This function mention item_ in queue. So the queue should be modified along LRU.
//If item_ is not in queue, it should be added,
//If item_ is in queue_, it should be placed in front of queue_.
void Reference(Queue* queue_, int item_) {
	int temp = 0;
	Node* it = queue_->head;
	if(queue_->count_ == 0){
		EnQueue(queue_, item_);
		return;
	}
	while (temp != queue_->count_) {
		temp++;
		if ((temp == 1) && (it->item == item_)) {
			return;
		}
		else if(temp == queue_->queue_size){
			EnQueue(queue_, item_);
			return;
		}
		else{
			if(it->item == item_){
				if(temp == queue_->count_){
					DeQueue(queue_);
					EnQueue(queue_, item_);
					return;
				}
				it->prev->next = it->next;
				it->next->prev = it->prev;
				it->next = queue_->head;
				it->prev = NULL;
				queue_->head->prev = it;
				queue_->head = it;
				return; 
			}
			else if(temp == queue_->count_){
				EnQueue(queue_, item_);
				return;
			}
		}
		it = it->next;
	}

	return;
    //TODO
}

//This function clear the queue_.
void ClearQueue(Queue* queue_) {
	queue_->count_ = 0;//0->NULL
	queue_->head = NULL;
	queue_->tail = NULL;
	queue_->queue_size = 0;
	return;
	//TODO
}

void PrintQueue(Queue* queue_) {//space bar -> tab
	Node* it = queue_->head;
	int index = 0;
	printf("------------------------\n");
	printf("Queue size : %d\n", queue_->count_);
	printf("Queue capacity : %d\n", queue_->queue_size);
	while (it != NULL) {
		printf("Queue %d Element : %d\n", index, it->item);
		index++;
		it = it->next;
	}
	printf("------------------------\n");
	return;
}
