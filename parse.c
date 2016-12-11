#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input_error.h"
#include <ctype.h>
#include <math.h>
#include "types.h"

void checkFormat(FILE *fp) {
	
	//Check if file is empty
    int c = fgetc(fp);
    if (c == EOF)
       exit(PARSING_ERROR_EMPTY_FILE);
	
	int length = 0;
	
	//getting file length
	fseek(fp , 0 , SEEK_END);
	length = ftell(fp);//length return is in bytes
	
	//put the file pointer back tot he front in order to work with it properly
	rewind(fp);
	
	//depending on system, sizeof determines size of a character
	//could be 2 bytes could be 4 for a char
	length = length / sizeof(char);//divides by the sizeof a char for a system to convert length from number of bytes to number of elements
	
	char *block = malloc(sizeof(char) * length);//block has bytes not spaces and length is in spaces so we need to have enough bytes
	
	int status = fread(block , sizeof(char) , length * sizeof(char) , fp);
	//error check for status here
	
	//return type on fread is weird
	if(status != (length*sizeof(char)))
		exit(PARSING_ERROR_INVALID_FORMAT);
	
	int i = 0;
	
	char *line = malloc(sizeof(char));
	
	line = strtok(block , "\n");//strtok caches a pointer for itself where it leaves off every time
								//so next time, null in place of block to leave off at the 
								//same spot and a line using array notation can be used like line[i] to check a character
	if(line == NULL)
		exit(PARSING_ERROR_EMPTY_FILE);
	
	int numlen = 0 , linelen = 0;
	
	for(i = 0;i < linelen;i++) {
		if(isdigit(line[i]) == 0 && line[i] != '\n') {
			exit(PARSING_ERROR_INVALID_FORMAT);
		}
	}
	
	i = 0;
	
	//then convert it to an actual number. issue with newline at end?
	roomsize = atoi(line);
	
	//roomsize cant be less than 2 because there are 3 things to place.this would make movement impossible but hey its a valid roomsize
	if(roomsize < 2)
		exit(PARSING_ERROR_IMPROPER_VALUE);

	
	//for taking in the bot's start/end
	int count = 0 , coordinate = 0;//2 because we read in the bot start&exit
	
	for(count = 0;count < 2;count++) {
		
		line = strtok(NULL , "\n");
		
		if(line == NULL)
			exit(PARSING_ERROR_EMPTY_FILE);
		
		if(line[i] != '(') {
			exit(PARSING_ERROR_INVALID_FORMAT);
		}
		
		line = line + 1;
		
		//for 1st coordinate
		
		while(line[i + numlen] != ',')
			numlen++;
		
		while(line[i] != ',' && isdigit(line[i]) != 0 && numlen != 0) {
			//printf("\nLine[i] before multiplcation: %c\n" , line[i]);
			if(numlen != 1)
				coordinate *= 10;
			coordinate += atoi(&line[i]);//should go until it doesnt hit a number according to Trevor
			i++;
			numlen--;
		}
	
		//to check that its not (, instead of (10,
		if(line[i] != ',')
			exit(PARSING_ERROR_INVALID_FORMAT);
		
		//check for valid coordinate size
		if(coordinate < 1 || coordinate > roomsize)
			exit(PARSING_ERROR_IMPROPER_VALUE);
		
		//for 2nd coordinate
		i++;
		coordinate = 0;
		numlen = 0;
		
		while(line[i + numlen] != ',')
			numlen++;
		
		while(line[i] != ')' && isdigit(line[i]) != 0 && numlen != 0) {
			if(numlen != 1)
				coordinate *= 10;
			coordinate += atoi(&line[i]);//should go until it doesnt hit a number according to Trevor
			i++;
			numlen--;
		}
		
		if(line[i] != ')') {
			exit(PARSING_ERROR_INVALID_FORMAT);
		}
		if(coordinate < 1 || coordinate > roomsize) {
			exit(PARSING_ERROR_IMPROPER_VALUE);
		}
	
		i = 0;
		coordinate = 0;
		numlen = 0;
	}
	
	obCheck(fp , block , line);
	
	//to check for any improper lines after all the ones that should be there
	//line = strtok(NULL , "\n");
	/*
	if(line[i] != EOF) {
		exit(PARSING_ERROR_INVALID_FORMAT);
	}*/
	//free(line);
	free(block);
	rewind(fp); //got to fix it for later use so it points back
	//to the front
}	



