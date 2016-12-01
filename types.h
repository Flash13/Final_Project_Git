typedef struct sq{
int check;
} Square;

typedef struct obstacle{
int speed;
int x;
int y;
int ns;
int ew;
} Obstacle;

typedef struct robot{
int x;
int y;
} Robot;

Square** createroom(char* filename);
void loadroom(char* filename,Square**room);
Obstacle loadob(FILE* fptr);
