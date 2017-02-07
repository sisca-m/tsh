#ifndef CONTAINER_DESIGN_H_
# define CONTAINER_DESIGN_H_

# include <stddef.h>
# include "libobject_types.h"
# include "new.h"
# include "bool.h"
# include "utils.h"

/**
 * @typedef Function pointer which represents a member function returning
 *          the contained data.
 *
 * @param self It's an Object * to avoid warnings
 *        when doing implicits upcastings.
 *
 * @return The contained value.
 */
typedef Object	*(*t_data)(Object *self);
Object		*_container_data(Object *self);

/**
 * @typedef Function pointer which represents a member function returning
 *          the size of something. Like size() for containers.
 *
 * @param self It's an Object * to avoid warnings
 *        when doing implicits upcastings.
 *
 * @return The size of the contained value.
 */
typedef size_t	(*t_size)(Object *self);
size_t		_container_size(Object *self);

/**
 * @typedef Function pointer which represents a member function retuning
 *        a bool if a something is empty or not. Like empty() for containers
 *
 * @param self It's an Object * to avoid warnings
 *        when doing implicits upcastings.
 *
 * @return TRUE if the t_container.contained is t_container.size == 0,
 *	   FALSE otherwise.
 */
typedef t_bool	(*t_empty)(Object *self);
t_bool		_container_empty(Object *self);

/**
 * @typedef Function pointer which represents a member function inserting
 *          an element in an Object at a given position. Assuming the
 *          position isn't out of range. Like insertAt() for containers
 *
 * @param self It's an Object * to avoid warnings
 *        when doing implicits upcastings.
 * @param data The data to insert.
 * @param pos The position at which the data is inserted. 0 means at the
 *	  begin, 1 at the second position etc...
 *
 * @return TRUE if insertion succed, FALSE otherwise.
 */
typedef int	(*t_rand_insert)(Object *self, void *data, int pos);

/**
 * @typedef Function pointer which represents a member function inserting
 *          an element in an Object at a position defined in the
 *          implementation function. Like push_back() for containers
 *
 * @param self It's an Object * to avoid warnings
 *        when doing implicits upcastings.
 * @param data The data to insert.
 *
 * @return TRUE if insertion succed, FALSE otherwise.
 */
typedef int	(*t_insert)(Object *self, void *data);
int		_container_push_back(Object *self, void *data);

/**
 * @typedef Function pointer which represents a member function deleting
 *        an element in an Object at a given position. Assuming the
 *        position isn't out of range. Like insertAt() for containers
 *
 * @param self It's an Object * to avoid warnings when doing implicits upcastings.
 * @param pos The position at which the data is deleted. 0 means at the
 *	  begin, 1 at the second position etc...
 *
 * @return TRUE if deletion succed, FALSE otherwise.
 */
typedef int	(*t_rand_delete)(Object *self, int pos);

/**
 * @typedef Function pointer which represents a member function deleting
 *          an element in an Object at a position defined in the
 *          implementation function. Like deleteAt() for containers.
 *
 * @param self It's an Object * to avoid warnings
 *        when doing implicits upcastings.
 *
 * @return TRUE if deletion succed, FALSE otherwise.
 */
typedef int	(*t_delete)(Object *self);

/**
 * @typedef Function pointer which represents a member function affecting
 *         a new value to an Object. Like affect() for containers.
 *
 * @param self It's an Object * to avoid warnings when doing
 *        implicits upcastings.
 * @param data The new value of the Object
 *
 * @return Returns nothing, if the affect failed the data structure
 *         stays unchanged.
 */
typedef void	(*t_affect)(Object *self, void *data);

/**
 * @typedef Function pointer which represents a member function accessing
 *          an Object at a position defined in the implementation function.
 *          Like back() or front() for containers.
 *
 * @param self It's an Object * to avoid warnings when doing implicits upcastings.
 * @param data The new value of the Object.
 *
 * @return The value at the position.
 */
typedef Object	*(*t_access)(Object *container);

/**
 * @typedef Function pointer which represents a member function accessing
 *          an Object at a given position. Like at() for containers.
 *
 * @param self It's an Object * to avoid warnings when doing
 *        implicits upcastings.
 * @param pos The position.
 *
 * @return The value at the position.
 */
