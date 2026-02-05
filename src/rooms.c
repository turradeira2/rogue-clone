#include "../include/rooms.h"
#include <stdlib.h>

#define ROOM_SIZE_X 10
#define ROOM_SIZE_Y 15

char room[ROOM_SIZE_X][ROOM_SIZE_Y];

void empty_room()
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

void chest_room()
{
    empty_room();
    int chest_position_x = 0;
    int chest_position_y = 0;
    chest_position_x = rand() % (1, ROOM_SIZE_X-1);
}

/*
 * ROOM TYPES
 * '0' - EMPTY SPACE
 * '1' - EMPTY ROOM
 * '2' - ENEMY ROOM
 * '3' - CHEST ROOM
 * '?' - ????? ROOM
 */
