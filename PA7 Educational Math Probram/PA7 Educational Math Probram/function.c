/******************************************************************************
* Programmer: Yeji Chung													  *
* Class: CptS 121; Lab Section 16                                             *
* Programming Assignment: PA7 Educational MAth Program                        *
* Date: 11/16/2016                                                            *
*                                                                             *
* Description:  This file contain all used function.                          *
*				                                     						  *
*             Inputs: x          						                      *
*             Computations:                        					          *
*             Outputs: x							                          *
******************************************************************************/
#include "header.h"
void display_menu(void)
{
	printf("1. Learn about how to use the program\n");
	printf("2. Enter your initials (3 individual characters...).\n");
	printf("3. Difficulty selection\n");
	printf("4. Start a new sequence of problems\n");
	printf("5. Save and Quit\n");
}
void display_how_to_use(void)
{
	printf("< Purpose of Program >\n");
	printf(" * This program is designed in purpose of  mathematical education for elementary school student.\n");
	printf(" * This program contain addition, subtraction, multiplication, and division.\n");
	printf("   It is consist of 5 level section.\n");
	printf("   - level 1 involve addition and subtraction('+', '-') of two number with positive single digit operand.\n");
	printf("   - level 2 involve multiplication('*') of two number with positive single digit operand.\n");
	printf("   - level 3 involve division('/') of two number with positive single digit operand.\n");
	printf("   - level 4 involve all four operator('+', '-', '*', '/') of three number with positive and negative single digit operand.\n");
	printf("   - level 5 involve all four operator('+', '-', '*', '/') of four number with positive and negative two and three digit operand.\n");

	printf("\n< How To Get Points >\n");
	printf(" * Each level have different points you can get or loss.\n");
	printf(" * (level 1 : 1pts, level 2: 2pts, level 3: 3pts, level 4 : 4pts, level 5 : 5pts\n");
	printf(" * As you answer correctly, you will get the points, or not, you will lose the points.\n");
	printf(" * When you will be done this program, your points will record.\n");

	printf("\n< How To Use This Program >\n");
	printf(" 1. Enter your initial for recording points which you get.\n");
	printf(" 2. Select difficulty between level 1 ~ level 5\n");
	printf(" 3. Enjoy solving math problem.\n");
	printf("  - Recommand to start from level 1 for step-by-step learning\n");


	printf(" *** You should enter some answer as \"aRb\" for division problem, where a is quotient and b is remainder.\n");

}

