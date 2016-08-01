#include "tsh.h"

t_shell	*sh = NULL;

int		main(int ac, char **av, char **env)
{
  t_shell	*_sh;
  char		*path_to_bin;

  if (!(_sh = new(_shell, env)))
    return (1);
  sh = _sh;
  path_to_bin = fetch_path("ls", "PATH", ":");
  printf("[%s]\n", path_to_bin);
  printf("[%s]", sh->stdin->getline(sh->stdin));
  fflush(stdin);
  delete(sh);
  (void)ac;
  (void)av;
  return (0);
}
