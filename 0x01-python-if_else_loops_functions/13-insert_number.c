#include "lists.h"

/**
 * insert_node - for inserting a new node.
 * @head: head of a list.
 * @number: index of the list
 * Return: the address of the new node or NULL if it
 * failed.
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *hd;
	listint_t *hd_bef;

	hd = *head;
	new = malloc(sizeof(listint_t));

	if (new == NULL)
		return (NULL);

	while (hd != NULL)
	{
		if (hd->n > number)
			break;
		hd_bef = hd;
		hd = hd->next;
	}

	new->n = number;

	if (*head == NULL)
	{
		new->next = NULL;
		*head = new;
	}
	else
	{
		new->next = hd;
		if (hd == *head)
			*head = new;
		else
			hd_bef->next = new;
	}

	return (new);
}
