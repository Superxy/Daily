#include <iostream>

/*delete node from binary search tree
1.We need to do two things
a)delete the reference from it's parent
b)wipe it off from the memory

Three case to delete:
1) no child 
a)delete the reference from it's parent
b)wipe it off from the memory

2) one child
a)connect the reference from it's parent to it's only child
b)wipe it off from the memory

3) two child
a)Find MinValue in right subtree.
property: MinValue in right subtree won't have a left child
b)copy the MinValue in targetted node
c)delete the MinValue Node in right subtree 
if the MinValue has the right child. switch case 3 to case 2
if the MinValue not has the right child(leaf node). switch case 3 to case 1
*/

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
BSTNode * DeleteNode(BSTNode *root,int data);

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

BSTNode * DeleteNode(BSTNode *root,int data)
{
	if(root == NULL)
		return root;
	else if(data < root->data)
		root->left = DeleteNode(root->left, data);
	else if(data > root->data)
		root->right = DeleteNode(root->right, data);
	else // Found the Node
	{
		// case 1: No child
		if(root->left == NULL && root->right == NULL)
		{
			delete root;
			root = NULL;
			return root;
		}
		// case 2: One child
		else if(root->left == NULL)
		{
			BSTNode * temp = root;
			root = root->right;
			delete temp;
			return root;
		}
		else if(root->right == NULL)
		{
			BSTNode * temp = root;
			root = root->left;
			delete temp;
			return root;
		}
		else // case 3: two child
		{
			BSTNode * temp = FindMin(root->right);
			root->data = temp->data;
			root->right = DeleteNode(root->right, temp->data);
		}
	}
	return root;
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
	root = DeleteNode(root, 15);
	PreOrder(root);
	
	return 0;
}


