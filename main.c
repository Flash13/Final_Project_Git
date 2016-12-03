#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "input_error.h"
#include <ctype.h>
int roomsize;

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
		
		loadroom(fp,room, bot, ob1, ob2);
		printf("Object 1s new spot: %d",obmotion(ob1));	
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
	
	//if(fclose(fptr)!=0)
	//	exit(FILE_FAILED_TO_CLOSE);
return room;
}
