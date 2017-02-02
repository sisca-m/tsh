#include "string_design.h"

void	_string_basic_print(size_t i, Object *elem, const char *prefix)
{
  printf("%s[%s]\n", prefix, (char *)elem);
  (void)i;
}

void	_string_print(Object *self, const char *title,
		      void (*f)(size_t i, Object *elem, const char *prefix),
		      const char *prefix)
{
  char	*concat_prefix;

  if (!(concat_prefix = concat(prefix, "  ")))
    return ;
  if (title)
    printf("%s%s\n", prefix, title);
  f(0, ((t_container *)self)->contained, concat_prefix);
  free(concat_prefix);
}
