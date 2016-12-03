#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input_error.h"
#include <ctype.h>

//file sent is open
void loadroom(FILE *file,Square *room)
{
	//array for finish coordinates
	int finish[2];
	
	//char roomsize;
	//fscanf(file,"%c",&roomsize);
	
	Robot* bot = malloc(sizeof(Robot));
	
	fscanf(file,"(%d,%d)",&bot->x,&bot->y);
	fscanf(file,"(%d,%d)",&finish[0],&finish[1]);
	
	Obstacle* ob1 = loadob(file);
	Obstacle* ob2 = loadob(file);
	
	printf("\n(%d,%d)\n" , ob1->speed , ob2->speed);
}

//sent an open file. correct file position?
Obstacle* loadob(FILE* file)
{
	char*garbage = malloc(sizeof(char)*2);
	char*hold = malloc(sizeof(char)*2);
	fscanf(file,"(%s,%s)",garbage,garbage);
	fscanf(file,"(%s,%s)",garbage,garbage);
	fscanf(file,"(%s,%s)",garbage,garbage);
	fscanf(file,"%s",garbage);
	fscanf(file,"(%s,%s)",garbage,hold);
	printf("\n(%s,%s)\n", garbage, hold);

	Obstacle* object = malloc(sizeof(Obstacle));
	//scanned in the roomsize already.start at line 2
	fscanf(file,"(%d,%d)",&object->x,&object->y);
	fscanf(file,"%d",&object->speed);
	/*char* token;
	int x;
	int y;*/
	fscanf(file,"%s",hold);
	//token = strtok(hold , "(,)");
	/*
	printf("\nToken: %s\n",token);
	char c[1];
	c[0] = token[0];
	x = atoi(c);
	token = strtok(NULL,"(,)");
	printf("\nToken2: %s\n",token);
	c[0] = token[0];
	y = atoi(c);
	printf("x = %d y = %d\n" ,x,y );*/
return object;
}        
