#include "tsh.h"

char	*dynamic_getenv(const char *var)
{
  return (sh->env->get_by_key(sh->env, var));
}
