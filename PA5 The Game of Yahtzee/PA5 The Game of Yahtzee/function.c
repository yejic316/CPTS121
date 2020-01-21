/*******************************************************************************
* Programmer: Yeji Chung		                                              *
* Class: CptS 121; Lab Section 16                                             *
* Programming Assignment: PA5 The Game of Yahtzee                             *
* Date: 10/21/2016                                                            *
*                                                                             *
* Description: This file contains the all functions which need to operate the *
*              game "Yahtzee"                                                 *
******************************************************************************/
#include "header.h"
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
void display_main_memu(void)
{
	printf("< SELECT MENU >\n");
	printf("1. print game rules\n");
	printf("2. Start a game of Yahtzee\n");
	printf("3. exit games\n");
}
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
void display_game_rule(void)
{
	printf("**************** \"Yahtzee\"GAME RULE ***********************\n");
	printf("1. A player roll 5 dice.\n");
	printf("2. Decide whether you use the result of dice, or roll dice again. \n");
	printf("\t-You can choose the dice you want to change. There are 3 chance you can roll\n");
	printf("3. Choose one dice combination between following 13 part. You will get score in () by choice\n\n");
	printf("\t< upper section >\n");
	printf("\t1) Sum of 1's (1 * the number of 1)\n");
	printf("\t2) Sum of 2's (2 * the number of 2)\n");
	printf("\t3) Sum of 3's (3 * the number of 3)\n");
	printf("\t4) Sum of 4's (4 * the number of 4)\n");
	printf("\t5) Sum of 5's (5 * the number of 5)\n");
	printf("\t6) Sum of 6's (6 * the number of 6)\n");
	printf("\t - if total upper section score is greater than or equal to 63 for a player, the player can get 35 more point.\n\n");
	printf("\t< lower section > \n");
	printf("\t7) Three of a kind : Three dice with the same face (Sum of all face values on the 5 dice)\n");
	printf("\t8) Four of a kind : Four dice with the same face. (Sum of all face values on the 5 dice)\n");
	printf("\t9) Full house : One pair and a three-of-a-kind (25)\n");
	printf("\t10) Small straight : A sequence of four dice (30)\n");
	printf("\t11) Large straight : A sequence of five dice (40)\n");
	printf("\t12) Yahtzee : Five dice with the same face (50)\n");
	printf("\t13) Chance : any combination of dice (Sum of all face values on the 5 dice)\n\n");

	printf("4. Another player repeat the step 1-3\n");
	printf("5. Keep playing until both player record all 13 combination. They will have 13 turns. Player who got high score is win.\n");
	
}
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
void roll_dice(int dice[], int size)
{
	int k = 0;

	printf("\n\"roll the dice!\"\n");
	system("pause");
	srand((unsigned int)time(NULL));

	for (k = 0; k < size; k++)
	{
		if (dice[k] == 0)
		{
			dice[k] = rand() % 6 + 1;
		}
	}
	
}
void display_roll_result(int *result_dice, int *count_comb_ptr, int *roll_count_ptr)
{
	int k = 0;
	printf("\n\t<Turn %d_%d>\n", *count_comb_ptr + 1, *roll_count_ptr + 1);

	for (k = 0; k < 5; k++)
	{
		printf("\tdice[%d]= %d\n", k + 1, result_dice[k]);
	}
	printf("************************************************************\n");
}
void roll_again(int result_dice[], int size)
{
	int choice = 0, k=0;
	printf("Select dice's number which you want to change.\tEnter \"0\"if you finish to choose\n");
	do
	{
		printf("* Enter a number between 0 through 5 : ");
		scanf(" %d", &choice);
		result_dice[choice - 1] = 0;

	} while (choice != 0);
	roll_dice(result_dice, size);
}
int select_combination(int *score)
{
	int flag_comb = 0;

	printf("* Select one of the game combinations : ");
	scanf("%d", &flag_comb);
	return flag_comb;
}
void count_dice(int count_dice[], int size_6, int result_dice[], int size_5)
{
	int k = 0, j = 0;
	for (j = 1; j < 7; j++)
	{
		for (k = 0; k < 5; k++)
		{
			if (j == result_dice[k])
			{
				count_dice[j]++;
			}
		}
	//	printf("dice[%d]= %d\n", j , count_dice[j]);
		//printf("************************************************************\n");


	}
}
int sum_num_1_6(int *count_dice, int *index)
{
	//printf("index : %d\n", *index);
	//printf("count_dice : %d\n", *count_dice);
	return (*index)*(*count_dice);
}
int three_four_kind(int *count_dice, int flag_3_4)
{
	int k = 0, sum = 0, flag = 0;
	for (k = 1; k < 7; k++)
	{
		sum += k*count_dice[k];
	//	printf("-----%d, %d\n", count_dice[k], flag_3_4);

		if (count_dice[k] >= flag_3_4)
		{
			flag = 1;
		}
	}
	if (flag == 1)
		return sum;
	else
		return 0;
}
int full_house(int *count_dice)
{
	int k = 0, j = 0, flag = 0;
	for(k = 1; k < 7; k++)
	{
		if (count_dice[k] == 2)
		{
			for (j = 1; j < 7; j++)
			{
				if (count_dice[j] == 3)
				{
					flag = 1;
					break;
				}
			}
		}
	}
	if (flag == 1)
		return FULL_HOUSE;
	else
		return 0;
	
}
int small_straight(int *count_dice)
{
	int k = 0, flag = 0;
	for (k = 1; k < 4; k++)
	{
		if ((count_dice[k] >= 1) && (count_dice[k + 1] >= 1) && (count_dice[k + 2] >= 1) && (count_dice[k + 3] >= 1))
		{
			printf("small_\n");
			flag = 1;
			break;
		}	
	}
	if (flag == 1)
		return SMALL_STRAIGHT;
	else
		return 0;
}
int large_straight(int *count_dice)
{
	int k = 0, flag = 0;
	for (k = 1; k < 3; k++)
	{
		if ((count_dice[k] >= 1) && (count_dice[k + 1] >= 1) && (count_dice[k + 2] >= 1) && (count_dice[k + 3] >= 1) && (count_dice[k + 4] >= 1))
		{
			flag = 1;
			break;
		}
	}
	if (flag == 1)
		return LARGE_STRAIGHT;
	else
		return 0;
}
int yahtzee(int *count_dice)
{
	int k = 0, flag = 0;
	for (k = 1; k < 7; k++)
	{
		if (count_dice[k] == 5)
		{
			flag = 1;
			break;
		}
	}
	if (flag == 1)
		return YAHTZEE;
	else
		return 0;
}
int chance(int *count_dice)
{
	int k = 0, sum = 0;
	for (k = 1; k < 7; k++)
	{
		sum += k*count_dice[k];
	}
	return sum;
}
void get_score(int *score, int *result_count_dice, int *flag_comb)
{
	//printf(" **** flag_comb : %d\n", *flag_comb);
	//printf(" **** result_count_dice : %d\n", result_count_dice[*flag_comb]);

	if (*flag_comb >= 1 && *flag_comb <= 6)
	{
		/*for (int k = 0; k < 7; k++)
		{
			printf("\t\tcount_dice[%d]= %d\n", k + 1, result_count_dice[k]);
		}*/
		//printf("##### result_countdice[*flag_comb] = %d\n", result_count_dice[*flag_comb]);
		score[*flag_comb] = sum_num_1_6(&result_count_dice[*flag_comb], flag_comb);
		//printf("1-6 score[%d]: %d\n", *flag_comb, score[*flag_comb]);
		//system("pause");
	}
	else if (*flag_comb == 7 )
	{
		score[*flag_comb] = three_four_kind(result_count_dice, 3);
		//printf("7 score[%d]: %d\n", *flag_comb, score[*flag_comb]);
	}
	else if ( *flag_comb == 8)
	{
		score[*flag_comb] = three_four_kind(result_count_dice, 4);
		//printf("8 score[%d]: %d\n", *flag_comb, score[*flag_comb]);
	}
	else if (*flag_comb == 9)
	{
		score[*flag_comb] = full_house(result_count_dice);
		//printf("9 score[%d]: %d\n", *flag_comb, score[*flag_comb]);
	}
	else if (*flag_comb == 10)
	{
		score[*flag_comb] = small_straight(result_count_dice);
		//printf("10 score[%d]: %d\n", *flag_comb, score[*flag_comb]);
	}
	else if (*flag_comb == 11)
	{
		score[*flag_comb] = large_straight(result_count_dice);
		//printf("11 score[%d]: %d\n", flag_comb, score[*flag_comb]);
	}
	else if (*flag_comb == 12)
	{
		score[*flag_comb] = yahtzee(result_count_dice);
	//	printf("12 score[%d]: %d\n", *flag_comb, score[*flag_comb]);
	}
	else if (*flag_comb == 13)
	{
		score[*flag_comb] = chance(result_count_dice);
		//printf("13 score[%d]: %d\n", *flag_comb, score[*flag_comb]);
	}
	else;
}
void display_score(int *score)//, int *count_comb_ptr, int *roll_count_ptr)
{
	printf("1) Sum of 1's : %d\t\t7) Three of a kind : %d\n", score[1],score[7]);
	printf("2) Sum of 2's : %d\t\t8)  Four of a kind : %d\n", score[2], score[8]);
	printf("3) Sum of 3's : %d\t\t9)  Full house     : %d\n", score[3], score[9]);
	printf("4) Sum of 4's : %d\t\t10) Small straight : %d\n", score[4], score[10]);
	printf("5) Sum of 5's : %d\t\t11) Large straight : %d\n", score[5], score[11]);
	printf("6) Sum of 6's : %d\t\t12) Yahtzee        : %d\n", score[6], score[12]);
	printf(" \t\t\t\t13) Chance         : %d\n", score[13]);
	printf("************************************************************\n");

}
int upper_bonus(int(*score)[2], int flag_player)
{
	int k = 0, sum = 0;
	for (k = 1; k < 7; k++)
	{
		sum += score[flag_player][k];
	}
	if (sum >= 63)
		return UPPER_BONUS;
	else
		return 0;
}
int total_score(int (*score)[2], int flag_player)
{
	int k = 0, sum = 0;
	for (k = 1; k < 14; k++)
	{
		sum += score[flag_player][k];
	}
	sum += upper_bonus(score, flag_player);

	return sum;
}
void display_result(int*score)
{
	int total_score_1 = 0, total_score_2 = 0, winner=0;
	printf("********************** GAME RESULT ***************************\n");
	printf("<player1>\n");
	display_score(score);// Player1

	printf("<player2>\n");
	display_score(score+14);// Player2
	total_score_1 = total_score((&score)[0], 0);
	total_score_2 = total_score((&score)[1], 1);
	printf("Player 1's total score is %d.", total_score_1);
	printf("Player 2's total score is %d.", total_score_2);

	if (total_score_1 > total_score_2)
		winner = 1;
	else if (total_score_1 < total_score_2)
		winner = 2;

	printf("Congratulation!! Player %d win!", winner);
}