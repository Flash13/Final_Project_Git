#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "types.h"


int main (void)
{
	int array[6] = {1,3,1,4,2,4};
	
	int length=1, i=0;
	
	Step *Path = malloc(sizeof(Step));
	
	length = addToPath(Path, length, array[0], array[1]);
	length = addToPath(Path, length, array[2], array[3]);
	length = addToPath(Path, length, array[4], array[5]);
	
	for(i=0; i<3; i++)
		printf("Path[%d]: x=%d, y=%d\n", i, Path[i].x, Path[i].y);
	
	return 0;
}
//send the  Path pointer, the pathLen, bot->x, and bot->y 
int addToPath(Step *Path, int pathLen, int newX, int newY)
{
	//Each time the robot moves
	pathLen++;
	Path = realloc(Path, pathLen); //add one to the number of structs in Path
	(Path+(pathLen-2))->x = newX; //add bot->x to the new step's 'x'
	(Path+(pathLen-2))->y = newY; //add bot->y to the new step's 'y'
	
	return pathLen; //just to keep track, nothing needs to be done to pathLen outside of this function, just sent back and forth
}
