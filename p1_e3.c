#include <stdlib.h>
#include <stdio.h>
#include "map.h"

int main(int argc, char *argv[]){
    if(argc != 2){
        fprintf(stdout, "Error al introducir argumentos.\n");
        return -1;
    }

    FILE *pf = NULL;
    Map *mp = NULL;
    Point *right_inferior = NULL;

    pf = fopen(argv[1], "r");
    if(pf==NULL){
        printf("Error abriendo el fichero\n");
        return -1;
    }

    mp = map_readFromFile(pf);
    if(mp == NULL){
        printf("Error iniciando mapa\n");
        fclose(pf);
        return -1;
    }

    fprintf(stdout, "Maze:\n");
    if(map_print(stdout, mp) == -1){
        printf("Error al imprimir\n");
        map_free(mp);
        fclose(pf);
        return -1;
    }

    fprintf(stdout, "\nGet output neighboors:\n");
    point_print(stdout, map_getNeighboor(mp, map_getOutput(mp), UP));
    point_print(stdout, map_getNeighboor(mp, map_getOutput(mp), DOWN));
    point_print(stdout, map_getNeighboor(mp, map_getOutput(mp), LEFT));
    point_print(stdout, map_getNeighboor(mp, map_getOutput(mp), RIGHT));

    fprintf(stdout, "\n");

    map_free(mp);
    point_free(right_inferior);
    fclose(pf);

    return 0;
}