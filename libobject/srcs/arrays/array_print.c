#include <stdio.h>
#include "array_design.h"

void	array_basic_print(size_t i, Object *elem, const char *prefix)
{
  printf("%s%u: [%s]\n", prefix, (unsigned int)i, (char *)elem);
}

void		_array_print(Object *container, const char *title,
			     void (*f)(size_t i, Object *elem,
				       const char *prefix),
			     const char *prefix)
{
  char		**array;
  char		*concat_prefix;
  unsigned int	i;

  array = ((t_container *)container)->contained;
  i = 0;
  if (!(concat_prefix = concat(prefix, "  ")))
    return ;
  if (title)
    printf("%s%s\n", prefix, title);
  printf("%s[\n", prefix);
  if (array)
    while (array[i])
      {
	f(i, array[i], concat_prefix);
	++i;
      }
  printf("%s]\n", prefix);
  free(concat_prefix);
}
