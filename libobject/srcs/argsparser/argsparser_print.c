#include <stdio.h>
#include "argsparser_design.h"

void	opt_print(size_t i, Object *elem)
{
  t_opt	*opt;

  opt = ((t_pair *)elem)->data;
  printf("  %u: basename:%s => %s%s%s%s",
	 (unsigned int)i,
	 ((t_pair *)elem)->key,
	 opt->optionnal == TRUE ? "[" : "",
	 opt->prefix, opt->opt,
	 opt->nargs == ONE_OPTIONNAL ? " [ARG]":
	 opt->nargs == ALL_PRESENTS ? " ..." :
	 opt->nargs == ALL_AT_LEAST_ONE ? " ...+" : "");
  if (opt->nargs == 1)
    printf(" ARG");
  else if (opt->nargs > 1)
    printf(" ARG%d...ARG%d", 1, opt->nargs);
  printf("%s\n", opt->optionnal == TRUE ? "]" : "");
}
