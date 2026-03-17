#include "../include/rooms.h"

char room[ROOM_SIZE_Y][ROOM_SIZE_X];
//#define TRANSITION_SIZE 3

void empty_room()
{
    int gap_x_center = ROOM_SIZE_X / 2;
    int gap_y_center = ROOM_SIZE_Y / 2;

    int gap_x_start = gap_x_center - TRANSITION_SIZE / 2;
    int gap_x_end = gap_x_center + TRANSITION_SIZE / 2;

    int gap_y_start = gap_y_center - TRANSITION_SIZE / 2;
    int gap_y_end = gap_y_center + TRANSITION_SIZE / 2;

    for(int room_row = 0; room_row < ROOM_SIZE_Y; room_row++)
    {
        for(int room_column = 0; room_column < ROOM_SIZE_X; room_column++)
        {
            if( room_row == 0 || room_row == ROOM_SIZE_Y - 1)
            {
                if (room_column >= gap_x_start && room_column <= gap_x_end)
                {
                    room[room_row][room_column] = '.';
                }
                else
                {
                    room[room_row][room_column] = '#';
                }
            }
            else if(room_column == 0 || room_column == ROOM_SIZE_X - 1)
            {
                if(room_row >= gap_y_start && room_row <= gap_y_end)
                {
                    room[room_row][room_column] = '.';
                }
                else
                {
                    room[room_row][room_column] = '#';
                }
            }
            else
            {
                room[room_row][room_column] = '.';
            }
        }
    }
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
