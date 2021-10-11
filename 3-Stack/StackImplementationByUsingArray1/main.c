#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#define STACK_SIZE 4

struct node {
	int data[STACK_SIZE];
	int top;
};
typedef struct node STACK;

bool IsFull(STACK* _stack)
{
	if (_stack->top == STACK_SIZE - 1)
		return true;
	else
		return false;
}

bool IsEmpty(STACK* _stack)
{
	if (_stack->top == -1)
		return true;
	else
		return false;
}

void Push(STACK* _stack, int _data)
{
	if (IsFull(_stack) == true)
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
	if (IsEmpty(_stack) == true)
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

void Reset(STACK* _stack)
{
	_stack->top = -1;
}

int main()
{
	STACK stack;
	int x;

	Reset(&stack);

	Push(&stack, 4);
	Push(&stack, 2);
	Push(&stack, 5);
	Push(&stack, 7);
	Push(&stack, 11);
	Push(&stack, 12);

	printf("\n");

	x = Pop(&stack);
	printf(" %d\n", x);

	x = Pop(&stack);
	printf(" %d\n", x);

	x = Pop(&stack);
	printf(" %d\n", x);

	x = Pop(&stack);
	printf(" %d\n", x);

	x = Pop(&stack);
	printf(" %d\n", x);

	x = Pop(&stack);
	printf(" %d\n", x);

	getch();
	return 0;
}
