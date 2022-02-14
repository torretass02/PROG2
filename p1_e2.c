#include <stdlib.h>
#include <stdio.h>
#include "map.h"

int main(){
    Map *mp;
    int i;
    Point *p[12];
    mp = map_new(3, 4);

    for(i=0;i<4;i++){
        p[i] = point_new(i, 0, BARRIER);
    }

    p[4] = point_new(0,1,BARRIER);
    p[5] = point_new(1,1,INPUT);
    p[6] = point_new(2,1,OUTPUT);
    p[7] = point_new(3,1,BARRIER);
    p[8] = point_new(0, 2, BARRIER);
    p[9] = point_new(1, 2, BARRIER);
    p[10] = point_new(2, 2, BARRIER);
    p[11] = point_new(3, 2, BARRIER);

    for(i=0; i<12; i++){
        map_insertPoint(mp, p[i]);
    }
    
    map_setOutput(mp, p[6]);

    map_print(stdout, mp);
    printf("\n");

    printf("Get output neighboors: ");
    printf("\n");

    for(i=0; i<4; i++){
        point_print(stdout, map_getNeighboor(mp, map_getOutput(mp), i));
    }
    printf("\n");

    map_free(mp);

    for(i=0; i<12; i++){
        point_free(p[i]);
    }

    return 0;
}
