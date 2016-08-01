#include <string.h>
#include "dict_design.h"

Object		*_get_obj_by_key(Object *dict_obj, const char *key)
{
  t_container	*dict;
  t_pair	**pairs;
  size_t	i;

  dict = dict_obj;
  if (!(pairs = dict->data(dict)))
    return (NULL);
  i = 0;
  while (i < dict->contained_size)
    {
      if (!strcmp(pairs[i]->key, key))
	return (pairs[i]->data);
      ++i;
    }
  return (NULL);
}
