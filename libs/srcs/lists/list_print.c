/*
** list_print.c for list dump in /home/roche_g/dataStructures/lists/oop
** 
** Made by 
** Login   <roche_g@epitech.net>
** 
** Started on  Sun Mar 13 20:53:14 2016 
** Last update Sat Mar 19 21:51:45 2016 
*/

#include <stdio.h>
#include "list_design.h"

void		list_print(Object *container)
{
  t_list_data	*begin;
  t_list_data	*list;

  list = (t_list_data *)((t_container *)container)->contained;
  printf("list_print:\n");
  begin = list;
  do
    {
      if (list)
	{
	  printf("\tcur [%s] prev [%s] next [%s]\n",
		 (char *)list->data,
		 (list->prev ? (char *)list->prev->data : "prev null"),
		 (list->next ? (char *)list->next->data : "next null"));
	  list = list->next;
	}
    }
  while (list && list != begin);
  list = begin;
}
