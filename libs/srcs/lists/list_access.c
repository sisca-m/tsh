/*
** list_access.c for list access in /home/roche_g/dataStructures/lists/oop
** 
** Made by 
** Login   <roche_g@epitech.net>
** 
** Started on  Sun Mar 13 20:31:07 2016 
** Last update Sat Mar 19 21:53:35 2016 
*/

#include "list_design.h"

Object		*list_end(Object *list)
{
  t_list_data	*begin;
  t_list_data	*res;

  list = (t_list_data *)((t_container *)list)->contained;
  res = begin = list;
  if (res && res->next)
    res = res->next;
  while (res && res->next && res->next != begin)
    res = res->next;
  list = begin;
  return (res ? res->data : NULL);
}

Object	*list_front(Object *list)
{
  if (list && ((t_container *)list)->empty(list) == FALSE)
    return (((t_list_data *)((t_container *)list)->contained)->data);
  return (NULL);
}

Object		*list_at(Object *list, size_t pos)
{
  t_list_data	*list_data;
  t_list_data	*begin;
  size_t	i;

  begin = list_data = (t_list_data *)((t_container *)list)->contained;
  i = 0;
  if (list_data && i < pos)
    {
      list_data = list_data->next;
      ++i;
    }
  while (list_data && list_data->next && list_data->next != begin && i < pos)
    {
      list_data = list_data->next;
      ++i;
    }
  return (list_data ? list_data->data : NULL);
}
