#ifndef TSH_H_
# define TSH_H_

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include "lobject.h"
# include "shell_design.h"
# include "builtin.h"

extern t_shell	*sh;

char	*dynamic_getenv(const char *var);
char	*fetch_path(const char *bin, const char *path_var, const char *sep);

char	*concat(const char *dest, const char *src);

#endif /* TSH_H_ */
