#include "new.h"
#include "container_design.h"

int		_container_push_back(Object *self, void *data)
{
  t_container	*self_c;

  self_c = self;
  return (self_c->insertAt(self_c, data, self_c->contained_size));
}

Object		*_container_sub(Object *self, Class *type, int begin, int len)
{
  t_container	*string;
  t_container	*self_c;
  char		*at;
  int		i;

  i = 0;
  self_c = (t_container *)self;
  begin = (begin && begin < 0 ? begin + 1 : begin - 1);
  begin = begin < 0 ? (int)self_c->contained_size - 1 + begin : begin;
  if (!(string = new(type, NULL, 0)))
    return (NULL);
  while (i < len && begin + i < (int)self_c->contained_size)
    {
      string->push_back(string, (at = (char *)self_c->at(self_c, begin + i)));
      ++i;
    }
  return (string);
}
