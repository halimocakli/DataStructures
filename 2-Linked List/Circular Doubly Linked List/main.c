#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

struct node* Create(int);
void AddNode();
void InsertToHead();
void InsertToTail();
void InsertToPosition();
void DeleteFromHead();
void DeleteFromTail();
void DeleteFromPosition();
void SortList();
void Update();
void Search();
void PrintHeadToTail();
void PrintFromTailToHead();
void Menu();

struct node {
	int data;
	struct node* next;
	struct node* prev;
};
typedef struct node Node;

Node* head = NULL;
Node* tail = NULL;

Node* newNode;
Node* tempHeadPtr;
Node* tempTailPtr;
Node* prevNode;

int counter = 0;

int main()
{

	getch();
	return 0;
}

Node* Create(int _data)
{
	counter = counter + 1;
	newNode = (Node*)malloc(sizeof(Node));

	newNode->data = _data;
	newNode->next = NULL;
	newNode->prev = NULL;

	return newNode;
}

void AddNode()
{
	int _data;

	printf("\n Enter the data value that you would like to add: ");
	scanf("%d", &_data);

	newNode = Create(_data);

	if (head == tail && head == NULL)
	{
		head = tail = newNode;
		head->next = tail->next = NULL;
		head->prev = tail->prev = NULL;
	}
	else
	{
		tail->next = newNode;
		newNode->prev = tail;

		tail = newNode;

		tail->next = head;
		head->prev = tail;
	}
}

void InsertToHead()
{
	int _data;

	printf("Insert the data that will be added to beginning of the list: ");
	scanf("%d", &_data);

	newNode = Create(_data);

	if (head == tail && head == NULL)
	{
		printf("\n Initial state of the list is empty so, the node has been added to list as both first and last node.");

		head = tail = newNode;
		head->next = tail->next = NULL;
		head->prev = tail->prev = NULL;
	}
	else
	{
		newNode->next = head;
		head->prev = newNode;

		head = newNode;

		head->prev = tail;
		tail->next = head;

		printf("\n The data value has inserted at beginning of the list.");
	}
}

void InsertToTail()
{
	int _data;

	printf("Insert the data that will be added to end of the list[as a tail]: ");
	scanf("%d", &_data);

	newNode = Create(_data);

	if (head == tail && head == NULL)
	{
		printf("\n Initial state of the list is empty so the node has been added to list as  both first and last node.");

		head = tail = newNode;
		head->next = tail->next = NULL;
		head->prev = tail->prev = NULL;
	}
	else
	{
		tail->next = newNode;
		newNode->prev = tail;

		tail = newNode;

		head->prev = tail;
		tail->next = head;
	}
}

void InsertToPosition()
{
	int _data;
	int position;
	int i;

	printf("\n Enter the data value that you would like to add: ");
	scanf("%d", &_data);

	printf("\n Enter the list position where the new node will be added ");
	scanf("%d", &position);

	newNode = Create(_data);

	if (head == tail && head == NULL)
	{
		if (position == 1)
		{
			head = tail = newNode;
			head->next = tail->next = NULL;
			head->prev = tail->prev = NULL;
		}
		else
		{
			printf("\n List is empty right now so, you can not add a new node to empty list which has no position.");
			return;
		}
	}
	else
	{
		if (counter < position)
		{
			printf("\n The position you have entered is not exist because the list doesn't has enough nodes to reach the position you have chose. ");
			return;
		}
		else
		{
			tempHeadPtr = head;
			for (i = 1; i <= counter; i++)
			{
				prevNode = tempHeadPtr;
				tempHeadPtr = tempHeadPtr->next;

				if (i == position - 1)
				{
					prevNode->next = newNode;
					newNode->prev = prevNode;
					newNode->next = tempHeadPtr;
					tempHeadPtr->prev = newNode;

					printf("\n Data->[%d] has inserted to the position->[%d] successfully", _data, position);
					break;
				}
			}
		}
	}
}

void DeleteFromHead()
{
	if (head == tail && head == NULL)
	{
		printf("\n List is empty right now so, you can not delete a node from an empty list which has no position.");
		return;
	}
	else
	{
		tempHeadPtr = head;
		tail->next = tempHeadPtr->next;
		tempHeadPtr->next->prev = tail;
		head = head->next;

		printf("\n %d is deleted.", tempHeadPtr->data);
		free(tempHeadPtr);
	}
}

void DeleteFromTail()
{
	if (head == tail && head == NULL)
	{
		printf("\n List is empty right now so, you can not delete a node from an empty list which has no position.");
		return;
	}
	else
	{
		tempTailPtr = tail;
		head->prev = tempTailPtr->prev;
		tempTailPtr->prev->next = head;
		tail = tail->prev;

		printf("\n %d is deleted.", tempTailPtr->data);
		free(tempTailPtr);
	}
}

