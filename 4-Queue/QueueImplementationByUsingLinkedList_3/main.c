#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

struct patient {
	double ID;
	char name[20];
	char surname[20];
	struct patient* next;
};
typedef struct patient PATIENT;

PATIENT* front = NULL;
PATIENT* rear = NULL;

PATIENT* Create()
{
	PATIENT* newPatient = (PATIENT*)malloc(sizeof(PATIENT));
	newPatient->next = NULL;

	return newPatient;
}

void Enqueue(PATIENT* additivePatient)
{
	if (front == NULL)
	{
		front = additivePatient;
		rear = additivePatient;
	}
	else
	{
		rear->next = additivePatient;
		rear = additivePatient;
	}
}

PATIENT* Dequeue()
{
	if (front == NULL)
	{
		printf("\n Queue is empty.\a");
		return NULL;
	}
	else
	{
		PATIENT* outgoing = front;
		PATIENT* tempFront = front->next;
		free(front);
		front = tempFront;

		return outgoing;
	}
}

void PrintQueue()
{
	if (front == NULL)
	{
		printf("\n Queue is empty");
		return;
	}
	else
	{
		PATIENT* temp = front;
		int counter = 1;

		while (temp != NULL)
		{
			printf("\n *********** ROTATION NUMBER - %d ***********", counter);
			printf("\n National ID Number:\t%.0lf", temp->ID);
			printf("\n Name:\t%s", temp->name);
			printf("\n Surname:\t%s\n ", temp->surname);

			temp = temp->next;
			counter++;
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
	PATIENT* newPatient;
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
			newPatient = Create();

			printf("\n Insert national ID number: ");
			scanf("%lf", &newPatient->ID);

			printf("\n Insert name: ");
			scanf("%s", newPatient->name);

			printf("\n Insert surname: ");
			scanf("%s", newPatient->surname);

			Enqueue(newPatient);
			break;

		case 2:
			Dequeue();
			break;

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
