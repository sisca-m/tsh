#ifndef ARGSPARSER_DESIGN_H_
# define ARGSPARSER_DESIGN_H_

/**
 * \file
 */

# include "object.h"
# include "container_design.h"
# include "array_design.h"
# include "dict_design.h"
# include "new.h"

/*
** nargs defines
** ?
** *
** +
*/
# define ONE_OPTIONNAL		-1
# define ALL_PRESENTS		-2
# define ALL_AT_LEAST_ONE	-3

/*
** nb_repet including aliases
** aliases not in excluded
** required with arguments
*/
typedef struct s_opt	t_opt;

typedef t_bool	(*t_test_arg)(t_opt *opt);
t_bool		_is_positionnal(t_opt *opt);
t_bool		_is_kwarg(t_opt *opt);

typedef t_bool	(*t_opt_match)(t_opt *opt, const char *arg);
t_bool		_opt_match(t_opt *opt, const char *arg);

typedef t_container	*(*t_arg_consume)(t_opt *opt, t_argsparser *p,
					  t_container *ctn);
t_container		*_consume_args(t_opt *opt, t_argsparser *p,
				       t_container *ctn);

# define NO_REPET	0
struct		s_opt {
  /**
   * @brief Struct that contains info about one option.
   */
  Class		base;
  char		*help;
  char		*prefix;
  char		*opt;
  char		*vdefault;
  int		nargs;
  int		nb_repet;
  t_bool	optionnal;
  t_bool	compound;
  t_test_arg	is_positionnal;
  t_test_arg	is_kwarg;
  t_opt_match	match;
  t_arg_consume	consume;
};

/**
 * @brief Argsparse class
 *
 * Inherits of the #t_container class.
 * The value contained in t_container#contained for the Array class is
 * a void ** which represents a table of whatever type.
 */
typedef t_bool	(*t_add_opt)(t_argsparser *parser, ...);
t_bool		_add_opt(t_argsparser *parser, ...);

typedef dict	*(*t_parse_args)(t_argsparser *parser);
dict		*_parse_args(t_argsparser *parser);

typedef t_pair	*(*t_kwarg)(t_argsparser *p, const char *arg);
t_pair		*_get_kwarg(t_argsparser *p, const char *arg);

typedef t_pair	*(*t_pos)(t_argsparser *p);
t_pair		*_next_positionnal(t_argsparser *p);

typedef int	(*t_set_defaults)(t_argsparser *p, dict *res);
int		_set_defaults(t_argsparser *p, dict *res);

struct			s_argsparser {
  /**
   * @brief Contains informations about the arguments to parse.
   */
  Class			base;
  dict			*opts;
  char			**args;
  size_t		i;
  size_t		i_positionnal;
  t_add_opt		add_opt;
  t_parse_args		parse;
  t_kwarg		get_kwarg;
  t_pos			next_positionnal;
  t_set_defaults	set_defaults;
};

void	opt_print(size_t i, Object *elem);

Object	*nth_arg(dict *args, const char *basename, size_t n);

/**
 * @brief argsparser and opt description variable
 */
extern Class	*_argsparser;
extern Class	*_opt;

#endif /* !ARGSPARSER_DESIGN_H_ */
