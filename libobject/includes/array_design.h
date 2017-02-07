#ifndef ARRAY_DESIGN_H_
# define ARRAY_DESIGN_H_

# include <stdio.h>
# include <stdlib.h>
# include "container_design.h"

/**
 * Macro telling to fully copy the ptr** given to the constructor
 * @code
 * t_array = new(_array, (char *[]){"toto", "titi", NULL}, COPY_ALL, 0);
 * @code
 */
# define COPY_ALL	0

/**
 * @class Array class
 *
 * Inherits of the container class.
 * The value contained in t_container.contained is a void ** which represents a table of any type.
 *
 * @field base
 * The base class is a container, the fact that containers inherit of the t_class allow us to do that.
 */
struct		s_Array {
  t_container	base;
};

extern Class	*_array;

/**
 * Refer to container_design.h to see which methods the following functions implement.
 */
int	_array_insert_at(Object *self, void *data, int pos);
int	_array_delete_at(Object *self, int pos);
int	_array_erase(Object *self);

void	_array_print(Object *self, const char *title,
		     void (*f)(size_t i, Object *elem, const char *prefix),
		     const char *prefix);
void	array_basic_print(size_t i, Object *elem, const char *prefix);

Object	*_array_front(Object *self);
Object	*_array_back(Object *self);
Object	*_array_at(Object *self, size_t pos);

#endif /* !ARRAY_DESIGN_H_ */