typedef Object	*(*t_rand_access)(Object *contained, size_t pos);

/**
 * @typedef Function pointer which represents a member function dumping
 *          the state of an Object. Usually used to print all the values
 *          contained in an Object. Like dump() for containers.
 *
 * @param self It's an Object * to avoid warnings when doing
 *        implicits upcastings.
 *
 * @return Nothing is returned.
 */
typedef void	(*t_dump)(Object *self, const char *title,
			  void (*f)(size_t i, Object *elem,
				    const char *prefix),
			  const char *prefix);

/**
 * @typedef Function pointer which represents a member function converting
 *          an Object to another type of Object.
 *          The Object used to convert to another is not deleted.
 *          Like convert() for containers.
 *
 * @param self It's an Object * to avoid warnings when doing implicits upcastings.
 * @param type A description class variable or an upcasted object.
 *        For containers and in the case of an upcasted object, the
 *        already existants contained values are not deleted due to the
 *        fact that the conversion use push_back().
 *
 * @return The new Object, result of the conversion.
 */
typedef Object	*(*t_converter)(Object *self, Class *type);
Object		*_container_to_type(Object *self, Class *type);

/**
 * @typedef Function pointer which represents a member function returning
 *          a subobject from an Object.
 *
 * @param self It's an Object * to avoid warnings
 *        when doing implicits upcastings.
 * @param type A description class variable or an upcasted object.
 *        For containers and in the case of an upcasted object, the
 *        already existants contained values are not deleted due to the
 *        fact that the conversion use push_back().
 * @param begin An index which points to the beginning of the subobject.
 *        A negative index means the substring start at n positions from
 *        the end.
 *        @code
 *        t_String	*string = new(_string, "filename.c", 0);
 *        string->substr(string, -2, 2); // Returns ".c"
 *        string->substr(string, 3, 4); // Returns "enam"
 *        @endcode
 * @param len The length on which the subobject is extract.
 *
 * @return A memory allocated Object containing the subobject.
 *
 * @warning A negative begin which is in absolute greater than the
 *          size of the Object will leads you to a crash.
 * @note If the len is greater than the size of the strings no crash
 *       will happen.
 */
typedef Object	*(*t_sub)(Object *self, Class *type, int begin, int len);
Object		*_container_sub(Object *self, Class *type, int begin, int len);

/**
 * @class Container class
 *
 * Inherits of the container class.
 * The value contained in t_container.contained is a void ** which represents a table of any type.
 *
 * @field base
 * The base class.
 *
 * @field contained
 * The data contained, on which the methods will operate.
 *
 * @field contained_size
 * An internal field used when dealing with the size of the contained data. External programs should use the size() method
 *
 * @field data
 * Refer to the typedef t_data documentation
 *
 * @field size
 * Refer to the typedef t_size documentation
 *
 * @field empty
 * Refer to the typedef t_empty documentation
 *
 * @field insertAt
 * Refer to the typedef t_rand_insert documentation
 *
 * @field push_back
 * Refer to the typedef t_insert documentation
 *
 * @field deleteAt
 * Refer to the typedef t_rand_delete documentation
 *
 * @field erase
 * Refer to the typedef t_delete documentation
 *
 * @field affect
 * Refer to the typedef t_affect documentation
 *
 * @field front
 * Refer to the typedef t_access documentation
 *
 * @field back
 * Refer to the typedef t_access documentation
 *
 * @field at
 * Refer to the typedef t_rand_access documentation
 *
 * @field dump
 * Refer to the typedef t_dump documentation
 *
 * @field convert
 * Refer to the typedef t_converter documentation
 *
 * @field sub
 * Refer to the typedef t_sub documentation
 */
struct		s_container
{
  Class		base;

  void		*contained;

  size_t	contained_size;
  t_data	data;

  t_size	size;
  t_empty	empty;

  t_rand_insert	insertAt;
  t_insert	push_back;
  t_rand_delete	deleteAt;
  t_delete	erase;
  t_affect	affect;

  t_access	front;
  t_access	back;
  t_rand_access	at;

  t_dump	dump;

  t_converter	convert;
  t_sub		sub;
};

#endif /* !CONTAINER_DESIGN_H_ */
