/*
** dup.c for dup in /home/roche_g/dataStructures/oop
** 
** Made by 
** Login   <roche_g@epitech.net>
** 
** Started on  Wed Mar 16 02:22:46 2016 
** Last update Sat Mar 19 20:59:17 2016 
*/

#include <stdlib.h>
#include <string.h>

/*
** -ansi removes the system strdup
*/
char	*str_dup(const char *str)
{
  char	*res;

  if (!(res = calloc(strlen(str) + 1, sizeof(char))) || !str)
    return (NULL);
  memcpy(res, str, strlen(str));
  return (res);
}
