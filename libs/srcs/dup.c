/*
** dup.c for dup in /home/roche_g/dataStructures/oop
**
** Made by
** Login   <roche_g@epitech.net>
**
** Started on  Wed Mar 16 02:22:46 2016
** Last update Thu Apr 28 03:39:01 2016 Guillaume roche
*/

#include <stdlib.h>
#include <string.h>

/*
** -ansi removes the system strdup
*/
char	*str_dup(const char *str)
{
  char	*res;

  if (!str)
    return (NULL);
  if (!(res = calloc(strlen(str) + 1, sizeof(char))) || !str)
    return (NULL);
  memcpy(res, str, strlen(str));
  return (res);
}
