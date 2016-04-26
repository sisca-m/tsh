/*
** list_design.h for list design in /home/roche_g/dataStructures/lists
** 
** Made by 
** Login   <roche_g@epitech.net>
** 
** Started on  Sun Mar 13 16:50:38 2016 
** Last update Sun Mar 20 01:59:58 2016 
*/

#ifndef LIST_DESIGN_H_
# define LIST_DESIGN_H_

/**
 * \file
 */

# include "object.h"
# include "container_design.h"
# include "array_design.h"

typedef t_Array	*(*t_to_array)(t_container *self);

/**
 * @brief List class
 *
 * Inherits of the #t_container class.
 * The value contained in t_container#contained for the List class is
 * a <tt>#t_list_data *</tt> which represents a linked-list.
 */
struct		s_list {
  t_container	base;
  t_to_array	to_array;
};

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
 * @brief No circular simple linked-list
 */
typedef t_list	t_spl_list;

/**
 * @brief Circular simple linked-list
 */
typedef t_list	t_spl_clist;

/**
 * @brief No ircular doubly linked-list
 */
typedef t_list	t_dbl_list;

/**
 * @brief Circular doubly linked-list
 */
typedef t_list	t_dbl_clist;

/**
 * @brief No circular simple linked-list description variable
 */
extern Class	*_spl_list;

/**
 * @brief Circular simple linked-list description variable
 */
extern Class	*_spl_clist;

/**
 * @brief No circular doubly linked-list description variable
 */
extern Class	*_dbl_list;

/**
 * @brief Circular doubly linked-list description variable
 */
extern Class	*_dbl_clist;

/**
 * @brief Type of linked-list. Used in interns functions.
 */
typedef enum	e_list_type {
  SIMPLE = 0,
  CIRC_SIMPLE,
  DOUBLE,
  CIRC_DOUBLE
}		t_list_type;

/*
** Two base functions for add / del elem in a linked list
*/
int	list_add(t_list_data **list, void *data, int pos, t_list_type type);
void	list_del(t_list_data **list, int pos, t_list_type type);

void	list_print(Object *list);

Object	*list_end(Object *list);
Object	*list_front(Object *list);
Object	*list_at(Object *list, size_t pos);

int	spl_list_add(Object *list, void *data, int pos);
int	spl_list_del(Object *list, int pos);

int	spl_clist_add(Object *list, void *data, int pos);
int	spl_clist_del(Object *list, int pos);

int	dbl_list_add(Object *list, void *data, int pos);
int	dbl_list_del(Object *list, int pos);

int	dbl_clist_add(Object *list, void *data, int pos);
int	dbl_clist_del(Object *list, int pos);

t_Array	*list_to_array(Object *self);

#endif /* !LIST_DESIGN_H_ */
