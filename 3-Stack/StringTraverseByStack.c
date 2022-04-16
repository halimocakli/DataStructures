#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define BOYUT 50
#define SIZE 50

char letters[SIZE];
char letterStack[SIZE];

int top = -1;

bool IsFull()
{
	if (top == 49)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool IsEmpty()
{
	if (top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Push(char letter)
{
	bool isFull = IsFull();

	if (isFull == false)
	{
		top++;
		letterStack[top] = letter;
	}
	else
	{
		printf("\n !!!STACKOVERFLOW!!!\a\n");
		return;
	}
}

char Pop()
{
	bool isEmpty = IsEmpty();

	if (isEmpty == true)
	{
		printf("\n Stack is empty right now.\n");
		return 0;
	}
	else
	{
		char letters = letterStack[top];
		top--;

		return letters;
	}
}

int main()
{
	printf("\n Insert a string: ");
	scanf("%[^\n]s", letters);

	for (int i = 0; i < strlen(letters); i++)
	{
		Push(letters[i]);
	}

	for (int i = 0; i < strlen(letters); ++i)
	{
		letters[i] = Pop();
	}

	printf("\n Traversed string is: %s", letters);

	getch();
	return 0;
}
