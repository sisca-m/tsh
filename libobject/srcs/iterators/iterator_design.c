#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "iterator_design.h"
#include "bool.h"

static int	_iterator_ctor(Object *self, va_list *args)
{
  t_container	*container;

  container = va_arg(*args, void *);
  memcpy((char *)self + sizeof(Class),
	 (char *)container + sizeof(Class),
	 sizeof(t_container) - sizeof(Class));
  printf("Iterator()\n");
  return (TRUE);
}

static void	_iterator_dtor(Object *self, va_list *args)
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
	&_iterator_ctor,
	&_iterator_dtor
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
    &_incr,
    &_decr,
    &_jump,
    &_rvalue,
    &_jmp_rvalue,
    0
  };

Class	*_it = (Class *)&_it_descr;
