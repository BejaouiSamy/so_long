#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

extern int	g_chest_counter;
extern int	g_exit_counter;

typedef struct	s_map
{
	char	**grid;
	int	width;
	int	height;
	int	collectibles;
	int	gelano;
	int	popo;
	int	glove;
	int	exit;
	int	player;
}	t_map;

typedef struct	s_textures
{
	void	*wall;
	void	*floor;
	void	*collectible;
	void	*player;
	void	*gelano;
	void	*popo;
	void	*glove;
	void	*enemy;
	void	*enemy_right;
	void	*enemy_left;
	void	*exit_frames[6];
	void	*chest_frames[4];
}	t_textures;

typedef struct	s_enemy
{
	int	x;
	int	y;
	int	dir;
}	t_enemy;

typedef struct	s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct	s_game
{
	void	*mlx;
	void	*win;
	t_map	*map;
	t_textures	textures;
	t_player	player;
	t_player	exit;
	int	exit_current_frame;
	int	chest_current_frame;
	t_enemy	enemy;
	int	enemy_timer;
	int	steps;
}	t_game;

typedef struct	s_queue
{
	int	x;
	int	y;
	struct	s_queue *next;
}	t_queue;

// Animation
int	animate_exit(t_game *game, int *exit_counter);
int	animate_chest(t_game *game, int *frame_counter);
int	load_exit_textures(t_game *game, int *width, int *height);
int	load_chest_textures(t_game *game, int *width, int *height);

// Asset/Textures
void	load_basic_texture_1(t_game *game, int *width, int *height);
int	load_basic_textures(t_game *game, int *width, int *height);
void	draw_map_1(t_game *game, int y, int x);
void	draw_map(t_game *game);
int	load_textures(t_game *game);

// Enemy
void	update_x_position(t_game *game);
void	move_enemies(t_game *game);
void	check_collision(t_game *game);
void	add_enemy(t_game *game, int x, int y);

// Parsing
void	count_map_elements(t_game *game, char *line, int y);
int	checks_wall(t_game *game);
int	parse_map(t_game *game, char *filename);
int	add_line_to_map(t_game *game, char *line);
int	validate_map(t_game *game);
int	check_horizontal_walls(t_game *game);
int	check_vertical_walls(t_game *game);
int	read_map_file(t_game *game, int fd);
int	init_map_structures(t_game *game);
int	check_line_validity(t_game *game, char *line, int *len);
int	allocate_new_grid(t_game *game, char *line, char ***new_grid);
void	count_collectibles(t_game *game, char element);
void	process_map_element(t_game *game, char element, int x, int y);

// Free function
void	free_textures(t_game *game);
void	free_loop(t_game *game);
int	free_game(t_game *game);
void	free_map(t_map *map);
void	free_visited(char **visited, int height);

// Get next line
char	*ft_append_buffer(char *line, char *buffer, int line_len, int buffer_len);
char	*get_next_line(int fd);
int	ft_strlen_until(char *str, char c);
char	*ft_sstrdup(char *s);
int	has_char(char *str, char c);
void	extract_line_1(char **stash, char **line, int *line_len);
char	*extract_line(char **stash);

// Input/Movement
void	move_player(t_game *game, int dx, int dy);
int	handle_collectibles(t_game *game, char new_cell);
int	check_cell(t_game *game, char new_cell);
void	display_steps(t_game *game);
int	key_press(int keycode, t_game *game);

// Path validation BFS
void	enqueue(t_queue **queue, int x, int y);
void	dequeue(t_queue **queue);
int	bfs(t_game *game, char **visited, int *c_found, int *e_found);
int	check_path(t_game *game);
int	is_valid_position(t_map *map, int x, int y, char **visited);
void	print_game_info(t_game *game);
void	process_node(t_game *game, char **visited, int x, int y, int *c_found, int *e_found, t_queue **queue);
char	**init_visited(t_game *game);

// in Main file function
int	check_file_extension(char *str);
int	game_loop(t_game *game);
int	initialize_game(t_game *game, char *map_path);
int	handle_error(char *msg, t_game *game);

# endif
