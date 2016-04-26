/*
** array_access.c for array access in /home/roche_g/dataStructures/lists/oop
** 
** Made by 
** Login   <roche_g@epitech.net>
** 
** Started on  Mon Mar 14 02:17:06 2016 
** Last update Sat Mar 19 21:12:53 2016 
*/

#include "array_design.h"

Object		*array_front(Object *array)
{
  t_container	*container;

  container = array;
  return (container->contained ? ((void **)container->contained)[0] : NULL);
}

Object		*array_back(Object *array)
{
  t_container	*container;

  container = array;
  return (container->contained ?
	  ((void **)container->contained)[container->contained_size - 1] :
	  NULL);
}

Object	*array_at(Object *self, size_t pos)
{
  t_container	*container;

  container = self;
  return (pos < container->contained_size && container->contained ?
	  ((void **)container->contained)[pos] :
	  NULL);
}
