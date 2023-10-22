void insertion_sort_list(listint_t **list) {
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *sorted = NULL;  // Initialize the sorted list
    listint_t *current = *list;

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
                temp->prev->next = current;
                temp->prev = current;
            }
        }

        *list = next;  // Move to the next node in the original list
        print_list(sorted);  // Print the list after each swap
        current = next;
    }

    *list = sorted;  // Update the list to the sorted list
}
