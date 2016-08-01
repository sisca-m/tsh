#include <stdio.h>
#include "list_design.h"

void		_list_basic_print(size_t i, Object *elem, const char *prefix)
{
  t_list_data	*list;

  list = elem;
  printf("%s%ul)cur [%s] prev [%s] next [%s]\n",
	 prefix, (unsigned int)i, (char *)list->data,
	 (list->prev ? (char *)list->prev->data : "prev null"),
	 (list->next ? (char *)list->next->data : "next null"));
}

void		_list_print(Object *container, const char *title,
			    void (*f)(size_t i, Object *elem,
				      const char *prefix),
			    const char *prefix)
{
  t_list_data	*begin;
  t_list_data	*list;
  char		*concat_prefix;
  size_t	i;

  list = (t_list_data *)((t_container *)container)->contained;
  if (!(concat_prefix = concat(prefix, "  ")))
    return ;
  if (title)
    printf("%s%s\n", prefix, title);
  begin = list;
  i = 0;
  do
    {
      if (list)
	{
	  f(i, list, concat_prefix);
	  list = list->next;
	  ++i;
	}
    }
  while (list && list != begin);
  list = begin;
  free(concat_prefix);
}
