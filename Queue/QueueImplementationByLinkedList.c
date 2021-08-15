#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct patient {
	double id;
	char name[20];
	char surname[20];
	int priority;
	struct patient* next;
};

struct patient* front = NULL;
struct patient* rear = NULL;

struct patient* Create()
{
	struct patient* newPatient = (struct patient*)malloc(sizeof(struct patient));
	if (newPatient == NULL)
	{
		printf("\n ERROR: STACKOVERFLOW!!!\a");
		return NULL;
	}

	newPatient->next = NULL;
	return newPatient;
}

void Enqueue(struct patient* addedPatient)
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
			struct patient* secondPatient = front;
			front = addedPatient;
			front->next = secondPatient;

			return;
		}

		else
		{
			struct patient* temp = front;
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
				struct patient* tempNext = temp->next;
				temp->next = addedPatient;
				addedPatient->next = tempNext;
			}
		}
	}
}

struct patient* Dequeue()
{
	if (front == NULL)
	{
		printf("\n Kuyruk bos...\a");
		return NULL;
	}

	struct patient* exitedPatient = front;
	struct patient* newFront = front->next;
	free(front);
	front = newFront;

	return exitedPatient;
}

void Print()
{
	if (front == NULL)
	{
		printf("\n Kuyruk Bos...\a");
		return;
	}

	struct patient* temp = front;
	int counter = 1;
	while (temp != NULL)
	{
		printf("\n ******** Sira Numarasi : %d", counter);
		printf("\n TC Kimlik No      : %lf", temp->id);
		printf("\n Isim              : %s", temp->name);
		printf("\n Soyisim           : %s", temp->surname);
		printf("\n Oncelik Derecesi  : %d", temp->priority);
		temp = temp->next;
		counter++;
	}
}

int main()
{
	int choice;
	struct patient* newMainPatient;

	do {
		printf("\n\n ******MENU******");
		printf("\n 0- Sonlandir");
		printf("\n 1- Ekle");
		printf("\n 2- Cikar");
		printf("\n 3- Yazdir");
		printf("\n ****************");
		printf("\n Islem secimini yapin: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 0:
			printf("\n Program Basariyla Sonlandirildi...\a");
			break;
		case 1:
			newMainPatient = Create();

			printf("\n TC Kimlik No Giriniz: ");
			scanf("%lf", &newMainPatient->id);

			printf("\n Isim Giriniz: ");
			scanf("%s", newMainPatient->name);

			printf("\n Soyisim Giriniz: ");
			scanf("%s", newMainPatient->surname);

			printf("\n Oncelik Derecesi Girin: ");
			scanf("%d", &newMainPatient->priority);

			Enqueue(newMainPatient);

			break;
		case 2:
			Dequeue();
			break;
		case 3:
			Print();
			break;
		default:
			printf("\n Gecersiz tuslama yaptiniz...\a");
			break;
		}
	}while (choice != 0);

	getch();
	return 0;
}
