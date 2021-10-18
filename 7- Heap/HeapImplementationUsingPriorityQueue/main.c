#include <conio.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 30
#define PARENT(x) x / 2
#define L_CHILD(x) 2 * x
#define R_CHILD(x) (2 * x) + 1

struct node {
	int arr[QUEUE_SIZE];
	int rear;
};
typedef struct node PriorityQueue;

void Initialization(PriorityQueue* pQueue)
{
	pQueue->rear = 0;
}

void Insert(PriorityQueue* pQueue, int key)
{
	pQueue->rear = pQueue->rear + 1;
	pQueue->arr[pQueue->rear] = key;

	int rearIndex = pQueue->rear;
	while (rearIndex != 1 && pQueue->arr[rearIndex] < pQueue->arr[PARENT(rearIndex)])
	{
		int temp = pQueue->arr[rearIndex];

		pQueue->arr[rearIndex] = pQueue->arr[PARENT(rearIndex)];
		pQueue->arr[PARENT(rearIndex)] = temp;
		rearIndex = PARENT(rearIndex);
	}
}

int Delete(PriorityQueue* pQueue)
{
	if (pQueue->rear == 0)
	{
		printf("\n Heap is empty.\n");
		return INT_MIN;
	}
	else
	{
		int i = 1;
		int temp;
		int key = pQueue->arr[1];

		pQueue->arr[1] = pQueue->arr[pQueue->rear];
		pQueue->arr[pQueue->rear] = INT_MAX;
		pQueue->rear = pQueue->rear - 1;

		while (i < PARENT(pQueue->rear) && pQueue->arr[i] > pQueue->arr[L_CHILD(i)] || pQueue->arr[i] > pQueue->arr[R_CHILD(i)])
		{
			if (pQueue->arr[L_CHILD(i)] < pQueue->arr[R_CHILD(i)])
			{
				temp = pQueue->arr[i];
				pQueue->arr[i] = pQueue->arr[L_CHILD(i)];
				pQueue->arr[L_CHILD(i)] = temp;
				i = L_CHILD(i);
			}
			else
			{
				temp = pQueue->arr[i];
				pQueue->arr[i] = pQueue->arr[R_CHILD(i)];
				pQueue->arr[R_CHILD(i)] = temp;
				i = R_CHILD(i);
			}
		}
		return key;
	}
}

void Menu()
{
	printf("\n\n 0-End process");
	printf("\n 1-Insert");
	printf("\n 2-Delete");
	printf("\n 3-Print Heap");
}

int main()
{
	PriorityQueue pQueue;
	Initialization(&pQueue);

	int selection;
	int key;
	/*
	do {
		Menu();
		printf("\n Insert function number: ");
		scanf("%d", &selection);

		if (selection != 0)
		{
			switch (selection)
			{
			case 1:
				printf("\n Please enter a data: ");
				scanf("%d", &key);

				Insert(&pQueue, key);
				break;

			case 2:
				printf("\n %d has been deleted", Delete(&pQueue));
				break;
			case 3:
				for (int i = 1; i <= pQueue.rear; i++)
				{
					printf("%d\t", pQueue.arr[i]);
				}
				break;
			default:
				printf("\n Undefined number inserted.");
				break;
			}
		}

	} while (selection != 0);
	*/

	Insert(&pQueue, 10);
	Insert(&pQueue, 20);
	Insert(&pQueue, 5);
	Insert(&pQueue, 8);
	Insert(&pQueue, 40);
	Insert(&pQueue, 18);
	Insert(&pQueue, 9);

	for (int i = 1; i <= pQueue.rear; i++)
	{
		printf("%d\t", pQueue.arr[i]);
	}

	printf("\n %d has been deleted\n", Delete(&pQueue));

	for (int i = 1; i <= pQueue.rear; i++)
	{
		printf("%d\t", pQueue.arr[i]);
	}

	printf("\n %d has been deleted\n", Delete(&pQueue));

	for (int i = 1; i <= pQueue.rear; i++)
	{
		printf("%d\t", pQueue.arr[i]);
	}

	printf("\n %d has been deleted\n", Delete(&pQueue));

	for (int i = 1; i <= pQueue.rear; i++)
	{
		printf("%d\t", pQueue.arr[i]);
	}

	printf("\n %d has been deleted\n", Delete(&pQueue));

	for (int i = 1; i <= pQueue.rear; i++)
	{
		printf("%d\t", pQueue.arr[i]);
	}

	printf("\n %d has been deleted\n", Delete(&pQueue));

	for (int i = 1; i <= pQueue.rear; i++)
	{
		printf("%d\t", pQueue.arr[i]);
	}

	printf("\n %d has been deleted\n", Delete(&pQueue));

	for (int i = 1; i <= pQueue.rear; i++)
	{
		printf("%d\t", pQueue.arr[i]);
	}

	printf("\n %d has been deleted\n", Delete(&pQueue));

	for (int i = 1; i <= pQueue.rear; i++)
	{
		printf("%d\t", pQueue.arr[i]);
	}

	printf("\n %d has been deleted\n", Delete(&pQueue));

	printf("\n %d has been deleted\n", Delete(&pQueue));

	printf("\n %d has been deleted\n", Delete(&pQueue));

	printf("\n %d has been deleted\n", Delete(&pQueue));

	printf("\n %d has been deleted\n", Delete(&pQueue));

	printf("\n %d has been deleted\n", Delete(&pQueue));

	Insert(&pQueue, 10);
	Insert(&pQueue, 20);
	Insert(&pQueue, 5);
	Insert(&pQueue, 8);
	Insert(&pQueue, 40);
	Insert(&pQueue, 18);
	Insert(&pQueue, 9);

	printf("\n");

	for (int i = 1; i <= pQueue.rear; i++)
	{
		printf("%d\t", pQueue.arr[i]);
	}

	getch();
	return 0;
}
