#include "point.h"
#include <string.h>

struct _Point{
    int x, y;
    char symbol;
    Bool visited;
};

Point * point_new (int x, int y, char symbol){
    Point* p = NULL;

    p = malloc(sizeof(Point));

    if(p == NULL) return NULL;

    p->x = x;
    p->y = y;
    p->symbol = symbol;
    p->visited = FALSE;

    return p;
}

void point_free (Point *p){
    free(p);
}

int point_getCoordinateX (const Point *p){
    if(!p) return -1;

    return p->x;
}

int point_getCoordinateY (const Point *p){
    if(!p) return -1;

    return p->y;
}

char point_getSymbol (const Point *p){
    if(p == NULL) return -1;

    return p->symbol;
}

Status point_setCoordinateX (Point *p, int x){
    if(!p) return ERROR;

    p->x = x;
    
    return OK;
}

Status point_setCoordinateY (Point *p, int y){
    if(!p) return ERROR;

    p->y = y;

    return OK;
}

Status  point_setSymbol (Point *p, char c){
    if(p == NULL) return ERROR;

    p->symbol = c;

    return OK;
}

Bool point_getVisited (const Point *p){
    if(!p) return FALSE;

    return p->visited;
}

Status point_setVisited (Point *p, Bool bol){
    if(!p) return ERROR;

    p->visited = bol;

    return OK;
}

Point *point_hardcpy (const Point *src){
    Point *trg;

    trg = point_new(point_getCoordinateX(src), point_getCoordinateY(src), point_getSymbol(src));
    return trg;
}

Bool point_equal (const void *p1, const void *p2){
    if(!p1 || !p2) return FALSE;

    if(point_getCoordinateX(p1) == point_getCoordinateX(p2) && point_getCoordinateY(p1) == point_getCoordinateY(p2) && point_getSymbol(p1) == point_getSymbol(p2)) return TRUE;
    else return FALSE;
}

int point_print (FILE *pf, const Point *p){
    if(!p){
        fprintf(pf, "Error printing point");
        return -1;
    }
    
    fprintf(pf, "[(%d, %d): %c]", p->x, p->y, p->symbol);

    return 0;
}

Status point_euDistance (const Point *p1, const Point *p2, double *distance){
    double potencia_1, potencia_2;

    potencia_1 = pow(point_getCoordinateX(p1)-point_getCoordinateX(p2), 2);
    potencia_2 = pow(point_getCoordinateY(p1)-point_getCoordinateY(p2), 2);

    *distance = sqrt(potencia_1 + potencia_2);

    return OK;
}

int point_cmpEuDistance (const void *p1, const void *p2){
    return 0;
}

