#include "tsh.h"

t_builtin	builtins_list[] = {{"env", &builtin_env},
				   {NULL, NULL}};

size_t	nb_builtins = sizeof(builtins_list) / sizeof(builtins_list[0]);
