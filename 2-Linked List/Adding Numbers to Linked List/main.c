#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
	int mNumber;
	struct node* nextNode;
	struct node* prevNode;
};

struct node* head = NULL;
struct node* tail = NULL;

struct node* Create(int number)
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->mNumber = number;
	newNode->nextNode = NULL;
	newNode->prevNode = NULL;

	return newNode;
}

void AddToTail(int number)
{
	struct node* addedMember = Create(number);

	if (head == NULL)
	{
		head = addedMember;
		return;
	}

	struct node* temp = head;
	while (temp->nextNode != NULL)
	{
		temp = temp->nextNode;
	}

	temp->nextNode = addedMember;
	addedMember->prevNode = temp;
}

void AddToHead(int number)
{
	struct node* addedMember = Create(number);
	if (head == NULL)
	{
		head = addedMember;
		return;
	}

	struct node* oldMember = head;
	head = addedMember;

	head->nextNode = oldMember;
	oldMember->prevNode = head;
}

void Insert(int index, int number)
{
	struct node* addedMember = Create(number);

	if (index == 0)
	{
		AddToHead(number);
		return;
	}

	if (head == NULL && index > 0)
	{
		printf("\n Bu konum uygun değil...\a");
		return;
	}

	int counter = 0;
	int flag = 0;

	struct node* temp = head;
	while (temp != NULL)
	{
		if (counter == index)
		{
			flag = 1;
			break;
		}

		temp = temp->nextNode;
		counter++;
	}

	if (flag == 0)
	{
		printf("\n Boyle bir pozisyon bulunmamaktadir...");
		return;
	}

	if (temp->nextNode == NULL)
	{
		AddToTail(number);
		return;
	}

	struct node* oldNode = temp->prevNode;
	oldNode->nextNode = addedMember;
	addedMember->prevNode = oldNode;
	addedMember->nextNode = temp;
	temp->prevNode = addedMember;
}

void DeleteFromHead()
{
	if (head == NULL)
	{
		return;
	}

	if (head->nextNode == NULL)
	{
		head = NULL;
		return;
	}

	struct node* second = head->nextNode;
	second->prevNode = NULL;
	free(head);
	head = second;
}

void DeleteFromTail()
{
	if (head == NULL)
	{
		return;
	}

	if (head->nextNode == NULL)
	{
		DeleteFromHead();
		return;
	}

	struct node* temp = head;
	while (temp->nextNode != NULL)
	{
		temp = temp->nextNode;
	}

	struct node* oldNode = temp->prevNode;
	oldNode->nextNode = NULL;
	free(temp);
}

void DeleteFromGap(int index)
{
	if (index == 0)
	{
		if (head != NULL)
		{
			DeleteFromHead();
			return;
		}
	}

	struct node* temp = head;
	int counter = 0;
	int flag = 0;

	while (temp != NULL)
	{
		if (counter == index)
		{
			flag = 1;
			break;
		}
		temp = temp->nextNode;
		counter++;
	}

	if (flag == 0)
	{
		printf("\n Boyle bir konum mevcut degil...");
		return;
	}

	if (temp->nextNode == NULL)
	{
		DeleteFromTail();
		return;
	}

	struct node* tempPrevNode = temp->prevNode;
	struct node* tempNextNode = temp->nextNode;

	tempPrevNode->nextNode = tempNextNode;
	tempNextNode->prevNode = tempPrevNode;
	free(temp);
}

void PrintList(struct node* firstNode, int direction)
{
	printf("\n");

	struct node* temp = firstNode;
	printf(" *************************************************************\n");
	while (temp != NULL)
	{
		printf(" %d =>", temp->mNumber);
		if (direction == 1)
		{
			temp = temp->nextNode;
		}

		else
		{
			temp = temp->prevNode;
		}
	}
	printf(" NULL");
	printf("\n *************************************************************");
	printf("\n");
}

int main()
{
	int secim;
	int sayi;
	int indis;

	do
	{
		printf("\n ****** Ekleme Islemleri ****** ...");
		printf("\n 1- Sona Eleman Ekle ...");
		printf("\n 2- Basa Eleman Ekle ...");
		printf("\n 3- Araya Eleman Ekle ...");
		printf("\n");
		printf("\n ****** Silme Islemleri ****** ...");
		printf("\n 4- Sondan Sil ...");
		printf("\n 5- Bastan Sil ...");
		printf("\n 6- Aradan Sil (pozisyona gore)...");
		printf("\n \n Yapmak istediginiz islemi secin ...");
		scanf("%d", &secim);

		switch (secim)
		{
		case 1:
			printf("\n Eklemek istediginiz sayiyi girin ...");
			scanf("%d", &sayi);
			AddToTail(sayi);
			PrintList(head, 1);
			break;

		case 2:
			printf("\n Eklemek istediginiz sayiyi girin ...");
			scanf("%d", &sayi);
			AddToHead(sayi);
			PrintList(head, 1);
			break;

		case 3:
			printf("\n Eklemek istediginiz sayiyi girin ...");
			scanf("%d", &sayi);
			printf("\n Hangi Konuma Ekleyeceksiniz ...");
			scanf("%d", &indis);
			Insert(indis, sayi);
			PrintList(head, 1);
			break;

		case 4:
			DeleteFromTail();
			PrintList(head, 1);
			break;

		case 5:
			DeleteFromHead();
			PrintList(head, 1);
			break;

		case 6:
			printf("\n Hangi indisteki degeri sileceksiniz");
			scanf("%d", &sayi);
			DeleteFromGap(sayi);
			PrintList(head, 1);
			break;
		}
	} while (secim != 0);

	getch();
	return 0;
}