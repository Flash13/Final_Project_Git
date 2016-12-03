int obmotion(Obstacle* object)
{
	int xmove;
	int ymove;
	int newspot//Objects new spot (x,y) converted to spot in a one-dimensional array (ex: A[newspot])
		if(object->x == roomsize && object->ns == 1)
			object->ns == (object->ns)*(-1);
	    if(object->x == 1 && object->ns == -1)
	        object->ns == (object->ns)*(-1);	   
	    if(object->y == roomsize && object->ew == 1)
			object->ew == (object->ew)*(-1);
	    if(object->y == 1 && object->ew == -1)
	        object->ew == (object->ew)*(-1); 
/*
Lines 8-11 check if object will hit NS walls in that 
case changing the objects movement direction

Lines 12-15 check if object will hit EW walls in that 
case changing the objects movement direction
*/
	    
	 xmove = (object->speed)*(object->ns);//Where and at what speed object will move vertically
	 ymove = (object->speed)*(objext->ew);//where and at what speed object will move horizontally
	 object->x = (object->x)+(xmove);// objects new "x" position
	 object->y = (object->y)+(ymove);// objects new "y" position 
	 
	 newspot = ((object->x)*n((object->y)-1);//formula for finding objects new position in one-dimensional array
	 
return newspot;	 
}
