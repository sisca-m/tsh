#ifndef BUILTIN_H_
# define BUILTIN_H_

# define BUILTIN_PROTO_ARGS	void

typedef t_bool	(*t_builtin_func)(void);
typedef struct		s_builtin {
  char			*name;
  t_builtin_func	f;
}			t_builtin;

t_bool	builtin_env(BUILTIN_PROTO_ARGS);

#endif /* BUILTIN_H_ */
