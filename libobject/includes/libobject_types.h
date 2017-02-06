#ifndef LIBOBJECT_TYPES_H_
# define LIBOBJECT_TYPES_H_

# include <stdarg.h>

/**
 * @typedef Object
 *
 * Typedef to increase the semantic of the code.
 * It represents an instance of any class.
 */
typedef void Object;

/**
 * @typedef Container class
 */
typedef struct Class	Class;


/**
 * @typedef Container class
 */
typedef struct s_container	t_container;


/**
 * @typedef Array class
 */
typedef struct s_Array		t_Array;

/**
 * @typedef Base class for Lists
 */
typedef struct s_list		t_list;

/**
 * @typedef Simple non circular linked-list
 */
typedef t_list	t_spl_list;

/**
 * @typedef Simple circular linked-list
 */
typedef t_list	t_spl_clist;

/**
 * @typedef Doubly non circular linked-list
 */
typedef t_list	t_dbl_list;

/**
 * @typedef Doubly circular linked-list
 */
typedef t_list	t_dbl_clist;

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
 * @typedef Map class;
 */
typedef struct s_dict	dict;

/**
 * @typedef Filestream class;
 */
typedef struct s_filestream	filestream;

#endif /* !LIBOBJECT_TYPES_H_ */
