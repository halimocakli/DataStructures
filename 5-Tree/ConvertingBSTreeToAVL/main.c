#include <conio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct node* CreateNode(int);
struct node* Insert(struct node*, int);
struct node* Delete(struct node*, int);
void Preorder(struct node*);
void Inorder(struct node*);
void Postorder(struct node*);
int Size(struct node*);
int Height(struct node*);
void Mirror(struct node*);
int LeafNodeCounter(struct node*);
int FindMinNodeIterative(struct node*);
int FindMaxNodeIterative(struct node*);
struct node* FindMaxNodeRecursive(struct node*);
struct node* FindMinNodeRecursive(struct node*);
void LevelOrderTraversal(struct node* _root, int level);
struct node* ConvertToAVL(struct node*);
void CollectDataInorder(struct node*, int[], int*);

struct node {
	int data;
	struct node* leftNode;
	struct node* rightNode;
};
typedef struct node BTREE;

int main()
{
	BTREE* mainRoot = NULL;
	int data = 0;

	printf("\n If you want to and the process, just insert \"-1\".\n\n");

	do {
		printf(" Insert a number that will be added to tree: ");
		scanf("%d", &data);

		if (data != -1)
		{
			mainRoot = Insert(mainRoot, data);
		}
		else
		{
			printf("\n Process has been ended.\n\n");
		}
	} while (data != -1);

	printf(" Preorder Traversal:");
	Preorder(mainRoot);
	printf("\n");

	printf(" Inorder Traversal:");
	Inorder(mainRoot);
	printf("\n");

	printf(" Postorder Traversal:");
	Postorder(mainRoot);

	/*
	Mirror(mainRoot);

	printf(" \n Postorder Traversal:");
	Postorder(mainRoot);

	BTREE* x = FindMinNodeRecursive(mainRoot);
	printf("\n\n%d", x->data);

	BTREE* y = FindMaxNodeRecursive(mainRoot);
	printf("\n\n%d", y->data);

	printf("\n\n");

	mainRoot = Delete(mainRoot, 63);
	printf(" Preorder Traversal:");
	Preorder(mainRoot);
	printf("\n");

	mainRoot = Delete(mainRoot, 26);
	printf(" Preorder Traversal:");
	Preorder(mainRoot);
	printf("\n");

	mainRoot = Delete(mainRoot, 50);
	printf(" Preorder Traversal:");
	Preorder(mainRoot);
	printf("\n");
	*/

	int height = Height(mainRoot);

	printf("\n Height: %d", height);
	printf("\n\n");

	for (int i = 1; i <= (height + 1); i++)
	{
		LevelOrderTraversal(mainRoot, i);
	}

	printf("\n\n");

	mainRoot = ConvertToAVL(mainRoot);

	getch();
	return 0;
}

BTREE* CreateNode(int key)
{
	BTREE* newNode = (BTREE*)malloc(sizeof(BTREE));

	newNode->data = key;
	newNode->leftNode = NULL;
	newNode->rightNode = NULL;

	return newNode;
}

BTREE* Insert(BTREE* _root, int key)
{
	if (_root == NULL)
	{
		_root = CreateNode(key);
	}
	else
	{
		if (key < _root->data)
		{
			_root->leftNode = Insert(_root->leftNode, key);
		}
		else
		{
			_root->rightNode = Insert(_root->rightNode, key);
		}
	}
	return _root;
}

BTREE* Delete(BTREE* _root, int key)
{
	if (_root == NULL)
	{
		return NULL;
	}
	else
	{
		if (key > _root->data)
		{
			_root->rightNode = Delete(_root->rightNode, key);
		}
		else if (key < _root->data)
		{
			_root->leftNode = Delete(_root->leftNode, key);
		}
		else
		{
			if ((_root->leftNode == NULL) && (_root->rightNode == NULL))
			{
				free(_root);
				return NULL;
			}
			else if (_root->leftNode == NULL)
			{
				BTREE* tempNode = _root;
				_root = _root->rightNode;

				free(tempNode);
				return _root;
			}
			else if (_root->rightNode == NULL)
			{
				BTREE* tempNode = _root;
				_root = _root->leftNode;

				free(tempNode);
				return _root;
			}
			else
			{
				BTREE* tempNode = FindMinNodeRecursive(_root->rightNode);
				_root->data = tempNode->data;
				_root->rightNode = Delete(_root->rightNode, tempNode->data);
			}
		}
	}
	return _root;
}

