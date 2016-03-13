/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	struct node* orderlist = NULL;
	if (head1 == NULL&&head2 == NULL)
		return NULL;
	else if (head1 == NULL)//checking NULL cases for two_lists.
		return(head2);
	else if (head2 == NULL)
		return(head1);
	if (head1->num <= head2->num)
	{
		orderlist = head1;
		orderlist->next = merge2LinkedLists(head1->next, head2);//using recursive approach for sorting.
	}
	else
	{
		orderlist = head2;
		orderlist->next = merge2LinkedLists(head1, head2->next);
	}
	return(orderlist);
}

