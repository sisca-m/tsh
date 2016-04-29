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

static char	*is_bin_found(const char *bin, const char *extract)
{
  char		*full_bin_path;

  if (strlen(extract) > 0 && extract[strlen(extract) - 1] == '/')
    full_bin_path = concat(extract, bin);
  else if (strlen(extract) > 0)
    {
      /* Leak to fix */
      full_bin_path = concat(extract, "/");
      full_bin_path = concat(full_bin_path, bin); 
    }
  else
    full_bin_path = str_dup(bin);
  printf("concat: [%s]\n", full_bin_path);
  return (full_bin_path);
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
      if ((path_to_bin = is_bin_found(bin, splited_var[i])) &&
	  !access(path_to_bin, X_OK))
	return (path_to_bin);
      free(path_to_bin);
      path_to_bin = NULL;
      ++i;
    }
  delete(splited_ctn);
  return (NULL);
}
