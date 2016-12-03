#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "input_error.h"
#include <ctype.h>

int main(int argc, char* argv[])
{
if(argc!=2)
return 0;

FILE* fp = fopen(argv[1], "r");
Square* room = createroom(fp);
	loadroom(fp,room);
return 0;
}
//gay

Square* createroom(FILE* file)
{
	//FILE *fptr;
	int roomsize;
	//	if((fptr=fopen(file,"r"))==NULL)
	//		exit(FILE_FAILED_TO_OPEN);
		
	fscanf(file,"%d",&roomsize);	
	int size = (roomsize*roomsize);
	Square* room = malloc(sizeof(Square)*size);
	
	//if(fclose(fptr)!=0)
	//	exit(FILE_FAILED_TO_CLOSE);
return room;
}