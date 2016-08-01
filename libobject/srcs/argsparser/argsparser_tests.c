#include <string.h>
#include "argsparser_design.h"

t_bool	_is_positionnal(t_opt *opt)
{
  return (!strcmp(opt->prefix, "") && !strcmp(opt->opt, "") ? TRUE : FALSE);
}

t_bool	_is_kwarg(t_opt *opt)
{
  return (strcmp(opt->prefix, "") || strcmp(opt->opt, "") ? TRUE : FALSE);
}

t_bool	_opt_match(t_opt *opt, const char *arg)
{
  if (opt->compound == TRUE)
    if (!strncmp(opt->prefix, arg, strlen(opt->prefix)) &&
	!strncmp(opt->opt, &arg[strlen(opt->prefix)], strlen(opt->opt)) &&
	arg[strlen(opt->prefix) + strlen(opt->opt)] == '=')
      return (TRUE);
  if (opt->compound == FALSE)
    if (!strncmp(opt->prefix, arg, strlen(opt->prefix)) &&
	!strncmp(opt->opt, &arg[strlen(opt->prefix)], strlen(opt->opt)) &&
	arg[strlen(opt->prefix) + strlen(opt->opt)] == '\0')
      return (TRUE);
  return (FALSE);
}

t_pair		*_get_kwarg(t_argsparser *p, const char *arg)
{
  t_pair	**opts_pairs;
  t_container	*opts_dict;
  t_opt		*cur_opt;
  size_t	i;

  opts_dict = (t_container *)p->opts;
  if (!(opts_pairs = opts_dict->data(opts_dict)))
    return (NULL);
  i = 0;
  while (opts_pairs[i])
    {
      cur_opt = opts_pairs[i]->data;
      if (cur_opt->is_kwarg(cur_opt) == TRUE &&
	  cur_opt->match(cur_opt, arg) == TRUE)
	return (opts_pairs[i]);
      ++i;
    }
  return (NULL);
}

t_pair		*_next_positionnal(t_argsparser *p)
{
  t_pair	**opts_pairs;
  t_container	*opts_dict;
  t_opt		*cur_opt;
  size_t	i;
  size_t	i_pos;

  opts_dict = (t_container *)p->opts;
  if (!(opts_pairs = opts_dict->data(opts_dict)))
    return (NULL);
  i = i_pos = 0;
  while (opts_pairs[i] && (cur_opt = opts_pairs[i]->data))
    {
      if (cur_opt->is_positionnal(cur_opt) == TRUE)
	{
	  ++i_pos;
	  if (i_pos == p->i_positionnal)
	    {
	      p->i_positionnal += i_pos == p->i_positionnal ? 1 : 0;
	      return (opts_pairs[i]);
	    }
	}
      ++i;
    }
  return (NULL);
}
