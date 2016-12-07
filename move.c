#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "input_error.h"
#include <ctype.h>

void obmotion(Obstacle* object)
{
	int xmove;
	int ymove;
		if(object->x == roomsize && object->ns == 1)
			object->ns = (object->ns)*(-1);  
	    if(object->x == 1 && object->ns == -1)
	        object->ns = (object->ns)*(-1);	   
	   
	    if(object->y == roomsize && object->ew == 1)
			object->ew = (object->ew)*(-1);
	     if(object->y == 1 && object->ew == -1)
	        object->ew = (object->ew)*(-1); 
/*
Lines 8-11 check if object will hit NS walls in that 
case changing the objects movement direction

Lines 12-15 check if object will hit EW walls in that 
case changing the objects movement direction
*/
	    
	 xmove = (object->speed)*(object->ns);//Where and at what speed object will move vertically
	 ymove = (object->speed)*(object->ew);//where and at what speed object will move horizontally
	 object->x = (object->x)+(xmove);// objects new "x" position
	 object->y = (object->y)+(ymove);// objects new "y" position 
}
int robotmotion(Robot* bot,Obstacle* ob1,Obstacle* ob2, Path* exit)
{
int new;
int xcheck = bot->x;
int ycheck = bot->y;
int stop = ((exit->x)-1)*roomsize+((exit->y)-1);//exits position
int hold1 = ((ob1->x)-1)*roomsize+((ob1->y)-1);//objects position
int hold2 = ((ob2->x)-1)*roomsize+((ob2->y)-1);//objects position
int checker = 0;//makes sure robot only moves once a turn
int boteast = ((xcheck)-1)*roomsize+((ycheck+1)-1);//if bot moves east
int botnorth = ((xcheck-1)-1)*roomsize+((ycheck)-1);//if bot moves north
int botwest = ((xcheck)-1)*roomsize+((ycheck-1)-1);//if bot moves west
int botsouth = ((xcheck+1)-1)*roomsize+((ycheck)-1);//if bot moves south
int botstay =  ((xcheck)-1)*roomsize+((ycheck)-1);//if bot stays
 		if(bot->y < exit->y)//checks if exit is east of robot
 		{	
 			if(hold1 != boteast && hold2 != boteast)
 		     {
 		       bot->y++;
 			   checker++;
 			 }
 		}
 		if(bot->y > exit->y && checker == 0)//checks if exit is west of robot
 		{
 			if(hold1 != botwest && hold2 != botwest)
 			  {
 			   bot->y--;
 		   	   checker++;
 			  }
 		}
 	
 		if(bot->x < exit->x && checker == 0)//checks if exit is south of robot
 		{	
 			if(hold1 != botsouth && hold2 != botsouth)
 		      	{
 		       bot->x++;
 		       checker++;
 				}
 		}
 		if(bot->x > exit->x && checker == 0)//checks if exit is north of robot
 		{
 			if(hold1 != botnorth && hold2 != botnorth)
 				{
 				bot->x--;
 		        checker++;
 				}
 		}
		if(hold1 == botstay || hold2 == botstay)
		{
			if(hold1 != botwest && hold2 != botwest)
			{
				if(checker == 0 && ycheck != 1)
				  {
				  bot->y--;
				  checker++;
				  }
			} 
			if(hold1 != botnorth && hold2 != botnorth)
			{
				if(checker == 0 && xcheck != 1)
				  {
				  bot->x--;
				  checker++;
				  }
			} 
			if(hold1 != boteast && hold2 != boteast)
			{
				if(checker == 0 && (ycheck) != roomsize)
				  {
				  bot->y++;
				  checker++;
				  }
			} 
			if(hold1 != botsouth && hold2 != botsouth)
			{
			 if(checker == 0 && (xcheck) != roomsize)
				 bot->x++; 
			 }
			 
		}	
 	new = ((bot->x)-1)*roomsize+((bot->y)-1);
 	if(new == stop)
       return 1;
    else
       return 0;
}