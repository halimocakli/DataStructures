#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#define SIZE 10

int queue[SIZE];
int frontIndex = -1;
int rearIndex = -1;

bool IsFull()
{
	if (rearIndex == SIZE - 1)
		return true;
	else
		return false;
}

bool IsEmpty()
{
	if (frontIndex == -1 || frontIndex > rearIndex)
		return true;

	else
		return false;
}

void Enqueue(int _data)
{
	if (IsFull() == true)
	{
		printf("\n STACKOVERFLOW\a\n");
	}
	else if (IsEmpty() == true)
	{
		frontIndex = 0;
		rearIndex = 0;
		queue[rearIndex] = _data;
	}
	else
	{
		rearIndex = rearIndex + 1;
		queue[rearIndex] = _data;
	}
}

int Dequeue()
{
	if (IsEmpty() == true)
	{
		printf("\n Queue is empty right now.\n");
		return 0;
	}
	else
	{
		int outgoing = queue[frontIndex];

		if (frontIndex == rearIndex)
		{
			frontIndex = -1;
			rearIndex = -1;

			return outgoing;
		}

		frontIndex = frontIndex + 1;
		return outgoing;
	}
}

void PrintQueue()
{
	int i = 1;

	if (IsEmpty() == true)
	{
		printf("\n Queue is empty right now.\n");
		return;
	}

	for (i = frontIndex; i <= rearIndex; i++)
	{
		if (i == frontIndex && i == rearIndex)
		{
			printf("\n %d.INDEX-> %d (Both front and rear)\n", i, queue[i]);
		}
		else if (i == frontIndex)
		{
			printf("\n %d.INDEX-> %d (Front)\n", i, queue[i]);
		}
		else if (i == rearIndex)
		{
			printf("\n %d.INDEX-> %d (Rear)\n", i, queue[i]);
		}
		else
		{
			printf("\n %d.INDEX-> %d\n", i, queue[i]);
		}
	}
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
			if (IsEmpty() == true)
			{
				printf("\n There is no data in Queue to delete.\n");
				break;
			}
			else
			{
				printf(" \n %d has been deleted.\n", Dequeue());
				break;
			}
		case 3:
			PrintQueue();
			break;
		default:
			printf("\n Undefined number, please insert a number that stated at the menu.");
			break;
		}
	} while (selection != 0);

	getch();
	return 0;
}
