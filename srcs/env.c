#include <stdio.h>
#include <string.h>
#include "ftsh.h"

char		*dynamic_getenv(const char *var)
{
  size_t	i;
  char		**env;

  i = 0;
  env = app.env->data(app.env);
  if (env)
    while (env[i] != NULL)
      {
	if (!strncmp(env[i], var, strlen(var)))
	  break ;
	++i;
      }
  return (env && env[i] ? &env[i][strlen(var) + 1] : NULL);
}
