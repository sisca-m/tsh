#ifndef NEW_H_
# define NEW_H_

# include <stdarg.h>
# include "object.h"

void	*new(Class *class, ...);
void	static_new(Object *new, Class *class, ...);
void	delete(Object *ptr, ...);

#endif /* !NEW_H_ */
