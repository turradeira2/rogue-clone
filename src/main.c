//include
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <string.h>

//local include
#include "../include/colors.h"
#include "../include/game_objects.h"
//#include "../include/test_maps.h"
#include "../include/room_types.h"

//const
#define ROOM_SIZE_X 26
#define ROOM_SIZE_Y 10
#define TRANSITION_SIZE 3

#define MAP_X 5
#define MAP_Y 5

//var
int lvl = 1;
int spawn_room_x, spawn_room_y, exit_room_x, exit_room_y;
int map[5][5];
char room[ROOM_SIZE_Y][ROOM_SIZE_X];

//player variables
char player_name[32];
int player_max_health = 20;
int player_health = 0;
int player_gold = 0;

int player_pos_x = 2;         // which room the player is in
int player_pos_y = 2;

int curr_room_x = 0;
int curr_room_y = 0;

void clear_screen();
void title_screen();
void name_screen();
void map_generator();
void draw_room_current();
void draw_info_box();
void game_loop();
void map_screen();
void empty_room(int room_x, int room_y);
void room_trasition();

int main()
{
	clear_screen();
	title_screen();
	clear_screen();
	name_screen();
	map_generator();
	empty_room(curr_room_x, curr_room_y);
	player_health = player_max_health;
	initscr();
	start_color();
	use_default_colors();
	init_pair(1, COLOR_GREEN, -1); // player
	init_pair(2, COLOR_WHITE, -1);  // walls
	init_pair(3, COLOR_YELLOW, -1);  // gold

	noecho();
	cbreak();
	game_loop();
	endwin();
	return 0;
}

void map_generator()
{
	srand(time(NULL));

	for(int map_y = 0; map_y<MAP_Y; map_y++)
	{
		for(int map_x = 0; map_x<MAP_X; map_x++)
		{
			int r =rand() % 100;
			if(r < 50)
			{
				map[map_y][map_x] = EMPTY_ROOM;
			}
			else if (r < 80)
			{
				map[map_y][map_x] = ENEMY_ROOM;
			}
			else if (r < 95)
			{
				map[map_y][map_x] = LOOT_ROOM;
			}
			else
			{
				map[map_y][map_x] = EXIT_ROOM;
			}
		}
	}
	spawn_room_x = rand() % MAP_X;
	spawn_room_y = rand() % MAP_Y;
	exit_room_x = rand() % MAP_X;
	exit_room_y = rand() % MAP_Y;
	int exit_x_set = 0;
	int exit_y_set = 0;
	int exit_set = 0;
	while(exit_set == 0)
	{
		if(exit_room_x == spawn_room_x)
		{
			exit_room_x = rand() % 4;
		}
		else
		{
			exit_x_set = 1;
		}

		if(exit_y_set == spawn_room_y)
		{
			exit_room_y =  rand() % 4;
		}
		else
		{
			exit_y_set = 1;
		}

		if(exit_x_set == 1 && exit_y_set == 1)
		{
			exit_set = 1;
		}
	}
	map[spawn_room_y][spawn_room_x] = START_ROOM;
	map[exit_room_y][exit_room_x] = EXIT_ROOM;
}

void game_loop()
{
	int game_over = 0;

	curr_room_x=spawn_room_x;
	curr_room_y=spawn_room_y;

	if(player_pos_x < 0 || player_pos_x >= ROOM_SIZE_X)
	{
		player_pos_x = ROOM_SIZE_X / 2;
	}
	if(player_pos_y < 0 || player_pos_y >= ROOM_SIZE_Y)
	{
		player_pos_y = ROOM_SIZE_Y / 2;
	}

	keypad(stdscr, TRUE);   // enables arrow keys
	curs_set(0);            // hide cursor

	while (game_over != 1)
	{
		clear();
		draw_room_current();
		draw_info_box();

		mvaddch(player_pos_y, player_pos_x, PLAYER | COLOR_PAIR(1) | A_BOLD);
		refresh();

		int ch = getch();
		switch (ch)
		{
			case KEY_UP:
				if(room[player_pos_y-1][player_pos_x] != '#')
					player_pos_y--;
				else
				{
					player_pos_y--; // allow transition
				}
			break;

			case KEY_DOWN:
				if(player_pos_y < ROOM_SIZE_Y - 1)
				{
					if(room[player_pos_y+1][player_pos_x] != '#')
						player_pos_y++;
				}
				else
				{
					player_pos_y++; // allow transition
				}
			break;

			case KEY_LEFT:
				if(player_pos_x > 0)
				{
					if(room[player_pos_y][player_pos_x-1] != '#')
						player_pos_x--;
				}
				else
				{
					player_pos_x--; // allow transition
				}
			break;

			case KEY_RIGHT:
				if(player_pos_x < ROOM_SIZE_X - 1)
				{
					if(room[player_pos_y][player_pos_x+1] != '#')
						player_pos_x++;
				}
				else
				{
					player_pos_x++; // allow transition
				}
			break;

			case 'q':
			case 'Q':
				game_over = 1;
				break;
		}

		room_trasition();
	}
}

