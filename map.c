#include "map.h"

#define MAX_NCOLS 64
#define MAX_NROWS 64
#define MAX_BUFFER 64

struct _Map {
    unsigned int nrows, ncols;
    Point *array[MAX_NROWS][MAX_NCOLS];
    Point *input, *output;
};

Map * map_new (unsigned int nrows,  unsigned int ncols){
    Map* mp = NULL;

    mp =  malloc(sizeof(Map));

    if(mp == NULL) return NULL;

    mp->array[MAX_NCOLS][MAX_NROWS] = NULL;
    mp->input = NULL;
    mp->ncols = ncols;
    mp->nrows = nrows;
    mp->output = NULL;

    return mp;
}

void map_free (Map *mp){
    free(mp);
}

Point *map_insertPoint (Map *mp, Point *p){
    mp->array[point_getCoordinateX(p)][point_getCoordinateY(p)] = point_hardcpy(p);

    return mp->array[point_getCoordinateX(p)][point_getCoordinateY(p)];
}

int map_getNcols (const Map *mp){
    if(!mp) return -1;

    return mp->ncols;
}

int map_getNrows (const Map *mp){
    if(!mp) return -1;

    return mp->nrows;
}

Point * map_getInput(const Map *mp){
    if(!mp) return NULL;

    return mp->input;
}

Point * map_getOutput (const Map *mp){
    if(!mp) return NULL;

    return mp->output;
}

Point *map_getPoint (const Map *mp, const Point *p){
    return mp->array[point_getCoordinateX(p)][point_getCoordinateY(p)];
}

Point *map_getNeighboor(const Map *mp, const Point *p, Position pos){
    if(pos == RIGHT){
        return mp->array[point_getCoordinateX(p)+1][point_getCoordinateY(p)];
    }
    else if(pos == UP){
        return mp->array[point_getCoordinateX(p)][point_getCoordinateY(p)+1];
    }
    else if(pos == LEFT){
        return mp->array[point_getCoordinateX(p)-1][point_getCoordinateY(p)];
    }
    else if(pos == DOWN){
        return mp->array[point_getCoordinateX(p)][point_getCoordinateY(p)-1];
    }
    else if(pos == STAY){
        return mp->array[point_getCoordinateX(p)][point_getCoordinateY(p)];
    }
    else return NULL;
}

Status map_setInput(Map *mp, Point *p){
    if(!mp) return ERROR;

    mp->input = point_hardcpy(p);

    return OK;
}

Status map_setOutput (Map *mp,Point *p){
    if(!mp) return ERROR;

    mp->output = point_hardcpy(p);

    return OK;
}

/*Map * map_readFromFile (FILE *pf){

}

Bool map_equal (const void *_mp1, const void *_mp2){
    int i, j;
    Bool bool;

    if(!_mp1 || !_mp2) return FALSE;

    if(map_getNcols(_mp1) == map_getNcols(_mp2) && map_getNrows(_mp1) == map_getNrows(_mp2) && map_getInput(_mp1) == map_getInput(_mp2) && map_getOutput(_mp1) == map_getOutput(_mp2)){
        for(i=0; i<map_getNrows(_mp1); i++){
            for(j=0; j<map_getNcols(_mp1); j++){
                bool = point_equal(map_getPoint(_mp1, point_new(j, i, BARRIER)), map_getPoint(_mp2, point_new(j, i, BARRIER)));
                if(bool = FALSE) return FALSE;
            }
        }
        return TRUE;
    }
    return FALSE;
}*/

int map_print (FILE*pf, Map *mp){
    int i, j;

    if(!pf){
        fprintf(pf, "Error printing map");
        return -1;
    }
    
    fprintf(pf, "%d, %d \n", map_getNrows(mp), map_getNcols(mp));
    for(i=0; i<map_getNrows(mp); i++){
        for(j=0; j<map_getNcols(mp); j++){
            point_print(pf, mp->array[j][i]);
        }
    }

    return 0;
}