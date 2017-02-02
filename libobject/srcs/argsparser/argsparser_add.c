#include "argsparser_design.h"

t_bool		_add_opt(t_argsparser *parser, char *basename, char *help, char *prefix, char *opt, char *vdefault, int nargs, int nb_repet, int optional, int compound)
{
  if (!parser)
    return (FALSE);
  new(_opt, parser, basename, help, prefix, opt, vdefault, nargs, nb_repet, optional, compound);
  return (TRUE);
}
