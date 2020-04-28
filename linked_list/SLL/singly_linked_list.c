#include "SLL.h"

t_node *create_elem(int data)
{
    t_node *new_node = malloc(sizeof(t_node));
    if (new_node==NULL)
        return NULL;
    new_node->data=data;
    new_node->next=NULL;
    return (new_node);
}

int list_add1(t_node **begin_list, int data)
{
    unsigned int i = 0;
    t_node *curr = *begin_list;
    if (begin_list == 0)
        return (-1);
    if (*begin_list == 0) //이 경우에는 curr(NULL)->next가 없기 떄문에 예외처리
    {
        *begin_list = create_elem(data);
        return (i);
    }
    while (curr->next != NULL)
    {
        curr = curr->next;
        i++;
    }
    curr->next = create_elem(data);
    if (curr->next == NULL)
        return (-1);

    return (i+1); //새로 만들어지는 node의 index값
}

int list_size(t_node *begin_list)
{
    unsigned int i = 0;
    while (begin_list != NULL)
    {
        begin_list = begin_list->next;
        i++;
    }
    return (i);
}

t_node *list_get(t_node *begin_list, int n)
{
    if (n<0 || n >= list_size(begin_list))
        return (NULL);
    while (n != 0)
    {
        begin_list=begin_list->next;
        n--;
    }
    return (begin_list);
}

int list_find(t_node *begin_list, int data)
{
    unsigned int index = 0;
    while (begin_list!= NULL) //->next (x)
    {
        if (begin_list->data == data)
            return (index);
        index++;
        begin_list=begin_list->next;
    }
    return (-1);
}

int list_remove(t_node **begin_list, int n)
{
    if (begin_list == 0 || *begin_list == 0) //첫째항은 system적인 문제/두번째는 node가 없는 경우
       return 0;

    t_node *remove_list = NULL;
    // t_node *curr = (*begin_list)->next;
    t_node *curr = (*begin_list);
    while (n > 1)
    {
        if (curr->next == NULL)
            return 0;
        curr= curr->next;
        n--;
    }
    remove_list = curr->next;
    curr->next = (remove_list->next);
    free(remove_list);
}

int list_add(t_node **begin_list, int data, int n)
{
    t_node *add_list;
    if (n < 0 || (add_list = create_elem(data)) == 0)
        return 0;

    if (n > list_size(*begin_list))
    {
        return (list_add1(begin_list,data));
    }
    t_node *curr = *begin_list;
    curr=list_get(*begin_list,n);
    add_list->next = curr->next;
    curr->next = add_list;
    return (n+1);
}