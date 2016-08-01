#include "filestream_design.h"

static int	_filestream_ctor(Object *self, va_list *args)
{
  filestream	*fs;
  void		*filename;
  char		*mode;

  fs = self;
  filename = va_arg(*args, char *);
  mode = va_arg(*args, char *);
  if (!mode)
    fs->stream = filename;
  else if (!(fs->stream = fopen(filename, mode)))
    return (FALSE);
  return (TRUE);
}

static void	_filestream_dtor(Object *self, va_list *args)
{
  filestream	*fs;

  fs = self;
  fclose(fs->stream);
  (void)args;
}

static filestream _filestream_descr =
  {
    {
      sizeof(filestream),
      "Filestream",
      &_filestream_ctor,
      &_filestream_dtor
    },
    NULL,
    &_filestream_getline
  };

Class	*_filestream = (Class *)&_filestream_descr;
