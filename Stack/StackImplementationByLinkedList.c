#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};
typedef struct node Stack;

Stack* top = NULL;

Stack* Create(int _data)
{
	Stack* newNode = (Stack*)malloc(sizeof(Stack));

	if (newNode == NULL)
	{
		printf("\n STACKOVERFLOW!\a\n");
		return NULL;
	}
	else
	{
		newNode->data = _data;
		newNode->next = NULL;

		return newNode;
	}
}

void Push(int _data)
{
	Stack* addedNode = Create(_data);

	addedNode->next = top;
	top = addedNode;
}

void Pop()
{
	if (top == NULL)
	{
		printf("\n Stack is empty right now.\n");
		return;
	}
	else
	{
		Stack* tempTop = top;
		top = top->next;

		free(tempTop);
	}
}

int Peek()
{
	return top->data;
}

void PrintStack()
{
	Stack* temp = top;

	printf("\n\n------------------------\n");

	if (top == NULL)
	{
		printf("NULL");
	}
	else
	{
		while (temp != NULL)
		{
			printf(" %d ", temp->data);
			temp = temp->next;
		}
	}

	printf("\n------------------------\n");
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