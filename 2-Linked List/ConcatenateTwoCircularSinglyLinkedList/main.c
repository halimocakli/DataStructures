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
	Node* ptrCList;

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
		ptrCList = firstList;
		while (ptrCList->next != firstList)
		{
			ptrCList = ptrCList->next;
		}
		ptrCList->next = secondList;

		ptrCList = secondList;
		while (ptrCList->next != secondList)
		{
			ptrCList = ptrCList->next;
		}
		ptrCList->next = firstList;

		return firstList;
	}
}

Node* AddHead(Node* head, int key)
{
	if (head == NULL)
	{
		head = (Node*)malloc(sizeof(Node));
		head->data = key;
		head->next = head;
	}

	else
	{
		Node* newHeadNode = (Node*)malloc(sizeof(Node));
		Node* tail = head;

		newHeadNode->data = key;

		while (tail->next != head)
		{
			tail = tail->next;
		}

		newHeadNode->next = head;
		tail->next = newHeadNode;
		head = newHeadNode;
	}

	return head;
}

void PrintList(Node* head)
{
	if (head == NULL)
	{
		printf("List is empty");
	}
	else
	{
		Node* tempHead = head;

		do {
			printf("%d ", tempHead->data);
			tempHead = tempHead->next;
		} while (tempHead->next != head->next);
	}
}

int main()
{
	Node* firstList = NULL;
	Node* secondList = NULL;
	Node* concatenatedList = NULL;

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

	concatenatedList = Concatenate(firstList, secondList);

	printf("Concatenated list: ");
	PrintList(concatenatedList);

	getch();
	return 0;
}