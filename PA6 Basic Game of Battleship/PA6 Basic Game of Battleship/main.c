/******************************************************************************
* Programmer: Yeji Chung													  *
* Class: CptS 121; Lab Section 16                                             *
* Programming Assignment: PA6 Basic Game of Battleship                        *
* Date: 11/05/2016                                                            *
*                                                                             *
* Description:                                                                *

*             Inputs: x          						                      *
*             Computations:                        					          *
*             Outputs: x							                          *
******************************************************************************/
#include "header.h"
int main(void)
{
	char p1_board[10][10] = { '\0' }, p2_board[10][10] = { '\0' },
		p1_target_board[10][10] = { '\0' }, p2_target_board[10][10] = { '\0' };
	
	int choice1 = 0, count_turn=0, hit_row=0, hit_col=0, hit_flag=0, win_flag=0;
	int *row_ptr, *col_ptr;
	int p1_ship_result[5] = { 0 }, p2_ship_result[5] = { 0 };
	DIR direction = 'HOR';
	WhoFirst turn = 'USER';
	SHIPS ship[5]={
		{ "Carrier",5,'c' },
		{ "Battleship",4,'b' },
		{ "Cruiser",3,'r' },
		{ "Submarine",3,'s' },
		{ "Destroyer",2,'d' }
	};
	Stats p1_stats = { 0, 0, 0, 0.0 }, p2_stats = { 0, 0, 0, 0.0 };
	FILE *outfile = NULL;
	outfile = fopen("battleship.log", "w");
	//fprintf(outfile, "open");
	//fputs( "open\n", outfile);
	init_game_board(p1_board, 10, 10);
	init_game_board(p2_board, 10, 10);
	init_game_board(p1_target_board, 10, 10);
	init_game_board(p2_target_board, 10, 10);
	welcome_screen();

	while (choice1 != 1 && choice1 != 2)
	{
		printf("< SELECT OPTION >\n");
		printf("1. Enter Positions of Ships Manually\n");
		printf("2. Program Randomly select position\n");
		scanf("%d", &choice1);
		srand((unsigned int)time(NULL));

		if (choice1 == 1)
		{
			//enter positions of ships manually
			for (int i = 0; i < 5; ++i)
			{
				printf("Enter the %d cells to place the %s across\n", ship[i].ship_num, ship[i].name);
				manually_place_ships(p1_board, ROWS, COLS, ship[i].ship_num, ship[i].ship_char);
				system("pause");
				system("cls");
			}
			printf(" < player1 >\n");
			print_board(p1_board, ROWS, COLS);
			printf(" < player2 >\n");
			print_board(p2_board, ROWS, COLS);
		}
		else if (choice1 == 2)
		{
			//program randmy select position
			for (int i = 0; i < 5; ++i)
			{
				direction = generate_dir();
				randomly_place_ship(p1_board, ROWS, COLS, &row_ptr, &col_ptr, direction, ship[i].ship_num, ship[i].ship_char);
			}
		
			//print_board(p1_board, ROWS, COLS);
			//print_board(p2_board, ROWS, COLS);
		}
		//set the board for computer
		for (int i = 0; i < 5; ++i)
		{
			direction = generate_dir();
			randomly_place_ship(p2_board, ROWS, COLS, &row_ptr, &col_ptr, direction, ship[i].ship_num, ship[i].ship_char);
		}

		printf("\"Now, Game Start\"\n");
		turn = select_who_starts_first();
		while (win_flag==0)
		{
			printf(" < player1's board >\n");
			print_board(p1_board, ROWS, COLS);
			printf(" < player2's board >\n");
			print_board(p2_target_board, ROWS, COLS);

			if (turn == USER)//Player
			{
				if (count_turn == 0)
				{
					printf("\"You start first!\"\n");
				}

				printf("* Select a position as row col :");
				scanf("%d %d", &hit_row, &hit_col);
				system("cls");
				hit_flag=check_shot(hit_row, hit_col, p2_board, ROWS, COLS);
				update_board(hit_row, hit_col, hit_flag, p2_target_board, ROWS, COLS);
				update_stats(&p2_stats, hit_flag);
				check_if_sunk_ship(hit_row, hit_col, p2_board, ROWS, COLS, p2_target_board, ROWS, COLS, p2_ship_result, 5);
				output_current_move(outfile, 0, hit_row, hit_col, hit_flag, p2_ship_result, 5);

				win_flag = is_winner(p2_ship_result, 5);

				if (win_flag == 1)
				{
					printf("Player 1 is win! \n");
				}
				turn = COMPUTER;
			}
			else if (turn == COMPUTER)//Computer
			{
				if (count_turn == 0)
				{
					printf("\"Computer start first!\"\n");
				}
				system("pause");
				system("cls");
				hit_row = rand() % 10;
				hit_col= rand() % 10;
				printf(" Player2 Select : %d, %d\n", hit_row, hit_col);
				hit_flag = check_shot(hit_row, hit_col, p1_board, ROWS, COLS);
				update_board(hit_row, hit_col, hit_flag, p1_target_board, ROWS, COLS);
				update_stats(&p1_stats, hit_flag);
				check_if_sunk_ship(hit_row, hit_col, p1_board, ROWS, COLS, p1_target_board, ROWS, COLS, p1_ship_result, 5);
				output_current_move(outfile, 1, hit_row, hit_col, hit_flag, p1_ship_result, 5);

				win_flag = is_winner(p1_ship_result, 5);
				if (win_flag == 1)
				{
					printf("Player 2 is win! \n");
				}
				turn = USER;
			}
			count_turn++;
		}
		
	}
	output_stats(outfile, &p1_stats, &p2_stats);

	fclose(outfile);
	return 0;
}