#ifndef CONTAINER_DESIGN_H_
# define CONTAINER_DESIGN_H_

/**
 * @typedef Container class
 */
typedef struct s_container	t_container;

/**
 * @typedef Array class
 */
typedef struct s_Array		t_Array;

/**
 * @typedef List class
 */
typedef struct s_list		t_list;

/**
 * @typedef String class
 */
typedef struct s_String		t_String;

/**
 * @typedef Iterator class
 */
typedef struct s_iter		t_iterator;

/**
 * @typedef Iterator class - For smaller type
 */
typedef t_iterator	t_it;

/**
 * @typedef Argparser class;
 */
typedef struct s_argsparser	t_argsparser;

/**
 * @typedef Map class;
 */
typedef struct s_dict	dict;

/**
 * @typedef Filestream class;
 */
typedef struct s_filestream	filestream;

# include <stddef.h>
# include "object.h"
# include "bool.h"
# include "utils.h"

/**
 * @brief Function pointer which represents a member function returning
 *        thee contained data.
 *
 * @param self It's an Object * to avoid warnings
 *        when doing implicits upcastings.
 *
 * @return The contained value.
 */
typedef Object	*(*t_data)(Object *self);
Object		*_container_data(Object *self);

/**
 * @brief Function pointer which represents a member function returning
 *        the size of something. Like size() for containers.
 *
 * @param self It's an Object * to avoid warnings
 *        when doing implicits upcastings.
 *
 * @return The size of the contained value.
 */
typedef size_t	(*t_size)(Object *self);
size_t		_container_size(Object *self);

/**
 * @brief Function pointer which represents a member function retuning
 *        a bool if a something is empty or not. Like empty() for containers
 *
 * @param self It's an Object * to avoid warnings
 *        when doing implicits upcastings.
 *
 * @return TRUE if the t_container#contained is t_container#size == 0,
 *	   FALSE otherwise.
 */
typedef t_bool	(*t_empty)(Object *self);
t_bool		_container_empty(Object *self);

/**
 * @brief Function pointer which represents a member function inserting
 *        an element in an #Object at a given position. Assuming the
 *        position isn't out of range. Like insertAt() for containers
 *
 * @param self It's an <tt>#Object *</tt> to avoid warnings
 *        when doing implicits upcastings.
 * @param data The data to insert.
 * @param pos The position at which the @p data is inserted. 0 means at the
 *	  begin, 1 at the second position etc...
 *
 * @return TRUE if insertion succed, FALSE otherwise.
 */
typedef int	(*t_rand_insert)(Object *self, void *data, int pos);

/**
 * @brief Function pointer which represents a member function inserting
 *        an element in an #Object at a position defined in the
 *        implementation function. Like push_back() for containers
 *
 * @param self It's an <tt>#Object *</tt> to avoid warnings
 *        when doing implicits upcastings.
 * @param data The data to insert.
 *
 * @return TRUE if insertion succed, FALSE otherwise.
 */
typedef int	(*t_insert)(Object *self, void *data);
int		_container_push_back(Object *self, void *data);

/**
 * @brief Function pointer which represents a member function deleting
 *        an element in an #Object at a given position. Assuming the
 *        position isn't out of range. Like insertAt() for containers
 *
 * @param self It's an <tt>#Object *</tt> to avoid warnings
 *        when doing implicits upcastings.
 * @param pos The position at which the @p data is deleted. 0 means at the
 *	  begin, 1 at the second position etc...
 *
 * @return TRUE if deletion succed, FALSE otherwise.
 */
typedef int	(*t_rand_delete)(Object *self, int pos);

/**
 * @brief Function pointer which represents a member function deleting
 *        an element in an #Object at a position defined in the
 *        implementation function. Like deleteAt() for containers.
 *
 * @param self It's an <tt>#Object *</tt> to avoid warnings
 *        when doing implicits upcastings.
 *
 * @return TRUE if deletion succed, FALSE otherwise.
 */
typedef int	(*t_delete)(Object *self);

/**
 * @brief Function pointer which represents a member function affecting
 *        a new value to an #Object. Like affect() for containers.
 *
 * @param self It's an <tt>#Object *</tt> to avoid warnings when doing
 *        implicits upcastings.
 * @param data The new value of the #Object
 *
 * @return Returns nothing, if the affect failed the data structure
 *         stays unchanged.
 */
typedef void	(*t_affect)(Object *self, void *data);

/**
 * @brief Function pointer which represents a member function accessing
 *        an #Object at a position defined in the implementation function.
 *        Like back() or front() for containers.
 *
 * @param self It's an <tt>#Object *</tt> to avoid warnings when doing
 *        implicits upcastings.
 * @param data The new value of the #Object.
 *
 * @return The value at the position.
 */
typedef Object	*(*t_access)(Object *container);

/**
 * @brief Function pointer which represents a member function accessing
 *        an #Object at a given position. Like at() for containers.
 *
 * @param self It's an <tt>#Object *</tt> to avoid warnings when doing
 *        implicits upcastings.
 * @param pos The position.
 *
 * @return The value at the position.
 */
typedef Object	*(*t_rand_access)(Object *contained, size_t pos);

/**
 * @brief Function pointer which represents a member function dumping
 *        the state of an #Object. Usually used to print all the values
 *        contained in an #Object. Like dump() for containers.
 *
 * @param self It's an <tt>#Object *</tt> to avoid warnings when doing
 *        implicits upcastings.
 *
 * @return Nothing is returned.
 */
typedef void	(*t_dump)(Object *self, const char *title,
			  void (*f)(size_t i, Object *elem,
				    const char *prefix),
			  const char *prefix);

/**
 * @brief Function pointer which represents a member function converting
 *        aa #Object to an another type of #Object.
 *        The #Object used to convert to another is not deleted.
 *        Like convert() for containers.
 *
 * @param self It's an <tt>#Object *</tt> to avoid warnings when doing
 *        implicits upcastings.
 * @param type A description class variable or an upcasted object.
 *        For containers and in the case of an upcasted object, the
 *        already existants contained values are not deleted due to the
 *        fact that the conversion use push_back().
 *
 * @return The new #Object, result the conversion.
 */
typedef Object	*(*t_converter)(Object *self, Class *type);
Object		*_container_to_type(Object *self, Class *type);

/**
 * @brief Function pointer which represents a member function returning
 *        a subobject from an <tt>#Object</tt>.
 *
 * @param self It's an <tt>#Object *</tt> to avoid warnings
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
 * @return A memory allocated <tt>#Object</tt> containing the subobject.
 *
 * @warning A negative @p begin which is in absolute greater than the
 *          size of the <tt>#Object</tt> will leads you to a crash.
 * @note If the @p len is greater than the size of the strings no crash
 *       will happen.
 */
typedef Object	*(*t_sub)(Object *self, Class *type, int begin, int len);
Object		*_container_sub(Object *self, Class *type, int begin, int len);

struct		s_container
{
  Class		base;

  Object	*contained;

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
