/******************************************************************************
* Programmer: Yeji Chung													  *
* Class: CptS 121; Lab Section 16                                             *
* Programming Assignment: PA5 The Game of Yahtzee                             *
* Date: 10/21/2016                                                            *
*                                                                             *
* Description: This program desgined one of the most popular games of a dice  *
*              game called "Yahtzee".                                         *
*              The rules of the game are following.                           *
*              1. A player roll 5 dice										  *
*              2. Decide whether you use the result of dice, or roll again.   *
*                 -You can choose the dice you want to change.				  *
*                 -There are 3 chance you can roll           				  *
*              3. Choose one dice combination between following 13 part.	  *
*                 You will get score in () by choice.						  *
*                                                                             *
*                < upper section >											  *
*                1) Sum of 1's (1 * the number of 1)						  *
*                2) Sum of 2's (2 * the number of 2)						  *
*                3) Sum of 3's (3 * the number of 3)						  *
*                4) Sum of 4's (4 * the number of 4)						  *
*                5) Sum of 5's (5 * the number of 5)						  *
*                6) Sum of 6's (6 * the number of 6)						  *
*					- if total upper section score is greater than or equal	  *
*					to 63 for a player, the player can get 35 more point.	  *
*                                                                             *
*               < lower section >	                                          *
*               7) Three of a kind : Three dice with the same face			  *
*					(Sum of all face values on the 5 dice)					  *
*               8) Four of a kind : Four dice with the same face.			  *
*					(Sum of all face values on the 5 dice)					  *
*               9) Full house : One pair and a three-of-a-kind (25)			  *
*               10) Small straight : A sequence of four dice (30)			  *
*               11) Large straight : A sequence of five dice (40)			  *
*				12) Yahtzee : Five dice with the same face (50)				  *
*				13) Chance : any combination of dice						  *
*					(Sum of all face values on the 5 dice)					  *
*                                                                             *
*              4. Another player repeat the step 1-3						  *
*              5. Keep playing until both player record all 13 combination.	  *
*				  They will have 13 turns. Player who got high score is win.  *
*              															      *
*             Inputs: x          						                      *
*             Computations:                        					          *
*             Outputs: x							                          *
******************************************************************************/
#include "header.h"

int main(void)
{
	int choice1 = 0, roll_count = 0, count_comb[2] = { 0 }, flag_ready_select = 0, temp_comb = 0, k = 0, flag_player = 0,
		dice[5] = { 0 }, result_count_dice[7] = { 0 }, score[2][14] = { 0 }, flag_score[2][14] = { 0 },
		*roll_count_ptr = NULL, *flag_comb = NULL, *count_comb_ptr[2] ;
	char flag_use_dice = 0;
	printf("**********  WELCOME!!  THIS IS \"Yahtzee\"  ******************\n");

	roll_count_ptr = &roll_count;
	do
	{
		display_main_memu();
		scanf("%d", &choice1);
		system("cls");
	
		switch (choice1)
		{
		case 1:
			display_game_rule();
			system("pause");
			system("cls");
			break;
		case 2:
			printf("********************** GAME START! ***************************\n");
			//display_result(&score);
			//system("pause");
			do
			{
		
					count_comb_ptr[flag_player] = &count_comb[flag_player];

					if (*roll_count_ptr == 0)
					{
						printf("< player %d >\n", flag_player + 1);
						display_score(score[flag_player]);
						roll_dice(dice, 5);
						display_roll_result(dice, count_comb_ptr[flag_player], roll_count_ptr);
					}
					else if ((*roll_count_ptr > 0) && (*roll_count_ptr <3))
					{
						printf("* Do you want to use this result of dice?\t (Press Y or N)\n");
						scanf(" %c", &flag_use_dice);
						//(*roll_count_ptr)++;

						if (flag_use_dice == 'Y' || flag_use_dice == 'y' || roll_count>3)
						{
							flag_ready_select = 1;
							system("cls");
							(*roll_count_ptr)--;
							display_roll_result(dice, count_comb_ptr[flag_player], roll_count_ptr);
						}
						else if (flag_use_dice == 'N' || flag_use_dice == 'n')
						{
							roll_again(dice, 5);
							system("cls");
							display_roll_result(dice, count_comb_ptr[flag_player], roll_count_ptr);
						}
						else
						{
							(*roll_count_ptr)--;
						}
					}
					else if (*roll_count_ptr == 3)
					{
						flag_ready_select = 1;
						system("pause");
					}
					(*roll_count_ptr)++;

					if (flag_ready_select == 1)
					{
						count_dice(result_count_dice, 7, dice, 5);
						display_score(score[flag_player]);//, count_comb_ptr, roll_count_ptr);
						do
						{
							temp_comb = select_combination(score[flag_player]);
							flag_comb = &temp_comb;
							//printf("%d, %d, %d\n", flag_player, *flag_comb, flag_score[flag_player][*flag_comb]);
							//system("pause");
							//printf("flag_comb : %d\n", *flag_comb);
							if (flag_score[flag_player][*flag_comb] == 0)
							{
								flag_score[flag_player][*flag_comb] = 1;
								(*count_comb_ptr[flag_player])++;
								printf("count_comb_ptr[1] : %d  count_comb_ptr[2] : %d", (*count_comb_ptr)[0], (*count_comb_ptr)[1]);

								system("pause");
								get_score(score[flag_player], result_count_dice, flag_comb);

								flag_player++;

								system("cls");
							}
							else
							{
								printf("\n\"You have already chosen that combination.\t Choose another one.\"\n");
								flag_score[flag_player][*flag_comb] = 2;
							}
							//flag_player++;
						} while (flag_score[flag_player-1][*flag_comb] != 1);
						flag_ready_select = 0;
						*roll_count_ptr = 0; //
						for (int k = 0; k < 5; k++)
						{
							dice[k] = 0;
						}
						for (int k = 0; k < 7; k++)
						{
							result_count_dice[k] = 0;
						}
					}
					if (flag_player == 2)
						flag_player = 0;
//				}//while(flag_player<2)
			} while ((*count_comb_ptr)[0]<13 || (*count_comb_ptr)[1] < 13);
			display_result(&score);
			system("pause");
			break;
		case 3: break;
		default: break;
		}
	
	} while (choice1 != 3);
	printf("Did you enjoy \"Yahtzee\"? If yes, Come and enjoy again!  Good bye :) \n");
	return 0;
}