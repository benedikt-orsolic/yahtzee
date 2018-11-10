/*******************************************************************************
*	File name: Print_functions.c
*
*	Author: Benedikt Orsolic
*
*	Purpose: Various print functions for game Yahtzee in terminal
*
*	Usage: \
*
*	TODO: tide up - void printScoreSheet()
*         void printWinner()
*             should get str as argument and only print name
*
*******************************************************************************/







#include <stdio.h>
#include "Yahtzee_global_vars.h"
#include "Print_functions.h"



#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"







//
void printScoreSheet(){
	
	int i, j, k;
	
	
	
	printf("%-22s|", "Player names");
	for( j = 0; j < n_players; ++j ){
			printf("%" NAME_LENGTH_STR "s  |", names[j]);
	}
	printf("\n");
	
	
	
	printf("-----------------------");
	for( i = 0; i < n_players * (NAME_LENGTH_ARRY+2); ++i ) printf("-");
	printf("\n");
	
	
	
	for( i = 0; i < N_SCORE_CATEGORIES; ++i ){
		printf("%-17s%3d  |", categoryNames[i], i+1);
		for( j = 0; j < n_players; ++j ){
			if(score[j][i] == -1) {
				for( k = 0; k < NAME_LENGTH_ARRY+1; ++k){
					printf(" ");
				}
				printf("|");
			}
			else printf("%" NAME_LENGTH_STR "d  |", score[j][i]);
		}
		printf("\n");
	}
	
	
	
	printf("-----------------------");
	for( i = 0; i < n_players * (NAME_LENGTH_ARRY+2); ++i ) printf("-");
	printf("\n");
}



//TODO what if multiple with same score?
void printWinner(){
	int player, category, index_of_max;
	for( player = 0; player < MAX_PLAYERS; ++player ){
		for( category = 1; category < N_SCORE_CATEGORIES; ++category){
			score[player][0] += score[player][category];
		}
	}
	index_of_max = score[0][0];//where is highest score
	for( player = 1; player < MAX_PLAYERS; ++player ){
		if( score[player][index_of_max] < score[player][0] ) index_of_max = player;
	}
	
	printf("%s won the game!", names[index_of_max]);
}



void clearScreen(){
    // ANSI escape codes: clear screen got to top left corner
    printf("\033[2J\033[H");
}



void resetScreen(){
	clearScreen();
	printScoreSheet();
}



void printDice(){
	int i;
	
	printf("\n");
	for( i = 0; i < N_OF_DICE * 11; ++i ) printf("-");
	printf("-\n");
	
	printf("|");
	for( i = 0; i < N_OF_DICE; ++i){
		printf("  Dice %c  |", 'a'+i);
	}
	printf("\n");
	
	
	
	printf("|");
	for( i = 0; i < N_OF_DICE; ++i ){
		printf(ANSI_COLOR_MAGENTA"%8d"ANSI_COLOR_RESET"  |", dice[i]);
	}
	
	printf("\n");
	for( i = 0; i < N_OF_DICE * 11; ++i ) printf("-");
	printf("-\n");
	
	
	
	printf("\n");
}



