/*******************************************************************************
* Programmer: Yeji Chung		                                              *
* Class: CptS 121; Lab Section 16                                             *
* Programming Assignment: PA5 The Game of Yahtzee                             *
* Date: 10/21/2016                                                            *
*                                                                             *
* Description: This file defines the function prototypes that the compiler    *
*              uses to recognize function calls, and define the constant.     *
******************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define FULL_HOUSE 25
#define SMALL_STRAIGHT 30
#define LARGE_STRAIGHT 40
#define YAHTZEE 50
#define UPPER_BONUS 35

/*************************************************************
* Function: display_main_memu                                *
* Date Created: 10/14/2016                                   *
* Date Last Modified: 10/21/2016                             *
* Description: display the main menu to player.              *
* Input parameters: none                                     *
* Returns:	none						                     *
* Preconditions: none								         *
* Postconditions: choose one option between 1-3              *
*************************************************************/
void display_main_memu(void);

/*************************************************************
* Function: display_game_rule                                *
* Date Created: 10/14/2016                                   *
* Date Last Modified: 10/21/2016                             *
* Description: display the game rule to player.              *
* Input parameters: none                                     *
* Returns:	none						                     *
* Preconditions: select game rule on main menu.		         *
* Postconditions: none                                       *
*************************************************************/
void display_game_rule(void);

/*************************************************************
* Function: roll_dice                                        *
* Date Created: 10/14/2016                                   *
* Date Last Modified: 10/21/2016                             *
* Description: Roll five dice. This function randomly        *
*              generated a value between 1 and 6.            *
* Input parameters: dice[], size                             *
* Returns:	none						                     *
* Preconditions: select to play game.       		         *
* Postconditions: determine whether keep dice or roll agian. *
*************************************************************/
void roll_dice(int dice[], int size);

int select_combination(int *score);
void roll_again(int result_dice[], int size);
void display_roll_result(int *result_dice, int *count_comb_ptr, int *roll_count_ptr);


void count_dice(int count_dice[], int size_6, int result_dice[], int size_5);

int sum_num_1_6(int *count_dice, int *index);
int three_four_kind(int *count_dice, int flag_3_4);
int full_house(int *count_dice);
int small_straight(int *count_dice);
int large_straight(int *count_dice);
int yahtzee(int *count_dice);
int chance(int *count_dice);

void get_score(int *score, int *result_count_dice, int *flag_comb);
void display_score(int *score);//, int *count_comb, int *roll_count);

int upper_bonus(int(*score)[2], int flag_player);
int total_score(int(*score)[2], int flag_player);
void display_result(int*score);




