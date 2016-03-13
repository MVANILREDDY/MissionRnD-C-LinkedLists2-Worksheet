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

struct node * insertAtEveryKthNode(struct node *head, int K) 
{
	struct node*insert, *current, *precur;
	int count = 0;

	if (K>0 && head != NULL)
	{
		current = head;
		precur = head;
		while (current != NULL)
		{

			if (count == K)//count is used as reference for Kth node.
			{
				insert = (struct node*)malloc(sizeof(struct node));
				insert->num = K;
				count = 0;
				precur->next = insert;//precur and current nodes are used asreference for current and previous nodes.
				insert->next = current;
			}
			else
			{
				precur = current;
				current = current->next;
				count++;
			}
		}
		if (count == K)  //after traversing entire list,if count is K,then inserting at end of the list.
		{
			insert = (struct node*)malloc(sizeof(struct node));
			insert->num = K;
			precur->next = insert;
			insert->next = NULL;
		}
		return head;

	}
	else
	{
		return NULL;
	}
}

