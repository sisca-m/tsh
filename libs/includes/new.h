/*
** new.h for new in /home/roche_g/dataStructures/lists
** 
** Made by 
** Login   <roche_g@epitech.net>
** 
** Started on  Sun Mar 13 15:58:38 2016 
** Last update Sun Mar 20 19:56:08 2016 
*/

#ifndef NEW_H_
# define NEW_H_

# include <stdarg.h>
# include "object.h"

void	*new(Class *class, ...);
#include "list_design.h"
void	static_new(Object *new, Class *class, ...);
void	delete(Object *ptr, ...);

#endif /* !NEW_H_ */