//to check object data
//make sure to think of where the pointers are and what varaibles exist or are needed
void obCheck(FILE *fp , char *block , char *line) {
	
	int obCount = 0, i = 0 , coordinate = 0 , linelen = 0 , numlen = 0;
	
	//this loop is for the the obstacle information
	for(obCount = 0;obCount < 2;obCount++) {
	
		line = strtok(NULL , "\n");
		
		//FOR THE 1ST LINE TO READ IN OBJECT DATA
		
		if(line == NULL)
			exit(PARSING_ERROR_EMPTY_FILE);
		
		if(line[i] != '(') {
			exit(PARSING_ERROR_INVALID_FORMAT);
		}

		line = line + 1;
		
		while(line[i + numlen] != ',')
			numlen++;
		
		while(line[i] != ',' && isdigit(line[i]) != 0 && numlen != 0) {
			if(numlen != 1)
				coordinate *= 10;
			coordinate += atoi(&line[i]);//should go until it doesnt hit a number according to Trevor
			i++;
			numlen--;
		}
		
		//to check that its not (, instead of (10,
		if(line[i] != ',')
			exit(PARSING_ERROR_INVALID_FORMAT);
		
		//check for valid coordinate size
		if(coordinate < 1 || coordinate > roomsize)
			exit(PARSING_ERROR_IMPROPER_VALUE);
		
		//FOR 2ND COORDINATE
		i++;
		coordinate = 0;
		numlen = 0;
		
		while(line[i + numlen] != ',')
			numlen++;
		
		while(line[i] != ')' || isdigit(line[i]) != 0) {
			if(numlen != 1)
				coordinate *= 10;
			coordinate += atoi(&line[i]);//should go until it doesnt hit a number according to Trevor
			i++;
			numlen--;
		}
		
		if(line[i] != ')') {
			exit(PARSING_ERROR_INVALID_FORMAT);
		}
		if(coordinate < 1 || coordinate > roomsize) {
			exit(PARSING_ERROR_IMPROPER_VALUE);
		}
	
		i = 0;
		coordinate = 0;
		numlen = 0;
		
		
		//FOR SPEED LINES
		line = strtok(NULL , "\n");
		
		if(line == NULL)
			exit(PARSING_ERROR_EMPTY_FILE);
		
		int speed = atoi(line);
		
		if(speed == 0)
			exit(PARSING_ERROR_INVALID_FORMAT);
		
		if(speed < 1)
			exit(PARSING_ERROR_IMPROPER_VALUE);
		
		
		//GETTING DIRECTION DATA
		
		line = strtok(NULL , "\n");
		
		if(line == NULL)
			exit(PARSING_ERROR_EMPTY_FILE);
		
		linelen = strlen(line);
		
		//because the max a direction line can be is 7 characters
		//Example  = (+1,-1)
		if(linelen > 8)	{
			exit(PARSING_ERROR_INVALID_FORMAT);
		}
			
		//min characters. Example = (0,0)
		if(linelen < 5) {
			exit(PARSING_ERROR_INVALID_FORMAT);
		}
			
		if(line[i] != '(' ) {
			exit(PARSING_ERROR_INVALID_FORMAT);
		}
		line = line + 1;
		
		//checking 1st value//
		//check for a sign in front
		if(isdigit(line[i]) == 0) {

			//checks the chrracter to see if it is a proper sign
			if(line[i] != '-' && line[i] != '+') {
				exit(PARSING_ERROR_INVALID_FORMAT);
			}
			
			//checks to see if the value after the sign, if there is one, is a number
			else if(isdigit(line[i + 1] == 0)) {
				exit(PARSING_ERROR_INVALID_FORMAT);
			}

			//checks to see if the character after a sign, if it exits, is 1
			else if(atoi(&line[i + 1]) != 1) {
				exit(PARSING_ERROR_IMPROPER_VALUE);
			}
			
			i++;
		}
			
		//if no sign is present and there is a digit, check if it is valid
		else if(isdigit(line[i]) != 0 && atoi(&line[i]) != 0) {
			exit(PARSING_ERROR_IMPROPER_VALUE);
		}
		
		//
		i++;
		
		if(line[i] != ',') {
			exit(PARSING_ERROR_INVALID_FORMAT);
		}
		
		i++;
		
		//checking 2nd value of direction
		
		//check for a sign in front
		if(isdigit(line[i]) == 0) {

			//checks the chrracter to see if it is a proper sign
			if(line[i] != '-' && line[i] != '+') {
				exit(PARSING_ERROR_INVALID_FORMAT);
			}
			//checks to see if the value after the sign, if there is one, is a number
			else if(isdigit(line[i + 1] == 0)) {
				exit(PARSING_ERROR_INVALID_FORMAT);
			}
			//checks to see if the character after a sign, if it exits, is 1
			else if(atoi(&line[i + 1]) != 1) {
				exit(PARSING_ERROR_IMPROPER_VALUE);
			}
			i++;
		}
		
		//if no sign is present and there is a digit, check if it is valid
		else if(isdigit(line[i]) != 0 && atoi(&line[i]) != 0) {
			exit(PARSING_ERROR_IMPROPER_VALUE);
		}
		
		i++;
		
		if(line[i] != ')') {
			exit(PARSING_ERROR_INVALID_FORMAT);
		}
		i = 0;
	}
}	

//reset pointer heads accordingly and reset i if need be
//get rid of printfs when done
//use fgets and fgetc if strtok doesnt work
//could read in each line length with a helper line length function or fseekend to get total file length to put it all in a string
//free and rewind if need be
//also check for empty lines