#include "iterator_design.h"

void	_incr(Object *self)
{
  ++((t_it *)self)->pos;
}

void	_decr(Object *self)
{
  --((t_it *)self)->pos;
}

void	_jump(Object *self, int pos)
{
  ((t_it *)self)->pos += pos;
}

Object	*_rvalue(Object *self)
{
  t_it	*it;

  it = self;
  if (it->pos >= 0 && it->pos < (int)it->container.contained_size)
    return ((it->container.at((t_container *)it, it->pos)));
  return (NULL);
}

Object	*_jmp_rvalue(Object *self, int pos)
{
  t_it	*it;

  it = self;
  it->jump(it, pos);
  if (it->pos >= 0 && it->pos < (int)it->container.contained_size)
    return ((it->container.at((t_container *)it, it->pos)));
  return (NULL);
}
