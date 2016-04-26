/*
** container_access.c for container access in /home/roche_g/ftsh
** 
** Made by 
** Login   <roche_g@epitech.net>
** 
** Started on  Mon Apr 25 23:26:34 2016 
** Last update Mon Apr 25 23:28:52 2016 
*/

#include "container_design.h"

Object	*contained_data(Object *self)
{
  return (((t_container *)self)->contained);
}
