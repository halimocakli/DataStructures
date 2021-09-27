#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

struct QNode {
	int data;
	struct QNode* next;
};
typedef struct QNode QNode;

struct Queue {
	QNode* front;
	QNode* rear;
};
typedef struct Queue Queue;

QNode* NewNode(int _data)
{
	QNode* tempNode = (QNode*)malloc(sizeof(QNode));
	tempNode->data = _data;
	tempNode->next = NULL;

	return tempNode;
}

Queue* CreateQueue()
{
	Queue* tempQueue = (Queue*)malloc(sizeof(Queue));
	tempQueue->front = tempQueue->rear = NULL;

	return tempQueue;
}

void Enqueue(Queue* _queue, int _data)
{
	QNode* temp = NewNode(_data);

	if (_queue->rear == NULL)
	{
		_queue->front = _queue->rear = temp;
		return;
	}

	_queue->rear->next = temp;
	_queue->rear = temp;
}

QNode* Dequeue(Queue* _queue)
{
	if (_queue->front == NULL)
		return NULL;

	QNode* temp = _queue->front;
	_queue->front = _queue->front->next;

	if (_queue->front == NULL)
		_queue->rear = NULL;

	return temp;
}

int main()
{
	Queue* queue = CreateQueue();

	Enqueue(queue, 1);
	Enqueue(queue, 2);

	Dequeue(queue);
	Dequeue(queue);

	Enqueue(queue, 3);
	Enqueue(queue, 4);
	Enqueue(queue, 5);

	QNode* var = Dequeue(queue);

	if(var != NULL)
	{
		printf("Dequeued item is %d", var->data);
	}

	getch();
	return 0;
}
