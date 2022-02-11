
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
        printf("Equal points p[0] and p[1]? YES \n");
    }
    else{
        printf("Equal points p[0] and p[1]? NO \n");
    }

    p[2] = point_hardcpy(p[0]);
    printf("Creating p[2]: [(%d, %d): %c] \n", point_getCoordinateX(p[2]), point_getCoordinateY(p[2]), point_getSymbol(p[2]));

    printf("\n");
    if(point_equal(p[0], p[2])==TRUE){
        printf("Equal points p[0] and p[2]? YES \n");
    }
    else{
        printf("Equal points p[0] and p[2]? NO \n");
    }

    point_setSymbol(p[2], SPACE);
    printf("Modifying p[2]: [(%d, %d): %c] \n", point_getCoordinateX(p[2]), point_getCoordinateY(p[2]), point_getSymbol(p[2]));

    printf("\n");
    if(point_equal(p[0], p[2])==TRUE){
        printf("Equal points p[0] and p[2]? YES \n");
    }
    else{
        printf("Equal points p[0] and p[2]? NO \n");
    }

    p[3] = point_hardcpy(p[0]);

    if(point_equal(p[3], p[0])==TRUE){
        printf("Assign p[3] = p[0] \n");
    }

    point_setSymbol(p[3], OUTPUT);
    printf("Modifying p[3]: [(%d, %d): %c] \n", point_getCoordinateX(p[3]), point_getCoordinateY(p[3]), point_getSymbol(p[3]));

    for(i=0;i<4;i++){
        printf("[(%d, %d): %c]", point_getCoordinateX(p[i]), point_getCoordinateY(p[i]), point_getSymbol(p[i]));
    }
}
