#include <stdio.h>
//#include <stdlib.h>

//const
#define ROOM_SIZE_X 10
#define ROOM_SIZE_Y 15

#define MAP_SIZE_X 50
#define MAP_SIZE_y 100

//game objects
#define PLAYER "8"
#define STAIRS "H"


//var
char map[MAP_SIZE_X][MAP_SIZE_y];
char room[ROOM_SIZE_X][ROOM_SIZE_Y];
int lvl = 0;
int player_position[]={0,0};


//char playerC = '8';

void map_generator();
void room_generator();
void draw_playfield(); //delete in favor of draw_game_screen

int main()
{
	map_generator();
	//room_generator();
	return 0;
}

void map_generator()
{
	for(int map_row = 0; map_row < MAP_SIZE_X; map_row++)
	{
		for(int map_column = 0; map_column < MAP_SIZE_y; map_column++)
		{
			map[map_row][map_column] = '|';
			printf("%c ", map[map_row][map_column]);
		}
		printf("\n");
	}

}

void room_generator()
{
	for(int room_row = 0; room_row < ROOM_SIZE_X; room_row++)
	{
		for(int room_column = 0; room_column < ROOM_SIZE_Y; room_column++)
		{
			if( room_row == 0 || room_row == ROOM_SIZE_X - 1)
			{
				room[room_row][room_column] = '#';
			}
			else if(room_column == 0 || room_column == ROOM_SIZE_Y - 1)
			{
				room[room_row][room_column] = '#';
			}
			else
			{
				room[room_row][room_column] = ' ';
			}
		}
	}
}


void draw_playfield()
{
	for(int room_row = 0; room_row < ROOM_SIZE_X; room_row++)
	{
		for(int room_column = 0; room_column < ROOM_SIZE_Y; room_column++)
		{
			printf("%c ", room[room_row][room_column]);
		}
		printf("\n");
	}
	//edit playfield
}
