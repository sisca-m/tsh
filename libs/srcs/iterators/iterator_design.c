/*
** iterator_design.c for iterator design in /home/roche_g/dataStructures/oop
** 
** Made by 
** Login   <roche_g@epitech.net>
** 
** Started on  Thu Mar 17 02:51:17 2016 
** Last update Mon Apr 25 23:32:59 2016 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "iterator_design.h"

static void	iterator_ctor(Object *self, va_list *args)
{
  t_container	*container;

  container = va_arg(*args, void *);
  memcpy((char *)self + sizeof(Class),
	 (char *)container + sizeof(Class),
	 sizeof(t_container) - sizeof(Class));
  printf("Iterator()\n");
}

static void	iterator_dtor(Object *self, va_list *args)
{
  (void)self;
  (void)args;
  free(self);
  printf("~Iterator()\n");
}

static t_iterator _it_descr =
  {
    {
      {
	sizeof(t_iterator),
	"Iterator",
	&iterator_ctor,
	&iterator_dtor
      },
      NULL,
      0,

      NULL,
      NULL,
      NULL,

      NULL,
      NULL,
      NULL,
      NULL,
      NULL,

      NULL,
      NULL,
      NULL,

      NULL,

      NULL,
      NULL
    },
    &incr,
    &decr,
    &jump,
    &rvalue,
    &jmp_rvalue,
    0
  };

Class	*_it = (Class *)&_it_descr;
