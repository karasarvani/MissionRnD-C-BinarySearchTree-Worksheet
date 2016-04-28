/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>


struct node{
	struct node * left;
	int data;
	struct node *right;
};
int postorder(struct node *temp, struct node*temp1, struct node*temp2)
{
	int l = 0, r = 0;
	if (temp == NULL)
		return 0;
		l = postorder(temp->left, temp1, temp2);
		return temp->left->data;
		r = postorder(temp->right,temp1, temp2);
		return temp->right->data;
		if (temp->data<r || temp->data>l)
		{
			if (temp1 == NULL)
				temp1 = temp;
			else
				temp2 = temp;
		}

}

void fix_bst(struct node *root){
	int temp;
	struct node *temp1 = NULL,*temp2 = NULL;
	postorder(root,temp1,temp2);
	temp=temp1->data;
	temp1->data = temp2->data;
	temp2->data = temp;

}
