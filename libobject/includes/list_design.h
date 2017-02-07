#ifndef LIST_DESIGN_H_
# define LIST_DESIGN_H_

# include <stdlib.h>
# include <stdio.h>
# include "container_design.h"
# include "libobject_types.h"
# include "array_design.h"

/**
 * @enum Type of linked-list. Used internally in lists functions.
 */
typedef enum	e_list_type {
  SIMPLE = 0,
  CIRC_SIMPLE,
  DOUBLE,
  CIRC_DOUBLE
}		t_list_type;

/**
 * @brief Linked list structure
 *
 * Basic linked-list. Can be [circular and / or doubly] or not
 */
typedef struct		s_list_data
{
  void			*data;
  struct s_list_data	*prev;
  struct s_list_data	*next;
}			t_list_data;

/**
 * @class List class
 *
 * Inherits of the container class.
 * The value contained in t_container.contained is a t_list_data *
 *
 * @field base
 * The base class is a container, the fact that containers inherit of the t_class allow us to do that.
 */
struct		s_list {
  t_container	base;
};

/**
 * Refer to container_design.h to see which methods the following functions implement.
 */
int	list_add(t_list_data **list, void *data, int pos, t_list_type type);
void	list_del(t_list_data **list, int pos, t_list_type type);

void	_list_print(Object *list, const char *title,
		    void (*f)(size_t i, Object *elem, const char *prefix),
		    const char *prefix);
void	_list_basic_print(size_t i, Object *elem, const char *prefix);

Object	*_list_end(Object *list);
Object	*_list_front(Object *list);
Object	*_list_at(Object *list, size_t pos);

int	_spl_list_add(Object *list, void *data, int pos);
int	_spl_list_del(Object *list, int pos);

int	_spl_clist_add(Object *list, void *data, int pos);
int	_spl_clist_del(Object *list, int pos);

int	_dbl_list_add(Object *list, void *data, int pos);
int	_dbl_list_del(Object *list, int pos);

int	_dbl_clist_add(Object *list, void *data, int pos);
int	_dbl_clist_del(Object *list, int pos);

extern Class	*_spl_list;
extern Class	*_spl_clist;
extern Class	*_dbl_list;
extern Class	*_dbl_clist;

#endif /* !LIST_DESIGN_H_ */
