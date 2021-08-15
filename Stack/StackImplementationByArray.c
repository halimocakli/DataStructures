#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#define SIZE 10

int stackArray[SIZE];
int top = -1;

bool IsFull()
{
	if (top == SIZE - 1)
		return true;
	else
		return false;
}

bool IsEmpty()
{
	if (top == -1)
		return true;
	else
		return false;
}

void Push(int data)
{
	bool isFull = IsFull();

	if (isFull == true)
	{
		printf("\n STACKOVERFLOW\a\n");
		return;
	}

	top = top + 1;
	stackArray[top] = data;
}

int Pop()
{
	bool isEmpty = IsEmpty();

	if (isEmpty == true)
	{
		printf("\n Stack is empty right now.\n");
		return 0;
	}

	int prevTop = stackArray[top];
	top = top - 1;

	return prevTop;
}

int Peek()
{
	return stackArray[top];
}

void PrintStack()
{
	printf("\n\n----------------");

	int i;
	for (i = top; i >= 0; i--)
	{
		printf("\n %d", stackArray[i]);
	}

	printf("\n----------------\n\n");
}

void Menu()
{

	printf(" \n-------------MENU-------------\n");
	printf(" 0- EXIT\n");
	printf(" 1- PUSH\n");
	printf(" 2- POP\n");
	printf(" 3- PEEK\n");
	printf(" 4- PRINT STACK\n");
	printf(" ------------------------------\n\n");
}

int main()
{
	int selection;
	int number;

	do {
		Menu();

		printf(" Insert the function number that you want to execute: ");
		scanf("%d", &selection);

		switch (selection)
		{
		case 0:
			printf("\n Process has been ended.\n");
			break;
		case 1:
			printf("\n Enter a number: ");
			scanf("%d", &number);
			Push(number);
			break;
		case 2:
			Pop();
			break;
		case 3:
			printf("\n Top data of the stack is: %d", Peek());
			break;
		case 4:
			PrintStack();
			break;
		default:
			printf("\n Undefined number, please insert a number that stated at the menu.");
			break;
		}
	} while (selection != 0);

	getch();
	return 0;
}
