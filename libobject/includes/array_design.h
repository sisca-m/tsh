#ifndef ARRAY_DESIGN_H_
# define ARRAY_DESIGN_H_

# include <stdio.h>
# include <stdlib.h>
# include "object.h"
# include "container_design.h"
# include "list_design.h"

# define COPY_ALL	0

/**
 * @brief Array class
 *
 * Inherits of the #t_container class.
 * The value contained in t_container#contained for the Array class is
 * a void ** which represents a table of whatever type.
 */
struct		s_Array {
  /**
   * @brief Inheritance of #t_container
   */
  t_container	base;
};

/**
 * @brief Array description variable
 */
extern Class	*_array;

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
