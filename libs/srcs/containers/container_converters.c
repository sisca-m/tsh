/*
** container_converters.c for container converters in 
** 
** Made by 
** Login   <roche_g@epitech.net>
** 
** Started on  Mon Mar 14 05:31:13 2016 
** Last update Sat Mar 19 21:57:53 2016 
*/

#include "new.h"
#include "container_design.h"

Object		*container_to_type(Object *self, Class *type)
{
  t_container	*self_c;
  t_container	*container;
  size_t	i;

  self_c = self;
  container = new(type, NULL, 0);
  i = 0;
  while (i < self_c->contained_size)
    {
      container->push_back(container, self_c->at(self_c, i));
      ++i;
    }
  return (container);
}
