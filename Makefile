NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

# Chemins vers libft et MinilibX
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
MLX_PATH = ./minilibx-linux
MLX = $(MLX_PATH)/libmlx.a

# Flags d'inclusion et de lien
INC = -I ./includes -I $(LIBFT_PATH) -I $(MLX_PATH)
MLX_LIB = -L $(MLX_PATH) -lmlx -lXext -lX11

# Chemins des fichiers source et objet
SRC_PATH = ./src
OBJ_PATH = ./obj

# Liste des fichiers sources
SRC = main.c get_next.c asset.c \
      input.c parsing.c path_validation.c
SRC_FILES = $(addprefix $(SRC_PATH)/, $(SRC))

# Fichiers objets
OBJ_FILES = $(SRC:.c=.o)
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_FILES))

# Règle principale
all: $(OBJ_PATH) $(MLX) $(LIBFT) $(NAME)

# Compilation de l'exécutable
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) $(MLX_LIB) -o $(NAME)

# Création du dossier pour les fichiers objets
$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

# Compilation de la bibliothèque libft
$(LIBFT):
	@make -C $(LIBFT_PATH)

# Compilation de MiniLibX
$(MLX):
	@make -C $(MLX_PATH)

# Compilation des fichiers objets
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	$(RM) -r $(OBJ_PATH)
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(MLX_PATH)

# Nettoyage complet + suppression de l'exécutable
fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFT_PATH)

# Recompilation complète
re: fclean all

.PHONY: all clean fclean re bonus
