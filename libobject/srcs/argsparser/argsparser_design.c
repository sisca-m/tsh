#include "argsparser_design.h"

static int	_argsparser_ctor(Object *self, va_list *args)
{
  t_argsparser	*parser;

  parser = self;
  parser->args = va_arg(*args, char **);
  if ((parser->opts = new(_dict)) == FALSE)
    return (FALSE);
  return (TRUE);
}

static void	_argsparser_dtor(Object *self, va_list *args)
{
  t_argsparser	*parser;

  parser = self;
  delete((void **)&parser->args);
  (void)args;
}

static int	_opt_ctor(Object *self, va_list *args)
{
  t_opt		*opt;
  t_argsparser	*parser;
  char		*basename;

  opt = self;
  if (!(parser = va_arg(*args, t_argsparser *)))
    return (FALSE);
  basename = va_arg(*args, char *);
  opt->help = va_arg(*args, char *);
  opt->prefix = va_arg(*args, char *);
  opt->opt = va_arg(*args, char *);
  opt->vdefault = va_arg(*args, char *);
  opt->nargs = va_arg(*args, int);
  opt->nb_repet = va_arg(*args, int);
  opt->optionnal = va_arg(*args, int);
  opt->compound = va_arg(*args, int);
  if (parser->opts->push_back(parser->opts, basename, opt) == FALSE)
    return (FALSE);
  return (TRUE);
}

static void	_opt_dtor(Object *self, va_list *args)
{
  (void)self;
  (void)args;
}

static t_argsparser _argsparser_descr =
  {
    {
      sizeof(t_argsparser),
      "Argsparser",
      &_argsparser_ctor,
      &_argsparser_dtor
    },
    NULL,
    NULL,
    1,
    1,
    &_add_opt,
    &_parse_args,
    &_get_kwarg,
    &_next_positionnal,
    &_set_defaults
  };

static t_opt _opt_descr =
  {
    {
      sizeof(t_opt),
      "Opt",
      &_opt_ctor,
      &_opt_dtor
    },
    NULL,
    NULL,
    NULL,
    NULL,
    0,
    0,
    FALSE,
    FALSE,
    &_is_positionnal,
    &_is_kwarg,
    &_opt_match,
    &_consume_args
  };

Class    *_argsparser = (Class *)&_argsparser_descr;
Class    *_opt = (Class *)&_opt_descr;
