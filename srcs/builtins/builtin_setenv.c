#include "tsh.h"

t_bool	builtin_setenv(char **args)
{
  dict	*new_env;

  if (!(new_env = new((Class *)sh->env, args, COPY_ALL, 0)))
    return (FALSE);
  delete(sh->env);
  sh->env = new_env;
  return (TRUE);
}

t_bool	wrapper_builtin_setenv(char **args)
{
  return (builtin_setenv(args));
}
