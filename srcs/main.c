#include "tsh.h"

t_shell	*sh = NULL;

int		main(int ac, char **av, char **env)
{
  char		*path_to_bin;
  filestream	*fs;

  fs = new(_filestream, "toto.txt", "r");
  char *s = NULL;
  while ((s= fs->getline(fs)))
    {
      printf("%s\n", s);
    }
  if (!(sh = new(_shell, env)))
    return (1);
  path_to_bin = fetch_path("ls", "PATH", ":");
  printf("[%s]\n", path_to_bin);
  free(path_to_bin);
  builtin_unsetenv((char *[]){"_", "SECURITYSESSIONID", NULL});
  printf("after unsetenv\n");
  builtin_env();
  sh->in = sh->stdin->getline(sh->stdin);
  if (sh->in)
    printf("[%s]\n", sh->in);
  delete(sh);

  (void)ac;
  (void)av;
  return (0);
}
