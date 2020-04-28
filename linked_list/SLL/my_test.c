/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 20:37:09 by marvin            #+#    #+#             */
/*   Updated: 2020/03/29 20:37:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SLL.h"

int main()
{
    int index;
    t_node *head;

    t_node *node1 = malloc(sizeof(t_node));
    head = node1;
    node1 -> data = 0;
    t_node *node2 = malloc(sizeof(t_node));
    node1 -> next = node2;
    node2 -> data = 1;
    t_node *node3 = malloc(sizeof(t_node));
    node2 -> next = node3;
    node3 -> data = 2;

    node3->next = NULL;

    index = list_add1(&head, 3);
    t_node *curr = head;
    printf("head1 memory : %p\n",head);
    printf("add1 index : %d\n",index);
    printf("size  : %d\n",list_size(head));
    printf("index : 2 , value : %d\n",list_get(head,2)->data);
    printf("list_find : %d\n",list_find(head,3));
    printf("list_remove : %d (success=1 fail=0)\n",list_remove(&head,1));
    printf("list_size?? : %d\n",list_size(head));
    // printf("node1 : %d\n",(head->next)->data);
    printf("list_add : %d\n",list_add(&head,5,6));
    printf("head2 memory : %p\n",head);

    while (curr != NULL)
    {
        printf("%d\n",curr->data);
        curr=curr->next;
    }
}