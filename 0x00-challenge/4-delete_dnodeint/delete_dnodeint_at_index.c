int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *saved_head;
    dlistint_t *tmp;
    unsigned int p;

    if (*head == NULL)
    {
        return (-1);
    }

    saved_head = *head;
    p = 0;
    
    // Traverse to the node at the specified index
    while (p < index && *head != NULL)
    {
        *head = (*head)->next;
        p++;
    }

    // If index is out of range
    if (p != index)
    {
        *head = saved_head;
        return (-1);
    }

    // Case: Deleting the head node
    if (0 == index)
    {
        tmp = (*head)->next;
        free(*head);
        *head = tmp;
        if (tmp != NULL)
        {
            tmp->prev = NULL;
        }
    }
    else
    {
        // Update the next and prev pointers of surrounding nodes
        (*head)->prev->next = (*head)->next;
        if ((*head)->next)
        {
            (*head)->next->prev = (*head)->prev;
        }
        free(*head);
    }
    
    // Reset the head to the original list
    *head = saved_head;
    return (1);
}
