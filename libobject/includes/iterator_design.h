#ifndef ITERATOR_DESIGN_H_
# define ITERATOR_DESIGN_H_

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
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
void		_incr(Object *self);
void		_decr(Object *self);

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
void		_jump(Object *self, int pos);

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
Object		*_rvalue(Object *self);

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
Object		*_jmp_rvalue(Object *self, int pos);

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

/**
 * @brief Iterator class description variable.
 */
extern Class	*_it;

#endif /* !ITERATOR_DESIGN_H_ */
