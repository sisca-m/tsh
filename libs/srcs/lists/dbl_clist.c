/*
** spl_list.c for list in /home/roche_g/data_structures/list
** 
** Made by 
** Login   <roche_g@epitech.net>
** 
** Started on  Thu Mar 10 21:00:10 2016 
** Last update Sat Mar 19 21:50:47 2016 
*/

#include "list_design.h"

int	dbl_clist_add(Object *list, void *data, int pos)
{
  if (list_add((t_list_data **)&((t_container *)list)->contained,
	       data, pos, CIRC_DOUBLE))
    {
      ++((t_container *)list)->contained_size;
      return (1);
    }
  return (0);
}

int	dbl_clist_del(Object *list, int pos)
{
  (void)list;
  (void)pos;
  return (1);
}
