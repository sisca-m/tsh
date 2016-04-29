#include "tsh.h"

char	*concat(const char *dest, const char *src)
{
  char		*res;
  size_t	i;
  size_t	j;

  i = j = 0;
  if ((res = calloc(strlen(dest) + strlen(src) + 1, sizeof(char))) == NULL)
    return (NULL);
  while (dest[i] != '\0')
    {
      res[i] = dest[i];
      ++i;
    }
  while (src[j] != '\0')
    res[i++] = src[j++];
  return (res);
}

