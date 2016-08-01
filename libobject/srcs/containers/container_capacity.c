#include "list_design.h"

t_bool	_container_empty(Object *container)
{
  return (((t_container *)container)->contained_size == 0 ? TRUE : FALSE);
}

size_t	_container_size(Object *container)
{
  return (((t_container *)container)->contained_size);
}
