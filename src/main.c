//include
#include <stdio.h>
#include <stdlib.h>

//local include
#include "../include/room_types.h"
#include "../include/rooms.h"
#include "../include/colors.h"
#include "../include/game_objects.h"

//const
//#define MAP_SIZE_X 10
//#define MAP_SIZE_Y 15

#define INFO_SIZE_X 26
#define INFO_SIZE_Y 10

//var
int map[5][5];
int lvl = 0;
char info_box[INFO_SIZE_Y][INFO_SIZE_X];

//player variables
char player_name[10];
int player_max_health = 20;
int player_health = 0;
int player_position_map[]={0,0};
int player_position_room[]={0,0};

void clear_screen();
void title_screen();
void map_generator();
void room_generator();
void draw_room_current();
void draw_game_screen();
void draw_info_box();

int main()
{

	clear_screen();
	title_screen();
	printf("\n");
	printf("Press Any Key to Continue\n");
	getchar();
	printf("\n");
	int map_test_arr[5][5];
	map_test_arr [0][0] = 0;
	map_test_arr [1][0] = 0;
	map_test_arr [2][0] = 0;
	for(int map_test_y = 0; map_test_y < 5; map_test_y++)
	{
		for(int map_test_x = 0; map_test_x < 5; map_test_x++)
		{
			printf("%i", map_test_arr[map_test_y][map_test_x]);
		}
		printf("\n");
	}
	printf("\n");
	//clear_screen();
	map_generator();
	printf("\n");
	int player_position_map_x = rand() % ((5 - 1) + 1);
	printf("%d \n",player_position_map_x);
	int player_position_map_y =rand() % ((5 - 1) + 1);
	printf("%d \n",player_position_map_y);
	player_health = player_max_health;
	draw_game_screen();
	return 0;
}

void clear_screen()
{
	printf("\033[H\033[J");
}

void title_screen()
{
	//printf(ANSI_COLOR_GREEN);
	printf("\n");
	printf(ANSI_COLOR_RED     " #####    ####    ####   #    #  ######          ####   #        ####   #    #  ######\n");
	printf(ANSI_COLOR_GREEN   " #    #  #    #  #       #    #  #              #    #  #       #    #  ##   #  #     \n");
	printf(ANSI_COLOR_YELLOW  " #    #  #    #  #       #    #  #              #       #       #    #  # #  #  #     \n");
	printf(ANSI_COLOR_BLUE    " #####   #    #  #  ###  #    #  ####     ###   #       #       #    #  #  # #  ####  \n");
	printf(ANSI_COLOR_MAGENTA " #    #  #    #  #    #  #    #  #              #    #  #       #    #  #   ##  #     \n");
	printf(ANSI_COLOR_CYAN    " #    #   ####    ####    ####   ######          ####   ######   ####   #    #  ######\n");
	printf("\n \n");
	printf("             BY TIAGO MATOS WITH SOME HELP FROM ALEXANDRE CARDOSO\n");
	printf(ANSI_COLOR_RESET);
}

/*
 * ROOM TYPES
 * '0' - EMPTY SPACE
 * '1' - EMPTY ROOM
 * '2' - ENEMY ROOM
 * '3' - LOOT ROOM
 * '?' - ????? ROOM
 */

void map_generator()
{
	for(int map_row = 0; map_row < 5; map_row++)
	{
		for(int map_column = 0; map_column < 5; map_column++)
		{
			if(map[map_row][map_column] == '\0') //check if coordinates are empty
			{
				int room_limit = 3;
				int room_type  = rand() % (room_limit + 1);
				char roomer = '0' + room_type;
				map[map_row][map_column] = roomer;
			}
			printf("%c ", map[map_row][map_column]);
		}
		printf("\n");
	}
}

void draw_room_current()
{
	for(int room_row = 0; room_row < ROOM_SIZE_Y; room_row++)
	{
		for(int room_column = 0; room_column < ROOM_SIZE_X; room_column++)
		{
			switch (room[room_row][room_column])
			{
				case '#':
					printf(ANSI_COLOR_WHITE_BG ANSI_COLOR_BLACK "%c" ANSI_COLOR_RESET , room[room_row][room_column]);
					break;

				case 'G':
					printf(ANSI_COLOR_YELLOW "%c" ANSI_COLOR_RESET , room[room_row][room_column]);
					break;

				default:
					printf("%c", room[room_row][room_column]);
					break;
			}
		}
		printf("\n");
	}
}

void draw_info_box()
{
	printf("#                        #\n");/*line 0*/
	printf("#        %d / %d         #\n",player_health, player_max_health);
	printf("#                        #\n");/*line 2*/
	printf("##########################\n");/*line 3*/
}

void draw_game_screen()
{
	draw_room_current();
	draw_info_box();
	printf("\n");
}
