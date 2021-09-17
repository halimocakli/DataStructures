#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

void InsertAtFront(int);
void InsertAtLast(int);
void InsertAtLastAlternative(int);
void PrintList();
struct node* Locate(int);
struct node* DeleteNode(int);

struct node {
	int data;
	struct node* next;
};
typedef struct node Node;

Node* head = NULL;

int main()
{
	InsertAtFront(5);
	InsertAtFront(4);
	InsertAtFront(3);
	InsertAtFront(2);
	InsertAtFront(1);

	InsertAtLast(7);
	InsertAtLast(8);
	InsertAtLast(9);

	head = DeleteNode(8);
	head = DeleteNode(1);

	PrintList();

	Node* find = Locate(9);
	printf("\nSearched data-%d has been located: %p", find->data, find);

	getch();
	return 0;
}

void InsertAtFront(int number)
{
	if (head == NULL)
	{
		head = (Node*)malloc(sizeof(Node));
		head->data = number;
		head->next = head;
	}
	else
	{
		Node* newHeadNode = (Node*)malloc(sizeof(Node));
		Node* tail = head;

		newHeadNode->data = number;

		while (tail->next != head)
		{
			tail = tail->next;
		}

		newHeadNode->next = head;
		tail->next = newHeadNode;
		head = newHeadNode;
	}
}

void InsertAtLast(int number)
{
	if (head == NULL)
	{
		head = (Node*)malloc(sizeof(Node));
		head->data = number;
		head->next = head;
	}
	else
	{
		Node* newLastNode = (Node*)malloc(sizeof(Node));
		Node* last = head;

		newLastNode->data = number;

		while (last->next != head)
		{
			last = last->next;
		}

		newLastNode->next = head;
		last->next = newLastNode;
	}
}

void InsertAtLastAlternative(int number)
{
	if (head == NULL)
	{
		head = (Node*)malloc(sizeof(Node));
		head->data = number;
		head->next = head;
	}
	else
	{
		Node* last = head;

		while (last->next != head)
		{
			last = last->next;
		}
		last->next = (Node*)malloc(sizeof(Node));
		last->next->data = number;
		last->next->next = head;
	}
}

Node* Locate(int searchedData)
{
	Node* locate = NULL;
	Node* tempHead = head;

	do {
		if (tempHead->data != searchedData)
		{
			tempHead = tempHead->next;
		}

		else
		{
			locate = tempHead;
			break;
		}
	} while (tempHead != head);

	return locate;
}

Node* DeleteNode(int key)
{
	if (head == NULL)
	{
		printf("There is no node in list\n");
		return NULL;
	}

	Node* temp = head;

	if (head->data == key)
	{
		Node* last = head;
		while (last->next != head)
		{
			last = last->next;
		}

		head = head->next;
		last->next = head;

		temp->next = NULL;
		free(temp);
	}

	else if (temp->next == NULL)
	{
		printf("There is no such list member that you want to delete.\n\n");
	}

	else
	{
		while (temp->next->data != key)
		{
			if (temp->next->next == NULL)
			{
				printf("There is no such list member that you want to delete.\n\n");
				return head;
			}
			temp = temp->next;
		}
		Node* secondTemp = temp->next;
		temp->next = temp->next->next;
		free(secondTemp);
	}
	return head;
}

void PrintList()
{
	Node* tempHead = head;

	do {
		printf("%d - %p\n", tempHead->data, tempHead);
		tempHead = tempHead->next;
	} while (tempHead->next != head->next);
}
