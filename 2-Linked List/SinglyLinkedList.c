#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};
typedef struct node Node;

Node* AddHead(Node* head, int key)
{
	Node* temp;
	temp = (Node*)malloc(sizeof(Node));

	temp->data = key;
	temp->next = head;
	head = temp;

	return head;
}

Node* AddTail(Node* head, int key)
{
	Node* temp;
	temp = (Node*)malloc(sizeof(Node));

	temp->data = key;
	temp->next = NULL;

	if (head == NULL)
	{
		head = temp;
	}

	else
	{
		Node* tempTail = head;
		while (tempTail->next != NULL)
		{
			tempTail = tempTail->next;
		}
		tempTail->next = temp;
	}

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

void PrintListRecursively(Node* head)
{
	if (head == NULL)
		return;

	printf("%d ", head->data);
	PrintListRecursively(head->next);
}

void PrintReverseRecursively(Node* head)
{
	if (head == NULL)
		return;

	PrintReverseRecursively(head->next);
	printf("%d ", head->data);
}

int Count(Node* head)
{
	int counter = 0;
	while (head != NULL)
	{
		counter++;
		head = head->next;
	}
	return counter;
}

int CountRecursively(Node* head)
{
	if (head == NULL)
		return 0;

	return 1 + CountRecursively(head->next);
}

void ListInfo(Node* head)
{
	int counter = 1;

	while (head != NULL)
	{
		printf("%d. Dugumun adresi: %p\n", counter, head);
		printf("%d. Dugumun verisi: %d\n", counter, head->data);
		printf("%d. Dugumun baglandigi dugumun adresi: %p\n\n", counter, head->next);

		head = head->next;
		counter++;
	}
}

Node* Locate(Node* head, int key)
{
	Node* locate = NULL;

	while (head != NULL)
	{
		if (head->data != key)
		{
			head = head->next;
		}

		else
		{
			locate = head;
			break;
		}
	}
	return locate;
}

Node* RemoveByDataValue(Node* head, int key)
{
	Node* temp = head;

	if (head == NULL)
	{
		printf("List is empty\n");
		return NULL;
	}

	else if (head->data == key)
	{
		head = head->next;
		free(temp);
	}

	else if (temp->next == NULL)
	{
		printf("There is no list member that you want to remove.\n\n");
		return head;
	}

	else
	{
		while (temp->next->data != key)
		{
			if (temp->next->next == NULL)
			{
				printf("There is no list member that you want to remove.\n\n");
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

void PrintReversedList(Node* head)
{
	Node* tempHead = NULL;
	Node* temp = head;

	while (temp != NULL)
	{
		tempHead = AddHead(tempHead, temp->data);
		temp = temp->next;
	}
	PrintList(tempHead);
}

Node* DestroyList(Node* head)
{
	if (head == NULL)
	{
		printf("List is empty\n");
		return NULL;
	}

	Node* temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
	return head;
}

int main()
{
	Node* head = NULL;

	PrintList(head);
	printf("\n\n");

	head = AddHead(head, 10);
	head = AddHead(head, 9);
	head = AddHead(head, 8);
	head = AddHead(head, 7);
	head = AddHead(head, 6);
	head = AddHead(head, 5);
	head = AddHead(head, 4);

	head = AddTail(head, 14);
	head = AddTail(head, 15);
	head = AddTail(head, 16);
	head = AddTail(head, 17);
	head = AddTail(head, 18);
	head = AddTail(head, 19);
	head = AddTail(head, 20);

	printf("The list: ");
	PrintList(head);
	printf("\n\n");

	printf("Recursively printed list: ");
	PrintListRecursively(head);
	printf("\n\n");

	printf("Recursively reversed list: ");
	PrintReverseRecursively(head);
	printf("\n\n");

	printf("Number of nodes in the list is: %d -- Iterative", Count(head));
	printf("\n\n");

	printf("Number of nodes in the list is: %d -- Recursive", CountRecursively(head));
	printf("\n\n");

	ListInfo(head);

	printf("Address of Key-%d is: %p", 14, Locate(head, 14));
	printf("\n");

	printf("Address of Key-%d is: %p", 20, Locate(head, 20));
	printf("\n");

	printf("Address of Key-%d is: %p", 7, Locate(head, 7));
	printf("\n\n");

	printf("The list before value-16 has removed: ");
	PrintList(head);
	printf("\n\n");

	RemoveByDataValue(head, 16);

	printf("The list after value-16 has removed: ");
	PrintList(head);
	printf("\n\n");

	printf("Reversed list that created by using new list method: ");
	PrintReversedList(head);
	printf("\n\n");

	head = DestroyList(head);

	PrintList(head);

	getch();
	return 0;
}
