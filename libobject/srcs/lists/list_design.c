#include <stdio.h>
#include "list_design.h"

static int	_list_ctor(Object *self, va_list *args)
{
  t_container	*list;
  size_t	nb_args;

  list = self;
  if ((list->contained = va_arg(*args, void *)))
    list->contained_size = va_arg(*args, size_t);
  nb_args = va_arg(*args, size_t);
  if (nb_args > 0)
    {
      while (nb_args > 0)
	{
	  list->insertAt(list, va_arg(*args, void *),
			 list->contained_size);
	  --nb_args;
	}
    }
  printf("List()\n");
  return (TRUE);
}

static void	_list_dtor(Object *self, va_list *args)
{
  (void)self;
  (void)args;
  printf("~List()\n");
}

static t_spl_list _spl_list_descr =
  {
    {
      {
	sizeof(t_list),
	"linked List",
	&_list_ctor,
	&_list_dtor
      },
      NULL,
      0,

      &_container_data,
      &_container_size,
      &_container_empty,

      &_spl_list_add,
      &_container_push_back,
      &_spl_list_del,
      NULL,
      NULL,

      &_list_front,
      &_list_end,
      &_list_at,

      &_list_print,

      &_container_to_type,
      &_container_sub
    }
  };

static t_spl_clist _spl_clist_descr =
  {
    {
      {
	sizeof(t_list),
	"Circular linked List",
	&_list_ctor,
	&_list_dtor
      },
      NULL,
      0,

      &_container_data,
      &_container_size,
      &_container_empty,

      &_spl_clist_add,
      &_container_push_back,
      &_spl_clist_del,
      NULL,
      NULL,

      &_list_front,
      &_list_end,
      &_list_at,

      &_list_print,

      &_container_to_type,
      &_container_sub
    }
  };

static t_dbl_list _dbl_list_descr =
  {
    {
      {
	sizeof(t_list),
	"Double linked List",
	&_list_ctor,
	&_list_dtor
      },
      NULL,
      0,

      &_container_data,
      &_container_size,
      &_container_empty,

      &_dbl_list_add,
      &_container_push_back,
      &_dbl_list_del,
      NULL,
      NULL,

      &_list_front,
      &_list_end,
      &_list_at,

      &_list_print,

      &_container_to_type,
      &_container_sub
    }
  };

static t_dbl_clist _dbl_clist_descr =
  {
    {
      {
	sizeof(t_list),
	"Circular Double linked List",
	&_list_ctor,
	&_list_dtor
      },
      NULL,
      0,

      &_container_data,
      &_container_size,
      &_container_empty,

      &_dbl_clist_add,
      &_container_push_back,
      &_dbl_clist_del,
      NULL,
      NULL,

      &_list_front,
      &_list_end,
      &_list_at,

      &_list_print,

      &_container_to_type,
      &_container_sub
    }
  };

Class *_spl_list = (Class *)&_spl_list_descr;
Class *_spl_clist = (Class *)&_spl_clist_descr;
Class *_dbl_list = (Class *)&_dbl_list_descr;
Class *_dbl_clist = (Class *)&_dbl_clist_descr;
