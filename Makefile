NAME	= cub3D

CC		:= cc
FLAGS	:=  -Wunreachable-code -Ofast -fsanitize=address -g
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

SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

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

OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

.PHONY: all clean fclean re libmlx

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): $(OBJECTS_DIRECTORY) $(OBJECTS)
	@$(CC) $(FLAGS) $(INCLUDES) $(OBJECTS) $(LIBS) -o $(NAME)

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

$(OBJECTS_DIRECTORY)%.o : $(LIBFT_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

clean:
	@rm -rf $(OBJECTS_DIRECTORY)

fclean: clean
	@rm -f $(NAME)

re:	fclean all
