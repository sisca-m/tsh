/*
** string_modifiers.c for string modifiers in 
** 
** Made by 
** Login   <roche_g@epitech.net>
** 
** Started on  Mon Mar 14 13:21:20 2016 
** Last update Sun Mar 20 18:20:18 2016 
*/

#include <stdlib.h>
#include <string.h>
#include "string_design.h"

int		string_insert_at(Object *string, void *data, int pos)
{
  t_container	*self;
  char		*res;

  self = string;
  res = calloc(self->contained_size + 2, sizeof(char));
  if (pos > 0)
    memcpy(res, self->contained, pos);
  res[pos] = data ? *(char *)data : '\0';
  memcpy(&res[pos + 1], &((char *)self->contained)[pos], self->contained_size - pos);
  free(self->contained);
  self->contained = res;
  ++self->contained_size;
  return (TRUE);
}

int		string_delete_at(Object *string, int pos)
{
  (void)pos;
  --((t_container *)string)->contained_size;
  return (TRUE);
}

int		string_erase(Object *string)
{
  t_container	*self;

  self = string;
  if (self->empty(self) == TRUE)
    return (TRUE);
  self->deleteAt(self, 0);
  self->erase(self);
  return (TRUE);
}

void		string_affect(Object *string, void *data)
{
  t_container	*self;

  self = string;
  free(self->contained);
  self->contained_size = (data ? strlen(data) : 0);
  self->contained = (data ? str_dup(data) : NULL);
}
