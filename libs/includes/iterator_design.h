/*
** iterator_design.h for iterator design in /home/roche_g/dataStructures/oop
** 
** Made by 
** Login   <roche_g@epitech.net>
** 
** Started on  Thu Mar 17 02:23:33 2016 
** Last update Sun Mar 20 17:41:57 2016 
*/

#ifndef ITERATOR_DESIGN_H_
# define ITERATOR_DESIGN_H_

/**
 * \file
 */

# include "object.h"
# include "container_design.h"

/**
 * @brief Function pointer which represents a member function which
 *        put an iterator to an implementation function defined position.
 *
 * @param self It's an <tt>#Object *</tt> to avoid warnings
 *        when doing implicits upcastings.
 *
 * @return Returns nothing.
 */
typedef void	(*t_it_access)(Object *self);

/**
 * @brief Function pointer which represents a member function which
 *        put an iterator to a given position.
 *
 * @param self It's an <tt>#Object *</tt> to avoid warnings
 *        when doing implicits upcastings.
 * @param pos The new position of the iterator.
 *
 * @return Returns nothing.
 */
typedef void	(*t_it_rand_access)(Object *self, int pos);

/**
 * @brief Function pointer which represents a member function which
 *        put an iterator to an implementation function defined position.
 *
 * @param self It's an <tt>#Object *</tt> to avoid warnings
 *        when doing implicits upcastings.
 *
 * @return Returns what is stored at the position which points the iterator.
 */
typedef Object	*(*t_rvalue)(Object *self);

/**
 * @brief Function pointer which represents a member function which
 *        put an iterator to a given position then returning what is stored
 *        there.
 *
 * @param self It's an <tt>#Object *</tt> to avoid warnings
 *        when doing implicits upcastings.
 *
 * @return Returns what is stored at the new position which points
 *         the iterator.
 */
typedef Object	*(*t_access_val)(Object *self, int pos);

/**
 * @brief Random access iterator class
 *
 * For classes who doesn't support random access, the following class must
 * not be used.
 */
struct			s_iter {
  t_container		container;
  t_it_access		incr;
  t_it_access		decr;
  t_it_rand_access	jump;
  t_rvalue		rvalue;
  t_access_val		jmp_rvalue;
  int			pos;
};

void	incr(Object *self);
void	decr(Object *self);
void	jump(Object *self, int pos);
Object	*rvalue(Object *self);
Object	*jmp_rvalue(Object *self, int pos);

/**
 * @brief Iterator class description variable.
 */
extern Class	*_it;

#endif /* !ITERATOR_DESIGN_H_ */
