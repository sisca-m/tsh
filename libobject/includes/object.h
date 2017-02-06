#ifndef OBJECT_H_
# define OBJECT_H_

# include <sys/types.h>
# include <stdarg.h>
# include <stdlib.h>
# include "libobject_types.h"

/**
 * @method Constructor
 *
 * All classes must implement a constructor of the following form.
 *
 * @param self The newly created Object.
 * @param args The optional arguments passed to new().
 *
 * @return Nothing is returned
 */
typedef int (*ctor_t)(Object *self, va_list *args);

/**
 * @method Destructor
 *
 * All classes must implement a destructor of the following form.
 * @param self A new'ed Object.
 * @param args The optional arguments passed to delete().
 *
 * @return Nothing is return
 */
typedef void (*dtor_t)(Object *self, va_list *args);

/**
 * @typedef Base class
 *
 * This is the base class whose all others classes must inherit.
 * Since the notion of class is implemented through structures and compile
 * time defined description variables, fields in Class are related to the
 * downmost class in the inheritance tree.
 *
 * @field __size__
 * __size__ is used during a call to new() to know how big a class is in memory
 * and to be able to copy the properties to the freshly malloc'd class
 *
 * @field __name__
 * Name of the downmost class. The name is currently not used anywhere.
 * 
 * @field __init__
 * Constructor of the downmost class. Used in new
 *
 * @field __del__
 * Destructor of the downmost class. Used in delete
 */
struct		Class {
  const size_t	__size__;
  const char	*__name__;
  ctor_t	__init__;
  dtor_t	__del__;
};

#endif /* !OBJECT_H_ */
