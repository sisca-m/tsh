#ifndef FTSH_H_
# define FTSH_H_

# include "lobject.h"

typedef struct {
  t_container	*env;
} t_app;

t_app	app;

char	*dynamic_getenv(const char *var);
char	**explode_path(const char *path);

#endif /* FTSH_H_ */
