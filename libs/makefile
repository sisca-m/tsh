##
## Makefile for Makefile in /home/roche_g/PSU_2015_lemipc
## 
## Made by 
## Login   <roche_g@epitech.net>
## 
## Started on  Thu Mar 17 15:08:58 2016 
## Last update Tue Apr 26 00:36:23 2016 
##

CC	=	gcc

AR	=	ar rcs

EXT	=	c

EXEC	=	libobject.a

OBJDIR	=	build

LIBSDIR	=	libs

CFLAGS	=	-Wall -Wextra -ansi -pedantic -g3
CFLAGS	+=	-I./includes/			\
		-I./includes/containers		\
		-I./includes/arrays		\
		-I./includes/lists		\
		-I./includes/strings		\
		-I./includes/iterators

VPATH	=	srcs/			\
		srcs/containers/	\
		srcs/lists/		\
		srcs/arrays/		\
		srcs/strings/		\
		srcs/iterators/

SRCS	=	new				\
		dup				\
		container_capacity		\
		container_modifiers		\
		container_converters		\
		container_access		\
		list_design			\
		list_access			\
		list_print			\
		list				\
		dbl_clist			\
		dbl_list			\
		spl_clist			\
		spl_list			\
		array_design			\
		array_access			\
		array_print			\
		array_modifiers			\
		string_design			\
		string_access			\
		string_modifiers		\
		string_print			\
		string_patterns			\
		string_generators		\
		string_finders			\
		iterator_design			\
		iterator_access



SRCS	:=	$(addsuffix .$(EXT), $(SRCS))

OBJS	=	$(SRCS:.$(EXT)=.o)

OBJS	:=	$(addprefix $(OBJDIR)/, $(OBJS))

all: 		$(EXEC)

$(EXEC):	$(OBJDIR) $(OBJS)
		-@echo -n Building $@ ...
		@$(AR) -o $@ $(filter %.o, $^)
		-@echo " [OK]"

$(OBJDIR):
		-@echo -n Building objects directory ...
		@mkdir -p $(OBJDIR)
		-@echo " [OK]"

$(OBJDIR)/%.o:	%.$(EXT)
		-@echo -n Compilation of $< ...
		@$(CC) -o $@ -c $< $(CFLAGS);
		-@echo " [OK]"

clean:
		-@$(RM) -r $(OBJDIR)
		-@echo Cleaning objects files ... [OK]

fclean:		clean
		-@$(RM) $(EXEC)
		-@echo Cleaning the library file ... [OK]

re:		fclean all

.PHONY:		all clean fclean re
