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

typedef struct node{
	int x;
	int y;
}Step;

int roomsize;

Square* createroom(FILE* filename);
void loadroom(FILE* filename,Square *room, Robot*, Obstacle*, Obstacle*);
Obstacle* loadob(FILE* fptr);
int obmotion(Obstacle* object,Square *room);
int addToPath(Step *Path, int pathLen, int newX, int newY); //in path.c