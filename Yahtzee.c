/*******************************************************************************
*	File name: Yahtzee.c
*
*	Author: Benedikt Orsolic
*
*	Purpose: Fun
*
*	Usage: User prompt via terminal
*
*	TODO: 
*	      score sheet keep track of total score?
*	      
*	      
*	      
*	      
*
*******************************************************************************/
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Yahtzee_global_vars.h"
#include "Print_functions.h"

int isFullHouse();
int isNOfAKind();
int isSequence( int n );
int isYahtzee();
int getCategory( int player );
int getScore( int category );


void playAllRounds();
void playRound();
void getDice();
void getDiceReRollStr();
void getPlayers();
void setDiceToNegative();
void setUpScore();
void removeNewLine( char* str );


int main( void ){
	
	//Get from user: number of players and names for players
	clearScreen();
	getPlayers();
	setUpScore();
	
	playAllRounds();
	
	printWinner();
	
}










/*******************************************************************************
*
*	Section: Game logic functions
*
*******************************************************************************/










void getPlayers(){
	
	int i;
	
	while(1){
		printf("Enter number of players: ");
		fgets(line, LINE_SIZE, stdin);
		sscanf(line, "%d", &n_players);
		if( n_players > 0 && n_players <= MAX_PLAYERS ) break;
		
		printf(ANSI_COLOR_RED 
		       "Number %d can not be used as number of players!\n" 
		       ANSI_COLOR_RESET, 
		       n_players);
	}
	
	for( i = 0; i < n_players; ++i) {
		while(1){
			printf("Enter name for player %d: ", i+1);
			fgets(line, LINE_SIZE, stdin);
			removeNewLine( line );
			
			if( strlen(line) < NAME_LENGTH_ARRY ) break;
			
			printf(ANSI_COLOR_RED
			       "You may enter only %d charters for name!\n"
			       ANSI_COLOR_RESET, 
			       NAME_LENGTH_ARRY-1);
		}
		strcpy( names[i], line );
		
	}
	
	printf("\n");
}










void playAllRounds(){
	
	int round;
	//Play the game until all scoring categories are filled
	for( round = 0; round < N_SCORE_CATEGORIES; ++round){
		//Let each player play the round
		playRound();

		
	}
}










//Player plays one round
void playRound(){
	
	int category, i, roll, player;
	
	
	for( player = 0; player < n_players; ++player){
		resetScreen();
		
		//Each player makes max of @MAX_DICE_ROLLS rolls
		setDiceToNegative();
		roll = 0;
		while(1){
			resetScreen();
			
			
			
			printf(ANSI_COLOR_GREEN);
			printf( "It is %s's turn: \n", names[player] );
			if( roll < MAX_DICE_ROLLS-1 ) {
				printf("You have %d re-rolls left!", MAX_DICE_ROLLS - roll - 1);
			} else {
				printf("You have no rolls left");
			}
			printf(ANSI_COLOR_RESET);
			
			
			getDice();
			printDice();
			
			if( roll >= MAX_DICE_ROLLS-1 ) break; //No re-roll if it was last roll
			
			getDiceReRollStr();
			
			for( i = 0; line[i] != '\0' && line[i] != '\n'; ++i ){
				
				dice[line[i]-'a'] = -1;
			}
			++roll;
		}
		
		
		category = getCategory( player );
		score[player][category] = getScore( category );
		
	}
}










//
void getDiceReRollStr(){
	int i, is_err_flag;
	
	while(1){
		printf("\nEnter letters with no separation of dice to re-roll: ");
		fgets(line, LINE_SIZE, stdin);
		
		is_err_flag = 0;
		for( i = 0; line[i] != '\n' && line[i] != '\0'; ++i ){
			if( line[i] < 'a' || line[i] > 'a' + N_OF_DICE ){
				printf(ANSI_COLOR_RED "Unknown dice!\n" ANSI_COLOR_RESET);
				is_err_flag = 1;
				break;
			}
		}
		
		if( !is_err_flag ) break;
	}
}










/*******************************************************************************
*
*	End section: Game logic functions
*
*******************************************************************************/




























//Replaces first \n with \0 and exits
void removeNewLine( char* str ){
	int i;
	for( i = 0; i < sizeof(str); ++i) {
		if( str[i] == '\n' ) {
			str[i] = '\0';
			return;
		}
	}
}







































































/*******************************************************************************
*
*	Section: Helper Functions
*
*******************************************************************************/





















//Set new value to dice where dice is set to negative number
void getDice(){
	int i; srand(time(NULL));
	for( i = 0; i < N_OF_DICE; ++i ){
		if ( dice[i] > -1 ) continue;
		
		dice[i] = ( rand()%6 ) + 1;
	}
	
	//dice[0] = 5;
	//dice[1] = 5;
	//dice[2] = 5;
	//dice[3] = 5;
	//dice[4] = 5;
	
	
}










//Set all values to -1 in dice
void setDiceToNegative(){
	int i;
	for( i = 0; i < N_OF_DICE; ++i ){
		dice[i] = -1;
	}
}










