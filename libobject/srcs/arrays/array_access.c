#include "array_design.h"

Object		*_array_front(Object *array)
{
  t_container	*container;

  container = array;
  return (container->contained ? ((void **)container->contained)[0] : NULL);
}

Object		*_array_back(Object *array)
{
  t_container	*container;

  container = array;
  return (container->contained ?
	  ((void **)container->contained)[container->contained_size - 1] :
	  NULL);
}

Object		*_array_at(Object *self, size_t pos)
{
  t_container	*container;

  container = self;
  return (pos < container->contained_size && container->contained ?
	  ((void **)container->contained)[pos] :
	  NULL);
}
