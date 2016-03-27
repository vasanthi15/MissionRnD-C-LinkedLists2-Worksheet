/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>
#include<malloc.h>
struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	struct node *temp = NULL;
	int len = 0, i = 0;
	if (head == NULL)
		return -1;
	temp = (struct node*)malloc(sizeof(struct node));
	temp = head;
	while (temp != NULL)
	{
		len++;
		temp = temp->next;
	}
	if (len == 1)
		return head->num;
	temp = head;
	i = len / 2 - 1;
	while (i>0)
	{
		temp = temp->next;
		i--;
	}
	if (len % 2 != 0)
		return temp->next->num;
	else
		return (temp->num + temp->next->num) / 2;
}
