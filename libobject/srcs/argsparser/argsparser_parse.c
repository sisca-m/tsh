#include "argsparser_design.h"

static t_bool	required_are_presents(t_argsparser *p, dict *d)
{
  t_pair	**opts_pairs;
  size_t	i;
  t_bool	required_found;

  required_found = TRUE;
  if (!(opts_pairs = ((t_container *)p->opts)->data(p->opts)))
    return (TRUE);
  i = 0;
  while (opts_pairs[i])
    {
      if (((t_opt *)opts_pairs[i]->data)->optionnal == MANDATORY_OPT &&
	  !(d->get_by_key(d, opts_pairs[i]->key)))
	{
	  required_found = FALSE;
	  fprintf(stderr, "%s is required.\n", opts_pairs[i]->key);
	}
      ++i;
    }
  return (required_found);
}

static t_pair	*get_valid_opt(t_argsparser *p)
{
  t_pair	*opt_pair;

  if (!(opt_pair = p->get_kwarg(p, p->args[p->i])))
    if (!(opt_pair = p->next_positionnal(p)))
      {
	fprintf(stderr, "parse error <%s>\n", p->args[p->i]);
	return (NULL);
      }
  return (opt_pair);
}

t_bool		_set_defaults(t_argsparser *p, dict *res)
{
  t_pair	**opts_pairs;
  t_container	*ctn;
  size_t	i;

  if (!(opts_pairs = ((t_container *)p->opts)->data(p->opts)))
    return (TRUE);
  i = 0;
  while (opts_pairs[i])
    {
      if (!res->get_by_key(res, opts_pairs[i]->key))
	{
	  if (!(ctn = new(_array, NULL, 1, ((t_opt *)opts_pairs[i]->data)->vdefault)))
	    return (FALSE);
	  if (res->push_back(res, opts_pairs[i]->key, ctn) == FALSE)
	    return (FALSE);
	}
      ++i;
    }
  return (TRUE);
}

dict		*_parse_args(t_argsparser *p)
{
  dict		*res;
  t_pair	*opt_pair;
  t_opt		*opt;
  t_container	*ctn;

  if (!(res = new(_dict)))
    return (NULL);
  while (p->args[p->i])
    {
      if (!(opt_pair = get_valid_opt(p)))
	return (NULL);
      opt = opt_pair->data;
      if (!(ctn = opt->consume(opt, p, res->get_by_key(res, opt_pair->key))))
	return (NULL);
      if (res->push_back(res, opt_pair->key, ctn) == FALSE)
	return (NULL);
    }
  if (required_are_presents(p, res) == FALSE)
    return (NULL);
  if (p->set_defaults(p, res) == FALSE)
    return (NULL);
  return (res);
}
