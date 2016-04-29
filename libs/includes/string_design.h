/*
** string_design.h for list design in /home/roche_g/dataStructures/oop
**
** Made by
** Login   <roche_g@epitech.net>
**
** Started on  Mon Mar 14 13:24:39 2016
** Last update Thu Apr 28 03:35:48 2016 Guillaume roche
*/

#ifndef STRING_DESIGN_H_
# define STRING_DESIGN_H_

/**
 * \file
 */

# include "object.h"
# include "container_design.h"

/**
 * @brief Function pointer which represents a member function returning
 *        memory allocated copy of something. Like strdup() for
 *        <tt>char *</tt> in the libC.
 *
 * @param self The <tt>#Object</tt> to duplicate.
 *
 * @return The duplicated <tt>#Object</tt>.
 */
typedef Object	*(*t_dup)(Object *self);

/**
 * @brief Function pointer which represents a member function returning a
 *        concatenated string. Like strcat() for <tt>char *</tt> in the
 *        libC except that a t_concat function will take care of memory
 *        allocation if needed..
 *
 * @param self The <tt>#Object</tt> to duplicate.
 *
 * @return The concatenated <tt>#Object</tt>.
 */
/*typedef Object	*(*t_concat)(Object *self, char *str_to_concat);
*/

/**
 * @brief Function pointer which represents a member function returning
 *        the first position at which a substring was found in an <tt>
 *        #Object</tt>. Like find() for strings.
 *
 * @param self It's an <tt>#Object *</tt> to avoid warnings
 *        when doing implicits upcastings. Very usually it's a string.
 *
 * @return If found, the first position at which such a substring starts.
 *         Otherwise, 0. The position is not index-like, the first elements
 *         is at the position 1.
 */
typedef size_t	(*t_str_findstr)(Object *self, char *substr);

/**
 * @brief Function pointer which represents a member function returning
 *        the first position at which a char was found in an <tt>
 *        #Object</tt>. Like find() for strings.
 *
 * @param self It's an <tt>#Object *</tt> to avoid warnings
 *        when doing implicits upcastings. Very usually it's a string.
 * @param substr The substring to find.
 *
 * @return If found, the first position at which such a char starts.
 *         Otherwise, 0. The position is not index-like, the first elements
 *         is at the position 1.
 */
typedef size_t	(*t_str_find)(Object *self, int c);

/**
 * @brief Function pointer which represents a member function returning
 *        a boolean telling if an <tt>#Object</tt> matches a pattern.
 *        Kind of regexp for poors.
 *
 * @param self It's an <tt>#Object *</tt> to avoid warnings
 *        when doing implicits upcastings. Very usually it's a string.
 * @param compare The pattern to match.
 *
 * @return TRUE if the pattern matches, FALSE otherwise.
 */
typedef t_bool	(*t_str_match)(Object *self, char *compare);

/**
 * @brief Function pointer which represents a member function returning
 *        the number of times an <tt>#Object</tt> matches a pattern.
 *
 * @param self It's an <tt>#Object *</tt> to avoid warnings
 *        when doing implicits upcastings. Very usually it's a string.
 * @param compare The pattern to match.
 *
 * @return The number of times the <tt>#Object</tt> matches the pattern.
 */
typedef int	(*t_str_nmatch)(Object *self, char *compare);

/**
 * @brief Function pointer which represents a member function returning
 *        an <tt>#Object</tt> instancied from <tt>#t_container</tt> or
 *        one of its derived class. The <tt>#Object</tt> returned contains
 *        the value contained in <tt>#Object @p self</tt> but splitted with
 *        separators. The returning <tt>#Object</tt> has to be  - or derived
 *        of - a <tt>#t_container</tt> to be able to store severals values in
 *        case where at least one separator is found in @p self.
 *
 * @param self It's an <tt>#Object *</tt> to avoid warnings
 *        when doing implicits upcastings. Very usually it's a string.
 * @param type A container class description variable or a container.
 *        The behaviour is defined by the implementation of push_back().
 * @param sep Each char in @p sep is a separator.
 *
 * @return The newly created <tt>#Object</tt> which store the splitted value
 *         of @p self.
 */
typedef Object	*(*t_str_split)(Object *self, Class *type, const char *sep);

struct		s_String {
  t_container	base;
  t_dup		dup;
  t_str_findstr	find_str;
  t_str_find	find;
  t_str_find	lfind;
  t_str_match	match;
  t_str_nmatch	nmatch;
  t_str_split	split;
};

/**
 * @brief String class description variable
 */
extern Class	*_string;

int	string_insert_at(Object *self, void *data, int pos);
int	string_delete_at(Object *self, int pos);
int	string_erase(Object *self);
void	string_affect(Object *self, void *data);

void	string_print(Object *self);

Object	*string_front(Object *self);
Object	*string_back(Object *self);
Object	*string_at(Object *self, size_t pos);

Object	*string_dup(Object *self);
Object	*string_split(Object *self, Class *type, const char *sep);
Object	*string_substr(Object *self, Class *type, int begin, int len);

t_bool	string_match(Object *self, char *compare);
int	string_nmatch(Object *self, char *compare);

size_t	string_findstr(Object *self, char *substr);
size_t	string_find(Object *self, int c);
size_t	string_lfind(Object *self, int c);

#endif /* !STRING_DESIGN_H_ */
