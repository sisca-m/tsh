#include "array_design.h"

static void	copy_array(void **dest, void **src, void *data, int pos)
{
  int		i;
  int		j;

  i = 0;
  if (!dest || !src)
    return ;
  while (src[i] && i < pos)
    {
      dest[i] = src[i];
      ++i;
    }
  j = i;
  dest[i++] = data;
  while (src[j])
    dest[i++] = src[j++];
}

int		_array_insert_at(Object *container, void *data, int pos)
{
  void		**res;
  t_container	*self;

  self = container;
  if (self->empty(self) == TRUE)
    {
      if (!(self->contained = malloc(2 * sizeof(void *))))
	return (FALSE);
      ((void **)self->contained)[0] = data;
      ((void **)self->contained)[1] = NULL;
    }
  else
    {
      if (!(res = malloc(sizeof(void *) * (self->contained_size + 2))))
	return (FALSE);
      copy_array(res, self->contained, data, pos);
      res[self->contained_size + 1] = NULL;
      free(self->contained);
      self->contained = res;
    }
  ++self->contained_size;
  return (TRUE);
}

int		_array_delete_at(Object *container, int pos)
{
  t_container	*self;
  void		**res;
  int		i;
  int		j;

  self = container;
  if (self->empty(self) == TRUE)
    return (TRUE);
  if (pos >= (int)self->contained_size)
    pos = self->contained_size - 1;
  if (!(res = malloc(self->contained_size * sizeof(void *))))
    return (FALSE);
  i = -1;
  while (((void **)self->contained)[++i] && i < pos)
    res[i] = ((void **)self->contained)[i];
  j = i;
  ++i;
  while (((void **)self->contained)[i])
    res[j++] = ((void **)self->contained)[i++];
  res[j] = NULL;
  free(self->contained);
  self->contained = res;
  --self->contained_size;
  return (TRUE);
}

int		_array_erase(Object *container)
{
  t_container	*self;

  self = container;
  if (self->empty(self) == TRUE)
    return (TRUE);
  self->deleteAt(self, 0);
  self->erase(self);
  return (TRUE);
}
