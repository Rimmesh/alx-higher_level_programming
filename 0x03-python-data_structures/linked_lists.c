#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * print_listint - prints elements of a listint_t
 * @h: pointer to head of the list
 * Return: number of nodes
 */
size_t print_listint(const listint_t *h)
{
const listint_t *current;
unsigned int n;
current = h;
n = 0;
while (current != NULL)
{
printf("%i\n", current->n);
current = current->next;
n++;
}
return (n);
}
/**
 * add_nodeint_end - new node to end of a listint_t
 * @head: pointer to pointer of first node
 * @n: integer to be included in new node
 * Return: address of the new element,if failed NULL
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
listint_t *new;
listint_t *current;
current = *head;
new = malloc(sizeof(listint_t));
if (new == NULL)
return (NULL);
new->n = n   new->next = NULL;
if (*head == NULL)
*head = new;
else
{
while (current->next != NULL)
current = current->next;
current->next = new;
}
return (new);
}
/**
 * free_listint - frees listint_t
 * @head: pointer to list
 * Return: void
 */
void free_listint(listint_t *head)
{
listint_t *current;
while (head != NULL)
{
current = head;
head = head->next;
free(current);
}
}
