#include <conio.h>
#include <stdio.h>
#define SIZE 10

int queue[SIZE];
int frontIndex = -1;
int rearIndex = -1;

void Enqueue(int _data)
{
	if ((frontIndex == 0 && rearIndex == SIZE - 1) || rearIndex + 1 == frontIndex)
	{
		printf("\n Queue is full right now.\n");
		return;
	}
	else
	{
		if (frontIndex == -1 && rearIndex == -1)
		{
			frontIndex = 0;
			rearIndex = 0;
		}
		else if (rearIndex == SIZE - 1)
		{
			rearIndex = 0;
		}
		else
		{
			rearIndex = rearIndex + 1;
		}

		queue[rearIndex] = _data;
	}
}

void Dequeue()
{
	int outgoing;

	if (frontIndex == -1)
	{
		printf("\n Queue is empty.\n");
	}
	else
	{
		outgoing = queue[frontIndex];

		if (frontIndex == rearIndex)
		{
			frontIndex = -1;
			rearIndex = -1;
		}
		else if (frontIndex == SIZE - 1)
		{
			frontIndex = 0;
		}
		else
		{
			frontIndex = frontIndex + 1;
		}
		printf(" \n %d has been deleted.\n", outgoing);
	}
}

void Display()
{
	int i;
	int j;

	if (frontIndex == -1 && rearIndex == -1)
	{
		printf("\n Queue is empty.\n");
	}
	else if (frontIndex > rearIndex)
	{
		for (i = frontIndex; i < SIZE; i++)
		{
			printf("%d  ", queue[i]);
		}
		for (j = 0; j <= rearIndex; j++)
		{
			printf("%d  ", queue[j]);
		}
	}
	else
	{
		for (i = frontIndex; i <= rearIndex; i++)
		{
			printf("%d  ", queue[i]);
		}
	}
	printf("\n");
}

void Menu()
{
	printf(" \n-------------MENU-------------\n");
	printf(" 0- EXIT\n");
	printf(" 1- ENQUEUE\n");
	printf(" 2- DEQUEUE\n");
	printf(" 3- PRINT QUEUE\n");
	printf(" ------------------------------\n\n");
}

int main()
{
	int data;
	int selection;

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
			scanf("%d", &data);
			Enqueue(data);
			break;
		case 2:
			Dequeue();
			break;
		case 3:
			Display();
			break;
		default:
			printf("\n Undefined number, please insert a number that stated at the menu.");
			break;
		}
	} while (selection != 0);

	getch();
	return 0;
}
