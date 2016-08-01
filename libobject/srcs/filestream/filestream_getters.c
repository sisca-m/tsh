#include <string.h>
#include "filestream_design.h"

char	*_filestream_getline(filestream *fs)
{
  char		*line;
  char		*tmp;
  size_t	cur_size;

  cur_size = READSIZE;
  line = calloc(cur_size, sizeof(char));
  while (fgets(&line[strlen(line)], READSIZE, fs->stream))
    {
      /* Search from the end, as there's where the newline should be */
      if (strrchr(line, '\n') != NULL)
	{
	  line[strlen(line) - 1] = '\0';
	  return (line);  /* Found the newline */
	}

      /* Need to allocate more memory */
      cur_size += READSIZE;
      tmp = line;
      line = realloc(line, cur_size);
    }
  free(line);
  return (NULL);
}
