/******************************************************************************
* Programmer: Yeji Chung													  *
* Class: CptS 121; Lab Section 16                                             *
* Programming Assignment: PA7 Educational MAth Program                        *
* Date: 11/16/2016                                                            *
*                                                                             *
* Description:  This file contain all needed function and definition          *
*				                                             				  *
*             Inputs: x          						                      *
*             Computations:                        					          *
*             Outputs: x							                          *
******************************************************************************/
#include<stdio.h>
#include<stdlib.h>//rand()
#include<time.h> //rand()
#include<math.h> //abs() : absolute value

void display_menu(void);
void display_how_to_use(void);
int calculator(int a, int b, char oper, int *result, int*rem);

int level1(int *count_correct);
int level2(int *count_correct);
int level3(int *count_correct);
int level4(int *count_correct);
int level5(int *count_correct);


