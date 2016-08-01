#include <stdlib.h>
#include <string.h>
#include "new.h"
#include "string_design.h"

Object		*_string_dup(Object *self)
{
  t_container	*string;

  if ((string = new(_string, 0)))
  string->affect(string, ((t_container *)self)->contained);
  return (string);
}

Object		*_string_split(Object *self, Class *type, const char *sep)
{
  t_container	*container;
  char		*token;

  if (!(container = new(type, NULL, 0)))
    return (NULL);
  token = strtok((char *)((t_container *)self)->contained, sep);
  while (token)
    {
      container->push_back(container, token);
      token = strtok(NULL, sep);
    }
  return (container);
}
