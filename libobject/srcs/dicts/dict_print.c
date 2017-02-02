#include "dict_design.h"

void		dict_basic_print(size_t i, Object *elem, const char *prefix)
{
  t_container	*ctn;

  ctn = ((t_pair *)elem)->data;
  printf("%skey: [%s]\n%svalue: ", prefix, ((t_pair *)elem)->key, prefix);
  ctn->dump(ctn, "Array", array_basic_print, prefix);
  (void)i;
}

void	dict_print_str(size_t i, Object *elem, const char *prefix)
{
  printf("%skey: [%s]\n%svalue: [%s]\n",
	 prefix, ((t_pair *)elem)->key, prefix, (char *)((t_pair *)elem)->data);
  (void)i;
}

void		_dict_print(Object *container, const char *title,
			    void (*f)(size_t i, Object *elem,
				      const char *prefix),
			    const char *prefix)
{
  char		**dict;
  char		*concat_prefix;
  unsigned int	i;

  dict = ((t_container *)container)->contained;
  i = 0;
  if (!(concat_prefix = concat(prefix, "  ")))
    return ;
  if (title)
    printf("%s%s\n", prefix, title);
  printf("%s[\n", prefix);
  if (dict)
    while (dict[i])
      {
	f(i, dict[i], concat_prefix);
	++i;
      }
  printf("%s]\n", prefix);
  free(concat_prefix);
}
