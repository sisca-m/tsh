CC	=	cc

AR	=	ar rcs

EXT	=	c

EXEC	=	libobject.a

OBJDIR	=	build

LIBSDIR	=	libs

CFLAGS	=	-Wall -Wextra -ansi -pedantic -g3
CFLAGS	+=	-I./includes/

VPATH	=	srcs/			\
		srcs/containers/	\
		srcs/lists/		\
		srcs/arrays/		\
		srcs/strings/		\
		srcs/dicts/		\
		srcs/iterators/		\
		srcs/argsparser/	\
		srcs/filestream/

SRCS	=	utils				\
		new				\
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
		iterator_access			\
		dict_design			\
		dict_access			\
		dict_modifiers			\
		dict_print			\
		argsparser_design		\
		argsparser_add			\
		argsparser_print		\
		argsparser_parse		\
		argsparser_tests		\
		argsparser_consume		\
		argsparser_getters		\
		filestream_design		\
		filestream_getters


SRCS	:=	$(addsuffix .$(EXT), $(SRCS))

OBJS	=	$(SRCS:.$(EXT)=.o)

OBJS	:=	$(addprefix $(OBJDIR)/, $(OBJS))

all: 		$(EXEC)

$(EXEC):	$(OBJDIR) $(OBJS)
		-@echo -n Building $@ ...
		@$(AR) $@ $(filter %.o, $^)
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
