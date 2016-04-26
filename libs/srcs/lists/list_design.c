/*
** list_design.c for list design in /home/roche_g/dataStructures/lists
** 
** Made by 
** Login   <roche_g@epitech.net>
** 
** Started on  Sun Mar 13 16:45:57 2016 
** Last update Mon Apr 25 23:32:37 2016 
*/

#include <stdio.h>
#include "list_design.h"

static void	list_ctor(Object *self, va_list *args)
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
}

static void	list_dtor(Object *self, va_list *args)
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
	&list_ctor,
	&list_dtor
      },
      NULL,
      0,

      &contained_data,
      &container_size,
      &container_empty,

      &spl_list_add,
      &container_push_back,
      &spl_list_del,
      NULL,
      NULL,

      &list_front,
      &list_end,
      &list_at,

      &list_print,

      &container_to_type,
      &container_sub
    },
    NULL
  };

static t_spl_clist _spl_clist_descr =
  {
    {
      {
	sizeof(t_list),
	"Circular linked List",
	&list_ctor,
	&list_dtor
      },
      NULL,
      0,

      &contained_data,
      &container_size,
      &container_empty,

      &spl_clist_add,
      &container_push_back,
      &spl_clist_del,
      NULL,
      NULL,

      &list_front,
      &list_end,
      &list_at,

      &list_print,

      &container_to_type,
      &container_sub
    },
    NULL
  };

static t_dbl_list _dbl_list_descr =
  {
    {
      {
	sizeof(t_list),
	"Double linked List",
	&list_ctor,
	&list_dtor
      },
      NULL,
      0,

      &contained_data,
      &container_size,
      &container_empty,

      &dbl_list_add,
      &container_push_back,
      &dbl_list_del,
      NULL,
      NULL,

      &list_front,
      &list_end,
      &list_at,

      &list_print,

      &container_to_type,
      &container_sub
    },
    NULL
  };

static t_dbl_clist _dbl_clist_descr =
  {
    {
      {
	sizeof(t_list),
	"Circular Double linked List",
	&list_ctor,
	&list_dtor
      },
      NULL,
      0,

      &contained_data,
      &container_size,
      &container_empty,

      &dbl_clist_add,
      &container_push_back,
      &dbl_clist_del,
      NULL,
      NULL,

      &list_front,
      &list_end,
      &list_at,

      &list_print,

      &container_to_type,
      &container_sub
    },
    NULL
  };

Class *_spl_list = (Class *)&_spl_list_descr;
Class *_spl_clist = (Class *)&_spl_clist_descr;
Class *_dbl_list = (Class *)&_dbl_list_descr;
Class *_dbl_clist = (Class *)&_dbl_clist_descr;
