#include <stdio.h>
//#include <stdlib.h>

//const
#define ROOM_SIZE_X 10
#define ROOM_SIZE_Y 15

//game objects
#define PLAYER "8"
#define STAIRS "H"



//var
char room[ROOM_SIZE_X][ROOM_SIZE_Y];
int lvl = 0;
int player_position[]={0,0};

//char playerC = '8';

void room_generator();
void create_playfield();
void draw_playfield();

int main()
{
	room_generator();
	create_playfield();
	return 0;
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

void create_playfield()
{}

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
	//edit and print playfield
}

/*
 * NOTES:
 *
 * ARRAYS START AT 0 DUMBASS
 */
