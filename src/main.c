#include <stdio.h>
#include <stdlib.h>

#include "../include/rooms.h"

//const
#define MAP_SIZE_X 10
#define MAP_SIZE_y 15

//game objects
#define PLAYER "8"
#define STAIRS "H"

//colors
#define ANSI_COLOR_BLACK   "\x1b[30m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_WHITE   "\x1b[37m"
#define ANSI_COLOR_RESET   "\x1b[0m"

//background colors
#define ANSI_COLOR_BLACK_BG   "\x1b[40m"
#define ANSI_COLOR_RED_BG     "\x1b[41m"
#define ANSI_COLOR_GREEN_BG   "\x1b[42m"
#define ANSI_COLOR_YELLOW_BG  "\x1b[43m"
#define ANSI_COLOR_BLUE_BG    "\x1b[44m"
#define ANSI_COLOR_MAGENTA_BG "\x1b[45m"
#define ANSI_COLOR_CYAN_BG    "\x1b[46m"
#define ANSI_COLOR_WHITE_BG   "\x1b[47m" // Light gray background


//var
int map[MAP_SIZE_X][MAP_SIZE_y];
int lvl = 0;
int player_position[]={0,0};


//char playerC = '8';
void clear_screen();
void map_generator();
//void mapper();
void room_generator();
void draw_game_screen(); //delete in favor of draw_game_screen

int main()
{
	//clear_screen();
	empty_room();
	draw_game_screen();
	//map_generator();
	return 0;
}

/*
 * ROOM TYPES
 * '0' - EMPTY SPACE
 * '1' - EMPTY ROOM
 * '2' - ENEMY ROOM
 * '3' - CHEST ROOM
 * '?' - ????? ROOM
 */

void clear_screen()
{
	printf("\033[H\033[J");
}

void map_generator()
{
	for(int map_row = 0; map_row < MAP_SIZE_X; map_row++)
	{
		for(int map_column = 0; map_column < MAP_SIZE_y; map_column++)
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

void draw_game_screen()
{

	for(int room_row = 0; room_row < ROOM_SIZE_X; room_row++)
	{
		for(int room_column = 0; room_column < ROOM_SIZE_Y; room_column++)
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
	//edit playfield
}
