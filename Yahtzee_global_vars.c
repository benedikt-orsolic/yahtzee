/*******************************************************************************
*	File name: Yahtzee_global_vars.c
*
*	Author: Benedikt Orsolic
*
*	Purpose: Definition of global varibles
*
*	Usage: \
*
*	TODO: \
*	      
*	      
*	      
*	      
*
*******************************************************************************/







#include "Yahtzee_global_vars.h"






// Score sheet
int score[MAX_PLAYERS][N_SCORE_CATEGORIES];
// Player names
char names[MAX_PLAYERS][NAME_LENGTH_ARRY];
// Used for random text inputs
char line[LINE_SIZE];
// How many players currently	
int n_players;
// dice array to store dice values
int dice[N_OF_DICE];
char categoryNames[N_SCORE_CATEGORIES][20]={
                                                "Aces",
                                                "Twos",
                                                "Threes",
                                                "Fours",
                                                "Fives",
                                                "Sixes",
                                                "Three Of A Kind",
                                                "Four Of A Kind",
                                                "Full House",
                                                "Small Straight",
                                                "Large straight",
                                                "Yahtzee",
                                                "Chance",
};
