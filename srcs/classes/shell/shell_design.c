#include "shell_design.h"

static int	_shell_ctor(Object *self, va_list *args)
{
  t_shell	*sh;

  sh = self;
  if (!(sh->env = new(_array, va_arg(*args, char **), 0, 0)))
    return (FALSE);
  sh->stdin = new(_filestream, stdin, NO_OPEN);
  sh->stdout = new(_filestream, stdout, NO_OPEN);
  sh->stderr = new(_filestream, stderr, NO_OPEN);
  sh->in = NULL;
  return (TRUE);
}

static void	_shell_dtor(Object *self, va_list *args)
{
  delete(((t_shell *)self)->env);
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
