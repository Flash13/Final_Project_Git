#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "input_error.h"

int main(int argc, char* argv[])
{
if(argc!=2)
return 0;

char* input = argv[1];
Square** room = createroom(input);
	loadroom(input,room);
return 0;
}


Square** createroom(char* filename)
{
FILE *fptr;
int roomsize;
	if((fptr=fopen(filename,"r"))==NULL)
  	  exit(FILE_FAILED_TO_OPEN);
fscanf(fptr,"%d",&roomsize);	
int size = (roomsize*roomsize);
Square** room = malloc(sizeof(Square)*size);	
if(fclose(fptr)!=0)
exit(FILE_FAILED_TO_CLOSE);
return room;
}

void loadroom(char* filename,Square**room)
{
FILE *fptr;
char garbage;
int finish[2];
        if((fptr=fopen(filename,"r"))==NULL)
        exit(FILE_FAILED_TO_OPEN);
fscanf(fptr,"%c",&garbage);
Robot* bot = malloc(sizeof(Robot));
fscanf(fptr,"(%d,%d)",&bot->x,&bot->y);
fscanf(fptr,"(%d,%d)",&finish[0],&finish[1]);
Obstacle ob1 = loadob(fptr);
Obstacle ob2 = loadob(fptr);
}

Obstacle loadob(FILE* fptr)
{
Obstacle* object = malloc(sizeof(Obstacle));
fscanf(fptr,"(%d,%d)",&object->x,&object->y);
fscanf(fptr,"%d",&object->speed);
char*line;
line = strtok(fptr , "(,)");
int i = 0;
if(!isdigit(line[i])) {
	object->ns = line[i];
	i++;
}
else if(line[i] == '+') {
	object->ns = 1;
	i+=2;
}

else{
	object->ns = -1;
	i+=2;
}

if(!isdigit(line[i])) {
        object->ns = line[i];
        i++;
}
else if(line[i] == '+') 
        object->ns = 1;
else
   object->ns = -1;

return object;
}        

~     
