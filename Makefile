CC	=	gcc

EXT	=	c

EXEC	=	ftsh

LIBS	=	libobject.a

OBJDIR	=	build

LIBSDIR	=	libs

CFLAGS	=	-Wall -Wextra -ansi -pedantic -g3
CFLAGS	+=	-I./srcs/includes/	\
		-I./libs/includes/
CFLAGS	+=	-L$(LIBSDIR) -lobject

VPATH	=	srcs/

SRCS	=	main	\
		env

SRCS	:=	$(addsuffix .$(EXT), $(SRCS))

OBJS	=	$(SRCS:.$(EXT)=.o)

OBJS	:=	$(addprefix $(OBJDIR)/, $(OBJS))

all: 		$(LIBS) $(EXEC)

$(LIBS):
		@$(MAKE) -C $(LIBSDIR)

$(EXEC):	$(OBJDIR) $(OBJS)
		-@echo -n Building $@ ...
		@$(CC) -o $@ $(filter %.o, $^) $(LDFLAGS) $(CFLAGS)
		-@echo " [OK]"

$(OBJDIR):
		-@echo -n Building objects directory ...
		@mkdir -p $(OBJDIR)
		-@echo " [OK]"

$(OBJDIR)/%.o:	%.$(EXT)
		-@echo -n Compilation of $< ...
		@$(CC) -o $@ -c $< $(CFLAGS)
		-@echo " [OK]"

clean:
		-@$(MAKE) clean -C $(LIBSDIR)
		-@$(RM) -r $(OBJDIR)
		-@echo Cleaning objects files ... [OK]

fclean:		clean
		-@$(MAKE) fclean -C $(LIBSDIR)
		-@$(RM) $(EXEC)
		-@echo Cleaning the executable ... [OK]

re:		fclean all

.PHONY:		all clean fclean re
