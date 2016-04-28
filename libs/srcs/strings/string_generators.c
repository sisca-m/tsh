/*
** string_generators.c for string generators in /home/roche_g/dataStructures/oop
**
** Made by
** Login   <roche_g@epitech.net>
**
** Started on  Mon Mar 14 21:05:05 2016
** Last update Thu Apr 28 03:35:25 2016 Guillaume roche
*/

#include <stdlib.h>
#include <string.h>
#include "new.h"
#include "string_design.h"

Object		*string_dup(Object *self)
{
  t_container	*string;

  if ((string = new(_string, 0)))
  string->affect(string, ((t_container *)self)->contained);
  return (string);
}

Object		*string_split(Object *self, Class *type, const char *sep)
{
  t_container	*container;
  char		*token;

  if (!(container = new(type, NULL, 0)))
    return (NULL);
  token = strtok((char *)((t_container *)self)->contained, sep);
  while (token)
    {
      container->push_back(container, token);
      token = strtok(NULL, sep);
    }
  return (container);
}
