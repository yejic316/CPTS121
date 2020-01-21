/*******************************************************************************
* Programmer: Yeji Chung		                                              *
* Class: CptS 121; Lab Section 16                                             *
* Programming Assignment: PA4 A Game of Chance Craps                          *
* Date: 10/06/2016                                                            *
*                                                                             *
* Description: This file defines the function prototypes that the compiler    *
*              uses to recognize function calls, and define the constant.     *
******************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MANY_TURN 5

/*************************************************************
* Function: print_game_rules(void)                          *
* Date Created: 10/01/2016                                  *
* Date Last Modified: 10/04/2016                            *
* Description: display the game rules to player.            *
* Input parameters: none                                    *
* Returns:	none						                    *
* Preconditions: choose game rule on menu			        *
* Postconditions: none					                    *
*************************************************************/
void print_game_rules(void);

/*************************************************************
* Function: get_bank_balance(void)                          *
* Date Created: 10/01/2016                                  *
* Date Last Modified: 10/04/2016                            *
* Description: Prompts the player for an initial bank       *
*			   balance from which wagering will be added or *
*			   subtracted.									*
* Input parameters: none                                    *
* Returns:	bank balance which player input.		        *
* Preconditions: choose play game on menu.			        *
* Postconditions: bank balance will adjust after finishing  *
*				  game with wager.							*
*************************************************************/
double get_bank_balance(void);

/*************************************************************
* Function: get_wager_amount(void)                          *
* Date Created: 10/01/2016                                  *
* Date Last Modified: 10/04/2016                            *
* Description: Prompts the player for a wager on particular *
*			   rool.										*
* Input parameters: none                                    *
* Returns:	wager which player input				        *
* Preconditions: get initial bank balance.			        *
* Postconditions: check wager amount if the wager is within *
*				  the limits.				 				*
*************************************************************/
double get_wager_amount(void);

/*************************************************************
* Function: check_wager_amount(double wager, double balance)*
* Date Created: 10/01/2016                                  *
* Date Last Modified: 10/04/2016                            *
* Description: Checks to see if the wager is within the     *
*			   limits of the player's available balance		*
* Input parameters: wager, balance                          *
* Returns:	if wager exceed the balance, return 0	        *
*			otherwise, return 1						        *
* Preconditions: get initial bank balance and wager.        *
* Postconditions: add the checked wager which is not exceed *
*				  the available bank balance.	 			*
*************************************************************/
int check_wager_amount(double wager, double balance);

/*************************************************************
* Function: roll_die(void)                                  *
* Date Created: 10/01/2016                                  *
* Date Last Modified: 10/04/2016                            *
* Description: Rolls one die. This function randomly        *
*			   generate a value between 1 and 6.   			*
* Input parameters: none 			                        *
* Returns:	result value of the die.             	        *
* Preconditions: input the wager from player.               *
* Postconditions: add the result of two dice.			    *
*************************************************************/
int roll_die(void);

/*************************************************************
* Function: calculate_sum_dice								*
* Date Created: 10/01/2016                                  *
* Date Last Modified: 10/04/2016                            *
* Description: Sums together the values of the two dice     *
* Input parameters: die value1, die value2                  *
* Returns:	the sum of the two dice value        	        *
* Preconditions: roll the die twice.                        *
* Postconditions: compare the sum of the dice and the rule  *
*				  to determine win or lose. On first turn,	*
*				  if neither win nor lose, then it will   	*
*				  become player's "point"			        *
*************************************************************/
int calculate_sum_dice(int die1_value, int die2_value);

/*************************************************************
* Function: is_win_loss_or_point							*
* Date Created: 10/01/2016                                  *
* Date Last Modified: 10/04/2016                            *
* Description: Determines the result on the first roll by   *
*			   the following game rules.                    *
*			   If the sum is 7 or 11 , the player win		*
*			   If the sum is 2, 3, or 12, the player lose   *
*			   Otherwise, the sum becomes the player's point*
* Input parameters: sume of the dice                        *
* Returns:	If the sum is 7 or 11 on the roll, return 1     *
*			If the sum is 2, 3, or 12, return 0			    *
*			Others, return -1							    *
* Preconditions: sum of the two dice value.                 *
* Postconditions: If pleyer win or lose, adjust the bank    *
*				  balance. Otherwise, roll the dice again.	*
*************************************************************/
int is_win_loss_or_point(int sum_dice);

/************************************************************
* Function: is_point_loss_or_neither						*
* Date Created: 10/01/2016                                  *
* Date Last Modified: 10/04/2016                            *
* Description: Determines the result after first roll by the*
*			   following game rules.                        *
*			   If the sum is the point_value, the player win*
*			   If the sum is a 7, the player lose			*
* Input parameters: sume of the dice, point value.          *
* Returns:	If the sum is the point_value, return 1			*
*			If the sum is a 7, return 0			    		*
*			Others, return -1							    *
* Preconditions: result of the first roll.                  *
* Postconditions: If pleyer win or lose, adjust the bank    *
*				  balance. Otherwise, roll the dice again.	*
*************************************************************/
int is_point_loss_or_neither(int sum_dice, int point_value);

/************************************************************
* Function: adjust_bank_balance								*
* Date Created: 10/01/2016                                  *
* Date Last Modified: 10/04/2016                            *
* Description: Adjust the bank balance following the result *
*			   of the game. If player win, the sum of wager *
*			   is added to the bank balance, If player lose,*
*			   the sum of wager is subtracted to the bank   *
*			   balance.                                     *
* Input parameters: bank balance, wager amount, value about *
*                   about add or subtract.                  *
* Returns:	result of bank balance                  		*
* Preconditions: result of game(win or lose)                *
* Postconditions: chatter messege following the result of   *
*				  the game.                               	*
*************************************************************/
double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract);

/************************************************************
* Function: chatter_messages								*
* Date Created: 10/01/2016                                  *
* Date Last Modified: 10/04/2016                            *
* Description: Print an appropriate message dependent on    *
*			   the result of game, current bank balance,    *
*			   and so on.                                   *
* Input parameters: number of rolls, initial bank balance,  *
*                   current bank balance, sum of wager,     *
*                   result of win_loss_neither, point       *
* Returns:	none					                		*
* Preconditions: result of game(win or lose)and adjusting   *
*                bank balance.                              *
* Postconditions: none                                      *
*************************************************************/
void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance, double sum_wager, int point);

/*************************************************************
* Function: add_wager(double wager)                         *
* Date Created: 10/01/2016                                  *
* Date Last Modified: 10/04/2016                            *
* Description: add the checked wager which is not exceed the*
*			   available balance for final balance.			*
* Input parameters: wager, sum of wager				        *
* Returns:	sum of the wager                     	        *
* Preconditions: check the wager if it is exceed            *
* Postconditions: adjust bank balance after last roll.      *
*************************************************************/
double add_wager(double wager, double sum_wager);

