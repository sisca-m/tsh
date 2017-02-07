#ifndef DICT_DESIGN_H_
# define DICT_DESIGN_H_

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "array_design.h"

/**
 * Struc used internally by the dict class
 */
typedef struct	s_pair {
  char		*key;
  void		*data;
}		t_pair;

/**
 * @typedef Function pointer which represents a member function getting a value associated with a given key
 *
 * @param dict It's an Object * to avoid warnings when doing implicits upcastings.
 * @param key A key used to retrieve the value
 *
 * @return The retrieved value
 */
typedef Object	*(*t_obj_by_key)(Object *dict, const char *key);
Object		*_get_obj_by_key(Object *dict, const char *key);

/**
 * @typedef Function pointer which represents a member function deleting a value associated with a given key
 *
 * @param dict It's an Object * to avoid warnings when doing implicits upcastings.
 * @param key A key used to find the value to delete
 *
 * @return TRUE if the action succeed, FALSE otherwise
 */
typedef t_bool	(*t_del_by_key)(Object *dict, const char *key);
t_bool		_del_by_key(Object *dict, const char *key);

/**
 * @typedef Function pointer which represents a member function inserting a new pair in a dict
 *
 * @param self It's an Object * to avoid warnings when doing implicits upcastings.
 * @param self A key associated with the value. It will be used to access the data afterwise
 *
 * @return TRUE if the insertion succeed, FALSE otherwise
 */
typedef t_bool	(*t_dict_push)(Object *self, char *key, void *data);
t_bool		_dict_push_back(Object *self, char *key, void *data);

/**
 * @class Dict class
 *
 * Inherits of the container class.
 * The value contained in t_container.contained is a t_pair ** which represents an associative array.
 *
 * @field base
 * The base class is a container, the fact that containers inherit of the t_class allow us to do that.
 *
 * @field get_by_key
 * Refer to the typedef t_obj_by_key documentation
 * 
 * @field del_by_key
 * Refer to the typedef t_del_by_key documentation
 *
 * @field push_back
 * Refer to the typedef t_dict_push documentation
 */
struct		s_dict {
  t_container	base;
  t_obj_by_key	get_by_key;
  t_del_by_key	del_by_key;
  t_dict_push	push_back;
};

void	dict_print_str(size_t i, Object *elem, const char *prefix);
void	dict_basic_print(size_t i, Object *elem, const char *prefix);
void	_dict_print(Object *container, const char *title,
		    void (*f)(size_t i, Object *elem, const char *prefix),
		    const char *prefix);

extern Class	*_dict;

#endif /* !DICT_DESIGN_H_ */
