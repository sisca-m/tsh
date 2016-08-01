#include "tsh.h"

char		*dynamic_getenv(const char *var)
{
  size_t	i;
  char		**env;

  i = 0;
  env = sh->env->data(sh->env);
  if (env)
    while (env[i] != NULL)
      {
	if (!strncmp(env[i], var, strlen(var)) && env[i][strlen(var)] == '=')
	  break ;
	++i;
      }
  return (env && env[i] ? &env[i][strlen(var) + 1] : NULL);
}
