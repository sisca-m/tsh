#ifndef ARGSPARSER_DESIGN_H_
# define ARGSPARSER_DESIGN_H_

# include <stdio.h>
# include <string.h>
# include "object.h"
# include "container_design.h"
# include "array_design.h"
# include "dict_design.h"
# include "new.h"

/**
 * @typedef Argparser class;
 */
typedef struct s_argsparser	t_argsparser;

/**
 * @typedef Option class;
 */
typedef struct s_opt	t_opt;

/**
 * nargs defines
 * ?: There could be 1 or 0 arguments to the option
 * *: All the following tokens are arguments to the option
 * +: Same as * but if there isn't at least 1 argument the parsing will fail
 */
# define ONE_OPTIONNAL		-1
# define ALL_PRESENTS		-2
# define ALL_AT_LEAST_ONE	-3

/**
 * Use for readability reasons when an option shouldn't be repeated
 */
# define NO_REPET	0

/**
 * Optional / mandatory option defines
 */
# define OPTIONAL_OPT	TRUE
# define MANDATORY_OPT	FALSE

/**
 * Compound / separate option defines
 */
# define COMPOUND	TRUE
# define SEPARATE	FALSE

/**
 * @brief Function pointer which represents a member function testing if an option matches some critera.
 *
 * @param opt The tested option.
 *
 * @return TRUE if the test succeeds, FALSE otherwise
 */
typedef t_bool	(*t_test_arg)(t_opt *opt);
t_bool		_is_positionnal(t_opt *opt);
t_bool		_is_kwarg(t_opt *opt);

/**
 * @brief Function pointer which represents a member function testing if an argument matches an option, prefix, compound are included in the test.
 *
 * @param opt The tested option.
 * @param opt The argument coming from the char ** provided to the argsparser.
 *
 * @return TRUE if the test succeeds, FALSE otherwise
 */
typedef t_bool	(*t_opt_match)(t_opt *opt, const char *arg);
t_bool		_opt_match(t_opt *opt, const char *arg);

/**
 * @brief Function pointer which represents a member function getting the argument(s) of an given option.
 *
 * @param opt The option to which the arguments belong to.
 * @param parser The argsparser.
 * @param ctn The container storing already existing argument(s) extracted from the stream; null if the option has not been seen already.
 *
 * @return The container storing the option arguments
 */
typedef t_container	*(*t_arg_consume)(t_opt *opt, t_argsparser *p,
					  t_container *ctn);
t_container		*_consume_args(t_opt *opt, t_argsparser *p,
				       t_container *ctn);

struct		s_opt {
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
 * @brief Argsparse methods and class
 */

/**
 * @brief Method adding an option to an argsparser
 *
 * @param parser The argsparser which the option is added to
 * @param basename The internal identifier of the option
 * @param help A string describing the purpose of the option
 * @param prefix The prefix of the option, usually a simple dash -
 * @param opt The external identifier for the option
 * @param vdefault The default value for the option, NULL if no default value should be set
 * @param nargs The number of arguments the option has
 * @param nb_repet The number of repetitions of the option
 * @param optional OPTIONAL_OPT if the option is optional, MANDATORY_OPT if not
 * @param compound COMPOUND if the option follows the form opt=value instead of opt [args]... , SEPARATE otherwise
 *
 * @return TRUE if the option has been added successfully, FALSE otherwise
 */
typedef t_bool	(*t_add_opt)(t_argsparser *parser, char *basename, char *help, char *prefix, char *opt, char *vdefault, int nargs, int nb_repet, int optional, int compound);
t_bool		_add_opt(t_argsparser *parser, char *basename, char *help, char *prefix, char *opt, char *vdefault, int nargs, int nb_repet, int optional, int compound);

/**
 * @brief Argsparse methods
 */

/**
 * @brief Method used to parse the options and arguments from the data given to the argsparser constructor
 *
 * @param parser The argsparser
 * @return A dict containing where the the keys are the basename of the options and the datas the arguments
 */
typedef dict	*(*t_parse_args)(t_argsparser *parser);
dict		*_parse_args(t_argsparser *parser);

/**
 * @brief Method used to get the next keyword argument
 *
 * @param parser The argsparser
 * @param arg The basename of the kwarg
 * @return A pair key value where key is the basename of the kwarg and data the arguments
 */
typedef t_pair	*(*t_kwarg)(t_argsparser *p, const char *arg);
t_pair		*_get_kwarg(t_argsparser *p, const char *arg);

/**
 * @brief Method used to get the next positional option
 *
 * @param parser The argsparser
 * @return A pair key value where key is the basename of the positional option and data the arguments
 */
typedef t_pair	*(*t_pos)(t_argsparser *p);
t_pair		*_next_positionnal(t_argsparser *p);

/**
 * @brief Method used to set the default values of the options added to a parser
 *
 * @param parser The argsparser
 * @return TRUE if success, FALSE otherwise
 */
typedef t_bool	(*t_set_defaults)(t_argsparser *p, dict *res);
t_bool		_set_defaults(t_argsparser *p, dict *res);

struct			s_argsparser {
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

/**
 * @brief Function used with the dump method of the argsparser (an upcast to container is needed) to dump the parser and its options
 */
void	opt_print(size_t i, Object *elem);

/**
 * @brief Function used to retrieve the nth argument from a dict returned by parse_args method
 */
Object	*nth_arg(dict *args, const char *basename, size_t n);

/**
 * @brief argsparser and opt description variable
 */
extern Class	*_argsparser;
extern Class	*_opt;

#endif /* !ARGSPARSER_DESIGN_H_ */
