/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
}; 
void inorder1(struct node*root, int *arr, int *index)
{
	if (root == NULL)
		return;
	if (root != NULL)
	{
		inorder1(root->left, arr, index);
		arr[(*index)++] = root->data;
		inorder1(root->right, arr, index);
	}
}
void inorder(struct node *root, int *arr){
	int index = 0;
	if (root == NULL || arr == NULL)
		return;
	inorder1(root, arr, &index);
}
void postorder1(struct node*root, int *arr, int *index)
{
	if (root == NULL)
		return;
	if (root != NULL)
	{
		postorder1(root->left, arr, index);
		postorder1(root->right, arr, index);
		arr[(*index)++] = root->data;
	}
}
void postorder(struct node *root, int *arr){
	int index = 0;
	if (root == NULL || arr == NULL)
		return;
	postorder1(root, arr, &index);
}
void preorder1(struct node*root, int *arr, int *index)
{
	if (root == NULL)
		return;
	if (root != NULL)
	{
		arr[(*index)++] = root->data;
		preorder1(root->left, arr, index);
		preorder1(root->right, arr, index);
	}
}
void preorder(struct node *root, int *arr){
	int index = 0;
	if (root == NULL || arr == NULL)
		return;
	preorder1(root, arr, &index);
}
