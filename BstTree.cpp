#include <iostream>

struct BSTNode
{
	int data;
	BSTNode *left;
	BSTNode *right;
};

BSTNode * GetNode(int data);
BSTNode * Insert(BSTNode *root, int data);
bool Search(BSTNode *root, int data);

BSTNode * Insert(BSTNode *root, int data)
{
	if(root == NULL)
	{
		root = GetNode(data);
		return root;
	}
	else if(data <= root->data)
		root->left = Insert(root->left, data);
	else if(data > root->data)
		root->right = Insert(root->right, data);

	return root;
}

BSTNode * GetNode(int data)
{
	BSTNode *newNode = new BSTNode;
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

bool Search(BSTNode *root, int data)
{
	if(root == NULL)
		return false;
	else if(data == root->data)
		return true;
	else if(data < root->data)
		return Search(root->left, data);
	else if(data > root->data)
		return Search(root->right, data);
}

int main()
{
	BSTNode *root = NULL;
	root = Insert(root, 15);
	root = Insert(root, 10);
	root = Insert(root, 20);
	root = Insert(root, 25);
	root = Insert(root, 8);
	root = Insert(root, 12);
	int num;
	scanf("%d", &num);
	if(Search(root, num) == true)
		std::cout << "Found" << std::endl;
	else
		std::cout << "Not Found" << std::endl;
	return 0;
}


