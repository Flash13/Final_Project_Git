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
	
	fseek(fp , 0 , SEEK_END);
	
	length = ftell(fp);//returns length of file in number of bytes
	
	rewind(fp);
	
	//depending on system, sizeof determines size of a character
	//could be 2 bytes could be 4 for a char
	length = length / sizeof(char);//divides by the sizeof a char for a system to convert length from number of bytes to number of elements
	
	char *block = malloc(sizeof(char) * length);//block has bytes not spaces and length is in spaces so we need to have enough bytes
	
	int status = fread(block , sizeof(char) , length * sizeof(char) , fp);
	
	//error check for status here
	
	int i = 0;
	
	//gets the data from fp to put in block
	fgets(block , status ,fp);
	
	/*
	while(!block) {
		printf("%c" , *block);
		block++;
	}*/
	
	char *line = malloc(sizeof(char));
	
	line = strtok(block , "\n");//strtok caches a pointer for itself where it leaves off every time
								//so next time, null in place of block to leave off at the 
								//same spot and a line using array notation can be used like line[i] to check a character
	
	printf("\nLine is: %s\n" , line);
	
	if(line == NULL)
		exit(PARSING_ERROR_EMPTY_FILE);
	
	int linelen = 0;
	
	for(i = 0;i < linelen;i++) {
		if(isdigit(line[i]) == 0 && line[i] != '\n') {
			printf("\nExiting\n");
			exit(PARSING_ERROR_INVALID_FORMAT);
			i++;
		}
	}
	
	i = 0;
	
	//then convert it to an actual number. issue with newline at end?
	roomsize = atoi(line);
	
	printf("\nRoomsize: %d\n" , roomsize);
	
	//roomsize cant be less than 2 because there are 3 things to place.this would make movement impossible but hey its a valid roomsize
	if(roomsize < 2)
		exit(PARSING_ERROR_IMPROPER_VALUE);

	int count = 2 , coordinate = 0;//2 because we read in the bot start&exit
	
	while(count != 0) {
		printf("\nCount is: %d\n" , count);
		
		//2nd line. Reads in first coordinate
		line = strtok(NULL , "," );
		//linelen = strlen(line);
		
		if(line == NULL)
			exit(PARSING_ERROR_EMPTY_FILE);
		
		if(count == 1)
			line = line + 1;
	
		printf("\nq Line is: %s\n" , line);
		
		if(line[i] != '(') {
			printf("\n$ Line[i] is: %c\n" , line[i]);
			exit(PARSING_ERROR_INVALID_FORMAT);
		}

		line = line + 1;
		
		printf("\nNow, line is: %s\n" , line);
		
		coordinate = atoi(line);
		
		//so between the '(' and the ',' , we need to check for only numbers
		if(coordinate == 0) {
			printf("\nUtter Failure! MOOO\n");
			exit(PARSING_ERROR_INVALID_FORMAT);
		}
		
		//checks for valid value compared to roomsize
		if(roomsize < coordinate) {
			printf("\natoi 1: %s\n" , line);
			exit(PARSING_ERROR_IMPROPER_VALUE);
		}

		//cant have negative coordinates
		else if(coordinate < 1) {
			printf("\natoi 2: %s\n" , line);
			exit(PARSING_ERROR_IMPROPER_VALUE);
		}
		
		//reads in the rest of that line from the , to the ')'
		line = strtok(NULL , ")");
		
		printf("\nx Line is: %s\n" , line);
		
		//could be nothing between ,) to read
		if(line == NULL) {
			printf("\nNo second digit\n");
			exit(PARSING_ERROR_EMPTY_FILE);
		}
		
		coordinate = atoi(line);
		
		//to check if the ',' to ')' is a number. Could be like
		//(1,2(
		//(3,4) and would read in till the first ) so it would have 1,2(3,4)
		if(coordinate == 0) {
			printf("\nHere.Line contains non-numbers\n");
			exit(PARSING_ERROR_INVALID_FORMAT);
		}
		/*/could be (100,) as we check for the existance of a second digit
		if(line[i] == ',' || line[i] != ')' )
			exit(PARSING_ERROR_INVALID_FORMAT);
		
		i++;*/
		
		count--;
	}
	
	int obCount = 2;
	
	printf("\nScanning in Objects\n\nLine is: %s\n" , line);
	
	//this loop is for the the obstacle information
	while(obCount != 0) {
		
		printf("\nobCount: %d\n" , obCount);
		
		//2nd line. Reads in first coordinate
		line = strtok(NULL , "," ) + 1;
		
		if(line == NULL)
			exit(PARSING_ERROR_EMPTY_FILE);
		
		//if(count == 0)
			//do same thing as below?
		
		/*
		if(obCount == 1)
			line = line + 1;*/
							
		printf("\nq Line is: %s\n" , line);
		
		if(line[i] != '(') {
			printf("\n$ Line[i] is: %c\n" , line[i]);
			exit(PARSING_ERROR_INVALID_FORMAT);
		}

		line = line + 1;
		
		printf("\nNow, line is: %s\n" , line);
		
		coordinate = atoi(line);
		
		//so between the '(' and the ',' , we need to check for only numbers
		if(coordinate == 0) {
			printf("\nUtter Failure! MOOO\n");
			exit(PARSING_ERROR_INVALID_FORMAT);
		}
		
		//checks for valid value compared to roomsize
		if(roomsize < coordinate) {
			printf("\natoi 1: %s\n" , line);
			exit(PARSING_ERROR_IMPROPER_VALUE);
		}

		//cant have negative coordinates
		else if(coordinate < 1) {
			printf("\natoi 2: %s\n" , line);
			exit(PARSING_ERROR_IMPROPER_VALUE);
		}
		
		//reads in the rest of that line from the , to the ')'
		line = strtok(NULL , ")");
		
		printf("\nx Line is: %s\n" , line);
		
		//could be nothing between ,) to read
		if(line == NULL) {
			printf("\nNo second digit\n");
			exit(PARSING_ERROR_EMPTY_FILE);
		}
		
		coordinate = atoi(line);
		
		//to check if the ',' to ')' is a number. Could be like
		//(1,2(
		//(3,4) and would read in till the first ) so it would have 1,2(3,4)
		if(coordinate == 0) {
			printf("\nHere.Line contains non-numbers\n");
			exit(PARSING_ERROR_INVALID_FORMAT);
		}
		/*/could be (100,) as we check for the existance of a second digit
		if(line[i] == ',' || line[i] != ')' )
			exit(PARSING_ERROR_INVALID_FORMAT);
		
		i++;*/
		
		//beginning of original code
		/*
		line = strtok(NULL , ",") + 1;
		
		printf("\nGoing into loop, line is: %s\n" , line);
		
		//to read in starting obstacle course
		if(line[i] != '(') {
			printf("\nHere\n");
			exit(PARSING_ERROR_INVALID_FORMAT);
		}
		
		line = line + 1;
		
		printf("\nNow, line is: %s\n" , line);
		
		//i++;
		
		//try to get rid of it
		while(atoi(line) != 0) {
			i++;
		}
			
		//because the format could be (,) or (,100)
		//does or to double check
		if(line[i] == '(' || line[i] != ',') 
			printf("Here");
			exit(PARSING_ERROR_INVALID_FORMAT);
		
		//i++;
		
		//try to get rid of it
		while(atoi(line) != 0) {
			i++;
		}
		
		//could be (100,) as we check for the existance of a second digit
		if(line[i] == ',' || line[i] != ')' )
			exit(PARSING_ERROR_INVALID_FORMAT);*/
		
		//reads in speed lines
		line = strtok(NULL , "\n");
		
		printf("\nSpeed is: %c\n" , line[i]);
		
		//?
		if(atoi(line) == 0) 
			exit(PARSING_ERROR_INVALID_FORMAT);

		//reads in direction
		line = strtok(NULL , ",");
		
		printf("\nDirection line is: %s\n" , line);
		
		if(line[i] != '(' )
			exit(PARSING_ERROR_INVALID_FORMAT);
		
		line = line + 1;
		
		printf("\nDirection line is now: %s\n" , line);
			
		linelen = strlen(line);
			
		printf("\nlinelen = %d\n" , linelen);	
			
		//coordinate = atoi(line);
		printf("\nI is: %d\n" , i);
		
		i = 0;
		
		if(linelen == 1)	{
			if(line[i] != '0') {
				printf("\nSingle character was not a 0: %c\n" , line[i]);
				exit(PARSING_ERROR_IMPROPER_VALUE);
			}
		}
		
		/*
		if(linelen == 2) {
			if(line[i] != '+' || line[i] != '-') {
				printf("\nr Direction symbol was invalid: %c\n", line[i]);
				exit(PARSING_ERROR_INVALID_FORMAT);
			}
			
			else if(line[i + 1] != 1) {
				printf("Line[i + 1] is: %c" , line[i + 1]);
				printf("Character after direction symbol was not a 1: %c" , line[i + 1]);
				exit(PARSING_ERROR_IMPROPER_VALUE);
			}
		}
		*/
		else if(linelen != 1 && linelen != 2) {
			printf("\nInvalid amount of characters for speed: %s\n\nlinelen = %d\n" , line , linelen);
			exit(PARSING_ERROR_INVALID_FORMAT);
		}
		
		printf("\nI: %d\n" , i);
		i = 0;

		line = strtok(NULL , ")");
		
		/*
		if(line[i] != ',') {
			printf("Symbol was not a ',': %c" , line[i]);
			exit(PARSING_ERROR_INVALID_FORMAT);
		}*/
		
		printf("\nDirection line is now: %s\n" , line);
			
		linelen = strlen(line);
			
		printf("\nq linelen = %d\n" , linelen);	
		
		
		if(linelen == 1)	{
			if(line[i] != '0') {
				printf("\nSingle character was not a 0: %c\n" , line[i]);
				exit(PARSING_ERROR_IMPROPER_VALUE);
			}
		}
		
		printf("\ng linelen = %d\n" , linelen);
		printf("\nline[i]: %c\n" , line[i]);
		
			/*
		if(linelen == 2) {
	
			if(line[i] != '+' || line[i] != '-') {
				printf("\nd Line[i] = %c\n" , line[i]);
				
				if('+' != line[i])
					printf("\nCharacters not equal: + != %c\n" , line[i]);
				
				printf("\nxDirection symbol was invalid: %c\n", line[i]);
				exit(PARSING_ERROR_INVALID_FORMAT);
			}
			
			else if(line[i + 1] != 1) {
				printf("\nCharacter after direction symbol was not a 1: %c\n" , line[i + 1]);
				exit(PARSING_ERROR_IMPROPER_VALUE);
			}
		}*/
		
		

		/*else*/ if(linelen != 1 && linelen != 2) {
			printf("\nInvalid amount of characters for speed: %s\n" , line);
			exit(PARSING_ERROR_INVALID_FORMAT);
		}
		
		/*
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
		*/
		obCount--;
		
		//?
		//line = strtok(NULL , "\n");
	}
	
	//free(line);
	free(block);
	rewind(fp); //got to fix it for later use so it points back
	//to the front
}	

//reset pointer heads accordingly and reset i if need be
//get rid of printfs when done
//use fgets and fgetc if strtok doesnt work
//could read in each line length with a helper line length function or fseekend to get total file length to put it all in a string
//free and rewind if need be
//also check for empty lines
//call parse in main and include it
//free each prev line before i scan in a new one?
//check for return value on fgets for errors
//could fgets using the amount of characters 
//that i know will be in each line