# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 13:07:33 by luicasad          #+#    #+#              #
#    Updated: 2024/12/02 14:12:49 by luicasad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ============================================================================ #
#                                 COLORS                                       #
# ============================================================================ #
DEF_COLOR		=	\033[0;39m
GRAY			=	\033[0;90m
RED				=	\033[0;91m
GREEN			=	\033[0;92m
YELLOW			=	\033[0;93m
BLUE			=	\033[0;94m
MAGENTA			=	\033[0;95m
CYAN			=	\033[0;96m
WHITE			=	\033[0;97m
BLACK			=	\033[0;99m
ORANGE			=	\033[38;5;209m
BROWN			=	\033[38;2;184;143;29m
DARK_GRAY		=	\033[38;5;234m
MID_GRAY		=	\033[38;5;245m
DARK_GREEN		=	\033[38;2;75;179;82m
DARK_YELLOW		=	\033[38;5;143m
# ============================================================================ #
#                                 TARGETS                                      #
# ============================================================================ #

TARGET			= megaphone
OBJDIR 			= ./obj/
# ============================================================================ #
#                               COMPILER SETUP                                 #
# ============================================================================ #
CC 				= c++ -std=c++98
WRNFL			= -Wall -Wextra -Werror -Wconversion -Wdouble-promotion #-fsanitize=address
DBGFL			= -g3  -pg
CFLGS			= $(DBGFL) $(WRNFL) -c 
HEADS			= -I$(INCDIR)
LFLGS 			= #-fsanitize=address


SRCS_TARGET	= 	megaphone.cpp


FILE_TARGET = $(addprefix $(SRCDIR_TARGET), $(SRCS_TARGET))
OBJS_TARGET = $(addprefix $(OBJDIR), $(SRCS_MINRT:.cpp=.o))
DEPE_TARGET = $(addprefix $(OBJDIR), $(SRCS_MINRT:.cpp=.d))

$(info tests object patha $(LLIBS))

# ============================================================================ #
#                                 RULES                                        #
# ============================================================================ #
all: makedirs: $(TARGET)
-include $(DEPE_TARGET)

# .......................... directories creation ............................ #
makedirs:
	$(shell for d in $(REQUIRED_DIRS); \
 				do \
 					[[ -d $$d ]] || mkdir -p $$d; \
 				done)
 
# ....................... dependencies construction .......................... #
#for each c file create its dependency file 
#READ GNU make  manual 4.14 Generating Prerequisites Automatically.
#READ GNU gcc manuel 3.13 Options controlling the preprocessor.
%.d: %.c
	@set -e; rm -f $@; \
	$(CC) $(HEADS) -MM $< > $@.$$$$ ; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
    rm -f $@.$$$$

# .......................... targets construction ............................ #
$(TARGET): Makefile  $(OBJS_TARGET)
	@echo "$(GREEN)========== GATHERING MINIRT OBJECTS =============$(DEF_COLOR)"
	$(CC) $(LFLGS) $(OBJS_MINRT) -o $@ $(LLIBS) $(FRAMEWORKS)

# .......................... objects construction ............................ #
$(OBJDIR)%.o: $(SRCDIR_MINRT)%.c $(INCDIR)$(HEADER_iRT)
	@echo "$(GREEN)========== COMPILING MINIRT FILES ===============$(DEF_COLOR)"
	$(CC) $(CFLGS) $< -o $@ $(HEADS)  

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LFLAGS)

show:
	@printf "UNAME		: $(UNAME)\n"
	@printf "NAME  		: $(NAME)\n"
	@printf "CC    		: $(CC)\n"
	@printf "CFLAGS		: $(CFLGS)\n"
	@printf "LFLAGS		: $(LFLGS)\n"
	@printf "WFLAGS		: $(WRNFL)\n"
	@printf "SRC		: $(SRC)\n"
	@printf "OBJ		: $(OBJ)\n"
	@printf "MINRT		: $(MINRT)\n"
	@printf "BONUS		: $(BONUS)\n"
	@printf "TESTS		: $(TESTS)\n"
	@printf "OBJDIR		: $(OBJDIR)\n"
	@printf "INCDIR		: $(INCDIR)\n"
	@printf "LIBDIR		: $(LIBDIR)\n"
	@printf "LIBSYS		: $(LIBSYS)\n"
	@printf "OBJS_MINRT : $(OBJS_MINRT)\n"


clean:
	rm -f $(TARGET) $(OBJ)
	rm -rf $(OBJDIR)
	
fclean: clean
	rm -f $(TARGET)
	rm -rf $(LIBDIR)
	rm -rf $(OBJDIR)

re: fclean all

rebonus : fclean bonus

norma:
	@echo "$(ORANGE)========== CHECKING NORME $(BONUS) ==============$(DEF_COLOR)"
	norminette $(SRCDIR_BONUS)
#	@echo "$(MAGENTA)========== CHECKING NORME $(TESTS) ==============$(DEF_COLOR)"
#	norminette $(SRCDIR_TESTS)
#	@echo "$(WHITE)========== CHECKING NORME $(SRCDIR_PRINT) ==============$(DEF_COLOR)"
#	$(MAKE) -C $(SRCDIR_PRINT)  norma
#	@echo "$(WHITE)========== CHECKING NORME $(SRCDIR_FTCOMPLEX) ==============$(DEF_COLOR)"
#	$(MAKE) -C $(SRCDIR_FTCOMPLEX)  norma
	@echo "$(DARK_GRAY)========== CHECKING NORME $(SRCDIR_LIBFT) ==============$(DEF_COLOR)"
	$(MAKE) -C $(SRCDIR_LIBFT)  norma
	@echo "$(YELLOW)========== CHECKING NORME $(SRCDIR_GETNL) ==============$(DEF_COLOR)"
	$(MAKE) -C $(SRCDIR_GETNL)  norma
	@echo "$(DARK_GREEEN)========== CHECKING NORME $(SRCDIR_CHUNK) ==============$(DEF_COLOR)"
	$(MAKE) -C $(SRCDIR_CHUNK)  norma
	@echo "$(BLUE)========== CHECKING NORME $(SRCDIR_VEC3) ==============$(DEF_COLOR)"
	$(MAKE) -C $(SRCDIR_VEC3)  norma
	@echo "$(YELLOW)========== CHECKING NORME $(SRCDIR_COLOR) ==============$(DEF_COLOR)"
	$(MAKE) -C $(SRCDIR_COLOR)  norma
	@echo "$(MID_GRAY)========== CHECKING NORME $(SRCDIR_POINT) ==============$(DEF_COLOR)"
	$(MAKE) -C $(SRCDIR_POINT)  norma
	@echo "$(DARK_YELLOW)========== CHECKING NORME $(SRCDIR_ELEME) ==============$(DEF_COLOR)"
	$(MAKE) -C $(SRCDIR_ELEME)  norma
	@echo "$(DARK_CYAN)========== CHECKING NORME $(SRCDIR_CAMER) ==============$(DEF_COLOR)"
	$(MAKE) -C $(SRCDIR_CAMER)  norma
	@echo "$(DARK_GRAY)========== CHECKING NORME $(SRCDIR_AMBIL) ==============$(DEF_COLOR)"
	$(MAKE) -C $(SRCDIR_AMBIL)  norma
	@echo "$(DARK_BLACK)========== CHECKING NORME $(SRCDIR_LIGHT) ==============$(DEF_COLOR)"
	$(MAKE) -C $(SRCDIR_LIGHT)  norma
	@echo "$(DARK_BLUE)========== CHECKING NORME $(SRCDIR_HITTABLE) ==============$(DEF_COLOR)"
	$(MAKE) -C $(SRCDIR_HITRECORD)  norma
	@echo "$(YELLOW)========== CHECKING NORME $(SRCDIR_HITRECORD) ==============$(DEF_COLOR)"
	$(MAKE) -C $(SRCDIR_HITTABLE)  norma
	@echo "$(DARK_GREEN)========== CHECKING NORME $(SRCDIR_INTERVAL) ==============$(DEF_COLOR)"
	$(MAKE) -C $(SRCDIR_INTERVAL)  norma
	@echo "$(DARK_GREEN)========== CHECKING NORME $(SRCDIR_RAY) ==============$(DEF_COLOR)"
	$(MAKE) -C $(SRCDIR_RAY)  norma
	@echo "$(GREEN)============ CHECKING NORME $(MINRT) ==============$(DEF_COLOR)"
	norminette $(SRCDIR_MINRT) 
	@echo "$(GREEN)============ CHECKING NORME $(INCDIR) ==============$(DEF_COLOR)"
	norminette $(INCDIR)
	@echo "$(RED)========== CHECKING NORME $(SRCDIR_MLIBX) ==============$(DEF_COLOR)"
	#$(MAKE) -C $(SRCDIR_MLIBX)  norma
	#norminette $(SRCDIR_MLIBX)

profile:
	valgrind --tool=callgrind ./$(TARGET)
	callgrind_annotate

leaks:
	valgrind -s --error-limit=no --tool=memcheck --leak-check=full ./$(TARGET)

.PHONY: all bonus test clean fclean re rebonus norma profile leaks