#include "sort.h"

void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);
/**
 * swap_node_ahead - Swap a node in a listint_t doubly-linked list
 *                   list of integers with the node ahead of it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @shaker: A pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *aux = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = aux;
	else
		*list = aux;
	aux->prev = (*shaker)->prev;
	(*shaker)->next = aux->next;
	if (aux->next != NULL)
		aux->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = aux;
	aux->next = *shaker;
	*shaker = aux;
}
/**
 * swap_node_behind - Swap a node in a listint_t doubly-linked
 *                    list of integers with the node behind it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @shaker: A pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *aux = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = aux;
	else
		*tail = aux;
	aux->next = (*shaker)->next;
	(*shaker)->prev = aux->prev;
	if (aux->prev != NULL)
		aux->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = aux;
	aux->prev = *shaker;
	*shaker = aux;
}
/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail shaker algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	bool no_shaken_stirred = false;
	listint_t *shaker, *tail;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (no_shaken_stirred == false)
	{
		no_shaken_stirred = true;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_node_ahead(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				no_shaken_stirred = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_node_behind(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				no_shaken_stirred = false;
			}
		}
	}
}
