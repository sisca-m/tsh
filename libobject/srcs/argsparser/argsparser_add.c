#include "argsparser_design.h"

t_bool		_add_opt(t_argsparser *parser, ...)
{
  va_list	args;
  char		*a, *b, *c, *d, *e;
  int		f, g, h, i;

  if (!parser)
    return (FALSE);
  va_start(args, parser);
  a = va_arg(args, char *);
  b = va_arg(args, char *);
  c = va_arg(args, char *);
  d = va_arg(args, char *);
  e = va_arg(args, char *);
  f = va_arg(args, int);
  g = va_arg(args, int);
  h = va_arg(args, int);
  i = va_arg(args, int);
  va_end(args);
  new(_opt, parser, a, b, c, d, e, f, g, h, i);
  return (TRUE);
}