void map_screen()
{
	for(int player_position_map_y = 0; player_position_map_y < MAP_Y; player_position_map_y++)
	{
		for(int player_position_map_x = 0; player_position_map_x < MAP_X; player_position_map_x++)
		{
			if(map[player_position_map_y][player_position_map_x] != 0)
			{
				printf("#");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	printf("this draws the Levels Map \n");
}

void clear_screen()
{
	printf("\033[H\033[J");
}

void title_screen()
{
	printf("\n");
	printf(ANSI_COLOR_RED     " #####    ####    ####   #    #  ######          ####   #        ####   #    #  ######\n");
	printf(ANSI_COLOR_GREEN   " #    #  #    #  #       #    #  #              #    #  #       #    #  ##   #  #     \n");
	printf(ANSI_COLOR_YELLOW  " #    #  #    #  #       #    #  #              #       #       #    #  # #  #  #     \n");
	printf(ANSI_COLOR_BLUE    " #####   #    #  #  ###  #    #  ####     ###   #       #       #    #  #  # #  ####  \n");
	printf(ANSI_COLOR_MAGENTA " #    #  #    #  #    #  #    #  #              #    #  #       #    #  #   ##  #     \n");
	printf(ANSI_COLOR_CYAN    " #    #   ####    ####    ####   ######          ####   ######   ####   #    #  ######\n");
	printf("\n");
	printf("\n");
	printf("             BY TIAGO MATOS WITH SOME HELP FROM ALEXANDRE CARDOSO\n");
	printf(ANSI_COLOR_RESET);
	printf("Press Any Key to Continue\n");
	getchar();
	printf("\n");
}

void name_screen()
{
	printf("WHAT IS THY NAME, ADVENTURER?\n");

	fgets(player_name, sizeof(player_name), stdin);

	player_name[strcspn(player_name, "\n")] = '\0';
}

void draw_room_current()
{
	 int room_type = map[curr_room_y][curr_room_x];

	 empty_room(curr_room_x, curr_room_y);

	switch (room_type)
	{
		case EXIT_ROOM:
			room[ROOM_SIZE_Y/2][ROOM_SIZE_X/2] = 'X';
			break;

		case ENEMY_ROOM:
			room[ROOM_SIZE_Y/2][ROOM_SIZE_X/2] = 'E';
			break;

		case LOOT_ROOM:
			room[ROOM_SIZE_Y/2][ROOM_SIZE_X/2] = 'G';
			break;

		default:
			empty_room(curr_room_x, curr_room_y);
			break;
	}

	for(int room_row = 0; room_row < ROOM_SIZE_Y; room_row++)
	{
		for(int room_column = 0; room_column < ROOM_SIZE_X; room_column++)
		{
			switch (room[room_row][room_column])
			{
				case '#':
					mvaddch(room_row, room_column, room[room_row][room_column] | COLOR_PAIR(2));
					break;

				case 'G':
					mvaddch(room_row, room_column, room[room_row][room_column] | COLOR_PAIR(3));
					break;

				default:
					mvaddch(room_row, room_column,room[room_row][room_column]);
					break;
			}
		}
	}
}

void draw_info_box()
{
	int info_y = ROOM_SIZE_Y + 1;
	mvprintw(info_y, 0, "PLAYER: %s", player_name);
	mvprintw(info_y + 1, 0, "HEALTH: %d / %d", player_health, player_max_health);
	mvprintw(info_y + 2, 0, "GOLD: %d", player_gold);

	/*
	printf("\n");
	printf("PLAYER_NAME\n");
	printf("HEALTH: %d / %d \n",player_health, player_max_health);
	printf("GOLD: %d \n",player_gold);
	printf("\n");
	*/
}

void empty_room(int room_x, int room_y)
{
	int gap_x_start = (ROOM_SIZE_X - TRANSITION_SIZE) / 2;
	int gap_x_end   = gap_x_start + TRANSITION_SIZE - 1;

	int gap_y_start = (ROOM_SIZE_Y - TRANSITION_SIZE) / 2;
	int gap_y_end   = gap_y_start + TRANSITION_SIZE - 1;

	for(int row = 0; row < ROOM_SIZE_Y; row++)
	{
		for(int col = 0; col < ROOM_SIZE_X; col++)
		{
			if(row == 0)
			{
				if (room_y == 0)
				{
					room[row][col] = '#';
				}
				else if(col >= gap_x_start && col <= gap_x_end)
				{
					room[row][col] = '.';  // gap
				}
				else
				{
					room[row][col] = '#';
				}
			}
			else if(row == ROOM_SIZE_Y - 1)
			{
				if (room_y == MAP_Y -1)
				{
					room[row][col] = '#';
				}
				else if(col >= gap_x_start && col <= gap_x_end)
				{
					room[row][col] = '.';  // gap
				}
				else
				{
					room[row][col] = '#';
				}
			}
			else if(col == 0)
			{
				if(room_x == 0)
				{
					room[row][col] = '#';
				}
				else if(row >= gap_y_start && row <= gap_y_end)
				{
					room[row][col] = '.';
				}
				else
				{
					room[row][col] = '#';
				}
			}
			else if( col == ROOM_SIZE_X - 1)
			{
				if(room_x == MAP_X -1)
				{
					room[row][col] = '#';
				}
				else if(row >= gap_y_start && row <= gap_y_end)
				{
					room[row][col] = '.';
				}
				else
				{
					room[row][col] = '#';
				}
			}
			else
			{
				room[row][col] = '.';
			}
		}
	}
}


void room_trasition()
{
	int gap_x_start = (ROOM_SIZE_X - TRANSITION_SIZE) / 2;
	int gap_x_end   = gap_x_start + TRANSITION_SIZE - 1;

	int gap_y_start = (ROOM_SIZE_Y - TRANSITION_SIZE) / 2;
	int gap_y_end   = gap_y_start + TRANSITION_SIZE - 1;

	// LEFT transition
	if(player_pos_x < 0 && curr_room_x > 0 &&
		player_pos_y >= gap_y_start && player_pos_y <= gap_y_end)
	{
		curr_room_x--;
		player_pos_x = ROOM_SIZE_X - 1 - (TRANSITION_SIZE / 2); // center in gap
		empty_room(curr_room_x, curr_room_y);
	}
	// RIGHT transition
	else if(player_pos_x >= ROOM_SIZE_X && curr_room_x < MAP_X - 1 &&
		player_pos_y >= gap_y_start && player_pos_y <= gap_y_end)
	{
		curr_room_x++;
		player_pos_x = TRANSITION_SIZE / 2; // center in gap
		empty_room(curr_room_x, curr_room_y);
	}
	// TOP transition
	else if(player_pos_y < 0 && curr_room_y > 0 &&
		player_pos_x >= gap_x_start && player_pos_x <= gap_x_end)
	{
		curr_room_y--;
		player_pos_y = ROOM_SIZE_Y - 1 - (TRANSITION_SIZE / 2); // center in gap
		empty_room(curr_room_x, curr_room_y);
	}
	// BOTTOM transition
	else if(player_pos_y >= ROOM_SIZE_Y && curr_room_y < MAP_Y - 1 &&
		player_pos_x >= gap_x_start && player_pos_x <= gap_x_end)
	{
		curr_room_y++;
		player_pos_y = TRANSITION_SIZE / 2; // center in gap
		empty_room(curr_room_x, curr_room_y);
	}

	// clamp player inside current room
	if(player_pos_x < 0) player_pos_x = 0;
	if(player_pos_x >= ROOM_SIZE_X) player_pos_x = ROOM_SIZE_X - 1;
	if(player_pos_y < 0) player_pos_y = 0;
	if(player_pos_y >= ROOM_SIZE_Y) player_pos_y = ROOM_SIZE_Y - 1;
}
