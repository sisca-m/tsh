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
  delete(sh);

  printf("toto\n");
  t_container      *string = new(_string, "filename.c", 0);

  t_container *substring = string->sub(string, _array, -2, 5); // Returns ".c"
  substring->dump(substring, "affiche c chien d'infidèle", _string_basic_print, "");
  string->sub(string, _array, 3, 4); // Returns "enam"

  string = substring->convert(substring, _string);
  string->dump(string, "converted array to string: .c", _string_basic_print, "");
  (void)ac;
  (void)av;
  return (0);
}
