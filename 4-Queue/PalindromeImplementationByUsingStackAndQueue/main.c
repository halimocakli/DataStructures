#include <conio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_SIZE 100
#define QUEUE_SIZE 100

struct stack {
	int data[STACK_SIZE];
	int top;
};
typedef struct stack STACK;

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

void Reset(STACK*);
void Initialize(QUEUE*);
void Push(STACK*, int);
int Pop(STACK*);
void Enqueue(QUEUE*, int);
int Dequeue(QUEUE*);
bool IsFullStack(STACK*);
bool IsEmptyStack(STACK*);
bool IsFullQueue(QUEUE*);
bool IsEmptyQueue(QUEUE*);

int main()
{
	STACK stack;
	QUEUE queue;

	Initialize(&queue);
	Reset(&stack);

	char str[QUEUE_SIZE];
	int i = 0;

	printf("\n Insert a sentence: ");
	gets(str);

	while (i < strlen(str))
	{
		if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z' || str[i] >= '0' && str[i] <= '9')
		{
			Push(&stack, tolower(str[i]));
			Enqueue(&queue, tolower(str[i]));
		}
		i = i + 1;
	}
	while (IsEmptyQueue(&queue) != true)
	{
		if (Pop(&stack) != Dequeue(&queue))
		{
			printf("\n Sentence that you have inserted is not palindrome.");
			exit(1);
		}
	}
	printf("\n Sentence that you have inserted is palindrome.");

	getch();
	return 0;
}

void Reset(STACK* _stack)
{
	_stack->top = -1;
}

void Initialize(QUEUE* q)
{
	q->counter = 0;
	q->front = q->rear = NULL;
}
void Push(STACK* _stack, int _data)
{
	if (IsFullStack(_stack) == true)
	{
		printf("\n Stack is full\n");
	}
	else
	{
		_stack->top += 1;
		_stack->data[_stack->top] = _data;
	}
}

int Pop(STACK* _stack)
{
	if (IsEmptyStack(_stack) == true)
	{
		printf("\n Stack is empty, ERROR CODE:");
		return -2147483648;
	}
	else
	{
		int x = _stack->data[_stack->top];
		_stack->top -= 1;

		return x;
	}
}

void Enqueue(QUEUE* q, int _data)
{
	if (IsFullQueue(q) == 1)
	{
		printf("\n Queue is full.");
		return;
	}
	else
	{
		NODE* temp = (NODE*)malloc(sizeof(NODE));
		temp->data = _data;
		temp->next = NULL;

		if (IsEmptyQueue(q) == 1)
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
	if (IsEmptyQueue(q) == 1)
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

		if (IsEmptyQueue(q) == 1)
		{
			q->rear = q->front = NULL;
		}
		free(temp);

		return _data;
	}
}

bool IsFullStack(STACK* _stack)
{
	if (_stack->top == STACK_SIZE - 1)
		return true;
	else
		return false;
}

bool IsEmptyStack(STACK* _stack)
{
	if (_stack->top == -1)
		return true;
	else
		return false;
}

bool IsFullQueue(QUEUE* q)
{
	if (q->counter == QUEUE_SIZE)
		return 1;
	else
		return 0;
}

bool IsEmptyQueue(QUEUE* q)
{
	if (q->counter == 0)
		return 1;
	else
		return 0;
}