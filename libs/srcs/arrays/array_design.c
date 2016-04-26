/*
** array_design.c for array design in /home/roche_g/dataStructures/lists/oop/src
** 
** Made by 
** Login   <roche_g@epitech.net>
** 
** Started on  Mon Mar 14 01:48:56 2016 
** Last update Tue Apr 26 02:12:27 2016 
*/

#include <stdio.h>
#include <stdlib.h>
#include "array_design.h"

static void	copy_ctor(t_container *array, void **copy, size_t size)
{
  size_t	i;

  i = 0;
  if (size == 0)
    {
      while (copy[size])
	++size;
    }
  if (!(array->contained = calloc(size + 1, sizeof(void *))))
    return ;
  array->contained_size = size;
  while (i < size)
    {
      ((char **)array->contained)[i] = ((char **)copy)[i];
      ++i;
    }
}

static void	array_ctor(Object *self, va_list *args)
{
  t_container	*array;
  size_t	nb_args;
  void		*copy;

  array = self;
  if ((copy = va_arg(*args, void *)))
    copy_ctor(array, copy, va_arg(*args, size_t));
  nb_args = va_arg(*args, size_t);
  printf("%zd\n", nb_args);
  while (nb_args > 0)
    {
      array->insertAt(array, va_arg(*args, void *),
		      array->contained_size);
      --nb_args;
    }
  printf("Array()\n");
}

static void	array_dtor(Object *self, va_list *args)
{
  (void)args;
  free(((t_container *)self)->contained);
  ((t_container *)self)->contained = NULL;
  ((t_container *)self)->contained_size = 0;
  printf("~Array()\n");
}

static t_Array _array_descr =
  {
    {
      {
	sizeof(t_Array),
	"Array",
	&array_ctor,
	&array_dtor
      },
      NULL,
      0,

      &contained_data,
      &container_size,
      &container_empty,

      &array_insert_at,
      &container_push_back,
      &array_delete_at,
      &array_erase,
      NULL,

      &array_front,
      &array_back,
      &array_at,

      &array_print,

      &container_to_type,
      &container_sub
    },
    NULL
  };

Class	*_array = (Class *)&_array_descr;