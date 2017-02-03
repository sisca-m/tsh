#include "tsh.h"

t_bool	builtin_unsetenv(char **args)
{
  size_t	i;

  i = 0;
  while (args[i])
    {
      if (sh->env->del_by_key(sh->env, args[i]) == FALSE)
        fprintf(stderr, "Unsetenv: Cannot delete invalid key %s\n", args[i]);
      ++i;
    }
  return (TRUE);
}


t_bool	wrapper_builtin_unsetenv(char **args)
{
  return (builtin_unsetenv(args));
}
