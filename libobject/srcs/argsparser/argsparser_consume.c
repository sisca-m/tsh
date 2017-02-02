#include "argsparser_design.h"

static char	*extract_arg(t_opt *opt, int i, char *arg)
{
  return (opt->compound == TRUE && i == 0 ? strchr(arg, '=') + 1 : arg);
}

static t_container	*case_all(t_opt *opt, t_argsparser *p,
				  t_container *existent)
{
  t_container	*ctn;
  int		i;

  i = 0;
  if (!(ctn = !existent ? new(_array, NULL, 0) : existent))
    return (NULL);
  while (p->args[p->i + i] && !p->get_kwarg(p, p->args[p->i + i]))
    {
      if (ctn->push_back(ctn, extract_arg(opt, i, p->args[p->i + i])) == FALSE)
	return (NULL);
      ++i;
    }
  p->i += i;
  if (opt->nargs == ALL_AT_LEAST_ONE && i < 1)
    {
      fprintf(stderr, "%s%s: at least 1 argument required, %d given\n",
	      opt->prefix, opt->opt, i);
      return (NULL);
    }
  return (ctn);
}

static t_container	*case_one_optionnal(t_opt *opt, t_argsparser *p,
					    t_container *existent)
{
  t_container	*ctn;

  if (!(ctn = !existent ? new(_array, NULL, 0) : existent))
    return (NULL);
  if (p->args[p->i])
    if (ctn->push_back(ctn, extract_arg(opt, 0, p->args[p->i])) == FALSE)
      return (NULL);
  if (opt->compound == TRUE)
    ++p->i;
  return (ctn);
}

static t_container	*case_normal(t_opt *opt, t_argsparser *p,
				     t_container *existent)
{
  t_container	*ctn;
  int		i;

  i = 0;
  if (!(ctn = !existent ? new(_array, NULL, 0) : existent))
    return (NULL);
  while (i < opt->nargs && p->args[p->i + i])
    {
      if (ctn->push_back(ctn, extract_arg(opt, i, p->args[p->i + i])) == FALSE)
	return (NULL);
      ++i;
    }
  p->i += i;
  if (i < opt->nargs)
    {
      fprintf(stderr, "%d arguments required, %d given.\n", opt->nargs, i);
      return (NULL);
    }
  return (ctn);
}

t_container	*_consume_args(t_opt *opt, t_argsparser *parser, t_container *ctn)
{
  if (opt->compound == FALSE)
    ++parser->i;
  if (opt->nargs == ONE_OPTIONNAL)
    return (case_one_optionnal(opt, parser, ctn));
  else if (opt->nargs == ALL_PRESENTS)
    return (case_all(opt, parser, ctn));
  else if (opt->nargs == ALL_AT_LEAST_ONE)
    return (case_all(opt, parser, ctn));
  else
    return (case_normal(opt, parser, ctn));
  return (NULL);
}
