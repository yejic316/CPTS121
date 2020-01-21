/******************************************************************************
* Programmer: Yeji Chung													  *
* Class: CptS 121; Lab Section 16                                             *
* Programming Assignment: PA8 C Interview Question                            *
* Date: 12/07/2016                                                            *
*                                                                             *
* Description:  This file contain 8 function. Each function correspond to each*
*				interview question.             							  *
*             Inputs: x          						                      *
*             Computations:                        					          *
*             Outputs: x							                          *
******************************************************************************/
#include "header.h"
/* Task 1 */
char *my_str_n_cpy(char *src_str, char *dest_str)
{
	int i = 0;
	for (i = 0; src_str[i] != '\0'; ++i)
	{
		dest_str[i] = src_str[i];
	}
	dest_str[i] = '\0';
	return dest_str;
}

/* Task 2 */
int binary_search(int list[], int n, int target, int *target_index_ptr)
{
	int left_index = 1, right_index = n, mid_index = 0, found=0;
	*target_index_ptr = -1;
	while ((left_index <= right_index) && !found)
	{
		mid_index = (left_index + right_index) / 2;
		if (list[mid_index] == target)
		{
			found = 1;
			*target_index_ptr = mid_index;
		}
		else if (list[mid_index] < target)
		{
			left_index = mid_index + 1;
		}
		else
		{
			right_index = mid_index - 1;
		}
	}
	return found;

}

/* Task 3 */
void bubble_sort(char *list[], int size)
{
	int U = size - 1, C=0;
	char *temp = NULL;
		
	for (U = 1; U < size ; ++U)
	{
		for (C = 1; C < size-U+1; ++C)
		{

			if (*list[C] < *list[C - 1])
			{
				temp = list[C-1];
				list[C-1] = list[C];
				list[C] = temp;
			}

		}
	}

}

/* Task 4*/
int is_palindrome(int index, char *arr, int length)
{
	//	printf("index : %d\n", index);
	//printf("size : %d\n\n", size);
	if ((length - index) < 1)
	{
		return 1;
	}
	else
	{
		if (arr[index] == arr[length])
		{
			is_palindrome(index + 1, arr, length - 1);
		}
		else
		{
			return 0;
		}
	}
}

/* Task 5 */
int sum_prime(unsigned int n, unsigned int prime_num, unsigned int sum)
{
	int is_prime = 0;

	for (int i = 2; i < prime_num; ++i)
	{
		if (prime_num%i == 0)
		{
			is_prime = 0;
			break;
		}
		else
		{
			is_prime = 1;
		}
	}
	if (prime_num == 2)
	{
		return 2;
	}
	if (is_prime)
	{
		return prime_num + sum_prime(n, prime_num - 1, sum);
	}
	else
	{
		sum_prime(n, prime_num - 1, sum);
	}
}

/* Task 6 */
int *maximum_occurences(char *string, Occurrences *ascii, int size, int *n, char *c)
{
	int length = 0, *max_index_ptr = NULL, max_index = 0;
	max_index_ptr = &max_index;
	length = strlen(string);
	
	for (int i = 0; i < length; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (string[i] == (char)j)
			{
				(ascii[j].num_occurrences)++;
				ascii[j].frequency = (double)ascii[j].num_occurrences / length;
			}
		}
	}
	
	for (int i = 0; i < size; ++i)
	{
		if (ascii[i].num_occurrences > ascii[*max_index_ptr].num_occurrences)
		{
			*max_index_ptr = i;
		}
	}
	*n = ascii[*max_index_ptr].num_occurrences;
	*c = (char)(*max_index_ptr);

	return max_index_ptr;
}

/* Task 7 */
int smallest_sum_sequence(int arr[], int size)
{
	int sum = 0, min = 0;

	min = sum = arr[0];
	for (int i = 1; i < size; ++i)
	{
		if (sum > 0)
		{
			sum = arr[i];
		}
		else
		{
			sum += arr[i];
		}
		if (sum <= min)
		{
			min = sum;
		}
	}
	return min; 
}

/* Task 8 */
void max_consecutive_integers(int arr[][5], int rows, int cols, int **ptr1, int *ptr2)
{
	int temp = 0, count = 1;

	temp = arr[0][0];
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			if (temp == arr[i][j])
			{
				++count;
				if (*ptr2 < count)
				{
					*ptr2 = count;	
					*ptr1 = &arr[i][j]- count +1;
				}
			}
			else
			{
				temp = arr[i][j];
				count = 1;
			}
		}
	}
}