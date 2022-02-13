#include <stdlib.h>
#include <stdio.h>
#include "map.h"

int main(){
    Map *mp;
    int i;

    mp = map_new(3, 4);

    for(i=0; i<4; i++){
        map_insertPoint(mp, point_new(i, 0, BARRIER));
    }

    map_insertPoint(mp, point_new(0,1,BARRIER));
    map_insertPoint(mp, point_new(1,1,INPUT));
    map_insertPoint(mp, point_new(2,1,OUTPUT));
    map_insertPoint(mp, point_new(3,1,BARRIER));

    for(i=0; i<4; i++){
        map_insertPoint(mp, point_new(i, 2, BARRIER));
    }

    map_print(stdout, mp);
    printf("\n");

    printf("Get output neighboors: ");
    point_print(stdout, map_getNeighboor(mp, map_getOutput(mp), RIGHT));

    map_free(mp);
    return 0;
}
