#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "input_error.h"
#include <ctype.h>

//ABBY WAS HERE
int main(int argc, char* argv[])
{
if(argc!=2)
return 0;
	FILE* fp = fopen(argv[1], "r");
	Square* room = createroom(fp);
	Robot *bot = malloc(sizeof(Robot));
	Obstacle *ob1 = malloc(sizeof(Obstacle));
	Obstacle *ob2 = malloc(sizeof(Obstacle));
	Path *exit = malloc(sizeof(Path));
		loadroom(fp,room, bot, ob1, ob2, exit);
	int new1;
	int new2;
	int stop = 0;
	while(stop != 1)
		{
	    new1 = obmotion(ob1,room);
	    new2 = obmotion(ob2,room);
		room[new1].check = 1;//Means obstacle is moving to this position
	    room[new2].check = 1;
		stop = robotmotion(room,bot,ob1,ob2,exit);
		printf("\nRobot Position: (%d,%d)",bot->x,bot->y);
		}
		printf("\nRobot Position: (%d,%d) Exit Position: (%d,%d)\n",bot->x,bot->y,exit->x,exit->y);
return 0;
}


Square* createroom(FILE* file)
{
	//FILE *fptr;
	//	if((fptr=fopen(file,"r"))==NULL)
	//		exit(FILE_FAILED_TO_OPEN);
		
	fscanf(file,"%d",&roomsize);	
	int size = (roomsize*roomsize);
	Square* room = malloc(sizeof(Square)*size);
	int i;
	for(i=0;i<size;i++)
	room[i].check = 0;
	//if(fclose(fptr)!=0)
	//	exit(FILE_FAILED_TO_CLOSE);
return room;
}
