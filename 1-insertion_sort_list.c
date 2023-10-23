#include "sort.h"

/**
 * add_node - Inserts a node in the sorted portion of the list
 * @list: Pointer to the head of the list
 * @node: Node to insert
 * Return: Nothing.
 */
void add_node(listint_t **list, listint_t *node)
{
	listint_t *current = *list;

	if (*list == NULL)
	{
		*list = node;
		return;
	}
	if (node->n < (*list)->n)
	{
		node->next = *list;
		node->prev = NULL;
		(*list)->prev = node;
		*list = node;
		return;
	}
	while (current->next != NULL && current->next->n <= node->n)
	{
		current = current->next;
	}
	node->next = current->next;
	if (current->next != NULL)
	{
		current->next->prev = node;

	}
	node->prev = current;
	current->next = node;
}

/**
 * insertion_sort_list - a function that sorts a doubly linked
 * list of integers in ascending order.
 * @list: a pointer to the head of the list.
 * Return: Nothing.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted = NULL, *unsorted = *list, *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (unsorted != NULL)
	{
		next = unsorted->next;

		unsorted->prev = NULL;
		unsorted->next = NULL;

		add_node(&sorted, unsorted);

		unsorted = next;
	}

	*list = sorted;
}

