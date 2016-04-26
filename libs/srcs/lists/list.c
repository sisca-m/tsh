/*
** spl_list.c for list in /home/roche_g/data_structures/list
** 
** Made by 
** Login   <roche_g@epitech.net>
** 
** Started on  Thu Mar 10 21:00:10 2016 
** Last update Tue Mar 15 22:39:44 2016 
*/

#include <stdlib.h>
#include "list_design.h"

static void	go_to_pos_in_list(t_list_data **list, t_list_data **tmp,
				  int pos)
{
  int		i;

  i = 0;
  *tmp = NULL;
  while (*list && i < pos)
    {
      ++i;
      *tmp = *list;
      *list = (*list)->next;
    }
}

static void	list_link(t_list_data **list, t_list_data **tmp,
			  t_list_data *elem, t_list_type type)
{
  if (type == CIRC_DOUBLE)
    elem->prev = (*tmp ? *tmp : (*list ? list_end(*list) : elem));
  else
    elem->prev = (type == DOUBLE ? *tmp : NULL);
  if (type == CIRC_SIMPLE || type == CIRC_DOUBLE)
    elem->next = (*list ? *list : elem);
  else
    elem->next = *list;
  if (!*list && !*tmp)
    {
      *list = elem;
      return ;
    }
  if (*tmp)
    (*tmp)->next = elem;
  else if (!*tmp && (type == CIRC_SIMPLE || type == CIRC_DOUBLE))
    ((t_list_data *)list_end(*list))->next = elem;
  if ((type == DOUBLE || type == CIRC_DOUBLE) && *list)
    (*list)->prev = elem;
}

int		list_add(t_list_data **list, void *data, int pos,
			 t_list_type type)
{
  t_list_data	*begin;
  t_list_data	*tmp;
  t_list_data	*elem;

  begin = *list;
  tmp = NULL;
  if (!(elem = malloc(sizeof(t_list))))
    return (FALSE);
  elem->data = data;
  go_to_pos_in_list(list, &tmp, pos);
  list_link(list, &tmp, elem, type);
  if (begin && pos > 0)
    *list = begin;
  if (pos == 0)
    *list = elem;
  return (TRUE);
}

void	list_affect(Object *list, void *data)
{
  ((t_container *)list)->contained = data;
}
