#ifndef NEW_H_
# define NEW_H_

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "object.h"
#include "bool.h"

/**
 * @brief Instanciate a Class
 *
 * Create a memory allocated object by copying the value of the given class
 * then call the constructor of the object.
 * Each classes have a description variable to define the functions member
 * and attributes of the class. Those variables are usually passed to new
 * but you can give any object you want if you know what you are doing.
 *
 * @param class	An object whose value will be copied (so attributes and
 *              functions member).
 * @param ...	Optionals arguments. They will be passed to the constructor
 *		of the freshly instancied object.
 * @return	Return the newly crated #Object.
 */
void	*new(Class *class, ...);

/**
 * @brief Delete an object
 *
 * Call the destructor of the given Object then release the memory which has been
 * allocated by a call to new().
 *
 * @param ptr	A pointer to a new'ed object.
 * @param ...	Optionals arguments. They will be passed to the destructor
 *		of the object.
 * @return	Return nothing
 */
void	delete(Object *ptr, ...);

#endif /* !NEW_H_ */
