#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct numbers {
	int number;
	struct numbers* nextNode;
};
typedef struct numbers Numbers;

Numbers* firstNode = NULL;

// Yeni dugum ureten fonksiyon
Numbers* NodeCreate(int _number)
{
	Numbers* newNode = (Numbers*)malloc(sizeof(Numbers));
	newNode->number = _number;
	newNode->nextNode = NULL;

	return newNode;
}

// Liste icerisinde dolasip son dugume ulasan fonksiyon
Numbers* ListTraverse(Numbers* _firstNode)
{
	Numbers* temp = _firstNode;
	while (temp->nextNode != NULL)
	{
		temp = temp->nextNode;
	}

	return temp;
}

// Liste basina eleman eklememizi saglayan fonksiyon
void AddToHead(int _newNumber)
{
	Numbers* addedToHead = NodeCreate(_newNumber);

	if (firstNode == NULL)
	{
		firstNode = addedToHead;
	}
	else
	{
		Numbers* prevFirstNode = firstNode;
		firstNode = addedToHead;
		firstNode->nextNode = prevFirstNode;
	}
}

// Liste sonuna eleman eklememizi saglayan fonksiyon
void AddToTail(int _newNumber)
{
	Numbers* addedToTail = NodeCreate(_newNumber);

	if (firstNode == NULL)
	{
		firstNode = addedToTail;
	}
	else
	{
		Numbers* temp = ListTraverse(firstNode);
		temp->nextNode = addedToTail;
	}
}

// Kullanici tarafindan girilen ve listeye eklenecek olan sayinin tek/cift durumunu belirleyen fonksiyon
int OddOrEven(int _number)
{
	if (_number % 2 == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

// Listeyi yazdiran fonksiyon
void PrintList()
{
	printf("\n---------------------------------------------------\n\n");

	Numbers* temp = firstNode;

	while (temp != NULL)
	{
		printf("%d -> ", temp->number);
		temp = temp->nextNode;
	}
	puts("NULL");
}

int main()
{
	int clientNumber;
	int numberTypeControl;

	do {
		printf("Insert a number that will be added to List: ");
		scanf("%d", &clientNumber);

		if (clientNumber != -1)
		{
			numberTypeControl = OddOrEven(clientNumber);

			if (numberTypeControl == 1)
			{
				AddToHead(clientNumber);
			}
			else
			{
				AddToTail(clientNumber);
			}
		}

	} while (clientNumber != -1);

	PrintList();

	getch();
	return 0;
}
