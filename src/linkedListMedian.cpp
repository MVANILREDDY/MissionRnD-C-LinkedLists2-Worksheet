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

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) 
{
	if (head == NULL)
		return -1;
	else
	{
		int middle = 0;
		struct node *lowlist, *highlist;
		lowlist = head;
		highlist = head->next;
		if (highlist != NULL&&highlist->next == NULL)//for list with 1 or 2 nodes.
		{
			middle++;
		}

		while (highlist != NULL)
		{
			  highlist = highlist->next;
			if (highlist != NULL)
			{
				middle++;//used to check middle element  in list.
				lowlist = lowlist->next;
				highlist = highlist->next;
			}

		}
		if (middle % 2 != 0&&middle!=1 || middle == 0)
			return lowlist->num;
		else
		{
			return ((lowlist->num + (lowlist->next)->num) / 2);
		}
	}
}



