#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

struct node* Insert(struct node*, int);
struct node* RightRotation(struct node*);
struct node* LeftRotation(struct node*);
struct node* Delete(struct node*, int);
int Height(struct node*);
int MaxValue(int, int);
struct node* MinValueNode(struct node*);
int BalanceCalc(struct node*, int, int);
void Preorder(struct node*);

struct node {
	int data;
	int height;
	struct node* leftChild;
	struct node* rightChild;
};
typedef struct node AVL_TREE;

int main()
{
	AVL_TREE* mainRoot = NULL;

	mainRoot = Insert(mainRoot, 20);
	mainRoot = Insert(mainRoot, 30);
	mainRoot = Insert(mainRoot, 40);
	mainRoot = Insert(mainRoot, 50);
	mainRoot = Insert(mainRoot, 10);
	mainRoot = Insert(mainRoot, 15);

	printf("Preorder Traversal of AVL Tree\n");
	printf("------------------------------\n");
	Preorder(mainRoot);

	mainRoot = Delete(mainRoot, 50);
	mainRoot = Delete(mainRoot, 15);
	mainRoot = Delete(mainRoot, 10);

	printf("\n\n");

	printf("Preorder Traversal of AVL Tree\n");
	printf("------------------------------\n");
	Preorder(mainRoot);

	getch();
	return 0;
}

AVL_TREE* CreateNode(int key)
{
	AVL_TREE* newNode = (AVL_TREE*)malloc(sizeof(AVL_TREE));

	newNode->data = key;
	newNode->height = 0;
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;

	return newNode;
}

AVL_TREE* Insert(AVL_TREE* _root, int key)
{
	if (_root == NULL)
	{
		_root = CreateNode(key);
		return _root;
	}
	else
	{
		if (key < _root->data)
		{
			_root->leftChild = Insert(_root->leftChild, key);
		}
		else if (key > _root->data)
		{
			_root->rightChild = Insert(_root->rightChild, key);
		}
		else
			return _root;
	}

	int leftSubtreeHeight = Height(_root->leftChild);
	int rightSubtreeHeight = Height(_root->rightChild);

	_root->height = 1 + MaxValue(leftSubtreeHeight, rightSubtreeHeight);

	int nodeBalance = BalanceCalc(_root, leftSubtreeHeight, rightSubtreeHeight);

	/* LEFT-LEFT ADDING CASE <=> RIGHT ROTATION */
	if (nodeBalance > 1 && key < _root->leftChild->data)
	{
		return RightRotation(_root);
	}
	/* RIGHT-RIGHT ADDING CASE <=> LEFT ROTATION */
	if (nodeBalance < -1 && key > _root->rightChild->data)
	{
		return LeftRotation(_root);
	}
	/* LEFT-RIGHT ADDING CASE <=> LEFT-RIGHT ROTATION */
	if (nodeBalance > 1 && key > _root->leftChild->data)
	{
		_root->leftChild = LeftRotation(_root->leftChild);
		return RightRotation(_root);
	}
	/* RIGHT-LEFT ADDING CASE <=> RIGHT-LEFT ROTATION */
	if (nodeBalance < -1 && key < _root->rightChild->data)
	{
		_root->rightChild = RightRotation(_root->rightChild);
		return LeftRotation(_root);
	}

	return _root;
}

AVL_TREE* RightRotation(AVL_TREE* _root)
{
	AVL_TREE* intendedRoot = _root->leftChild;
	_root->leftChild = intendedRoot->rightChild;
	intendedRoot->rightChild = _root;

	_root->height = MaxValue(Height(_root->leftChild), Height(_root->rightChild)) + 1;
	intendedRoot->height = MaxValue(Height(intendedRoot->leftChild), Height(intendedRoot->rightChild)) + 1;

	return intendedRoot;
}

AVL_TREE* LeftRotation(AVL_TREE* _root)
{
	AVL_TREE* intendedRoot = _root->rightChild;
	_root->rightChild = intendedRoot->leftChild;
	intendedRoot->leftChild = _root;

	_root->height = MaxValue(Height(_root->leftChild), Height(_root->rightChild)) + 1;
	intendedRoot->height = MaxValue(Height(intendedRoot->leftChild), Height(intendedRoot->rightChild)) + 1;

	return intendedRoot;
}

AVL_TREE* Delete(AVL_TREE* _root, int key)
{
	if (_root == NULL)
		return _root;

	else
	{
		if (key < _root->data)
		{
			_root->leftChild = Delete(_root->leftChild, key);
		}

		else if (key > _root->data)
		{
			_root->rightChild = Delete(_root->rightChild, key);
		}

		else
		{
			if (_root->leftChild == NULL || _root->rightChild == NULL)
			{
				AVL_TREE* tempNode = _root->leftChild ? _root->leftChild : _root->rightChild;

				if (tempNode == NULL)
				{
					tempNode = _root;
					_root = NULL;
				}
				else
				{
					*_root = *tempNode;
				}

				free(tempNode);
			}
			else
			{
				AVL_TREE* tempNode = MinValueNode(_root->rightChild);

				_root->data = tempNode->data;
				_root->rightChild = Delete(_root->rightChild, tempNode->data);
			}
		}
	}

	if (_root == NULL)
		return _root;

	int leftSubtreeHeight = Height(_root->leftChild);
	int rightSubtreeHeight = Height(_root->rightChild);

	_root->height = 1 + MaxValue(leftSubtreeHeight, rightSubtreeHeight);

	int nodeBalance = BalanceCalc(_root, leftSubtreeHeight, rightSubtreeHeight);

	/* LEFT-LEFT ADDING CASE <=> RIGHT ROTATION */
	if (nodeBalance > 1 && key < _root->leftChild->data)
	{
		return RightRotation(_root);
	}
	/* RIGHT-RIGHT ADDING CASE <=> LEFT ROTATION */
	if (nodeBalance < -1 && key > _root->rightChild->data)
	{
		return LeftRotation(_root);
	}
	/* LEFT-RIGHT ADDING CASE <=> LEFT-RIGHT ROTATION */
	if (nodeBalance > 1 && key > _root->leftChild->data)
	{
		_root->leftChild = LeftRotation(_root->leftChild);
		return RightRotation(_root);
	}
	/* RIGHT-LEFT ADDING CASE <=> RIGHT-LEFT ROTATION */
	if (nodeBalance < -1 && key < _root->rightChild->data)
	{
		_root->rightChild = RightRotation(_root->rightChild);
		return LeftRotation(_root);
	}

	return _root;
}

int Height(AVL_TREE* _root)
{
	if (_root == NULL)
		return -1;
	else
		return _root->height;
}

int MaxValue(int x, int y)
{
	if (x > y)
		return x;
	else
		return y;
}

AVL_TREE* MinValueNode(AVL_TREE* node)
{
	while (node->leftChild != NULL)
	{
		node = node->leftChild;
	}

	return node;
}

int BalanceCalc(AVL_TREE* _root, int leftSubtreeHeight, int rightSubtreeHeight)
{
	if (_root == NULL)
		return 0;
	else
		return leftSubtreeHeight - rightSubtreeHeight;
}

void Preorder(AVL_TREE* _root)
{
	if (_root != NULL)
	{
		printf("%d ", _root->data);
		Preorder(_root->leftChild);
		Preorder(_root->rightChild);
	}
}