int calculator(int a, int b, char oper, int *result, int*rem)
{
	if (oper == '+')
	{
		*result = a + b;
	}
	else if (oper == '-')
	{
		*result = a - b;
	}
	else if (oper == '*')
	{
		*result = a * b;
	}
	else
	{
		*result = a / b;
		*rem = a % b;
	}
}
int level1(int *count_correct)
{
	int num1 = 0, num2 = 0, result = 0, answer = 0, index = 0, point = 0;
	char operators[2] = {'+', '-'};

	index = rand() % 2;
	if (*count_correct < 5)//less than 5 correct answer-> easy problem
	{
		num1 = rand() % 5;
		num2 = rand() % 5;
	}
	else//more than 5 correct answer->hard problem
	{
		do
		{
			num1 = rand() % 10;
			num2 = rand() % 10;
		} while (num1 < 5 || num2 < 5);
	}
	calculator(num1, num2, operators[index], &result, 0);

	printf("> %d %c %d = ", num1, operators[index], num2);
	scanf("%d", &answer);
	if (result==answer)
	{
		++(*count_correct);
		printf("\t\"Correct!\"\n");
		point = 1;
	}
	else
	{
		printf("\t\"Wrong answer..\"\n");
		point = -1;
	}
	return point;
}
int level2(int *count_correct)
{
	int num1 = 0, num2 = 0, result = 0, answer = 0, point = 0;

	if (*count_correct < 5)//less than 5 correct answer-> easy problem
	{
		num1 = rand() % 5;
		num2 = rand() % 5;
	}
	else//more than 5 correct answer->hard problem
	{
		do
		{
			num1 = rand() % 10;
			num2 = rand() % 10;
		} while (num1 < 5 || num2 < 5);
	}
	calculator(num1, num2, '*', &result, 0);

	printf("> %d * %d = ", num1, num2);
	scanf("%d", &answer);
	if (result == answer)
	{
		++(*count_correct);
		printf("\t\"Correct!\"\n");
		point = 2;
	}
	else
	{
		printf("\t\"Wrong answer..\"\n");
		point = -2;
	}
	return point;
}
int level3(int *count_correct)
{
	int num1 = 0, num2 = 0, div = 0, rem = 0, answer_div = 0, answer_rem = 0, point = 0;

	if (*count_correct < 5)//less than 5 correct answer-> easy problem
	{
		num1 = rand() % 5;
		num2 = rand() % 4 + 1;
	}
	else//more than 5 correct answer->hard problem
	{
		do
		{
			num1 = rand() % 10;
			num2 = rand() % 9 + 1;
		}
		while (num1 < 2 || num2 < 2 );
	}
	calculator(num1, num2, '/', &div, &rem);

	printf("> %d / %d = ", num1, num2);
	printf("(Your answer should contain Remainder as \"aRb\" form. )\n=");

	scanf(" %dR%d", &answer_div, &answer_rem);
	if ((div == answer_div) && (rem == answer_rem))
	{
		++(*count_correct);
		printf("\t\"Correct!\"\n");
		point = 3;
	}
	else
	{
		printf("\t\"Wrong answer..\"\n");
		point = -3;
	}
	return point;
}
int level4(int *count_correct)
{
	int num1 = 0, num2 = 0, num3 = 0, result = 0, answer = 0,
		div = 0, rem = 0, answer_div = 0, answer_rem = 0,
		index1 = 0, index2 = 0, point = 0;
	char operators[4] = { '+', '-', '*', '/' };
	index1 = rand() % 4;
	index2 = rand() % 4;
	if (*count_correct < 5)//less than 5 correct answer-> easy problem
	{
		do
		{
			num1 = rand() % 19 - 9;
			num2 = rand() % 19 - 9;
			num3 = rand() % 19 - 9;
		} while ( abs(num1) > 5|| abs(num2) > 5 || abs(num3) > 5 || num1 == 0 || num2 == 0 || num3 == 0);
	}
	
	else//more than 5 correct answer->hard problem
	{
		do
		{
			num1 = rand() % 19 - 9;
			num2 = rand() % 19 - 9;
			num3 = rand() % 19 - 9;
		} while (abs(num1) < 5 || abs(num2) < 5 || abs(num3) < 5);
	}


	if ((index2==2 || index2 == 3) && (index1 == 0 || index1 == 1))
	{ //  case of  a+b*c1R4
		printf("case1\n");
		calculator(num2, num3, operators[index2], &result,  &rem);
		calculator(num1, result, operators[index1], &result, &rem);
	}
	else if (index2 == 2  && index1 == 3 ) //  case of  a/b*c
	{
		printf("case2\n");
		calculator(num1, num3, operators[index2], &result, &rem);
		calculator(result, num2, operators[index1], &result, &rem);
	}
	else if (index2 == 3 && index1 == 3)//  case of  a/b/c
	{
		printf("case3\n");
		calculator(num2, num3, operators[2], &result, &rem);
		calculator(num1, result, operators[index1], &result, &rem);
	}
	else// others (a+b-c , a*b/c ...)
	{
		printf("case4\n");

		calculator(num1, num2, operators[index1], &result, &rem);
		calculator(result, num3, operators[index2], &result, &rem);
	}
	
	printf("> %d %c %d %c %d = ", num1, operators[index1], num2, operators[index2], num3);
	if (index1 == 3 || index2 == 3)
	{
		printf("(Your answer should contain Remainder as \"aRb\" form. )\n=");
		scanf(" %dR%d", &answer_div, &answer_rem);
		if ((result == answer_div) && (rem == answer_rem))
		{
			++(*count_correct);

			printf("\t\"Correct!\"\n");
			point = 4;
		}
		else
		{
			printf("\t\"Wrong answer.. correct answer : %dR%d\"\n", div, rem);

			point = -4;
		}

	}
	else
	{
		scanf("%d", &answer);
		if (result == answer)
		{
			++(*count_correct);

			printf("\t\"Correct!\"\n");
			point = 4;
		}
		else
		{
			printf("\t\"Wrong answer.. correct answer : %d\"\n", result);
			point = -4;
		}

	}

	return point;
}
int level5(int *count_correct)
{
	int num1 = 0, num2 = 0, num3 = 0, num4 = 0, result = 0, answer = 0,
		div = 0, rem = 0, answer_div = 0, answer_rem = 0,
		index1 = 0, index2 = 0, index3 = 0, point = 0, temp=0;
	char operators[4] = { '+', '-', '*', '/' };
	index1 = rand() % 4;
	index2 = rand() % 4;
	index3 = rand() % 4;
	if (*count_correct < 5)//less than 5 correct answer-> easy problem
	{
		do
		{
			num1 = rand() % 1999 - 999;
			num2 = rand() % 1999 - 999;
			num3 = rand() % 1999 - 999;
			num4 = rand() % 1999 - 999;
		} while (abs(num1) > 100 || abs(num2) > 100 || abs(num3) > 100 || abs(num4) > 100 || abs(num1) <10 || abs(num2) <10 || abs(num3) <10 || abs(num4) <10);
	}

	else//more than 5 correct answer->hard problem
	{
		do
		{
			num1 = rand() % 1999 - 999;
			num2 = rand() % 1999 - 999;
			num3 = rand() % 1999 - 999;
			num4 = rand() % 1999 - 999;
		} while (num1 == 0 || num2 == 0 || num3 == 0 || num4 == 0);
	}
	
	if ((index2 > 1) && (index1 < 2 || index3 < 2))
	{ //  case of  a+b*c-d
		printf("case1\n");
		calculator(num2, num3, operators[index2], &result, &rem);
		calculator(num1, result, operators[index1], &result, &rem);
		calculator(result, num4, operators[index3], &result, &rem);
	}
	else if (index3 > 1  && index2 < 2)
	{ //  case of  a+b-c*d
		printf("case2\n");
		calculator(num3, num4, operators[index2], &temp, &rem);
		calculator(num1, num2, operators[index2], &result, &rem);
		calculator(result, temp, operators[index1], &result, &rem);
	}
	else if (index2 > 1 && index3 > 1 && index1<2)
	{//  case of  a+b/c*d
		printf("case3\n");
		calculator(num2, num3, operators[index2], &result, &rem);
		calculator(result, num4, operators[index3], &result, &rem);
		calculator(num1, result, operators[index1], &result, &rem);
	}
	else if (index1 == 3 && index3 ==3 && index2 == 3)
	{ //  case of  a/b/c/d
		printf("case4\n");
		calculator(num3, num4, operators[2], &temp, &rem);
		calculator(num2, result, operators[2], &result, &rem);
		calculator(num1, result, operators[index1], &result, &rem);
	}
	else// others 
	{
		printf("case5\n");

		calculator(num1, num2, operators[index1], &result, &rem);
		calculator(result, num3, operators[index2], &result, &rem);
		calculator(result, num4, operators[index3], &result, &rem);
	}
	
	printf("> %d %c %d %c %d %c %d= ", num1, operators[index1], num2, operators[index2], num3, operators[index3], num4);
	if (index1 == 3 || index2 == 3 || index3 == 3)
	{
		printf("(Your answer should contain Remainder as \"aRb\" form. )\n=");
		scanf(" %dR%d", &answer_div, &answer_rem);
		if ((result == answer_div) && (rem == answer_rem))
		{
			++(*count_correct);

			printf("\t\"Correct!\"\n");
			point = 5;
		}
		else
		{
			printf("\t\"Wrong answer.. correct answer : %dR%d\"\n", div, rem);

			point = -5;
		}

	}
	else
	{
		scanf("%d", &answer);
		if (result == answer)
		{
			++(*count_correct);

			printf("\t\"Correct!\"\n");
			point = 5;
		}
		else
		{
			printf("\t\"Wrong answer.. correct answer : %d\"\n", result);
			point = -5;
		}

	}

	return point;
}