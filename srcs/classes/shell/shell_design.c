#include "shell_design.h"

static int	_shell_ctor(Object *self, va_list *args)
{
  t_shell	*shell;
  t_String	*string;
  t_container	*splited_var;
  char		**env;
  size_t	i;

  shell = self;
  if (!(shell->env = new(_dict, NULL, 0)))
    return (FALSE);
  env = va_arg(*args, char **);
  i = 0;
  while (env[i])
    {
      if (!(string = new(_string, env[i], 0)))
	return (FALSE);
      if (!(splited_var = string->split(string, _array, "=")))
	return (FALSE);
      shell->env->push_back(shell->env,
			    splited_var->at(splited_var, 0),
			    splited_var->at(splited_var, 1));
      delete(splited_var);
      delete(string);
      ++i;
    }
  shell->stdin = new(_filestream, stdin, NO_OPEN);
  shell->stdout = new(_filestream, stdout, NO_OPEN);
  shell->stderr = new(_filestream, stderr, NO_OPEN);
  shell->in = NULL;
  return (TRUE);
}

static void	_shell_dtor(Object *self, va_list *args)
{
  t_shell	*shell;

  shell = self;
  delete(shell->env);
  (void)args;
}

static t_shell _shell_descr =
  {
    {
      sizeof(t_shell),
      "Shell",
      &_shell_ctor,
      &_shell_dtor
    },
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
  };

Class	*_shell = (Class *)&_shell_descr;
