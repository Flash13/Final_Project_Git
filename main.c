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
	Robot *bot = malloc(sizeof(Robot));
	Obstacle *ob1 = malloc(sizeof(Obstacle));
	Obstacle *ob2 = malloc(sizeof(Obstacle));
	Path *exit = malloc(sizeof(Path));
		loadroom(fp, bot, ob1, ob2, exit);
	int stop = 0;
		printf("\nRobot Starting Position: (%d,%d)",bot->x,bot->y);
	while(stop != 1)
		{
	    obmotion(ob1);
	    obmotion(ob2);
		stop = robotmotion(bot,ob1,ob2,exit);
		printf("\nRobot Position: (%d,%d)",bot->x,bot->y);
		}
		printf("\nExit Position: (%d,%d)\n",exit->x,exit->y);
return 0;
}