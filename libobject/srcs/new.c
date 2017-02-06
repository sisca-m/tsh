#include "new.h"

static Object	*va_new(Class *class, va_list *ap)
{
  Object	*new;

  new = malloc(class->__size__);
  if (!new)
    return (NULL);
  new = memcpy(new, class, class->__size__);
  if (!new)
    return (NULL);
  if (class->__init__)
    if (class->__init__(new, ap) == FALSE)
      return (NULL);
  return (new);
}

Object		*new(Class *class, ...)
{
  Object	*new;
  va_list	ap;

  if (!class)
    return (NULL);
  va_start(ap, class);
  new = va_new(class, &ap);
  va_end(ap);
  return (new);
}

void		delete(Object *ptr, ...)
{
  Class		*class;
  va_list	ap;

  if (!ptr)
    return ;
  va_start(ap, ptr);
  class = ptr;
  if (class->__del__)
    class->__del__(ptr, &ap);
  va_end(ap);
  free(ptr);
}
