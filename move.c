#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "input_error.h"
#include <ctype.h>

int obmotion(Obstacle* object,Square* room)
{
 int position = (object->x-1)*roomsize+((object->y)-1);//Objects current positon before motion
 room[position].check = 0;//Set that object is moving positions by setting its current square to "0"
	int xmove;
	int ymove;
	int newspot;//Objects new spot (x,y) converted to spot in a one-dimensional array (ex: A[newspot])
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
	 newspot = ((object->x-1)*roomsize+((object->y)-1));//formula for finding objects new position in one-dimensional array
	 
return newspot;	 
}
int robotmotion(Square* room, Robot* bot,Obstacle* ob1,Obstacle* ob2, Path* exit)
{
int xcheck = bot->x;
int ycheck = bot->y;
int stop = ((exit->x-1)*roomsize+((exit->y)-1));
int hold;
 		if(bot->y < exit->y)
 		{	
 			if(ob1->y != ycheck+1 && ob2->y != ycheck+1)
 		       bot->y++;
 		}
 		if(bot->y > exit->y)
 		{
 			if(ob1->y != ycheck-1 && ob2->y != ycheck-1)
 			   bot->y--;
 		}
 	
 		if(bot->x < exit->x)
 		{	
 			if(ob1->y != xcheck+1 && ob2->y != xcheck+1)
 		       bot->x++;
 		}
 		if(bot->x > exit->x)
 		{
 			if(ob1->y != xcheck-1 && ob2->y != xcheck-1)
 				bot->x--;
 		}
		
		
 	hold = ((bot->x-1)*roomsize+((bot->y)-1));
 	if(hold == stop)
       return 1;
    else
       return 0;
}