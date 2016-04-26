/*
** string_patterns.c for string pattern in /home/roche_g/dataStructures/oop
** 
** Made by 
** Login   <roche_g@epitech.net>
** 
** Started on  Mon Mar 14 21:01:24 2016 
** Last update Mon Mar 14 23:21:06 2016 
*/

#include "string_design.h"

static int	nmatch(const char *s1, const char *s2)
{
  if (*s1 != '\0' && *s2 == '*')
    return (nmatch(s1 + 1, s2) + nmatch(s1, s2 + 1));
  if (*s1 == '\0' && *s2 == '*')
    return (nmatch(s1, s2 + 1));
  if (*s1 == *s2 && *s1 != '\0' && s2 != '\0')
    return (nmatch(s1 + 1, s2 + 1));
  if (*s1 == *s2 && *s1 == '\0' && *s2 == '\0')
    return (1);
  return (0);
}

t_bool	string_match(Object *self, char *compare)
{
  return (nmatch(((t_container *)self)->contained, compare) ? TRUE : FALSE);
}

int	string_nmatch(Object *self, char *compare)
{
  return (nmatch(((t_container *)self)->contained, compare));
}
