#include "map.h"

int main(int argc){
    const Point *p1, *p2;
    double d;
    p1 = point_new (6, 3, BARRIER);
    p2 = point_new (0, 0, SPACE);
    point_euDistance (p1, p2, &d);
    printf ("%lf \n", d);

    return 0;
}