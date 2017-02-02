#ifndef DICT_DESIGN_H_
# define DICT_DESIGN_H_

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "object.h"
# include "container_design.h"
# include "array_design.h"

typedef struct	s_pair {
  char		*key;
  void		*data;
}		t_pair;

typedef Object	*(*t_obj_by_key)(Object *dict, const char *key);
Object		*_get_obj_by_key(Object *dict, const char *key);

typedef t_bool	(*t_del_by_key)(Object *dict, const char *key);
t_bool		_del_by_key(Object *dict, const char *key);

typedef t_bool	(*t_map_push)(Object *self, char *key, void *data);
t_bool		_dict_push_back(Object *self, char *key, void *data);

struct		s_dict {
  t_container	base;
  t_obj_by_key	get_by_key;
  t_del_by_key	del_by_key;
  t_map_push	push_back;
};

void	dict_print_str(size_t i, Object *elem, const char *prefix);
void	dict_basic_print(size_t i, Object *elem, const char *prefix);
void	_dict_print(Object *container, const char *title,
		    void (*f)(size_t i, Object *elem, const char *prefix),
		    const char *prefix);

extern Class	*_dict;

#endif /* !DICT_DESIGN_H_ */
