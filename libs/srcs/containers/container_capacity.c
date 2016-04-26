/*
** list_capacity.c for list capacity in /home/roche_g/dataStructures/lists/oop
** 
** Made by 
** Login   <roche_g@epitech.net>
** 
** Started on  Sun Mar 13 23:38:55 2016 
** Last update Sat Mar 19 21:56:53 2016 
*/

#include "list_design.h"

t_bool	container_empty(Object *container)
{
  return (((t_container *)container)->contained_size == 0 ? TRUE : FALSE);
}

size_t	container_size(Object *container)
{
  return (((t_container *)container)->contained_size);
}
