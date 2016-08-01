#include <stdio.h>
#include <stdlib.h>
#include "dict_design.h"
#include "array_design.h"

static int	_dict_ctor(Object *self, va_list *args)
{
  (void)self;
  (void)args;
  return (TRUE);
}

static void	_dict_dtor(Object *self, va_list *args)
{
  (void)args;
  free(((t_container *)self)->contained);
  ((t_container *)self)->contained = NULL;
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
    &_dict_push_back
  };

Class	*_dict = (Class *)&_dict_descr;
