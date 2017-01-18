#include <iostream>
#include <algorithm>

struct BSTNode
{
	int data;
	BSTNode *left;
	BSTNode *right;
};

BSTNode * GetNode(int data);
BSTNode * Insert(BSTNode *root, int data);
bool IsBinarySearchTree(BSTNode *root);
bool IsSubtreeLesser(BSTNode *root, int data);
bool IsSubtreeGreater(BSTNode *root, int data);
bool IsBinarySearchTreeTwo(BSTNode *root, int minValue, int maxValue);


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



bool IsBinarySearchTree(BSTNode *root)
{
	if(root == NULL)
		return true;
	if(IsSubtreeLesser(root->left, root->data) &&
		IsSubtreeGreater(root->right, root->data) &&
		IsBinarySearchTree(root->left) &&
		IsBinarySearchTree(root->right) )
		return true;
	else
		return false;

}

bool IsSubtreeLesser(BSTNode *root, int data)
{
	if(root == NULL)
		return true;
	if(root->data <= data &&
		IsSubtreeLesser(root->left, data) && IsSubtreeLesser(root->right, data))
		return true;
	else
		return false;
}

bool IsSubtreeGreater(BSTNode *root, int data)
{
	if(root == NULL)
		return true;
	if(root->data > data &&
		IsSubtreeGreater(root->left, data) && IsSubtreeGreater(root->right, data))
		return true;
	else
		return false;
}

bool IsBinarySearchTreeTwo(BSTNode *root, int minValue, int maxValue)
{
	if(root == NULL)
		return true;
	if(root->data >= minValue && root->data < maxValue &&
		IsBinarySearchTreeTwo(root->left, minValue, root->data) &&
		IsBinarySearchTreeTwo(root->right, root->data, maxValue))
		return true;
	else 
		return false;
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
	
	bool flag = IsBinarySearchTree(root);
	if(flag == true)
		std::cout << "Is Binary Search Tree" << std::endl;
	else
		std::cout << "Not Binary Search Tree" << std::endl;

	flag = IsBinarySearchTreeTwo(root, INT_MIN, INT_MAX);
	if(flag == true)
		std::cout << "Is Binary Search Tree" << std::endl;
	else
		std::cout << "Not Binary Search Tree" << std::endl;
	return 0;
}


