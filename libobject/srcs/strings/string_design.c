#include "string_design.h"

static int	_string_ctor(Object *self, va_list *args)
{
  t_container	*string;
  size_t	nb_args;
  char		*copy;

  string = self;
  if ((copy = va_arg(*args, char *)))
    {
      string->contained = str_dup(copy);
      if (string->contained)
	string->contained_size = strlen(string->contained);
    }
  nb_args = va_arg(*args, size_t);
  while (nb_args > 0)
    {
      string->insertAt(string, va_arg(*args, void *),
		       string->contained_size);
      --nb_args;
    }
  return (TRUE);
}

static void	_string_dtor(Object *self, va_list *args)
{
  (void)self;
  (void)args;
}

static t_String _string_descr =
  {
    {
      {
	sizeof(t_String),
	"String",
	&_string_ctor,
	&_string_dtor
      },
      NULL,
      0,

      &_container_data,
      &_container_size,
      &_container_empty,

      &_string_insert_at,
      &_container_push_back,
      &_string_delete_at,
      &_string_erase,
      &_string_affect,

      &_string_front,
      &_string_back,
      &_string_at,

      &_string_print,

      &_container_to_type,
      &_container_sub
    },
    &_string_dup,
    &_string_findstr,
    &_string_find,
    &_string_lfind,
    &_string_match,
    &_string_nmatch,
    &_string_split
  };

Class	*_string = (Class *)&_string_descr;
