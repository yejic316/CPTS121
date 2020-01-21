#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 10
#define COLS 10

typedef enum direction
{
	HOR, VER
}DIR;
typedef struct ships
{
	char name[11];
	int ship_num;
	char ship_char;

}SHIPS;
typedef struct stats {
	int num_hit;
	int num_miss;
	int total_shot;
	double hit_miss_ratio;
}Stats;
typedef enum who_first
{
	USER, COMPUTER
}WhoFirst;
void welcome_screen(void);

void init_game_board(char board[][10], int rows, int cols);
void print_board(char board[][10], int rows, int cols);

int select_who_starts_first(void);
void manually_place_ships(char board[][10], int rows, int cols, int ship_num, char ship_char);
DIR generate_dir(void);

void randomly_place_ship(char board[][10], int rows, int cols,
int *row_ptr, int *col_ptr, DIR direction, int ship_num, char ship_char);
int check_shot(int hit_row, int hit_col, char board[][10], int rows, int cols);
int is_winner(int ship_result[], int index);
void update_board(int hit_row, int hit_col, int hit, char target_board[][10], int rows, int cols);
void output_current_move(FILE *outfile, int turn_flag, int hit_row, int hit_col, int hit_flag, int ship_result[], int index);
void check_if_sunk_ship(int hit_row, int hit_col,	char board[][10], int rows, int cols, 
	char target_board[][10], int rows_t, int cols_t, int ship_result[], int index);
void update_stats(Stats *p_stats, int hit);

void output_stats(FILE*outfile, Stats *p1_stats_ptr, Stats *p2_stats_ptr);
