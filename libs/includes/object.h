/*
** object.h for object in /home/roche_g/dataStructures/lists
** 
** Made by 
** Login   <roche_g@epitech.net>
** 
** Started on  Sun Mar 13 16:41:31 2016 
** Last update Sun Mar 20 01:32:05 2016 
*/

#ifndef OBJECT_H_
# define OBJECT_H_

/**
 * \file
 */

# include <sys/types.h>
# include <stdarg.h>

/**
 * @brief Object
 *
 * Typedef to increase the readability of the code
 * All internals functions use at least one pointer to Object.
 * It represents an instance of any class.
 */
typedef void Object;

/**
 * @brief Constructor
 *
 * All classes must implement a constructor of the following form otherwise
 * a segmentation fault will occur at an instanciation of the #Class
 *
 * @param self The newly created #Object.
 * @param args The optional arguments passed to new().
 *
 * @return Nothing is return
 */
typedef void (*ctor_t)(Object *self, va_list *args);

/**
 * @brief Destructor
 *
 * All classes must implement a destructor of the following form otherwise
 * a segmentation fault will occur at the destruction of the given #Object
 *
 * @param self A new'ed #Object.
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
 * time defined description variables, fields in #Class are related to the
 * downmost class in the inheritance tree.
 */
typedef struct {
  /**
   * @brief Size of an instance of the downmost class.
   *
   * Class#__size__ is used during a call to new() to know how many memory
   * takes the given #Class and so to be able to copy its fields correctly.
   */
  const size_t	__size__;
  /**
   * @brief Name of the downmost class.
   *
   * Class#__name__ is currently not used anywhere.
   */
  const char	*__name__;
  /**
   * @brief Constructor of the downmost class.
   *
   * Class#__init__ is used in new().
   */
  ctor_t	__init__;
  /**
   * @brief Destructor of the downmost class.
   *
   * Class#__del__ is used in delete().
   */
  dtor_t	__del__;
} Class;

char	*str_dup(const char *str);

#endif /* !OBJECT_H_ */
