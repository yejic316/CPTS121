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
//Create a function welcome_screen() that displays an initial program welcome message along with the rules of Battleship.
void welcome_screen(void)
{
	printf("**********  WELCOME!!  THIS IS \"Battle ship\"  ******************\n");
	printf("1. This is a two player game.\n");
	printf("2. Player1 is you and Player2 is computer.\n");
	printf("3. Etc..\n");
	printf("\n\"Hit enter to start the game!\"\n");
	system("pause");
	system("cls");
}
//Create a function initialize_game_board() that sets each cell in a game board to '-'.
void init_game_board(char board[][10], int rows, int cols)
{
	int row_index = 0, col_index = 0;
	for (row_index = 0; row_index < rows; ++row_index)
	{
		for (col_index = 0; col_index < cols; ++col_index)
		{
			board[row_index][col_index] = '~';
		}
	}

}
//Create a function select_who_starts_first() that determines if Player1 or Player2 goes first in the game.
WhoFirst select_who_starts_first(void)
{
	return (WhoFirst)rand() % 2;
}
//Create a function manually_place_ships_on_board() that allows the user to place each of the 5 types of ships on his / her game board.
void manually_place_ships(char board[][10], int rows, int cols,int ship_num, char ship_char)
{
	int  ship[10] = { 0 }, error_check = 0;
	print_board(board, ROWS, COLS);

	do
	{
		for (int k = 0; k < 2*ship_num; k=k+2)
		{
			printf("Cell(%d)  ", k/2+1);
			scanf("%d %d", &ship[k], &ship[k+1]);
			if (ship[k] < 0 || ship[k+1] < 0 || ship[k] > 9 || ship[k+1] > 9)//error1 : range is not on 0 ~ 9
			{
				printf("\"You can't place the ship to that spot. Select again.\"\n");
				error_check = 1;
				break;
			}
			else if (board[ship[k]][ship[k + 1]] != '~')// error 2: select non-empty spot
			{
				printf("You have already selected that spot. Select again.\n");
				error_check = 1;
				break;
			}
			else if (k >=2)//error3 : select non- contiguous cell
			{
				error_check = 1;
				if (ship[2] == ship[0])//horizontal
				{
					if ((ship[k + 1] == ship[k - 1] + 1) && (ship[k] == ship[k - 2]))
					{
						error_check = 0;
					}
					else
					{
						printf("\"You should select contiguous horizontal or vertical cell . Select again.\"\n");
						error_check = 1;
						break;
					}
				}
				else if (ship[3] == ship[1])//vertical
				{
					if ((ship[k] == ship[k - 2] + 1) && (ship[k + 1] == ship[k - 1]))
					{
						error_check = 0;
					}
					else
					{
						printf("\"You should select contiguous horizontal or vertical cell . Select again.\"\n");
						error_check = 1;
						break;
					}
				}
				else
				{
					printf("\"You should select contiguous horizontal or vertical cell . Select again.\"\n");
					error_check = 1;
					break;
				}
			}
		}
		if (error_check == 1)// if error, initialize 0
		{
		//	printf("error_check : %d\n", error_check);
			for (int i = 0; i < 10; ++i)
			{
				ship[i] = 0;
			}
		}
	} while (error_check==1);
	//printf("out\n");
	for(int j=0; j < 2*ship_num; j=j+2)
	{
		//printf("%d %d\n", j, j + 1);
		board[ship[j]][ship[j+1]] = ship_char;
	}
}

