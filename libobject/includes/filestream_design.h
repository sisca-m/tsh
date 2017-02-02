#ifndef FILESTREAM_DESIGN_H_
# define FILESTREAM_DESIGN_H_

# include <string.h>
# include <stdio.h>
# include "container_design.h"
# include "object.h"

# define READSIZE	(2)
# define NO_OPEN	NULL

typedef char	*(*t_getline)(filestream *fs);
char		*_filestream_getline(filestream *fs);

struct		s_filestream {
  Class		base;
  FILE		*stream;
  t_getline	getline;
};

extern Class *_filestream;

#endif /* !FILESTREAM_DESIGN_H_ */
