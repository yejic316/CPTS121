/******************************************************************************
* Programmer: Yeji Chung													  *
* Class: CptS 121; Lab Section 16                                             *
* Programming Assignment: PA8 C Interview Question                            *
* Date: 12/07/2016                                                            *
*                                                                             *
* Description:  This program consist of 8 Question which is common question   *
*				for interview.                  							  *
*             Inputs: x          						                      *
*             Computations:                        					          *
*             Outputs: x							                          *
******************************************************************************/
#include "header.h"
int main(void)
{

	/*Task 1*/
	printf("\n< Task 1 : my_str_n_cpy>\n");
	char src_str[10] = "string", dest_str[10] = { '\0' };

	my_str_n_cpy(&src_str, &dest_str);
	printf("dest_str : %s\n", dest_str);

	system("pause");
	system("cls");

	/*Task2*/
	printf("\n< Task 2 : binary_search>\n");
	int list[12] = { 1,2,3,4,5,6,7,8,9,10,11,12 }, status = 0, index = 0;

	status = binary_search(list, 12, 8, &index);
	printf("status : %d ,index of target : %d\n", status, index);
	system("pause");
	system("cls");

	/*Task3*/	
	printf("\n< Task 3 : bubble_sort>\n");
	int *string_list[5] = { "bread", "fork", "egg", "apple", "candy" };

	bubble_sort(string_list, 5);
	for (int i = 0; i < 5; i++)
	{
		printf("%d) %s\n", i+1, string_list[i]);
	}
	system("pause");
	system("cls");

	/*Task4*/
	printf("\n< Task 4 : is_palindrome>\n");
	char *arr =  "racecar";
	int length = 0, result = 0;
	
	length = strlen(arr);
	result = is_palindrome(0, arr, length - 1);
	printf("%s\n", arr);
	printf("result : %d\n", result);
	system("pause");
	system("cls");

	/*Task5*/
	printf("\n< Task 5 : sum_prime>\n");
	unsigned int num_5 = 0, prime_num=0, sum=0, result_5=0;

	printf("* Compute sum of all primes from 2 to n\n Enter n :");
	scanf("%u", &num_5);
	result_5 = sum_prime(num_5, num_5, sum);
	printf("Sum : %u\n", result_5);
	system("pause");
	system("cls");

	/*Task6*/
	printf("\n< Task 6 : maximum_occurences>\n");
	char *string = "test string", max_c = 0;
	Occurrences ascii[123] = { {0, 0.0} };// 52 alphabet (Upper + Lower) and 1 white space 
	int max_num=0, *max_index = NULL;
	
	printf("string : ");
	puts(string);
	max_index = maximum_occurences(string, ascii, 123, &max_num, &max_c);
	printf(" max_index : %d, max_char : %c, max_num : %d, frequency : %lf\n", *max_index, max_c, max_num, ascii[*max_index].frequency);
	system("pause");
	system("cls");

	/*Task7*/
	printf("\n< Task 7 : smallest_sum_sequence>\n");
	int num_arr[10] = { -3, 5,-1, 4, -5, 2, -7, 1, -2 }, min_num=0;

	min_num = smallest_sum_sequence(num_arr, 10);
	printf("min_num : %d\n", min_num);
	system("pause");
	system("cls");

	/*Task8*/
	printf("\n< Task 8 : max_consecutive_integers>\n");

	int num_arr_8[4][5] = { {-5, 6, 0, 2, 2},
						{ 2, 2, 2, 9, 3 },
						{ 3, 3, 2, 1, -8 },
						{ 7, -2, 6, 0, 4 } },
		first_address = 0, consecutive_num = 0;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			printf(" %d [$%d]\t", num_arr_8[i][j], &num_arr_8[i][j]);
		}
		printf("\n");
	}

	max_consecutive_integers(num_arr_8, 4, 5, &first_address, &consecutive_num);
	printf("\naddress : %d, size : %d\n", first_address, consecutive_num);

	return 0;
}