void print_board(char board[][10], int rows, int cols)
{
	printf("  0 1 2 3 4 5 6 7 8 9\n");
	for (int k = 0; k < rows; ++k)
	{
		printf("%d ", k);
		for (int j = 0; j < cols; ++j)
		{
			printf("%c ", board[k][j]);
		}
		printf("\n");
	}
	printf("\n");

}
//Create a function randomly_place_ships_on_board() that randomly places the 5 types of ships on a given board.
DIR generate_dir(void)
{
	DIR direction = HOR;
	direction = (DIR)rand() % 2;
	return direction;
}
void randomly_place_ship(char board[][10], int rows, int cols, 
			int *row_ptr, int *col_ptr, DIR direction, int ship_num, char ship_char)
{
	int error_check = 0;
	//printf("%d\n", direction);
	if (direction == HOR)
	{
		do
		{
			*row_ptr = rand() % ROWS;
			*col_ptr = rand() % (COLS - ship_num + 1);
			for (int i = 0; i < ship_num; ++i)
			{
				//printf("%c\n", board[*row_ptr][(*col_ptr) + i]);

				if ((board[*row_ptr][(*col_ptr) + i] == '~') && ((*col_ptr)+i < cols) )
				{
					error_check = 0;
				}
				else
				{
					error_check = 1;
					break;
				}
				//printf("error: %d\n", error_check);

				
			}
			if (error_check == 0)
			{
				for (int i=0; i < ship_num; ++i)
				{
					board[*row_ptr][(*col_ptr) + i] = ship_char;
				}
			}

		} while (error_check == 1);
	}
	else
	{
		do
		{
			*row_ptr = rand() % (ROWS - ship_num + 1);
			*col_ptr = rand() % COLS;
			for (int i = 0; i < ship_num; ++i)
			{
				//printf("%c\n", board[(*row_ptr) + i][*col_ptr]);
				if ((board[(*row_ptr) + i][*col_ptr] == '~') &&  ((*row_ptr) + i < rows) )
				{
					error_check = 0;
				}
				else
				{
					error_check = 1;
					break;
				}
				//printf("error: %d\n", error_check);

	
			}
			if (error_check == 0)
			{
				for (int i=0; i < ship_num; ++i)
				{
					board[(*row_ptr) + i][*col_ptr] = ship_char;
				}
			}

		} while (error_check == 1);
		
	}
}
//Create a function check_shot() that determines if the shot taken was a hit or a miss.
int check_shot(int hit_row, int hit_col, 
	char board[][10], int rows, int cols)
{
	if (board[hit_row][hit_col] != '~')//hit
	{
		printf("\"%d, %d is a hit!\"\n\n", hit_row, hit_col);
		return 1;
	}
	else//miss
	{
		printf("\"%d, %d is a miss!\"\n\n", hit_row, hit_col);
		return 0;
	}
}
//Create a function is_winner() that determines if a winner exists.
int is_winner(int ship_result[], int index)
{
	int win_flag = 0;
	for (int i = 0; i < index; ++i)
	{
		if (ship_result[i] == 1)
		{
			win_flag = 1;
		}
		else
		{
			win_flag = 0;
			break;
		}
	}
	if (win_flag == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//Create a function update_board() that updates the board every time a shot is taken. '*' indicates a hit and 'm' indicates a miss.
void update_board(int hit_row, int hit_col,  int hit,
			char target_board[][10], int rows, int cols)
{
	if (hit == 1)//hit
	{
		target_board[hit_row][hit_col] = '*';
	}
	else//miss
	{
		target_board[hit_row][hit_col] = 'm';
	}

}
//Create a function output_current_move() that writes the position of the shot taken by the current player to the log file.It also writes whether or not it was a hit, miss, and if the ship was sunk.
void output_current_move(FILE *outfile, int turn_flag, int hit_row, int hit_col, int hit_flag, int ship_result[], int index)
{
	if (hit_flag == 1)
	{
		fprintf(outfile, "\nPlayer%d : %d, %d \"hit\"", turn_flag+1, hit_row, hit_col );
	}
	else
	{
		fprintf(outfile, "\nPlayer%d : %d, %d \"miss\"", turn_flag+1, hit_row, hit_col);
	}
	if (ship_result[0] == 1 )
	{
		fprintf(outfile, "Sunk Carrier!");
	}
	else if (ship_result[1] == 1) 
	{
		fprintf(outfile, "Sunk Battleship!");
	}
	else if (ship_result[2] == 1 )
	{
		fprintf(outfile, "Sunk Cruiser!");
	}
	else if (ship_result[3] == 1 )
	{
		fprintf(outfile, "Sunk Submarine!");
	}
	else if (ship_result[4] == 1 )
	{
		fprintf(outfile, "Sunk Destroyer!");
	}
}
//Create a function check_if_sunk_ship() that determines if a ship was sunk.
void check_if_sunk_ship(int hit_row, int hit_col,
	char board[][10], int rows, int cols,
	char target_board[][10], int rows_t, int cols_t, int ship_result[], int index)
{
	int count = 0;
	switch(board[hit_row][hit_col])
	{
		case 'c':
			for (int i = 0; i < rows; ++i)
			{
				for (int j = 0; j < cols; ++j)
				{
					if (board[i][j] == 'c' && target_board[i][j] == '*')
					{
						count++;
					}
				}
			}
			if (count == 5)
			{
				printf("\"Carrier is sunk!...\"\n");
				ship_result[0] = 1;
			}
			break;
		case 'b':
			for (int i = 0; i < rows; ++i)
			{
				for (int j = 0; j < cols; ++j)
				{
					if (board[i][j] == 'b' && target_board[i][j] == '*')
					{
						count++;
					}
				}
			}
			if (count == 4)
			{
				printf("\"Battleship is sunk!...\"\n");
				ship_result[1] = 1;
			}
			break;		
		case 'r':
			for (int i = 0; i < rows; ++i)
			{
				for (int j = 0; j < cols; ++j)
				{
					if (board[i][j] == 'r' && target_board[i][j] == '*')
					{
						count++;
					}
				}
			}
			if (count == 3 )
			{
				printf("\"Cruiser is sunk!...\"\n");
				ship_result[2] = 1;
			}
			break;
		case 's':
			for (int i = 0; i < rows; ++i)
			{
				for (int j = 0; j < cols; ++j)
				{
					if (board[i][j] == 's' && target_board[i][j] == '*')
					{
						count++;
					}
				}
			}
			if (count == 3 )
			{
				printf("\"Submarine is sunk!...\"\n");
				ship_result[3] = 1;
			}
			break;
		case 'd':
			for (int i = 0; i < rows; ++i)
			{
				for (int j = 0; j < cols; ++j)
				{
					if (board[i][j] == 'd' && target_board[i][j] == '*')
					{
						count++;
					}
				}
			}
			if (count == 2 )
			{
				printf("\"Distroyer is sunk!...\"\n");
				ship_result[4] = 1;
			}
			break;
	}

}
//Create a function output_stats() that writes the statistics collected on each player to the log file.
void output_stats(FILE*outfile, Stats *p1_stats_ptr, Stats *p2_stats_ptr)
{

	fprintf(outfile, "\n\n\n***** Player 1 *****\n");
	fprintf(outfile, "* Number Hits : %d\n", p1_stats_ptr->num_hit);
	fprintf(outfile, "* Number Misses : %d\n", p1_stats_ptr->num_miss);
	fprintf(outfile, "* Total Shot : %d\n", p1_stats_ptr->total_shot);
	p1_stats_ptr->hit_miss_ratio = ((double)(p1_stats_ptr->num_hit) / (p1_stats_ptr->total_shot))*100;
	fprintf(outfile, "* Hit/Miss Ratio : %.0lf%%\n", p1_stats_ptr->hit_miss_ratio);

	fprintf(outfile, "\n***** Player 2 *****\n");
	fprintf(outfile, "* Number Hits : %d\n", p2_stats_ptr->num_hit);
	fprintf(outfile, "* Number Misses : %d\n", p2_stats_ptr->num_miss);
	fprintf(outfile, "* Total Shot : %d\n", p2_stats_ptr->total_shot);
	p2_stats_ptr->hit_miss_ratio = ((double)(p2_stats_ptr->num_hit) / (p2_stats_ptr->total_shot))*100;
	fprintf(outfile, "* Hit/Miss Ratio : %.0lf%%\n", p2_stats_ptr->hit_miss_ratio);
}
void update_stats(Stats *p_stats_ptr, int hit)
{
	if (hit)
	{
		p_stats_ptr->num_hit += 1;
	}
	else
	{
		p_stats_ptr->num_miss += 1;
	}
	p_stats_ptr->total_shot += 1;

}
//Other functions that you think are necessary!
//A main function that does the following :
//o   Opens an output file battleship.log for writing;
//o   Simulates the game of Battleship
//o   Outputs data to logfile
//o   Outputs stats to logfile
//o   Closes logfile