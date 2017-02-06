#ifndef BOOL_H_
# define BOOL_H_

/**
 * @typedef Boolean type
 *
 * Typedef to char. When manipulating a t_bool value,
 * the defines TRUE and FALSE should always be used.
 */
typedef char	t_bool;

# define TRUE	1
# define FALSE	(!TRUE)

#endif /* !BOOL_H_ */
