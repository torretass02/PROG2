#include <math.h>
#include "point.h"

#define MAX_RAND 10
int main() {
Point *p[5] = {NULL};
Point *origen;
int i, j;
double d;

p[0] = point_new(6,3,BARRIER);
p[1] = point_new(5,7,BARRIER);
p[2] = point_new(5,3,BARRIER);
p[3] = point_new(2,6,BARRIER);
p[4] = point_new(1,9,BARRIER);

origen = point_new (0, 0, BARRIER);
for (i=0; i < 5; i++) {
    fprintf(stdout, "Point p[%d] = ", i);
    point_print (stdout, p[i]);
    point_euDistance (p[i], origen, &d);
    fprintf (stdout, " distance: %f\n", d);
}

for(i=0; i<5;i++){
    for(j=0; j<5; j++){
        if(point_cmpEuDistance(p[i], p[j])== -1){
            fprintf(stdout, "p[%d] < p[%d]: TRUE\n", i, j);
        }
        else{
            fprintf(stdout, "p[%d] < p[%d]: FALSE\n", i, j);
        }
    }
}

return 0;
}