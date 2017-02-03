#ifndef BUILTIN_H_
# define BUILTIN_H_

# define BUILTIN_PROTO_ARGS	void

typedef t_bool	(*t_builtin_func)(char **);
typedef struct		s_builtin {
  char			*name;
  t_builtin_func	f;
}			t_builtin;

/**
 * Use the wrappers unless you know what you are doing. The wrappers are here to provide a safe way of calling builtins, arguments management and stuffs like that shouldn't be in a builtin function but in the associated wrapper.
 */
t_bool	builtin_env(void);
t_bool	builtin_setenv(char **args);
t_bool	builtin_unsetenv(char **args);


t_bool	wrapper_builtin_env(char **args);
t_bool	wrapper_builtin_setenv(char **args);
t_bool	wrapper_builtin_unsetenv(char **args);

#endif /* BUILTIN_H_ */
