#ifndef BUILTIN_H_
# define BUILTIN_H_

# define BUILTIN_PROTO_ARGS	void

typedef t_bool	(*t_builtin_func)(void);
typedef struct		s_builtin {
  char			*name;
  t_builtin_func	f;
}			t_builtin;

t_bool	builtin_env(void);
t_bool	builtin_setenv(char **args);
t_bool	builtin_unsetenv(char **args);

#endif /* BUILTIN_H_ */
