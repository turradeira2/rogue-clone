//#include <stdlib.h>

#include "../include/test_maps.h"
//#include "../include/rooms.h"
//#include "../include/game_objects.h"

int test_map[MAP_X][MAP_Y];

void test_map_1()
{
    test_map[0][0]=0;
    test_map[0][1]=1;
    test_map[0][2]=1;
    test_map[0][3]=0;
    test_map[0][4]=0;

    test_map[1][0]=0;
    test_map[1][1]=1;
    test_map[1][2]=1;
    test_map[1][3]=1;
    test_map[1][4]=0;

    test_map[2][0]=0;
    test_map[2][1]=0;
    test_map[2][2]=1;
    test_map[2][3]=1;
    test_map[2][4]=0;

    test_map[3][0]=0;
    test_map[3][1]=1;
    test_map[3][2]=1;
    test_map[3][3]=1;
    test_map[3][4]=0;

    test_map[4][0]=0;
    test_map[4][1]=1;
    test_map[4][2]=1;
    test_map[4][3]=1;
    test_map[4][4]=0;

    /*
     * {0,1,1,0,0},
     * {0,1,1,1,0},
     * {0,0,1,1,0},
     * {0,1,1,1,0},
     * {0,1,1,1,0}
     */
}
