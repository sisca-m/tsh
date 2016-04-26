/*
** string_access.c for string access in 
** 
** Made by 
** Login   <roche_g@epitech.net>
** 
** Started on  Mon Mar 14 13:13:16 2016 
** Last update Sat Mar 19 21:43:43 2016 
*/

#include <stdlib.h>
#include "string_design.h"

Object		*string_front(Object *string)
{
  t_container	*container;

  container = string;
  return (container->contained ? &((char *)container->contained)[0] : NULL);
}

Object		*string_back(Object *string)
{
  t_container	*container;

  container = string;
  return (container->contained ?
	  &((char *)container->contained)[container->contained_size - 1] :
	  NULL);
}

Object		*string_at(Object *string, size_t pos)
{
  t_container	*self;
  char		*res;

  self = string;
  if (pos < self->contained_size && self->contained)
    {
      if (!(res = calloc(2, sizeof(char))))
	return (NULL);
      res[0] = ((char *)self->contained)[pos];
    }
  return (pos < self->contained_size && self->contained ? res : NULL);
}
