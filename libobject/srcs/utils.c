#include <stdlib.h>
#include <string.h>
#include "object.h"
#include "utils.h"
#include "new.h"

t_bool	typecmp(const Object *self, const char *name)
{
  return (!strcmp(((Class *)self)->__name__, name) ? TRUE : FALSE);
}

void		release_newed_ctn(t_container **ctn)
{
  size_t	i;
  Class		**data;

  if (!*ctn)
    return ;
  if ((data = (*ctn)->data(*ctn)))
    {
      i = 0;
      while (i < (*ctn)->size(*ctn))
	{
	  delete((void **)&data[i]);
	  ++i;
	}
    }
  delete((void **)ctn);
}

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
