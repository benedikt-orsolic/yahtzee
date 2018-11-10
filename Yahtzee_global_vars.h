/*******************************************************************************
*	File name: Yahtzee_global_vars.c
*
*	Author: Benedikt Orsolic
*
*	Purpose: Fun
*
*	Usage: Definition of global varibles
*
*	TODO: /
*	      
*	      
*	      
*	      
*
*******************************************************************************/











#ifndef _YAHTZEE_GLOBAL_VARS_INCLUDED
#define _YAHTZEE_GLOBAL_VARS_INCLUDED











#define MAX_PLAYERS 4
#define MAX_DICE_ROLLS 3
#define N_SCORE_CATEGORIES 13
#define NAME_LENGTH_ARRY 18
#define NAME_LENGTH_STR "17"
#define LINE_SIZE 50
#define N_OF_DICE 5







#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"










// Score sheet
extern int score[][N_SCORE_CATEGORIES];
	/***************************************************************************  
	Aces................Sum of dice with num 1
	Twos................Sum of dice with num 2
	Threes..............Sum of dice with num 3
	Fours...............Sum of dice with num 4
	Fives...............Sum of dice with num 5
	Sixes...............Sum of dice with num 6
	  
	Three Of A Kind.....At least three dice the same and sum of all dice
	Four Of A Kind......At least four dice the same and sum of all dice
	Full House..........Three of one number and two of another 25
	Small Straight......Four sequential dice (1-2-3-4; 2-3-4-5) 30
	Large Straight......Five sequential dice (1-2-3-4-5; 2-3-4-5-6) 40
	Yahtzee.............All five dice the same 50
	Chance..............Any combination and Sum of all dice
	***************************************************************************/
	
// Player names
extern char names[][NAME_LENGTH_ARRY];
// Used for random text inputs
extern char line[];
// Number of players
extern int n_players;
// Arry storing dice values
// -1 value means: set to new rand int between 1 and 6
extern int dice[];
// Stores names of categories in score sheet
extern char categoryNames[][20];












#endif






