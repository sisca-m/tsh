#ifndef OBJECT_H_
# define OBJECT_H_

# include <sys/types.h>
# include <stdarg.h>
# include <stdlib.h>
# include "bool.h"

/**
 * @typedef Object
 *
 * Typedef to increase the readability of the code
 * All internals functions use at least one pointer to Object.
 * It represents an instance of any class.
 */
typedef void Object;

/**
 * @method Constructor
 *
 * All classes must implement a constructor of the following form, otherwise,
 * a segmentation fault will occur when instanciating the Class
 *
 * @param self The newly created Object.
 * @param args The optional arguments passed to new().
 *
 * @return Nothing is return
 */
typedef int (*ctor_t)(Object *self, va_list *args);

/**
 * @method Destructor
 *
 * All classes must implement a destructor of the following form otherwise
 * a segmentation fault will occur at the destruction of the given #Object
 *
 * @param self A new'ed Object.
 * @param args The optional arguments passed to delete().
 *
 * @return Nothing is return
 */
typedef void (*dtor_t)(Object *self, va_list *args);

/**
 * @brief Base class for all classes
 *
 * This is the base class whose all others classes must inherit otherwise no
 * call to new() will be possible due to the type of the  new() first argument
 * Since the notion of class is implemented through structures and compile
 * time defined description variables, fields in Class are related to the
 * downmost class in the inheritance tree.
 *
 * @field __size__
 * __size__ is used during a call to new() to know how many memory
 * takes the given Class and so to be able to copy its fields correctly.
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
typedef struct {
  const size_t	__size__;
  const char	*__name__;
  ctor_t	__init__;
  dtor_t	__del__;
} Class;

#endif /* !OBJECT_H_ */
