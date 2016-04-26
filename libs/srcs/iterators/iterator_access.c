/*
** iterator_access.c for iterator access in /home/roche_g/dataStructures/oop
** 
** Made by 
** Login   <roche_g@epitech.net>
** 
** Started on  Thu Mar 17 03:01:24 2016 
** Last update Thu Mar 17 03:22:56 2016 
*/

#include "iterator_design.h"

void	incr(Object *self)
{
  ++((t_it *)self)->pos;
}

void	decr(Object *self)
{
  --((t_it *)self)->pos;  
}

void	jump(Object *self, int pos)
{
  ((t_it *)self)->pos += pos;
}

Object	*rvalue(Object *self)
{
  t_it	*it;

  it = self;
  if (it->pos >= 0 && it->pos < (int)it->container.contained_size)
    return ((it->container.at((t_container *)it, it->pos)));
  return (NULL);
}

Object	*jmp_rvalue(Object *self, int pos)
{
  t_it	*it;

  it = self;
  it->jump(it, pos);
  if (it->pos >= 0 && it->pos < (int)it->container.contained_size)
    return ((it->container.at((t_container *)it, it->pos)));
  return (NULL);
}
