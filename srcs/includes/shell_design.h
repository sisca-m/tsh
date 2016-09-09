#ifndef SHELL_DESIGN_H_
# define SHELL_DESIGN_H_

# include <stdio.h>
# include "lobject.h"

typedef struct	s_shell {
  Class		base;
  dict		*env;
  filestream   	*stdin;
  filestream	*stdout;
  filestream   	*stderr;
  char		*in;
}		t_shell;

extern Class	*_shell;

#endif /* !SHELL_DESIGN_H_ */
