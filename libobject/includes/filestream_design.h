#ifndef FILESTREAM_DESIGN_H_
# define FILESTREAM_DESIGN_H_

# include <string.h>
# include <stdio.h>
# include "object.h"
# include "bool.h"

/**
 * Macro used in the getline method. It's the number of char read by fgets.
 */
# define READSIZE	(2)

/**
 * Macro used in the constructor. It tells to not open the file representing the stream
 */
# define NO_OPEN	NULL

/**
 * @typedef Function pointer which represents a member function returning a line from the stream fs
 *
 * @param fs The filestream
 *
 * @return The line, result of the call to the function pointer
 */
typedef char	*(*t_getline)(filestream *fs);
char		*_filestream_getline(filestream *fs);

/**
 * @class Filestream class
 *
 * Inherits of the base class.
 * The purpose of the class is to manipulate filestreams (i/o, pipe, redirection etc..)
 *
 * @field base
 * The base class
 *
 * @field stream
 * The filestream manipulated by the methods
 *
 * @field getline
 * Refer to the typedef t_getline documentation
 */
struct		s_filestream {
  Class		base;
  FILE		*stream;
  t_getline	getline;
};

extern Class *_filestream;

#endif /* !FILESTREAM_DESIGN_H_ */
