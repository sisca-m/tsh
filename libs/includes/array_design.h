/*
** array_design.h for ARRAY_DESIGN in /home/roche_g/dataStructures/lists/oop/src
** 
** Made by 
** Login   <roche_g@epitech.net>
** 
** Started on  Mon Mar 14 01:49:25 2016 
** Last update Sun Mar 20 01:55:46 2016 
*/

#ifndef ARRAY_DESIGN_H_
# define ARRAY_DESIGN_H_

/**
 * \file
 */

# include "object.h"
# include "container_design.h"
# include "list_design.h"

typedef t_list	*(*t_to_list)(t_container *self, Class *type);

/**
 * @brief Array class
 *
 * Inherits of the #t_container class.
 * The value contained in t_container#contained for the Array class is
 * a void ** which represents a table of whatever type.
 */
struct		s_Array {
  /**
   * @brief Inheritance of #t_container
   */
  t_container	base;
  t_to_list	to_list;
};

/**
 * @brief Array description variable
 */
extern Class	*_array;

int	array_insert_at(Object *self, void *data, int pos);
int	array_delete_at(Object *self, int pos);
int	array_erase(Object *self);

void	array_print(Object *self);

Object	*array_front(Object *self);
Object	*array_back(Object *self);
Object	*array_at(Object *self, size_t pos);

t_list	*array_to_list(t_container *self, Class *type);

#endif /* !ARRAY_DESIGN_H_ */
