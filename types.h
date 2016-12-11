#include <stdio.h>
#include <stdlib.h>
//dont forget to put other libraries if you need them

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
void parse(FILE *fp);
void obCheck(FILE *fp , char *block , char *line);
void loadroom(FILE* filename, Robot*, Obstacle*, Obstacle*, Path*);
Obstacle* loadob(FILE* fptr);
void obmotion(Obstacle* object);
int robotmotion(Robot *bot, Obstacle* ob1, Obstacle* ob2, Path* exit);
int addToPath(Step *Path, int pathLen, int newX, int newY); //in path.c
void checkFormat(FILE *fp);
