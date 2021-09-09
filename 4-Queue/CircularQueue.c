#include <conio.h>
#include <stdio.h>
#define SIZE 10

int queue[SIZE];
int front = -1;
int rear = -1;

void Enqueue(int number)
{
	if ((front == 0 && rear == SIZE - 1) || rear + 1 == front)
	{
		printf("\n Kuyruk dolu...\a");
		return;
	}

	if (front == -1)
	{
		front = 0;
	}

	rear = (rear + 1) % 5;
	queue[rear] = number;
}

int Dequeue()
{
	if (front == -1)
	{
		printf("\n Kuyruk Bos...\a");
		return -1;
	}

	int leaver = queue[front];

	if (front == rear)
	{
		front = -1;
		rear = -1;
		return leaver;
	}

	front = (front + 1) % SIZE;
	return leaver;
}

void Print()
{
	if (front == -1)
	{
		printf("\n Kuyruk Bos...\a");
		return;
	}

	// Bu kısmı düzenle
	for (int i = front; i != rear; i = (i + 1) % SIZE)
	{
		if (i == front && i == rear)
		{
			printf("\n %d --> REAR <=> FRONT", queue[i]);
		}

		else if (i == front)
		{
			printf("\n %d --> FRONT", queue[i]);
		}

		else
		{
			printf("\n %d", queue[i]);
		}
	}
	printf("\n %d --> REAR", queue[rear]);
}
int main()
{
	int number;
	int choice;

	do
	{
		printf("\n\n ******MENU******");
		printf("\n 0-) Sonlandir");
		printf("\n 1-) Ekle");
		printf("\n 2-) Cikar  ");
		printf("\n ****************");
		printf("\n Islem numaranizi giriniz: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 0:
			printf("\n Program Basariyla Sonlandirildi...\a");
			break;
		case 1:
			printf("\n Sayi girin: ");
			scanf("%d", &number);
			Enqueue(number);
			Print();
			break;
		case 2:
			number = Dequeue();
			printf("\n Cikarilan eleman = %d \n", number);
			Print();
			break;
		default:
			printf("\n Yanlis tercih yaptiniz");
			break;
		}
	} while (choice != 0);

	getch();
	return 0;
}
