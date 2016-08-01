#include "container_design.h"

Object	*_container_data(Object *self)
{
  return (((t_container *)self)->contained);
}
