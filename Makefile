NAME		= cub3D
NAME_BON	= cub3D_bonus

CC		:= cc
FLAGS	:=  -Wunreachable-code -Ofast #-fsanitize=address -g
LIBMLX	:= /USERS/$(USER)/MLX42
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

INCLUDES = -I$(HEADERS_DIRECTORY) -I $(LIBMLX)/include

HEADERS_DIRECTORY = include/
HEADERS_LIST =	cub3D.h \
				libft.h

HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_DIRECTORY =	./
SOURCES_LIST =	cub3D.c 		\
				parse.c 		\
				raycast.c 		\
				error_one.c		\
				xtractfunc.c	\
				xtractfunc_2.c	\
				xtractfunc_3.c	\
				get_next_line.c	\
				filter_m.c		\
				movs.c			\
				bonufication.c	\
				clean_up.c		\
				xtra_func.c		\
				xtra_func_2.c	\
				get_next_line_utils.c

SOURCES_DIRECTORY_BON =	./bonus
SOURCES_LIST_BON =	bonufication_bonus.c\
				clean_up_bonus.c	\
				cub3D_bonus.c		\
				error_one_bonus.c	\
				filter_m_bonus.c	\
				movs_bonus.c		\
				parse_bonus.c		\
				raycast_bonus.c		\
				xtra_func_2_bonus.c	\
				xtra_func_bonus.c	\
				xtractfunc_2_bonus.c\
				xtractfunc_3_bonus.c\
				xtractfunc_bonus.c


SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))
SOURCES_BON = $(addprefix $(SOURCES_DIRECTORY_BON), $(SOURCES_LIST_BON))

LIBFT_DIRECTORY =	libft/
LIBFT_SOURCES_LIST =	ft_split.c		\
						ft_strchr.c		\
						ft_atoi.c		\
						ft_itoa.c		\
						ft_isdigit.c	\
						ft_bzero.c		\
						ft_strjoin.c	\
						ft_memset.c 	\
						ft_strnstr.c	\
						ft_strlen.c 	\
						ft_strncmp.c 	\
						ft_strdup.c 	\
						ft_calloc.c 	\
						ft_substr.c 	\
						ft_lstnew.c 	\
						ft_lstadd_back.c\
						ft_lstlast.c	\
						ft_lstsize.c	\
						ft_lstclear.c	\
						ft_lstiter.c

LIBFT_SOURCES = $(addprefix $(LIBFT_DIRECTORY), $(LIBFT_SOURCES_LIST))


SOURCES_LIST += $(LIBFT_SOURCES_LIST)
SOURCES += $(LIBFT_SOURCES)
SOURCES_LIST_BON += $(LIBFT_SOURCES_LIST)
SOURCES_BON += $(LIBFT_SOURCES)

OBJECTS_DIRECTORY = objects/
OBJECTS_DIRECTORY_BON = objects_bon/
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))
OBJECTS_BON	= $(addprefix $(OBJECTS_DIRECTORY_BON), $(OBJECTS_LIST_BON))

OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS_LIST_BON = $(patsubst %.c, %.o, $(SOURCES_LIST_BON))


all: libmlx $(NAME)

bonus : libmlx $(NAME_BON)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): $(OBJECTS_DIRECTORY) $(OBJECTS)
	@$(CC) $(FLAGS) $(INCLUDES) $(OBJECTS) $(LIBS) -o $(NAME)

$(NAME_BON): $(OBJECTS_DIRECTORY_BON) $(OBJECTS_BON)
	@$(CC) $(FLAGS) $(INCLUDES) $(OBJECTS_BON) $(LIBS) -o $(NAME_BON)

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)

$(OBJECTS_DIRECTORY_BON):
	@mkdir -p $(OBJECTS_DIRECTORY_BON)

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

$(OBJECTS_DIRECTORY_BON)%.o : $(SOURCES_DIRECTORY_BON)%.c $(LIBFT_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@


clean:
	@rm -rf $(OBJECTS_DIRECTORY) $(OBJECTS_DIRECTORY_BON)

fclean: clean
	@rm -f $(NAME) $(NAME_BON)

re:	fclean all

.PHONY: all clean fclean re libmlx bonus