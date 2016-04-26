/*
** strings_design.c for strings design in /home/roche_g/dataStructures/oop
** 
** Made by 
** Login   <roche_g@epitech.net>
** 
** Started on  Mon Mar 14 12:59:57 2016 
** Last update Tue Apr 26 03:06:26 2016 
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "string_design.h"

static void	string_ctor(Object *self, va_list *args)
{
  t_container	*string;
  size_t	nb_args;
  char		*copy;

  string = self;
  if ((copy = va_arg(*args, char *)))
    {
      string->contained = str_dup(copy);
      if (string->contained)
	string->contained_size = strlen(string->contained);
    }
  nb_args = va_arg(*args, size_t);
  while (nb_args > 0)
    {
      string->insertAt(string, va_arg(*args, void *),
		       string->contained_size);
      --nb_args;
    }
  printf("String()\n");
}

static void	string_dtor(Object *self, va_list *args)
{
  (void)args;
  free(((t_container *)self)->contained);
  ((t_container *)self)->contained = NULL;
  printf("~String()\n");
}

static t_String _string_descr =
  {
    {
      {
	sizeof(t_String),
	"String",
	&string_ctor,
	&string_dtor
      },
      NULL,
      0,

      &contained_data,
      &container_size,
      &container_empty,

      &string_insert_at,
      &container_push_back,
      &string_delete_at,
      &string_erase,
      &string_affect,

      &string_front,
      &string_back,
      &string_at,

      &string_print,

      &container_to_type,
      &container_sub
    },
    &string_dup,
    &string_findstr,
    &string_find,
    &string_lfind,
    &string_match,
    &string_nmatch,
    &string_split
  };

Class	*_string = (Class *)&_string_descr;
