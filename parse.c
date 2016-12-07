#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input_error.h"
#include <ctype.h>
#include <math.h>
#include "types.h"

void checkFormat(FILE *fp) {
	
	int length = 0;
	
	fseek(fp , 0 , SEEK_END);
	
	length = ftell(fp);//returns length of file in number of bytes
	
	rewind(fp);
	
	//depending on system, sizeof determines size of a character
	//could be 2 bytes could be 4 for a char
	length = length / sizeof(char);//divides by the sizeof a char for a system to convert length from number of bytes to number of elements
	
	char *block = malloc(sizeof(char) * length);//block has bytes not spaces and length is in spaces so we need to have enough bytes
	
	char *line = strtok(block , "\n");//strtok caches a pointer for itself where it leaves off every time
									  //so next time, null in place of block to leave off at the 
									  //same spot and a line using array notation can be used like line[i] to check a character
	int roomsize = 0 , i = 0;
	
	//might actually need to convert the number with atoi and not just assume isdigit will work like this//also change down below in code too if need be
	//might throw the printf and exit if it hits the newline

	//first check if the whole first line are numbers
	//while(isdigit(line[i]) != 0)	{
		printf("First line is: %s" , line);
		i++;
	//}
	
	i = 0;
	
	//then convert it to an actual number. issue with newline at end?
	//roomsize = atoi(line);
	
	//2nd line
	line = strtok(NULL , "," );
	
	int count = 2 , check = 0;//2 because we read in the bot start&&exit
	
	while(count != 0) {
		if(*line != '(')
			exit(PARSING_ERROR_INVALID_FORMAT);
		
		i++;
		line++;//so the only thing left is the digit in line
		
		check = atoi(line);
		//checking for invalid coordinates
		if(check > roomsize || check < 1)
			exit(PARSING_ERROR_IMPROPER_VALUE);

		//reads in the rest of that line from the , to the )
		line = strtok(NULL , ")");

		while(!line) {
			printf("%c" , line[i]);
			i++;
		}
		
		//int lineLen = strlen(line);
	
		//atoi(line)
		
		//not line[i]? is it permanently changing line permanently?
		//could negatively affect characters that are characters
		while(atoi(line) != 0) {
			i++;
		}
			
		//because the format could be (,) or (,100)
		//does or to double check
		if(line[i] == '(' || line[i] != ',')
			exit(PARSING_ERROR_INVALID_FORMAT);
		
		i++;
		
		//?
		while(atoi(line) != 0) {
			printf("Atoi gives out: %s" , line);
			i++;
		}
		
		//could be (100,) as we check for the existance of a second digit
		if(line[i] == ',' || line[i] != ')' )
			exit(PARSING_ERROR_INVALID_FORMAT);
		
		i++;
		
		count--;
		
		line = strtok(NULL , "\n");
	}

	int obCount = 2;
	
	//this loop is for the the obstacle information
	while(obCount != 0) {
		
		//to read in starting obstacle course
		if(line[i] != '(')
			exit(PARSING_ERROR_INVALID_FORMAT);
		
		i++;
		
		while(atoi(line) != 0) {
			i++;
		}
			
		//because the format could be (,) or (,100)
		//does or to double check
		if(line[i] == '(' || line[i] != ',')
			exit(PARSING_ERROR_INVALID_FORMAT);
		
		i++;
		
		while(atoi(line) != 0) {
			i++;
		}
		
		//could be (100,) as we check for the existance of a second digit
		if(line[i] == ',' || line[i] != ')' )
			exit(PARSING_ERROR_INVALID_FORMAT);
		
		//reads in speed lines
		line = strtok(NULL , "\n");
		
		//?
		if(atoi(line) == 0) 
			exit(PARSING_ERROR_INVALID_FORMAT);

		//reads in direction
		line = strtok(NULL , "\n");
		
		if(line[i] != '(' )
			exit(PARSING_ERROR_INVALID_FORMAT);
		
		i++;
		
		if(atoi(line) == 0) {
			if(line[i] != '+' || line[i] != '-') {
				printf("Direction symbol was invalid: %c", line[i]);
				exit(PARSING_ERROR_INVALID_FORMAT);
			}
			
			i++;
		}
		
		else if(line[i] != 0) {
			printf("Character did not have a symbol in front and was not a 0: %c" , line[i]);
			exit(PARSING_ERROR_INVALID_FORMAT);
		}
		
		if(line[i] != 1) {
			printf("Number after a symbol was not 1: %c" , line[i]);
			exit(PARSING_ERROR_INVALID_FORMAT);
		}
			
		i++;
		
		if(line[i] != ',') {
			printf("Symbol was not a ',': %c" , line[i]);
			exit(PARSING_ERROR_INVALID_FORMAT);
		}//
		
		if(atoi(line) == 0) {
			if(line[i] != '+' || line[i] != '-') {
				printf("Direction symbol was invalid: %c", line[i]);
				exit(PARSING_ERROR_INVALID_FORMAT);
			}
			
			i++;
		}
		
		else if(line[i] != 0) {
			printf("Character did not have a symbol in front and was not a 0: %c" , line[i]);
			exit(PARSING_ERROR_INVALID_FORMAT);
		}
		
		if(line[i] != 1) {
			printf("Number after a symbol was not 1: %c" , line[i]);
			exit(PARSING_ERROR_INVALID_FORMAT);
		}
			
		i++;
		
		if(line[i] != ')' )
			exit(PARSING_ERROR_INVALID_FORMAT);
	
		obCount--;
		
		line = strtok(NULL , "\n");
	}
	
	//rewind(file); dont need it since we arent messing with
	//the actual file. only fp which is a copy
}	

//get rid of printfs when done
//libraries
//use fgets and fgetc if strtok doesnt work
//could read in each line length with a helper line length function
//free and rewind if need be
//send strtok NULL or file?
//also check for empty lines
//call parse in main and include it
//free each prev line before i scan in a new one?
//check for return value on fgets for errors
//if any numbers go outside of the grid like if a room is
//10 by 10 and a coordinate is 11
//could fgets using the amount of characters that i know will be in each line
