#include "dict_design.h"

t_bool		_dict_push_back(Object *self, char *key, void *data)
{
  t_container	*self_c;
  t_pair	*pair;

  self_c = self;
  if (!(pair = malloc(1 * sizeof(*pair))))
    return (FALSE);
  pair->key = key;
  pair->data = data;
  return (self_c->insertAt(self_c, pair, self_c->contained_size));
}

t_bool		_del_by_key(Object *self, const char *key)
{
  t_container	*dict;
  t_pair	**pairs;
  size_t	i;

  dict = self;
  if (!(pairs = dict->data(dict)))
    return (FALSE);
  i = 0;
  while (i < dict->contained_size)
    {
      if (!strcmp(pairs[i]->key, key))
	return (dict->deleteAt(dict, i));
      ++i;
    }
  return (FALSE);
}
