#include "dict_design.h"

static t_bool	copy_ctor(dict *dict, void **copy, size_t size)
{
  size_t	i;
  size_t	j;
  void		*new_contained;
  t_container	*dict_ctn;
  t_pair	*pair;

  dict_ctn = (t_container *)dict;

  if (size == 0)
    while (copy[size])
      ++size;
  if (size % 2)
    return (FALSE);
  size = size / 2 + dict_ctn->contained_size;

  if (!(new_contained = calloc(size + 1, sizeof(t_pair *))))
    return (FALSE);
  i = 0;
  while (i < dict_ctn->contained_size)
    {
      ((t_pair **)new_contained)[i] = dict_ctn->at(dict_ctn, i);
      ++i;
    }

  dict_ctn->contained_size = size;
  j = 0;
  while (i + j < dict_ctn->contained_size)
    {
      pair = calloc(1, sizeof(t_pair));
      pair->key = ((char **)copy)[j * 2];
      pair->data = ((char **)copy)[j * 2 + 1];
      ((t_pair **)new_contained)[i + j] = pair;
      j += 1;
    }
  dict_ctn->contained = new_contained;

  return (TRUE);
}

static int	_dict_ctor(Object *self, va_list *args)
{
  dict		*dict_ctn;
  size_t	nb_args;
  void		*copy;

  dict_ctn = self;

  if ((copy = va_arg(*args, void *)))
    if (copy_ctor(dict_ctn, copy, va_arg(*args, size_t)) == FALSE)
      return (FALSE);

  nb_args = va_arg(*args, size_t);
  while (nb_args > 0)
    {
      if (dict_ctn->push_back(dict_ctn, va_arg(*args, char *), va_arg(*args, char *)) == FALSE)
	return (FALSE);
      nb_args -= 2;
    }

  if (!((t_container *)dict_ctn)->contained)
    {
      if (dict_ctn->push_back(dict_ctn, NULL, NULL) == FALSE)
	return (FALSE);
      ((t_container *)dict_ctn)->contained_size = 0;
    }

  return (TRUE);
}

static void	_dict_dtor(Object *self, va_list *args)
{
  t_container	*dict;

  dict = self;
  while (dict->contained_size > 0)
    dict->deleteAt(dict, 0);
  free(((t_container *)self)->contained);
  ((t_container *)self)->contained_size = 0;
}

static dict _dict_descr =
  {
    {
      {
	sizeof(dict),
	"Dict",
	&_dict_ctor,
	&_dict_dtor
      },
      NULL,
      0,

      &_container_data,
      &_container_size,
      &_container_empty,

      &_array_insert_at,
      &_container_push_back,
      &_array_delete_at,
      &_array_erase,
      NULL,

      &_array_front,
      &_array_back,
      &_array_at,

      &_dict_print,

      &_container_to_type,
      &_container_sub
    },
    &_get_obj_by_key,
    &_del_by_key,
    &_dict_push_back
  };

Class	*_dict = (Class *)&_dict_descr;
