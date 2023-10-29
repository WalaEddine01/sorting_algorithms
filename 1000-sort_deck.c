#include "deck.h"

/**
 * compare_cards - a function that compare function for qsort
 * @a: the first card node pointer
 * @b: the second card node pointer
 * Return: positive integer if a > b,
 * 0 if a = b, negative integer if a < b.
 */
int compare_cards(const void *a, const void *b)
{
	const deck_node_t *node_a = *(const deck_node_t **)a;
	const deck_node_t *node_b = *(const deck_node_t **)b;

	const card_t *card_a = node_a->card;
	const card_t *card_b = node_b->card;

	if (card_a->kind != card_b->kind)
	{
		return ((int)(card_a->kind) - (int)(card_b->kind));
	}

	return (strcmp(card_a->value, card_b->value));
}

/**
 * sort_deck - a function that sorts a deck of cards
 * in a doubly linked list
 * @deck: a pointer to the deck of cards
 * Returns: Nothing.
 */
void sort_deck(deck_node_t **deck)
{
	size_t deck_size = 52, i;
	deck_node_t **nodes;
	deck_node_t *current = *deck;

	nodes = (deck_node_t **)malloc(deck_size * sizeof(deck_node_t *));

	if (nodes == NULL)
	{
		return;
	}

	for (i = 0; i < deck_size; ++i)
	{
		nodes[i] = current;
		current = current->next;
	}

	qsort(nodes, deck_size, sizeof(deck_node_t *), compare_cards);

	for (i = 0; i < deck_size - 1; ++i)
	{
		nodes[i]->next = nodes[i + 1];
		nodes[i + 1]->prev = nodes[i];
	}

	nodes[0]->prev = NULL;
	nodes[deck_size - 1]->next = NULL;
	*deck = nodes[0];

	free(nodes);
}
