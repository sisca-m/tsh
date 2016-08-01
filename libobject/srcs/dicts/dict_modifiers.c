#include <stdlib.h>
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
