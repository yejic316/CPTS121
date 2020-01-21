/******************************************************************************
* Programmer: Yeji Chung													  *
* Class: CptS 121; Lab Section 16                                             *
* Programming Assignment: PA4 A Game of Chance Craps                          *
* Date: 10/06/2016                                                            *
*                                                                             *
* Description: This program desgined one of the most popular games of a dice  *
*              game called "Craps" which is played in casinos.                *
*              The rules of the game are following.                           *
*              1. Enter your initial bank balance							  *
*              2. Bet your money											  *
*              3. Roll the die												  *
*              4. On first throw, if the sum of the dies is 7 or 11, you wins *
*								  if the sum is 2, 3, or 12 , you lose.       *
*								  else, the sum will be your "point"	      *
*			  5. Bet your money and roll the die again						  *	
*			  6. Since Second throw, if the sum is the "point" , you wins 	  *
*									 if the sum is 7, you lose				  *
*             7. Keep betting and rolling the die until you win or you lose	  *
*				If you win, you get double amount of money which you bet	  *
*               If you lose, you lose your money which you bet		          *
*              															      *
*             Inputs: x          						                      *
*             Computations:                        					          *
*             Outputs: x							                          *
******************************************************************************/
#include "header.h"
int main(void)
{
	int choice = 0, die1 = 0, die2 = 0, sum_dice = 0, result_win_lose_or_point = 0, count = 1, point = 0;
	double initial_bank_balance = 0, current_bank_balance = 0, wager = 0, sum_wager = 0;
	printf("**********  WELCOME!!  THIS IS \"CRAPS\"  ******************\n");

	do
	{
		printf("< SELECT MENU >\n");
		printf("1. print game rules\n");
		printf("2. Play games\n");
		printf("3. exit games\n");
		scanf("%d", &choice);
		system("cls"); 
		switch (choice)
		{
		case 1:
			print_game_rules();
			system("pause");
			system("cls");
			break;
		case 2:

			initial_bank_balance = get_bank_balance();
			current_bank_balance = initial_bank_balance;
			printf("< Current Bank Balance: $%lf >\n", initial_bank_balance);
			printf("************************************************************\n");

			do
			{
				do
				{
					wager = get_wager_amount();
					if (check_wager_amount(wager, initial_bank_balance - sum_wager) == 0)
					{
						printf("The wager exceeds your allowable balance!! Bet again.\n\n");
					}
				} while (check_wager_amount(wager, initial_bank_balance - sum_wager) == 0);
				
				sum_wager = add_wager(wager, sum_wager);

				printf("\n Now, Roll the dice\n");
				system("pause");
				srand((unsigned int)time(NULL));
				die1 = roll_die();
				die2 = roll_die();

				printf("\n* result of dice :  %d  ,  %d\n\n", die1, die2);
				sum_dice = calculate_sum_dice(die1, die2);
				if (count == 1)
				{
					point = sum_dice;
					result_win_lose_or_point = is_win_loss_or_point(sum_dice);
				}
				else
				{
					result_win_lose_or_point = is_point_loss_or_neither(sum_dice, point);
				}
				current_bank_balance = adjust_bank_balance(initial_bank_balance, sum_wager, result_win_lose_or_point); // If add_or_subtract is 1, then the wager amount is added to the bank_balance.If add_or_subtract is 0, then the wager amount is subtracted from the bank_balance.Otherwise, the bank_balance remains the same.The bank_balance result is returned.

				chatter_messages(count, result_win_lose_or_point, initial_bank_balance, current_bank_balance, sum_wager, point);
				count++;
			}
			while (result_win_lose_or_point==-1);

			system("pause");
			system("cls");
			count = 1;
			current_bank_balance = 0;
			initial_bank_balance = 0;
			sum_wager = 0;

		break;

		case 3:
			break;
		default:
			break;
		}
	} 
	while ((choice == 1) || (choice == 2));

	
	return 0;
}