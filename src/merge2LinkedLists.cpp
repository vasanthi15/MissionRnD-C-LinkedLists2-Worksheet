/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<malloc.h>
struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	struct node *temp1 = NULL, *temp2 = NULL, *mergelist = NULL, *head3 = NULL;
	if (head1 == NULL&&head2 == NULL)
		return NULL;
	if (head1 == NULL)
	{
		return head2;
	}
	else if (head2 == NULL)
	{
		return head1;
	}
	temp1 = head1;
	temp2 = head2;
	mergelist = (struct node *)malloc(sizeof(struct node));
	head3 = mergelist;
	while (temp1 != NULL&&temp2 != NULL)
	{
		if (temp1->num<temp2->num)
		{
			mergelist->next = temp1;
			temp1 = temp1->next;
		}
		else if (temp1->num>temp2->num)
		{
			mergelist->next = temp2;
			temp2 = temp2->next;
		}
		else
		{
			mergelist->next = temp2;
			mergelist = mergelist->next;
			temp2 = temp2->next;
			mergelist->next = temp1;
			temp1 = temp1->next;
		}
		mergelist = mergelist->next;
	}
	head3 = head3->next;
	while (temp1 != NULL)
	{
		mergelist->next = temp1;
		temp1 = temp1->next;
		mergelist = mergelist->next;
	}
	while (temp2 != NULL)
	{
		mergelist->next = temp2;
		temp2 = temp2->next;
		mergelist = mergelist->next;
	}
	mergelist = NULL;
	mergelist = head3;
	return head3;
}
