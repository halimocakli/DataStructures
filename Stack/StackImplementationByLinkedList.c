#include <stdio.h>
#include <stdlib.h>

struct node {
	int mNumber;
	struct node* nextNode;
};
typedef struct node Stack;

Stack* top = NULL;

void Push(int number)
{
	Stack* addedMember = (Stack*)malloc(sizeof(Stack));
	if (addedMember == NULL)
	{
		printf("\n !!!Stackoverflow!!!\a\n");
	}
	addedMember->mNumber = number;

	addedMember->nextNode = top;
	top = addedMember;
}

void Pop()
{
	if(top == NULL)
	{
		printf("\n There is no stack element already...\a\n");
		return;
	}

	Stack* removedMember = top;
	top = removedMember->nextNode;
	free(removedMember);
}

int Peek()
{
	return top->mNumber;
}

void Print()
{
	printf("\n");

	Stack* temp = top;
	while (temp != NULL)
	{
		printf("\n %d", temp->mNumber);
		temp = temp->nextNode;
	}

	printf("\n");
}

int main()
{
	int selection;
	int number;
	int removed;
	int topElement;

	do {
		printf("\n 0- End Programme");
		printf("\n 1- Push");
		printf("\n 2- Pop");
		printf("\n 3- Peek");
		printf("\n 4- Print");
		printf("\n Make a selection: ");
		scanf("%d", &selection);

		switch (selection)
		{
		case 0:
			printf("\n Programme ended successfully!\a");
			break;
		case 1:
			printf("\n Insert a number that you wanna add: ");
			scanf("%d", &number);
			Push(number);
			break;
		case 2:
			Pop();
			break;
		case 3:
			topElement = Peek();
			printf("\n Top element of array is: %d\n", topElement);
			break;
		case 4:
			Print();
			break;
		}
	} while (selection != 0);

	return 0;
}
