/****************************************************************************************
* Programmer: Yeji Chung																*
* Class		: CptS 121, Fall  2016														*
* Programming Assignment: PA2 : A Modular Approach to the Equation Evaluator			*
* Date		: September 9, 2016															*
*																						*
* Description: This program calculate following 7 equations evaluator					*
*				1. Newton’s Second Law of Motion										*
*				2. Volume of a cylinder: volume_cylinder								*
*				3. Character encoding													*
*				4. Equivalent parallel resistance										*
*				5. Resistive divider													*
*				6. Distance between two points											*
*				7. General equation														*
*				The program reads input of each equation from a user. Also, the results	*
*				calculations of 7 equations are displayed to the screen.     			*
*****************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#define PI 3.14		/*a constant value of PI*/

#include<stdio.h>	/* Header file for scanf, printf */
#include<math.h>	/* Header file for scanf, printf */

/************************************************************
* Function: calculate_newtons_2nd_law ()                    *
* Date Created: September 9, 2016		                    *
* Date Last Modified: September 9, 2016			            *
* Description: The function compute newton's law            *
* Input parameters: The mass in kg and acceleration in m/s^2*
* Returns: force as double									*
* Preconditions:										    *
* Postconditions:                                           *
*************************************************************/

double calculate_newtons_2nd_law(double mass, double acceleration);

/************************************************************
* Function: calculate_volume_cylinder ()                    *
* Date Created: September 9, 2016		                    *
* Date Last Modified: September 9, 2016			            *
* Description: The function compute volume of cylinder	    *
* Input parameters: The radius and height in meter			*
* Returns: voulume of cylinder as double                    *
* Preconditions:											*
* Postconditions:                                           *
*************************************************************/

double calculate_volume_cylinder(double radius, double height);

/************************************************************
* Function: perform_character_encoding ()                   *
* Date Created: September 9, 2016		                    *
* Date Last Modified: September 12, 2016			        *
* Description: The function encode the input character to   *
*				new character by shifting					*
* Input parameters: one character and number of shift		*
* Returns: The result of encording character		        *
* Preconditions:										    *
* Postconditions:                                           *
*************************************************************/

char perform_character_encoding(char plaintext_character, int shift);

/************************************************************
* Function: calculate_parallel_resistance ()	            *
* Date Created: September 9, 2016		                    *
* Date Last Modified: September 9, 2016			            *
* Description: The function calculate parallel resistence   *
* Input parameters:	resistence r1, r2 and r3				*
* Returns: The result of total parallel resistence          *
* Preconditions:										    *
* Postconditions:                                           *
*************************************************************/

double calculate_parallel_resistance(int r1, int r2, int r3);

/************************************************************
* Function: calculate_resistive_divider ()                  *
* Date Created: September 9, 2016		                    *
* Date Last Modified: September 9, 2016			            *
* Description: The function calculate resistive divider     *
* Input parameters: Resistence r1, r2 and input voltage		*
* Returns: Output voltage as double                         *
* Preconditions:											*
* Postconditions:                                           *
*************************************************************/

double calculate_resistive_divider(int r1, int r2, double vin);

/************************************************************
* Function: calculate_distance_between_2pts ()			    *
* Date Created: September 9, 2016		                    *
* Date Last Modified: September 9, 2016			            *
* Description: The function calculate distance between		*
*				two points (x1, y1) and (x2, y2)			*
* Input parameters: The points x1, x2, y1 and y2            *
* Returns: the distance as double                           *
* Preconditions:											*
* Postconditions:                                           *
*************************************************************/

double calculate_distance_between_2pts(double x1, double x2, double y1, double y2);

/************************************************************
* Function: calculate_general_equation ()                   *
* Date Created: September 9, 2016		                    *
* Date Last Modified: September 9, 2016			            *
* Description: The function calculate general equations     *
* Input parameters: a, x and z in following equation		*
*					 y = -x * (3 / 4) - z + a / (a % 2)		*
* Returns: the value of y		                            *
* Preconditions:								            *
* Postconditions:                                           *
*************************************************************/

double calculate_general_equation(int a, double x, double z);