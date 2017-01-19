#include <iostream>

struct BSTNode
{
	int data;
	BSTNode *left;
	BSTNode *right;
};

BSTNode * GetNode(int data);
BSTNode * FindMin(BSTNode *root);
BSTNode * Insert(BSTNode *root, int data);
void PreOrder(BSTNode *root);
BSTNode * SuccessorInorder(BSTNode *root, int data);
BSTNode * Find(BSTNode * root, int data);

BSTNode * GetNode(int data)
{
	BSTNode *newNode = new BSTNode;
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

BSTNode * FindMin(BSTNode *root)
{
	if(root == NULL)
		return root;
	while(root->left != NULL)
		root = root->left;
	return root;

}

BSTNode * Insert(BSTNode *root, int data)
{
	if(root == NULL)
	{
		root = GetNode(data);
		return root;
	}
	else if (data <= root->data)
		root->left = Insert(root->left, data);
	else if (data > root->data)
		root->right = Insert(root->right, data);
	return root;
}

void PreOrder(BSTNode *root)
{
	if(root == NULL)
		return;
	std::cout << root->data << std::endl;
	PreOrder(root->left);
	PreOrder(root->right);
}



BSTNode * SuccessorInorder(BSTNode *root, int data)
{
	BSTNode * current = Find(root, data);
	if(current == NULL) // not found the node
		return NULL;
	// case 1: the node has right subtree
	if(current->right != NULL)
		return FindMin(current->right);
	// case 2: the node not has right subtree
	else
	{
		BSTNode * successor = NULL;
		BSTNode * ancestor = root;
		while(ancestor != current)
		{
			if(current->data < ancestor->data)
			{
				successor = ancestor;
				ancestor = ancestor->left;
			}
			else
				ancestor = ancestor->right;
		}
		return successor;
	}
}

BSTNode * Find(BSTNode * root, int data)
{
	if(root == NULL)
		return NULL;
	if(root->data == data)
		return root;
	else if(data < root->data)
		return Find(root->left, data);
	else if(data > root->data)
		return Find(root->right, data);
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

	BSTNode * temp = SuccessorInorder(root, 8);
	std::cout << temp->data << std::endl;
	
	return 0;
}


