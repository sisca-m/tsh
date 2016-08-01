#include <string.h>
#include "string_design.h"

size_t	_string_findstr(Object *self, char *substr)
{
  char	*res;

  res = strstr((char *)((t_container *)self)->contained, substr);
  return (res ? ((t_container *)self)->contained_size - (strlen(res) - 1) : 0);
}

size_t	_string_find(Object *self, int c)
{
  char	*res;

  res = strchr((char *)((t_container *)self)->contained, c);
  return (res ? ((t_container *)self)->contained_size - (strlen(res) - 1) : 0);
  return (0);
}

size_t	_string_lfind(Object *self, int c)
{
  char	*res;

  res = strrchr((char *)((t_container *)self)->contained, c);
  return (res ? ((t_container *)self)->contained_size - (strlen(res) - 1) : 0);
}
