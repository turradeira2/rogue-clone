#include "../include/rooms.h"
#include <stdlib.h>

//game objects
#define PLAYER "8"
#define STAIRS "H"
//#define CHEST ""

char room[ROOM_SIZE_Y][ROOM_SIZE_X];

void empty_room()
{
    for(int room_row = 0; room_row < ROOM_SIZE_Y; room_row++)
    {
        for(int room_column = 0; room_column < ROOM_SIZE_X; room_column++)
        {
            if( room_row == 0 || room_row == ROOM_SIZE_Y - 1)
            {
                room[room_row][room_column] = '#';
            }
            else if(room_column == 0 || room_column == ROOM_SIZE_X - 1)
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


void loot_room()
{
    empty_room();
    int loot_position_x = rand() % (ROOM_SIZE_X-1 - 1) + 1;
    int loot_position_y = rand() % (ROOM_SIZE_Y-1 - 1) + 1;
    room[loot_position_x][loot_position_y] = LOOT_GOLD;
}

/*
 * LOOT TYPES
 * 0 - GOLD - yellow 'G' * amount
 *
 */

/*
 * ROOM TYPES
 * '0' - EMPTY SPACE
 * '1' - EMPTY ROOM
 * '2' - ENEMY ROOM
 * '3' - LOOT ROOM
 * '?' - ????? ROOM
 */
