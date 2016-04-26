/*
** array_print.c for array print in /home/roche_g/dataStructures/lists/oop
** 
** Made by 
** Login   <roche_g@epitech.net>
** 
** Started on  Mon Mar 14 02:28:59 2016 
** Last update Sat Mar 19 21:45:52 2016 
*/

#include <stdio.h>
#include "string_design.h"

void		string_print(Object *self)
{
  printf("string_print:\n");
  printf("\t[%s]\n", (char *)((t_container *)self)->contained);
}
