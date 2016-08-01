#ifndef BOOL_H_
# define BOOL_H_

/**
 * \file
 */

/**
 * @brief Boolean type
 *
 * Typedef to char. When manipulating a t_bool value,
 * the defines TRUE and FALSE should always be used.
 */
typedef char	t_bool;

/**
 * @brief TRUE statement
 */
# define TRUE	1
/**
 * @brief FALSE statement
 */
# define FALSE	(!TRUE)

#endif /* !BOOL_H_ */
