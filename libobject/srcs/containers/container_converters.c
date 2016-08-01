#include "new.h"
#include "container_design.h"

Object		*_container_to_type(Object *self, Class *type)
{
  t_container	*self_c;
  t_container	*container;
  size_t	i;

  self_c = self;
  container = new(type, NULL, 0);
  i = 0;
  while (i < self_c->contained_size)
    {
      container->push_back(container, self_c->at(self_c, i));
      ++i;
    }
  return (container);
}
