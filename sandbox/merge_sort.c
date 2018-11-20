#include <stdlib.h>
#include <stdio.h>
#include "../filler.h"

t_dist* merge_sort_list_recursive(t_dist *list,int (*compare)(t_dist *one,t_dist *two))
{
	if (!list || !list->next)
		return list;

	t_dist *right = list,
		  *temp  = list,
		  *last  = list,
		  *result = 0,
		  *next   = 0,
		  *tail   = 0;

	while (temp && temp->next)
	{
		last = right;
		right = right->next;
		temp = temp->next->next;
	}

	last->next = 0;

	list = merge_sort_list_recursive(list, compare);
	right = merge_sort_list_recursive(right, compare);

	while (list || right)
	{
		if (!right) {
			next = list;
			list = list->next;
		} else if (!list) {
			next = right;
			right = right->next;
		} else if (compare(list, right) < 0) {
			next = list;
			list = list->next;
		} else {
			next = right;
			right = right->next;
		}
		if (!result) {
			result=next;
		} else {
			tail->next=next;
		}
		tail = next;
	}
	return result;
}
void	print_list(t_dist *head)
{
	t_dist *tmp = head;
	while (tmp)
	{
		printf("list: %d\n", tmp->dist);
		tmp = tmp->next;
	}
}

void	add_item(t_dist **head, int value)
{
	t_dist	*new;

	new = malloc(sizeof(t_dist));
	new->next = *head;
	new->dist = value;
	*head = new;
}

int		compare(t_dist *a, t_dist *b)
{
	if (!a || !b)
		return (0);
	if (a->dist >= b->dist)
		return (1);
	return (-1);
}

/*
int		main(void)
{
	t_dist	*list = NULL;
	t_dist	*tmp;
	int		i = 0;
	int		tab[10] = {5, 8, 3, 12, 1, 2, 7, 9, 4, 11};

	while (i < 10)
	{
		add_item(&list, tab[i]);
		i++;
	}
	print_list(list);
	list = merge_sort_list_recursive(list, compare);
	printf("-----------\n");
	print_list(list);
 
}
*/
