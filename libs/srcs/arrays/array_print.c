/*
** array_print.c for array print in /home/roche_g/dataStructures/lists/oop
** 
** Made by 
** Login   <roche_g@epitech.net>
** 
** Started on  Mon Mar 14 02:28:59 2016 
** Last update Sat Mar 19 21:32:28 2016 
*/

#include <stdio.h>
#include "array_design.h"

void		array_print(Object *container)
{
  char		**array;
  unsigned int	i;

  array = ((t_container *)container)->contained;
  i = 0;
  printf("array_print:\n");
  if (array)
    while (array[i])
      {
	printf("\t%u: [%s]\n", i, array[i]);
	++i;
      }
}
