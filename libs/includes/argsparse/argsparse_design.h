/*
** argsparse_design.h for argsparse_design in /home/roche_g/dataStructures/oop
** 
** Made by 
** Login   <roche_g@epitech.net>
** 
** Started on  Sun Mar 20 21:22:49 2016 
** Last update Sun Mar 20 22:39:16 2016 
*/

#ifndef ARGSPARSE_DESIGN_H_
# define ARGSPARSE_DESIGN_H_

/**
 * \file
 */

# include "object.h"
# include "container_design.h"

# define OPTIONAL	0
# define REQUIRED	1
# define NO_OPT_CHAR	~((char)0)	

typedef struct	s_opt {
  char		*opt;
  size_t	nargs;
  t_bool	required;
  t_bool	compound;
  char		opt_char;
}		t_opt;

/**
 * @brief Argsparse class
 *
 * Inherits of the #t_container class.
 * The value contained in t_container#contained for the Array class is
 * a void ** which represents a table of whatever type.
 */
struct		s_argsparser {
  /**
   * @brief Contains informations about the arguments to parse.
   */
  t_container	*container;
};

/**
 * @brief Array description variable
 */
extern Class	*_argsparser;

#endif /* !ARGSPARSE_DESIGN_H_ */
