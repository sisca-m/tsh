/**
 * \file
 */

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "object.h"
#include "bool.h"

static Object	*va_new(Class *class, va_list *ap)
{
  Object	*new;

  new = malloc(class->__size__);
  if (!new)
    return (NULL);
  new = memcpy(new, class, class->__size__);
  if (!new)
    return (NULL);
  if (class->__init__)
    if (class->__init__(new, ap) == FALSE)
      return (NULL);
  return (new);
}

/**
 * @brief Instanciate a <tt>Class</tt>
 *
 * Create a memory allocated object from @p class by copying the value
 * of @p class and then call the constructor of the object.
 * Each classes have a description variable to define the functions member
 * and attributes of the class. Those variables are usually pass to new
 * but you can give any object you want if you know what you are doing. #t_bool
 *
 * @param class	An object whose value will be copied (so attributes and
 *              functions member).
 * @param ...	Optionals arguments. They will be passed to the constructor
 *		of the freshly instancied object.
 * @return	Return the newly crated #Object.
 */
Object		*new(Class *class, ...)
{
  Object	*new;
  va_list	ap;

  if (!class)
    return (NULL);
  va_start(ap, class);
  new = va_new(class, &ap);
  va_end(ap);
  return (new);
}

void	static_new(Object *new, Class *class, ...)
{
  va_list	ap;

  va_start(ap, class);
  memcpy(new, class, class->__size__);
  if (class->__init__)
    class->__init__(new, &ap);
  va_end(ap);
}

/**
 * @brief Delete an object
 *
 * Call the #Object destructor then release the memory which was
 * allocated by a call to new().
 *
 * @param ptr	A pointer to a new'ed object.
 * @param ...	Optionals arguments. They will be passed to the destructor
 *		of the object.
 * @return	Return nothing
 */
void		delete(Object *ptr, ...)
{
  Class		*class;
  va_list	ap;

  if (!ptr)
    return ;
  va_start(ap, ptr);
  class = ptr;
  if (class->__del__)
    class->__del__(ptr, &ap);
  va_end(ap);
  free(ptr);
}
