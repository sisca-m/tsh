#include "string_design.h"

Object		*_string_front(Object *string)
{
  t_container	*container;

  container = string;
  return (container->contained ? &((char *)container->contained)[0] : NULL);
}

Object		*_string_back(Object *string)
{
  t_container	*container;

  container = string;
  return (container->contained ?
	  &((char *)container->contained)[container->contained_size - 1] :
	  NULL);
}

Object		*_string_at(Object *string, size_t pos)
{
  t_container	*self;
  char		*res;

  self = string;
  if (pos < self->contained_size && self->contained)
    {
      if (!(res = calloc(2, sizeof(char))))
	return (NULL);
      res[0] = ((char *)self->contained)[pos];
    }
  return (pos < self->contained_size && self->contained ? res : NULL);
}
