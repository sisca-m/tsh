#include "tsh.h"

static t_container	*splited_path(const char *path, const char *sep)
{
  t_container	*splited;
  t_String	*str;

  if ((str = new(_string, path, 0)) == NULL)
    return (NULL);
  splited = str->split(str, _array, sep);
  delete(str);
  return (splited);
}

static char	*build_bin(const char *bin, const char *extract)
{
  char		*full_bin_path;

  if (strlen(extract) > 0 && extract[strlen(extract) - 1] == '/')
    full_bin_path = concat(extract, bin);
  else if (strlen(extract) > 0)
    asprintf(&full_bin_path, "%s/%s", extract, bin);
  else
    full_bin_path = str_dup(bin);
  return (full_bin_path);
}

char	*fetch_path(const char *bin, const char *path_var, const char *sep)
{
  t_container	*splited_path_ctn;
  char		**dirs_in_path;
  char		*path_to_bin;
  size_t	i;

  path_to_bin = NULL;
  splited_path_ctn = splited_path(dynamic_getenv(path_var), sep);

  if (!splited_path_ctn)
    return (NULL);

  i = 0;
  dirs_in_path = splited_path_ctn->data(splited_path_ctn);
  while (dirs_in_path[i])
    {
      if ((path_to_bin = build_bin(bin, dirs_in_path[i])) && !access(path_to_bin, X_OK))
	break;
      free(path_to_bin);
      path_to_bin = NULL;
      ++i;
    }
  delete(splited_path_ctn);
  return (path_to_bin);
}
