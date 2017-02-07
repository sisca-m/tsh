#ifndef UTILS_H_
# define UTILS_H_

# include "container_design.h"
# include "bool.h"

char	*str_dup(const char *str);
t_bool	typecmp(const Object *self, const char *name);
void	release_newed_ctn(t_container **ctn);
char	*concat(const char *dest, const char *src);

#endif /* !UTILS_H_ */
