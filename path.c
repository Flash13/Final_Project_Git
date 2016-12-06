typedef struct node{
	int x;
	int y;
}Step;

//Put this in the loop that runs the robot
int pathLen = 1;
Step *Path = malloc(sizeof(Step));
*(Path+0)->x = (starting x from file);
*(Path+0)->y = (starting y from file);

//Each time the robot moves
pathLen++;
Path = realloc(Path, pathLen);
*(Path+(pathLen-1))->x = (x of new step);
*(Path+(pathLen-1))->y = (y of new step);
0
