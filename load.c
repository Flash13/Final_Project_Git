#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input_error.h"
#include <ctype.h>

//file sent is open!
void loadroom(FILE *fp,Square *room,Robot* bot, Obstacle* ob1, Obstacle* ob2)
{
	//Need to make bot, ob1, and ob2 global in the main?

	//array for finish coordinates
	int finish[2];
	int size;
	
	bot = malloc(sizeof(Robot));	
	ob1 = malloc(sizeof(Obstacle));
	ob2 = malloc(sizeof(Obstacle));
	
	fscanf(fp, "%d\n", &size);
	fscanf(fp, "(%d,%d)\n", &bot->x, &bot->y);
	fscanf(fp, "(%d,%d)\n", &finish[0], &finish[1]);
	fscanf(fp, "(%d,%d)\n", &ob1->x, &ob1->y);
	fscanf(fp, "%d\n", &ob1->speed);
	fscanf(fp, "(%d,%d)\n", &ob1->ns, &ob1->ew);
	fscanf(fp, "(%d,%d)\n", &ob2->x, &ob2->y);
	fscanf(fp, "%d\n", &ob2->speed);
	fscanf(fp, "(%d,%d)\n", &ob2->ns, &ob2->ew);
	
	
	printf("\n(%d,%d)\n" , ob1->speed , ob2->speed);
}

//sent an open file. correct file position?
/*Obstacle* loadob(FILE* file)
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
	//char* token;
	int x;
	int y;
	//fscanf(file,"%s",hold);
	//token = strtok(hold , "(,)");
	
	printf("\nToken: %s\n",token);
	char c[1];
	c[0] = token[0];
	x = atoi(c);
	token = strtok(NULL,"(,)");
	printf("\nToken2: %s\n",token);
	c[0] = token[0];
	y = atoi(c);
	printf("x = %d y = %d\n" ,x,y );
return object;
} */       
