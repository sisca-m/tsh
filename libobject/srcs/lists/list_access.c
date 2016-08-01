#include "list_design.h"

Object		*_list_end(Object *list)
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

Object	*_list_front(Object *list)
{
  if (list && ((t_container *)list)->empty(list) == FALSE)
    return (((t_list_data *)((t_container *)list)->contained)->data);
  return (NULL);
}

Object		*_list_at(Object *list, size_t pos)
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
