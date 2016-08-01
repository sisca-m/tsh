#include <stdlib.h>
#include <string.h>

/*
** -ansi removes the system strdup
*/
char	*str_dup(const char *str)
{
  char	*res;

  if (!str)
    return (NULL);
  if (!(res = calloc(strlen(str) + 1, sizeof(char))) || !str)
    return (NULL);
  memcpy(res, str, strlen(str));
  return (res);
}
