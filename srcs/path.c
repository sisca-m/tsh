#include "tsh.h"

static t_container	*splited_path(const char *path, const char *sep)
{
  t_container	*splited;
  t_String	*str;

  if ((str = new(_string, path, 0)) == NULL)
    return (NULL);
  splited = str->split(str, _array, sep);
  return (splited);
}

char	*fetch_path(const char *bin, const char *path_var, const char *sep)
{
  t_container	*splited_ctn;
  char		**splited_var;
  char		*path_to_bin;
  size_t	i;

  splited_ctn = splited_path(dynamic_getenv(path_var), sep);
  i = 0;
  if (!splited_ctn)
    return (NULL);
  splited_var = splited_ctn->data(splited_ctn);
  while (splited_var[i])
    {
      if (!access(splited_var[i], X_OK))
	{
	  printf("in func: [%s] [%s]\n", bin, splited_var[i]);
	  break;
	}
      ++i;
    }
  path_to_bin = str_dup(splited_var[i]);
  delete(splited_ctn);
  return (path_to_bin);
}
