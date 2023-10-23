#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 * @list: Pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *sorted = NULL;
    listint_t *current = *list;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
	return;

    while (current != NULL) {
        listint_t *next = current->next;

        if (sorted == NULL || sorted->n >= current->n) {
            current->next = sorted;
            current->prev = NULL;
            if (sorted != NULL)
                sorted->prev = current;
            sorted = current;
        } else {
            listint_t *temp = sorted;

            while (temp != NULL && temp->n < current->n) {
                temp = temp->next;
            }
            if (temp == sorted) {
                current->prev = sorted;
                current->next = sorted->next;
                if (sorted->next != NULL)
                    sorted->next->prev = current;
                sorted->next = current;
            } else {
                current->next = temp;
                current->prev = temp->prev;
                if (temp->prev != NULL)
                    temp->prev->next = current;
                temp->prev = current;
            }
        }

        if (next != NULL)
            next->prev = current;
        current = next;
    }

    *list = sorted;
}

