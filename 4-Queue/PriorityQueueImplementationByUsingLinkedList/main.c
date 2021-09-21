// Decreased priority queue
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

struct patient {
	double id;
	char name[20];
	char surname[20];
	int priority;
	struct patient* next;
};
typedef struct patient Patient;

Patient* front = NULL;
Patient* rear = NULL;

Patient* Create()
{
	Patient* newPatient = (Patient*)malloc(sizeof(Patient));

	if (newPatient == NULL)
	{
		printf("\n ERROR: STACKOVERFLOW!!!\n");
		return NULL;
	}

	newPatient->next = NULL;
	return newPatient;
}

Patient* PatientInfo()
{
	Patient* patient = Create();

	printf("\n Insert patient's national ID number: ");
	scanf("%lf", &patient->id);

	printf("\n Insert patient's name: ");
	scanf("%s", patient->name);

	printf("\n Insert patient's surname: ");
	scanf("%s", patient->surname);

	printf("\n Insert priority degree: ");
	scanf("%d", &patient->priority);

	return patient;
}

void Enqueue(Patient* addedPatient)
{
	if (front == NULL)
	{
		front = addedPatient;
		rear = addedPatient;
	}
	else
	{
		if (addedPatient->priority > front->priority)
		{
			Patient* secondPatient = front;
			front = addedPatient;
			front->next = secondPatient;
		}
		else
		{
			Patient* temp = front;

			while (temp->next != NULL && addedPatient->priority < temp->next->priority)
			{
				temp = temp->next;
			}

			if (temp->next == NULL)
			{
				rear->next = addedPatient;
				rear = addedPatient;
			}
			else
			{
				Patient* tempNext = temp->next;
				temp->next = addedPatient;
				addedPatient->next = tempNext;
			}
		}
	}
}

Patient* Dequeue()
{
	if (front == NULL)
	{
		printf("\n Kuyruk bos...\a");
		return NULL;
	}

	Patient* exitedPatient = front;
	Patient* newFront = front->next;
	free(front);
	front = newFront;

	return exitedPatient;
}

void Print()
{
	if (front == NULL)
	{
		printf("\n Queue is empty.\a\n");
		return;
	}

	Patient* temp = front;
	int counter = 1;

	while (temp != NULL)
	{
		printf("\n ******** Sira Numarasi : %d", counter);
		printf("\n National ID Number     : %lf", temp->id);
		printf("\n Name                   : %s", temp->name);
		printf("\n Surname                : %s", temp->surname);
		printf("\n Priority Degree        : %d", temp->priority);

		temp = temp->next;
		counter++;
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
	int selection;
	Patient* newMainPatient;

	do {
		printf(" Insert the function number that you want to execute: ");
		scanf("%d", &selection);

		switch (selection)
		{
		case 0:
			printf("\n Process has been ended.\n");
			break;

		case 1:
			newMainPatient = PatientInfo();
			Enqueue(newMainPatient);
			break;

		case 2:
			Dequeue();
			break;

		case 3:
			Print();
			break;

		default:
			printf("\n Undefined number, please insert a number that stated at the menu.");
			break;
		}
	} while (selection != 0);

	getch();
	return 0;
}