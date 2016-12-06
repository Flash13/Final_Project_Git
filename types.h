#include <stdio.h>
#include <stdlib.h>
//dont forget to put other libraries if you need them

typedef struct sq{
int check;
} Square;

typedef struct obstacle{
int speed;
int x;
int y;
int ns;
int ew;
} Obstacle;

typedef struct robot{
int x;
int y;
} Robot;

typedef struct path{
int x;
int y;
} Path;

int roomsize;

Square* createroom(FILE* filename);
void loadroom(FILE* filename,Square *room, Robot*, Obstacle*, Obstacle*, Path*);
Obstacle* loadob(FILE* fptr);
int obmotion(Obstacle* object,Square *room);
int robotmotion(Square *room, Robot *bot, Obstacle* ob1, Obstacle* ob2, Path* exit);