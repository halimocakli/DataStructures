#include <stdbool.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#define SIZE 50

char word[SIZE];
char wordStack[SIZE];

int top = -1;

bool FullControl()
{
	if (top == 49)
	{
		return true;
	}

	else
	{
		return false;
	}
}

bool EmptinessControl()
{
	if (top == -1)
	{
		return true;
	}

	else
	{
		return false;
	}
}

void Push(char letter)
{
	bool isFull = FullControl();
	if (isFull == false)
	{
		top++;
		wordStack[top] = letter;
	}

	else
	{
		printf("\n !!!Stackoverflow!!!\a\n");
		return;
	}
}

char Pop()
{
	bool isEmpty = EmptinessControl();
	if (isEmpty == true)
	{
		return 0;
	}

	else
	{
		char letter = wordStack[top];
		top--;

		return letter;
	}
}

int main()
{
	printf("\n Insert a word: ");
	scanf("%[^\n]s", word);

	for (int i = 0; i < strlen(word); i++)
	{
		Push(word[i]);
	}

	for (int i = 0; i < strlen(word); ++i)
	{
		word[i] = Pop();
	}

	printf("\n Traversed word is: %s", word);

	getch();
	return 0;
}
