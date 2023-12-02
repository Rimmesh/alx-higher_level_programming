#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
/**
*add_nodeint - new node at beg of listint_t
*@head: head of list
*@n: int to add yo list
*Return: address of new element,if failed NULL
*/
listint_t *add_nodeint(listint_t **head, const int n)
{
listint_t *new;
new = malloc(sizeof(listint_t));
if (new == NULL)
return (NULL);
new->n = n;
new->next = *head;
*head = new;
return (new);
}
/**
*is_palindrome - sees if syngle linked list is palindrome
*@head: head of list
*Return: If palindrome 1, otherwise 0
*/
int is_palindrome(listint_t **head)
{
listint_t *head2 = *head;
listint_t *aux = NULL, *aux2 = NULL;
if (*head == NULL || head2->next == NULL)
return (1);
while (head2 != NULL)
{
add_nodeint(&aux, head2->n);
head2 = head2->next;
}
aux2 = aux;
while (*head != NULL)
{
if ((*head)->n != aux2->n)
{
free_listint(aux);
return (0);
}
*head = (*head)->next;
aux2 = aux2->next;
}
free_listint(aux);
return (1);
}