void DeleteFromPosition()
{
	int position;
	int i;

	printf("\n Enter the list position where the node will be deleted: ");
	scanf("%d", &position);

	if (head == tail && head == NULL)
	{
		printf("\n List is empty right now so, you can not delete a node from an empty list which has no position.");
		return;
	}
	else
	{
		if (counter < position)
		{
			printf("\n The position you have entered is not exist because the list doesn't has enough nodes to reach the position you have chose. ");
			return;
		}
		else
		{
			tempHeadPtr = head;
			for (i = 1; i <= counter; i++)
			{
				prevNode = tempHeadPtr;
				tempHeadPtr = tempHeadPtr->next;

				if (position == 1)
				{
					counter = counter - 1;
					tail->next = prevNode->next;
					tempHeadPtr->prev = prevNode->prev;
					head = tempHeadPtr;

					printf("\n %d has been deleted.", prevNode->data);

					free(prevNode);
					break;
				}
				else if (i == position - 1)
				{
					counter = counter - 1;
					prevNode->next = tempHeadPtr->next;
					tempHeadPtr->next->prev = prevNode;

					printf("\n %d is deleted.", tempHeadPtr->data);
					free(tempHeadPtr);
					break;
				}
			}
		}
	}
}

void SortList()
{
	Node* tempNode;
	int tempData;
	int i;
	int j;

	if (head == tail)
	{
		printf("\n Initial state of the list is empty so, there is no node to sort.");
		return;
	}
	else
	{
		tempHeadPtr = head;
		for (i = 0; i < counter; i++)
		{
			for (tempNode = tempHeadPtr->next, j = i; j < counter; j++)
			{
				if (tempHeadPtr->data > tempNode->data)
				{
					tempData = tempHeadPtr->data;
					tempHeadPtr->data = tempNode->data;
					tempNode->data = tempData;
				}
			}
			tempHeadPtr = tempHeadPtr->next;
		}
		printf("\n\nSorted List: ");
		for (tempHeadPtr = head, i = 0; i < counter; i++)
		{
			printf("%d ", tempHeadPtr->data);
		}
	}
}

void Update()
{
	int oldData;
	int newData;
	int flag;
	int i;

	printf("\n Insert the integer data as old data that will be updated: ");
	scanf("%d", &oldData);

	printf("Insert the integer data that will be added as new data: ");
	scanf("%d", &newData);

	if (head == tail && head == NULL)
	{
		printf("\n List is empty right now so you can not update any node data.");
		return;
	}
	else
	{
		tempHeadPtr = head;
		for (i = 0; i < counter; i++)
		{
			if (tempHeadPtr->data == oldData)
			{
				tempHeadPtr->data = newData;
				printf("\n%d data has been updated to %d", oldData, tempHeadPtr->data);

				flag = 1;
			}
			tempHeadPtr = tempHeadPtr->next;
		}
		if (flag == 0)
		{
			printf("\n There is no such an integer data that you have inserted as old data in the list to be updated.");
		}
	}
}

void Search()
{
	int key;
	int flag = 0;
	int searchCounter = 0;
	int i;

	printf("\n Insert the integer data that will be searched: ");
	scanf("%d", &key);

	if (head == tail && head == NULL)
	{
		printf("\n List is empty right now so you can not search any node data.");
		return;
	}
	else
	{
		tempHeadPtr = head;
		for (i = 0; i < counter; i++)
		{
			searchCounter = searchCounter + 1;
			if (tempHeadPtr->data == key)
			{
				printf("\n The integer data has been found at %d position.", searchCounter);
				flag = 1;
			}
			tempHeadPtr = tempHeadPtr->next;
		}
		if (flag == 0)
		{
			printf("\n There is no such an integer data that you have inserted to be searched.");
		}
	}
}

void PrintHeadToTail()
{
	int i;
	if (head == tail && head == NULL)
	{
		printf("\n List is empty right now so you can not display any node data.");
		return;
	}
	else
	{
		printf("\nThere are %d node in the circular doubly linked list\n", counter);
		printf("----------------------------------------------------\n");

		tempHeadPtr = head;

		for (i = 0; i < counter; i++)
		{
			printf("%3d", tempHeadPtr->data);
			tempHeadPtr = tempHeadPtr->next;
		}
	}
}

void PrintFromTailToHead()
{
	int i;
	if (head == tail && head == NULL)
	{
		printf("\n List is empty right now so you can not display any node data.");
		return;
	}
	else
	{
		printf("\nThere are %d node in the circular doubly linked list\n", counter);
		printf("----------------------------------------------------\n");

		tempHeadPtr = tail;

		for (i = 0; i < counter; i++)
		{
			printf("%3d", tempHeadPtr->data);
			tempHeadPtr = tempHeadPtr->prev;
		}
	}
}

void Menu()
{

}
