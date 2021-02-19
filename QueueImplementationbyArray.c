#include <stdio.h>
#define SIZE 10

int queue[SIZE];// Kuyruk dizimizi deklare ettik
int front = -1; // Dizinin ilk indisi
int rear = -1;  // Dizinin son indisi

void Enqueue(int number)
{
	if (rear == SIZE - 1)
	{
		printf("\n Kuyruk Dolu \n");
		return;
	}

	if (front == -1)
	{
		front = 0;
	}

	rear++;
	queue[rear] = number;
}

int Dequeue()
{
	if (front == -1 || front > rear)
	{
		printf("\n Kuyruk Bos \n");
		return 0;
	}

	int leaver = queue[front];

	if (front == rear)
	{
		front = -1;
		rear = -1;
		return leaver;
	}

	front++;
	return leaver;
}

void Print()
{
	for (int i = front; i <= rear; i++)
	{
		if (i == front && i == rear)
		{
			printf("\n %d-) %d (FRONT) <=> (REAR)", i, queue[i]);
		}

		else if (front == i)
		{
			printf("\n %d-) %d (FRONT)", i, queue[i]);
		}

		else if (rear == i)
		{
			printf("\n %d-) %d (REAR)", i, queue[i]);
		}

		else
		{
			printf("\n %d-) %d", i, queue[i]);
		}
	}
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
		printf("\n Islem numaranizi giriniz: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("\n Sayi girin: ");
			scanf("%d", &number);
			Enqueue(number);
			Print();
			break;
		case 2:
			number = Dequeue();
			printf("\n **** Cikarilan eleman %d ****\n", number);
			Print();
			break;
		default:
			printf("\n Yanlis tercih yaptiniz");
			break;
		}
	}while (choice != 0);
}
