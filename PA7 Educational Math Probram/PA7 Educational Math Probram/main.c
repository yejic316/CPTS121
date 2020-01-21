/******************************************************************************
* Programmer: Yeji Chung													  *
* Class: CptS 121; Lab Section 16                                             *
* Programming Assignment: PA7 Educational MAth Program                        *
* Date: 11/16/2016                                                            *
*                                                                             *
* Description:  This program is designed in purpose of mathematical education *
*				 for elementary school student.								  *
*             Inputs: x          						                      *
*             Computations:                        					          *
*             Outputs: x							                          *
******************************************************************************/
#include "header.h"

int main(void)
{
	int choice1 = 0, choice2 = 0, point=0;
	int count_correct=0;
	char initial[4] =  "ini\0" ;
	FILE *outfile = NULL;
	outfile = fopen("point_result_MATH_PROBLEM.dsv", "w");
	srand((unsigned int)time(NULL));
	printf("*************  THIS IS EDUCATIONAL MATH PROGRAM  *****************\n");

	do
	{
		display_menu();
		scanf("%d", &choice1);
		system("cls");
		switch (choice1)
		{
			case 1:
				display_how_to_use();
				system("pause");
				system("cls");
				break;
			case 2:
				printf("* Enter your initial : ");
				scanf("%s", initial);
				break;	
			case 3:
				printf("* Select difficulty between level1 ~ level5: ");
				scanf("%d", &choice2);
				break;
			case 4:
				switch (choice2)
				{
					case 1:
						printf("< LEVEL 1 >\n");

						for (int i = 0; i < 10; ++i)
						{
							point += level1(&count_correct);
						}
						printf("point : %d\n", point);
						break;
					case 2:
						printf("< LEVEL 2 >\n");
						for (int i = 0; i < 10; ++i)
						{
							point += level2(&count_correct);
						}
						printf("point : %d\n", point);
						break;
					case 3:
						printf("< LEVEL 3 >\n");
						for (int i = 0; i < 10; ++i)
						{
							point += level3(&count_correct);
						}
						printf("point : %d\n", point);
						break;
					case 4:
						printf("< LEVEL 4 >\n");
						for (int i = 0; i < 10; ++i)
						{
							point += level4(&count_correct);
						}
						printf("point : %d\n", point);
						break;
					case 5:
						printf("< LEVEL 5 >\n");
						for (int i = 0; i < 10; ++i)
						{
							point += level5(&count_correct);
						}
						printf("point : %d\n", point);
						break;
				}

				system("pause");
				system("cls");
				count_correct = 0;
				break;
			case 5:
				fprintf(outfile, " User Initial : %s\n   point : %d\n\n", initial, point);
				break;
		}
	} while (choice1!=5);
	fclose(outfile);
	return 0;
}