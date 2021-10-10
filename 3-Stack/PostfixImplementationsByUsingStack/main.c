#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 5

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
	char key;

	Reset(&stack);

	FILE* fPtr;

	if ((fPtr = fopen("C:\\Users\\halim\\OneDrive\\Desktop\\DataStructures\\Kitap\\PostfixImplementationsByUsingStack\\code.txt", "r")) == NULL)
	{
		printf("\n File could not been opened.\n");
		exit(1);
	}
	else
	{
		while (!feof(fPtr))
		{
			key = (char)getc(fPtr);

			switch (key)
			{
			case '(':
				Push(&stack, key);
				break;
			case '{':
				Push(&stack, key);
				break;
			case '[':
				Push(&stack, key);
				break;
			case ')':
				if (Pop(&stack) == '(')
					continue;
				else
				{
					printf("\n Error for ()");
					exit(1);
				}
				break;
			case '}':
				if (Pop(&stack) == '{')
					continue;
				else
				{
					printf("\n Error for {}");
					exit(1);
				}
				break;
			case ']':
				if (Pop(&stack) == '[')
					continue;
				else
				{
					printf("\n Error for []");
					exit(1);
				}
				break;
			}
		}
		if (stack.top == -1)
		{
			printf(" There is no parentheses error in the code\n");
		}
		else
		{
			printf("\n There is at least one parentheses which is has not been closed.");
		}
		fclose(fPtr);
	}

	getch();
	return 0;
}