//
int getScore( int category ){
	int i, points=0;
	switch( category ){
		case 0:
			//Aces................Sum of dice with num 1
			for( i = 0; i < N_OF_DICE; ++i ){
				if( dice[i] == 1 ) points += dice[i];
			}
			break;
		case 1:
			//Twos................Sum of dice with num 2
			for( i = 0; i < N_OF_DICE; ++i ){
				if( dice[i] == 2 ) points += dice[i];
			}
			break;
		case 2:
			//Threes................Sum of dice with num 3
			for( i = 0; i < N_OF_DICE; ++i ){
				if( dice[i] == 3 ) points += dice[i];
			}
			break;
		case 3:
			//Fours................Sum of dice with num 4
			for( i = 0; i < N_OF_DICE; ++i ){
				if( dice[i] == 4 ) points += dice[i];
			}
			break;
		case 4:
			//Fives................Sum of dice with num 5
			for( i = 0; i < N_OF_DICE; ++i ){
				if( dice[i] == 5 ) points += dice[i];
			}
			break;
		case 5:
			//Sixes................Sum of dice with num 6
			for( i = 0; i < N_OF_DICE; ++i ){
				if( dice[i] == 6 ) points += dice[i];
			}
			break;
		case 6:
			//Three Of A Kind.....At least three dice the same and sum of all dice
			if( isNOfAKind( 3 ) )
				for( i = 0; i < N_OF_DICE; ++i )
					points += dice[i];
			break;
		case 7:
			//Four Of A Kind......At least four dice the same and sum of all dice
			if( isNOfAKind( 4 ) )
				for( i = 0; i < N_OF_DICE; ++i )
					points += dice[i];
			break;
		case 8:
			//Full House..........Three of one number and two of another 25
			if( isFullHouse() ) points = 25;
			break;
		case 9:
			//Small Straight......Four sequential dice (1-2-3-4; 2-3-4-5) 30
			if( isSequence( 4 ) ) points = 30;
			break;
		case 10:
			//Large Straight......Five sequential dice (1-2-3-4-5; 2-3-4-5-6) 40
			if( isSequence( 5 ) ) points = 40;
		case 11:
			//Yahtzee.............All five dice the same 50
			if( isYahtzee() ) points = 50;
			break;
		case 12:
			//Chance..............Any combination and Sum of all dice
			for( i = 0; i < N_OF_DICE; ++i ) points += dice[i];
			break;
		default:
			printf(ANSI_COLOR_RED "Ups! Something Went Wrong!!!\n" ANSI_COLOR_RESET);
			break;
	}
	
	return points;
}
































//Returns 1 if true and 0 if false
int isNOfAKind( int n ){
	int count_same, i, j;
	
	for( i = 1; i <= 6; ++i ){
		count_same = 0;
		for( j = 0; j < N_OF_DICE; ++j ){
			if( dice[j] == i ) ++count_same;
		}
		if( count_same >= n ) return 1;
	}
	
	return 0;
}










//
int isFullHouse(){
	int count_same, which_same=-1, i, j, k;
	
	for( i = 1; i <= 6; ++i ){
		count_same = 0;
		for( j = 0; j < N_OF_DICE; ++j ){
			if( dice[j] == i ) ++count_same;
		}
		if( count_same == 3 ){
			for( k = 0; k < N_OF_DICE; ++k ){
				if( dice[k] != i && which_same == -1 )
					which_same = dice[k];
				else if ( dice[k] != i && which_same == dice[k] )
					return 1;
					
			}
		}
	}
	
	return 0;
}










//@n how many in sequence
int isSequence( int n ){
	int i, j, count_seq = 0, is_in;
	
	for( i = 0; i <= 6; ++i ){
		//Find i+1 or set count_seq to 0
		is_in = 0;
		for( j = 0; j < N_OF_DICE; ++j ){
			if( dice[j] == i+1 ){
				is_in = 1;
				break;
			}
		}
		if( !is_in ) count_seq = 0;
		else {
			++count_seq;
			if( count_seq >= 4 ) return 1;
		}
		
	}
	
	return 0;
}











//
int isYahtzee(){
	int i;
	for( i = 1; i < N_OF_DICE; ++i ){
		if( dice[i] != dice[0] ) return 0;
	}
	
	return 1;
}










//Initializes score sheet to -1
void setUpScore(){
	
	int i, j;
	
	
	for( i = 0; i < MAX_PLAYERS; ++i){
		for( j = 0; j < N_SCORE_CATEGORIES; ++j){
			score[i][j] = -1;
		}
	}
}











//Prompts user until valid category is selected
int getCategory( int player ){
	
	int category;
	
	
	while(1){
		printf("Select category: ");
		fgets(line, LINE_SIZE, stdin);
		sscanf(line, "%d", &category);
		
		--category;	//So it matches array indexing
		
		if( category >= N_SCORE_CATEGORIES || category < 0){
			printf(ANSI_COLOR_RED "You may select categories from 1 to %d!\n" ANSI_COLOR_RESET, N_SCORE_CATEGORIES);
			continue;
		}
		
		if( score[player][category] == -1 ){
			break;
		}
		
		printf(ANSI_COLOR_RED "U can not reuse categories!\n" ANSI_COLOR_RESET);
	}
	
	
	
	return category;
}










































/*******************************************************************************
*
*	End section: Helper Functions
*
*******************************************************************************/




















