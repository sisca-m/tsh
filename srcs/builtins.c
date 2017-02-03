#include "tsh.h"

t_builtin	builtins_list[] = {{"env", &wrapper_builtin_env},
				   {"setenv", &wrapper_builtin_setenv},
				   {"unsetenv", &wrapper_builtin_unsetenv},
				   {NULL, NULL}};

size_t	nb_builtins = sizeof(builtins_list) / sizeof(builtins_list[0]);
