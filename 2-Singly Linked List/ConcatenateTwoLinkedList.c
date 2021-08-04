#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};
typedef struct node Node;

Node* Concatenate(Node* firstList, Node* secondList)
{
	Node* ptrList;

	if (firstList == NULL)
	{
		firstList = secondList;
		return firstList;
	}

	else if (secondList == NULL)
	{
		return firstList;
	}

	else
	{
		ptrList = firstList;

		while (ptrList->next != NULL)
		{
			ptrList = ptrList->next;
		}
		ptrList->next = secondList;

		return firstList;
	}
}

Node* AddHead(Node* head, int key)
{
	Node* temp;
	temp = (Node*)malloc(sizeof(Node));

	temp->data = key;
	temp->next = head;
	head = temp;

	return head;
}

void PrintList(Node* head)
{
	if (head == NULL)
	{
		printf("List is empty");
		return;
	}

	else
	{
		while (head != NULL)
		{
			printf("%d ", head->data);
			head = head->next;
		}
	}
}

int main()
{
	Node* firstList = NULL;
	Node* secondList = NULL;

	firstList = AddHead(firstList, 10);
	firstList = AddHead(firstList, 9);
	firstList = AddHead(firstList, 8);
	firstList = AddHead(firstList, 7);
	firstList = AddHead(firstList, 6);
	firstList = AddHead(firstList, 5);
	firstList = AddHead(firstList, 4);
	firstList = AddHead(firstList, 3);
	firstList = AddHead(firstList, 2);
	firstList = AddHead(firstList, 1);
	firstList = AddHead(firstList, 0);

	secondList = AddHead(secondList, 20);
	secondList = AddHead(secondList, 19);
	secondList = AddHead(secondList, 18);
	secondList = AddHead(secondList, 17);
	secondList = AddHead(secondList, 16);
	secondList = AddHead(secondList, 15);
	secondList = AddHead(secondList, 14);
	secondList = AddHead(secondList, 13);
	secondList = AddHead(secondList, 12);
	secondList = AddHead(secondList, 11);

	printf("First list: ");
	PrintList(firstList);
	printf("\n\n");

	printf("Second list: ");
	PrintList(secondList);
	printf("\n\n");

	Concatenate(firstList, secondList);

	printf("Concatenated list: ");
	PrintList(firstList);

	getch();
	return 0;
}