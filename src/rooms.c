#include "../include/rooms.h"

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
