#include "string_design.h"

static int	nmatch(const char *s1, const char *s2)
{
  if (*s1 != '\0' && *s2 == '*')
    return (nmatch(s1 + 1, s2) + nmatch(s1, s2 + 1));
  if (*s1 == '\0' && *s2 == '*')
    return (nmatch(s1, s2 + 1));
  if (*s1 == *s2 && *s1 != '\0' && s2 != '\0')
    return (nmatch(s1 + 1, s2 + 1));
  if (*s1 == *s2 && *s1 == '\0' && *s2 == '\0')
    return (1);
  return (0);
}

t_bool	_string_match(Object *self, char *compare)
{
  return (nmatch(((t_container *)self)->contained, compare) ? TRUE : FALSE);
}

int	_string_nmatch(Object *self, char *compare)
{
  return (nmatch(((t_container *)self)->contained, compare));
}
