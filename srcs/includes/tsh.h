#ifndef FTSH_H_
# define FTSH_H_

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include "lobject.h"

typedef struct {
  t_container	*env;
} t_app;

t_app	app;

char	*dynamic_getenv(const char *var);
char	*fetch_path(const char *bin, const char *path_var, const char *sep);

#endif /* FTSH_H_ */
