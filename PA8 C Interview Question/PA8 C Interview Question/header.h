/******************************************************************************
* Programmer: Yeji Chung													  *
* Class: CptS 121; Lab Section 16                                             *
* Programming Assignment: PA8 C Interview Question                            *
* Date: 12/07/2016                                                            *
*                                                                             *
* Description:  This file contain all needed function and definition          *
*				                                             				  *
*             Inputs: x          						                      *
*             Computations:                        					          *
*             Outputs: x							                          *
******************************************************************************/
#include<stdio.h>
#include<string.h>


/* Task 1 */
char *my_str_n_cpy(char *src_str, char *dest_str);

/* Task 2 */
int binary_search(int list[], int n, int target, int *target_index_ptr);

/* Task 3 */
void bubble_sort(char *list[], int size);

/* Task 4 */
int is_palindrome(int index, char *arr, int length);

/* Task 5 */
int sum_prime(unsigned int n, unsigned int prime_num, unsigned int sum);

/*Task 6*/
typedef struct occurrences
{
	int num_occurrences;
	double frequency;
} Occurrences;

int *maximum_occurences(char *string, Occurrences *ascii, int size, int *n, char *c);

/* Task 7 */
int smallest_sum_sequence(int arr[], int size);

/* Task 8 */
void max_consecutive_integers(int arr[][5], int rows, int cols, int **ptr1, int *ptr2);
