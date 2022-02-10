
#include <stdlib.h>
#include <stdio.h>
#include "point.h"
int main(){
    Point *p[4];
    Point *t;
    int i;

    p[0] = point_new(0, 0, BARRIER);
    p[1] = point_new(0, 1, BARRIER);

    for(i=0;i<2;i++){
        printf("[(%d, %d): %c]", point_getCoordinateX(p[i]), point_getCoordinateY(p[i]), point_getSymbol(p[i]));
    }
    printf("\n");
    if(point_equal(p[0], p[1])==TRUE){
        printf("Equal points p[0] and p[1]? YES");
    }
    else{
        printf("Equal points p[0] and p[1]? NO");
    }

    p[2] = point_hardcpy(p[0]);
    printf("Creating p[2]: [(%d, %d): %c]", point_getCoordinateX(p[2]), point_getCoordinateY(p[2]), point_getSymbol(p[2]));

}