void Preorder(BTREE* _root) /* ROOT -> LEFT -> RIGHT */
{
	if (_root == NULL)
		return;

	printf("\t%d", _root->data);
	Preorder(_root->leftNode);
	Preorder(_root->rightNode);
}

void Inorder(BTREE* _root) /* LEFT -> ROOT -> RIGHT */
{
	if (_root == NULL)
		return;

	Inorder(_root->leftNode);
	printf("\t%d ", _root->data);
	Inorder(_root->rightNode);
}

void Postorder(BTREE* _root) /* LEFT -> RIGHT -> ROOT */
{
	if (_root == NULL)
		return;

	Postorder(_root->leftNode);
	Postorder(_root->rightNode);
	printf("\t%d", _root->data);
}

void LevelOrderTraversal(BTREE* _root, int level)
{
	if (_root != NULL)
	{
		if (level == 1)
		{
			printf("%4d", _root->data);
		}
		else
		{
			LevelOrderTraversal(_root->leftNode, level - 1);
			LevelOrderTraversal(_root->rightNode, level - 1);
		}
	}
}

int Size(BTREE* _root)
{
	if (_root == NULL)
		return 0;
	else
		return 1 + Size(_root->leftNode) + Size(_root->rightNode);
}

int Height(BTREE* _root)
{
	if (_root == NULL)
		return -1;
	else
	{
		int leftHeight;
		int rightHeight;

		leftHeight = Height(_root->leftNode);
		rightHeight = Height(_root->rightNode);

		if (rightHeight > leftHeight)
			return rightHeight + 1;
		else
			return leftHeight + 1;
	}
}

void Mirror(BTREE* _root)
{
	if (_root == NULL)
		return;
	else
	{
		BTREE* temp;

		Mirror(_root->leftNode);
		Mirror(_root->rightNode);
		temp = _root->leftNode;
		_root->leftNode = _root->rightNode;
		_root->rightNode = temp;
	}
}

int LeafNodeCounter(BTREE* _root)
{
	if (_root == NULL)
		return 0;
	if (_root->leftNode == NULL && _root->rightNode == NULL)
		return 1;
	else
		return LeafNodeCounter(_root->leftNode) + LeafNodeCounter(_root->rightNode);
}

int FindMinNodeIterative(BTREE* _root)
{
	if (_root == NULL)
		return INT_MAX;

	while (_root->leftNode != NULL)
	{
		_root = _root->leftNode;
	}
	return _root->data;
}

int FindMaxNodeIterative(BTREE* _root)
{
	if (_root == NULL)
		return INT_MIN;

	while (_root->rightNode != NULL)
	{
		_root = _root->rightNode;
	}
	return _root->data;
}

BTREE* FindMaxNodeRecursive(BTREE* _root)
{
	if (_root->rightNode != NULL)
	{
		return FindMaxNodeRecursive(_root->rightNode);
	}
	return _root;
}

BTREE* FindMinNodeRecursive(BTREE* _root)
{
	if (_root->leftNode != NULL)
	{
		return FindMinNodeRecursive(_root->leftNode);
	}
	return _root;
}

BTREE* ConvertToAVL(BTREE* _root)
{
	int size = Size(_root);

	int arrInorder[size];
	int index = 0;

	CollectDataInorder(_root, arrInorder, &index);

	for (int i = 0; i < size ; ++i)
	{
		printf("%4d", arrInorder[i]);
	}

	return _root;
}

void CollectDataInorder(struct node* _root, int arrInorder[], int* ptrIndex)
{
	if (_root == NULL)
		return;

	CollectDataInorder(_root->leftNode, arrInorder, ptrIndex);

	arrInorder[*ptrIndex] = _root->data;
	*(ptrIndex)++;

	CollectDataInorder(_root->rightNode, arrInorder, ptrIndex);
}
