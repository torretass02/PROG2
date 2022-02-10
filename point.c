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
    if(p == NULL || c == NULL) return ERROR;

    if(!strcpy(p->symbol, c)) return ERROR;

    else return OK
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

}

Bool point_equal (const void *p1, const void *p2){
    if(!p1 || !p2) return FALSE;

    if(p1 == p2) return TRUE;
    else return FALSE;
}

int point_print (FILE *pf, const Point *p){
    if(!p){
        fprintf(pf, "Error printing point");
        return -1;
    }
    
    fprintf(pf, "[(%d, %d): %s]", p->x, p->y, p->symbol);

    return 0;
}

