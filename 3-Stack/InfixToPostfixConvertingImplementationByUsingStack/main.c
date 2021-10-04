#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	char data;
	struct node* next;
};
typedef struct node NODE;

NODE* top = NULL;

void Push(char x)
{
	NODE* newNode = (NODE*)malloc(sizeof(NODE));

	if (newNode == NULL)
		printf("stack is full\n");
	else
	{
		newNode->data = x;
		newNode->next = top;
		top = newNode;
	}
}

char Pop()
{
	NODE* outgoingNode;
	char x = -1;

	if (top == NULL)
		printf("Stack is Empty\n");
	else
	{
		outgoingNode = top;
		top = top->next;
		x = outgoingNode->data;
		free(outgoingNode);
	}
	return x;
}

void Display()
{
	NODE* print = top;
	while (print != NULL)
	{
		printf("%d ", print->data);
		print = print->next;
	}
	printf("\n");
}

int IsBalanced(char* exp)
{
	int i;

	for (i = 0; exp[i] != '\0'; i++)
	{
		if (exp[i] == '(')
			Push(exp[i]);
		else if (exp[i] == ')')
		{
			if (top == NULL)
				return 0;
			Pop();
		}
	}
	if (top == NULL)
		return 1;
	else
		return 0;
}
int pre(char x)
{
	if (x == '+' || x == '-')
		return 1;
	else if (x == '*' || x == '/')
		return 2;
	return 0;
}

int isOperand(char x)
{
	if (x == '+' || x == '-' || x == '*' || x == '/')
		return 0;
	else
		return 1;
}

char* InToPost(const char* infix)
{
	int i = 0, j = 0;
	char* postfix;
	size_t len = strlen(infix);
	postfix = (char*)malloc((len + 2) * sizeof(char));

	while (infix[i] != '\0')
	{
		if (isOperand(infix[i]))
			postfix[j++] = infix[i++];
		else
		{
			if (pre(infix[i]) > pre(top->data))
				Push(infix[i++]);
			else
			{
				postfix[j++] = Pop();
			}
		}
	}
	while (top != NULL)
		postfix[j++] = Pop();
	postfix[j] = '\0';
	return postfix;
}

int main()
{
	char* infix = "a+b*c-d/e";
	Push('#');

	char* postfix = InToPost(infix);

	printf("%s ", postfix);

	return 0;
}