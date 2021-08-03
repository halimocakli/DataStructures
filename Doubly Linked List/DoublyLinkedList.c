#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

struct node* Create(int);
void InsertToHead(int);
void InsertToTail(int);
void InsertToPosition(int, int);
void DeleteFromHead();
void DeleteFromTail();
void DeleteByPosition(int);
void Locate(int searchedData);
void PrintList();

struct node {
	int data;
	struct node* next;
	struct node* prev;
};
typedef struct node Node;

Node* head = NULL;

int main()
{
	int selection;
	int number;
	int position;

	do
	{
		printf("\n *********** MENU ***********");
		printf("\n 0- End execution");
		printf("\n 1- Add node to head");
		printf("\n 2- Add node to tail");
		printf("\n 3- Add node to list by using position info");
		printf("\n 4- Delete from head");
		printf("\n 5- Delete from tail");
		printf("\n 6- Delete node from list by using position info");
		printf("\n 7- Locate a node in the list");
		printf("\n 8- Display the list");
		printf("\n\n Select a function: ");
		scanf("%d", &selection);

		switch (selection)
		{
		case 0:
			printf("\n Execution has been ended.\n");
			break;
		case 1:
			printf("\n Insert a data number of node: ");
			scanf("%d", &number);
			InsertToHead(number);
			break;
		case 2:
			printf("\n Insert a data number of node: ");
			scanf("%d", &number);
			InsertToTail(number);
			break;
		case 3:
			printf("\n Insert a data number of node: ");
			scanf("%d", &number);
			printf("\n Insert position that you will add the node: ");
			scanf("%d", &position);
			InsertToPosition(position, number);
			break;

		case 4:
			DeleteFromHead();
			break;
		case 5:
			DeleteFromTail();
			break;
		case 6:
			printf("\n Insert the node position that you want to delete: ");
			scanf("%d", &number);
			DeleteByPosition(number);
			break;
		case 7:
			printf("\n Insert the node data number that you want to locate: ");
			scanf("%d", &number);
			Locate(number);
			break;
		case 8:
			PrintList();
			break;
		default:
			printf("\n Wrong choice.\n");
			break;
		}
	} while (selection != 0);

	getch();
	return 0;
}

Node* Create(int number)
{
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = number;
	newNode->next = NULL;
	newNode->prev = NULL;

	return newNode;
}

void InsertToHead(int number)
{
	Node* addedNode = Create(number);

	if (head == NULL)
	{
		head = addedNode;
		return;
	}
	else
	{
		Node* tempHead = head;
		head = addedNode;

		head->next = tempHead;
		tempHead->prev = head;
	}
}

void InsertToTail(int number)
{
	Node* addedNode = Create(number);

	if (head == NULL)
	{
		head = addedNode;
		return;
	}
	else
	{
		Node* tempTail = head;

		while (tempTail->next != NULL)
		{
			tempTail = tempTail->next;
		}

		tempTail->next = addedNode;
		addedNode->prev = tempTail;
	}
}

void InsertToPosition(int position, int number)// Son konumdan bir önceki konuma ekleme yaparken sıkıntı çıkıyor
{
	Node* addedNode = Create(number);

	if (position == 1)
	{
		InsertToHead(number);
		return;
	}
	else if (head == NULL && position > 0)
	{
		printf(" There is no Node in the list so that is impossible to determine any position of the list.\n\n");
		return;
	}
	else
	{
		int counter = 1;
		int flag = 0;

		Node* tempHead = head;

		while (tempHead != NULL)
		{
			if (counter == position)
			{
				flag = 1;
				break;
			}
			tempHead = tempHead->next;
			counter = counter + 1;
		}

		if (flag == 0)
		{
			printf(" There is no such a position in the list that you indicated\n\n");
			return;
		}
		else
		{
			Node* backNode = tempHead->prev;
			backNode->next = addedNode;
			addedNode->prev = backNode;
			addedNode->next = tempHead;
			tempHead->prev = addedNode;
		}
	}
}

void DeleteFromHead()
{
	if (head == NULL)
	{
		printf(" List is empty right now.\n");
		return;
	}
	else if (head->next == NULL)
	{
		head = NULL;
	}
	else
	{
		Node* tempNext = head->next;
		tempNext->prev = NULL;
		free(head);
		head = tempNext;
	}
}

void DeleteFromTail()
{
	if (head == NULL)
	{
		printf(" List is empty right now.\n");
		return;
	}
	else if (head->next == NULL)
	{
		DeleteFromHead();
		return;
	}
	else
	{
		Node* tempHead = head;

		while (tempHead->next != NULL)
		{
			tempHead = tempHead->next;
		}

		Node* backNode = tempHead->prev;
		backNode->next = NULL;
		free(tempHead);
	}
}

void DeleteByPosition(int position)
{
	if (position == 1)
	{
		if (head != NULL)
		{
			DeleteFromHead();
			return;
		}
	}

	Node* tempHead = head;

	int counter = 1;
	int flag = 0;

	while (tempHead != NULL)
	{
		if (counter == position)
		{
			flag = 1;
			break;
		}
		tempHead = tempHead->next;
		counter = counter + 1;
	}

	if (flag == 0)
	{
		printf(" There is no such a position in the list that you indicated\n\n");
		return;
	}
	else if (tempHead->next == NULL)
	{
		DeleteFromTail();
		return;
	}
	else
	{
		Node* tempPrevNode = tempHead->prev;
		Node* tempNextNode = tempHead->next;

		tempPrevNode->next = tempNextNode;
		tempNextNode->prev = tempPrevNode;

		free(tempHead);
	}
}

void Locate(int searchedData)
{
	int flag = 0;
	int counter = 1;

	if (head == NULL)
	{
		printf(" List is empty right now.\n");
		return;
	}
	else if (head->data == searchedData)
	{
		printf("\n Searched data[%d] has been found at %dst node\n", head->data, counter);
		return;
	}
	else
	{
		Node* tempHead = head;

		while (tempHead != NULL)
		{
			if (tempHead->data == searchedData)
			{
				flag = 1;
				printf("\n Searched data[%d] has been found at %dst node\n", tempHead->data, counter);

				break;
			}
			tempHead = tempHead->next;
			counter = counter + 1;
		}

		if (flag == 0)
		{
			printf(" Searching process has been completed and the data that you are searching could not found.\n");
			return;
		}
	}
}

void PrintList()
{
	printf("\n *************************************************************\n");

	Node* tempHead = head;

	while (tempHead != NULL)
	{
		printf(" %d -> ", tempHead->data);
		tempHead = tempHead->next;
	}
	printf(" NULL");
	printf("\n *************************************************************\n");
}
