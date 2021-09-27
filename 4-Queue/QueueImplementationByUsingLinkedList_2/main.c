#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 4

struct node {
	int data;
	struct node* next;
};
typedef struct node NODE;

struct queue {
	struct node* front;
	struct node* rear;
	int counter;
};
typedef struct queue QUEUE;

void Initialize(QUEUE* q)
{
	q->counter = 0;
	q->front = q->rear = NULL;
}

bool IsFull(QUEUE* q)
{
	if (q->counter == QUEUE_SIZE)
		return 1;
	else
		return 0;
}

bool IsEmpty(QUEUE* q)
{
	if (q->counter == 0)
		return 1;
	else
		return 0;
}

void Enqueue(QUEUE* q, int _data)
{
	if (IsFull(q) == 1)
	{
		printf("\n Queue is full.");
		return;
	}
	else
	{
		NODE* temp = (NODE*)malloc(sizeof(NODE));
		temp->data = _data;
		temp->next = NULL;

		if (IsEmpty(q) == 1)
		{
			q->rear = q->front = temp;
		}
		else
		{
			q->rear->next = temp;
			q->rear = temp;
		}
		q->counter = q->counter + 1;
	}
}

int Dequeue(QUEUE* q)
{
	if (IsEmpty(q) == 1)
	{
		printf("\n Queue is empty.");
		return -100;
	}
	else
	{
		int _data = q->front->data;
		NODE* temp = q->front;
		q->front = temp->next;
		q->counter = q->counter - 1;

		if (IsEmpty(q) == 1)
		{
			q->rear = q->front = NULL;
		}
		free(temp);

		return _data;
	}
}

int main()
{
	QUEUE q;

	Initialize(&q);

	Enqueue(&q, 10);
	Enqueue(&q, 5);
	Enqueue(&q, 6);
	Enqueue(&q, 8);
	Enqueue(&q, 1);

	printf("\n %d", Dequeue(&q));
	printf("\n %d", Dequeue(&q));
	printf("\n %d", Dequeue(&q));
	printf("\n %d", Dequeue(&q));
	printf("\n %d", Dequeue(&q));

	getch();
	return 0;
}
