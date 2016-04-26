/*
** string_finders.c for string finders in /home/roche_g/dataStructures/oop
** 
** Made by 
** Login   <roche_g@epitech.net>
** 
** Started on  Mon Mar 14 21:10:42 2016 
** Last update Mon Mar 14 23:31:29 2016 
*/

#include <string.h>
#include "string_design.h"

size_t	string_findstr(Object *self, char *substr)
{
  char	*res;

  res = strstr((char *)((t_container *)self)->contained, substr);
  return (res ? ((t_container *)self)->contained_size - (strlen(res) - 1) : 0);
}

size_t	string_find(Object *self, int c)
{
  char	*res;

  res = strchr((char *)((t_container *)self)->contained, c);
  return (res ? ((t_container *)self)->contained_size - (strlen(res) - 1) : 0);
  return (0);
}

size_t	string_lfind(Object *self, int c)
{
  char	*res;

  res = strrchr((char *)((t_container *)self)->contained, c);
  return (res ? ((t_container *)self)->contained_size - (strlen(res) - 1) : 0);
}
