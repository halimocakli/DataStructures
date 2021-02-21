#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
	char data;
	struct Node* next;
};

struct Node* top = NULL;

void Push(char x)
{
	struct Node* temp;
	temp = (struct Node*)malloc(sizeof(struct Node));

	if (temp == NULL)
	{
		printf("STACKOVERFLOW!\n");
	}

	else
	{
		temp->data = x;
		temp->next = top;
		top = temp;
	}
}

char Pop()
{
	struct Node* temp;
	char x = -1;

	if (top == NULL)
	{
		printf("Stack is empty\n");
	}

	else
	{
		temp = top;
		top = top->next;
		x = temp->data;
		free(temp);
	}

	return x;
}

void Display()
{
	struct Node* temp;
	temp = top;

	while (temp != NULL)
	{
		printf(" %c\n", temp->data);
		temp = temp->next;
	}
}

int isBalanced(const char* exp)
{
	int i;

	for (int i = 0; exp[i] != '\0'; i++)
	{
		if (exp[i] == '(')
		{
			Push(exp[i]);
		}

		else if (exp[i] == ')')
		{
			if (top == NULL)
			{
				return 0;
			}

			Pop();
		}
	}

	if (top == NULL)
	{
		return 1;
	}

	else
	{
		return 0;
	}
}

int main()
{
	const char* exp = "((a+b)*(c-d))";

	printf("%d", isBalanced(exp));
	getch();
	return 0;
}
