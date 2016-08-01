#include "list_design.h"

int	_dbl_clist_add(Object *list, void *data, int pos)
{
  if (list_add((t_list_data **)&((t_container *)list)->contained,
	       data, pos, CIRC_DOUBLE))
    {
      ++((t_container *)list)->contained_size;
      return (1);
    }
  return (0);
}

int	_dbl_clist_del(Object *list, int pos)
{
  (void)list;
  (void)pos;
  return (1);
}
