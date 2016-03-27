/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {
	struct node *temp1 = NULL,*newnode=NULL;
	int i = 1, len = 0, temp;
	if ((head == NULL) || K <= 0)
		return NULL;
	temp1 = head;
	while (temp1 != NULL)
	{
		temp1 = temp1->next;
		len++;
	}
	if (K > len)
		return head;
	temp1 = head;
	for (i = 0; i<len;i++)
	{

		if ((i + 1) % K == 0)
		{
			newnode = (struct node*)malloc(sizeof(struct node));
			newnode->num = K;
			newnode->next=temp1->next;
			temp1->next = newnode;
			temp1 = temp1->next;
			if (temp1->next != NULL)
				temp1 = temp1->next;
		}
		else
			if (temp1->next != NULL)
				temp1 = temp1->next;
	}
	return head;

}
