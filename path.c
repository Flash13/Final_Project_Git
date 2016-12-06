#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<limits.h>
#include<stdbool.h>

typedef struct node{
	int x;
	int y;
}Step;

int addToPath(Step *Path, int pathLen)
{
	//Each time the robot moves
	pathLen++;
	Path = realloc(Path, pathLen);
	*(Path+(pathLen-1))->x = (x of new step);
	*(Path+(pathLen-1))->y = (y of new step);
	
	return pathLen;
}
