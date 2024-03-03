#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct RollerCoaster{
    char name[30];
    char world[30];
    int height;
    int time;




} ROLLER_COASTER;

int cmp(const void *a, const void *b){
    ROLLER_COASTER *left = (ROLLER_COASTER *)a;
    ROLLER_COASTER *right = (ROLLER_COASTER *)b;

    if(left->time != right->time){
        return left->time - right->time;
    }

    if(left->height != right->height){
        return -(left->height - right->height);
    }

   
   
   return strcmp(left->name, right->name);
   
    if(left->name != right->name)
    {
        return left->name - right->name;
    }


}


int main(){
    char line[101];
    int n = atoi(gets(line));
    ROLLER_COASTER coaster[n];


    for(int i = 0 ; i < n ; i++){
        gets(line);
        
        char *name = strtok(line, ";");
        char *world = strtok(NULL, ";");
        char *height = strtok(NULL, ";");
        char *time = strtok(NULL, ";");

        strcpy(coaster[i].name, name);
        strcpy(coaster[i].world, world);
        coaster[i].height = atoi(height);
        coaster[i].time = atoi(time);
    }

    qsort(coaster, n, sizeof(ROLLER_COASTER), cmp);
    printf("------------------------\n");
    for(int i = 0 ; i < n ; i++){
        printf("%s (%s): %d\n", coaster[i].name, coaster[i].world, coaster[i].time);
    }



    return EXIT_SUCCESS;
}