#include "tsh.h"

static void    print_varenv(size_t i, Object *elem, const char *prefix)
{
  printf("%s%zd: [%s=%s]\n", prefix, i, ((t_pair *)elem)->key, ((t_pair *)elem)->data);
}

t_bool	builtin_env(void)
{
  ((t_container *)sh->env)->dump(sh->env, "Env", &print_varenv, "");
  return (TRUE);
}

t_bool	wrapper_builtin_env(char **args)
{
  (void)args;
  return (builtin_env());
}
