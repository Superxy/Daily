#include <iostream>
#include <queue>
#include <algorithm>

struct BSTNode
{
	int data;
	BSTNode *left;
	BSTNode *right;
};

BSTNode * GetNode(int data);
BSTNode * Insert(BSTNode *root, int data);
bool Search(BSTNode *root, int data);
int FindMin(BSTNode *root);
int FindMax(BSTNode *root);
int FindHeight(BSTNode *root);
// breadth first travel
void LevelOrder(BSTNode *root);
//preorder travel  <root><left><right>
void Preorder(BSTNode *root);
//Inorder travel <left><root><right>
void Inorder(BSTNode *root);
//PostOrder travel <left><right><root>
void PostOrder(BSTNode *root);

bool IsBinarySearchTree(BSTNode *root);

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

int FindMin(BSTNode *root)
{
	if(root == NULL)
		std::cout << "Tree is empty" << std::endl;
	else if(root->left == NULL)
		return root->data;
	return FindMin(root->left);
}

int FindMax(BSTNode *root)
{
	BSTNode * current = root;
	if(current == NULL)
		std::cout << "Tree is empty" << std::endl;
	while(current->right != NULL)
		current = current->right;
	return current->data;
}

int FindHeight(BSTNode *root)
{
	if(root == NULL)
		return -1;
	else
		return std::max(FindHeight(root->left), FindHeight(root->right))+1;
}

void LevelOrder(BSTNode *root)
{
	if(root == NULL)
		return;
	std::queue<BSTNode *> q;
	q.push(root);
	while(!q.empty())
	{
		BSTNode * current = q.front();
		std::cout << current->data << std::endl;
		if(current->left != NULL)
			q.push(current->left);
		if(current->right != NULL)
			q.push(current->right);
		q.pop();
	}
}

void Preorder(BSTNode *root)
{
	if(root == NULL)
		return;
	std::cout << root->data << std::endl;
	Preorder(root->left);
	Preorder(root->right);
}

void Inorder(BSTNode *root)
{
	if(root == NULL)
		return;
	Inorder(root->left);
	std::cout << root->data << std::endl;
	Inorder(root->right);
}

void PostOrder(BSTNode *root)
{
	if(root == NULL)
		return;
	PostOrder(root->left);
	PostOrder(root->right);
	std::cout << root->data << std::endl;
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
	int num = FindMin(root);
	std::cout << num << std::endl;
	num = FindMax(root);
	std::cout << num << std::endl;
	int height = FindHeight(root);
	std::cout << height << std::endl;
	PostOrder(root);
	return 0;
}


