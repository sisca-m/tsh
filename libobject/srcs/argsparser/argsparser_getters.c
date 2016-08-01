#include "argsparser_design.h"

Object		*nth_arg(dict *args, const char *basename, size_t n)
{
  t_container	*ctn;

  if (!args || !(ctn = args->get_by_key(args, basename)))
    return (NULL);
  return (ctn->at(ctn, n));
}
