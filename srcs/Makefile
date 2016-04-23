##
## Makefile for Makefile in /home/roche_g/PSU_2015_lemipc
## 
## Made by 
## Login   <roche_g@epitech.net>
## 
## Started on  Thu Mar 17 15:08:58 2016 
## Last update Sun Apr 24 00:26:42 2016 Guillaume roche
##

CC	=	gcc

EXT	=	c

EXEC	=	ftsh

OBJDIR	=	build

CFLAGS	=	-Wall -Wextra -ansi -pedantic
CFLAGS	+=	-I./includes/

VPATH	=	srcs/

SRCS	=	main

SRCS	:=	$(addsuffix .$(EXT), $(SRCS))

OBJS	=	$(SRCS:.$(EXT)=.o)

OBJS	:=	$(addprefix $(OBJDIR)/, $(OBJS))

all: 		$(EXEC)

$(EXEC):	$(OBJDIR) $(OBJS)
		-@echo -n Building $@ ...
		@$(CC) -o $@ $(filter %.o, $^) $(LDFLAGS)
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
		-@echo Cleaning the executable ... [OK]

re:		fclean all

.PHONY:		all clean fclean re
