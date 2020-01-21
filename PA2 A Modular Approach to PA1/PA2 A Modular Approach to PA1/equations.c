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
#include"equations.h"

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

double calculate_newtons_2nd_law(double mass, double acceleration)
{
	double force_l = 0.0;
	force_l = mass * acceleration;
	return force_l;
}

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

double calculate_volume_cylinder(double radius, double height)
{
	double volume_cylinder_l = 0.0;
	volume_cylinder_l = (float)PI * radius * height;
	return volume_cylinder_l;
}

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

char perform_character_encoding(char plaintext_character, int shift)
{
	char encoded_character_l = '\0';
	encoded_character_l = (plaintext_character - 'A') + 'a' - shift;
	return encoded_character_l;
}

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

double calculate_parallel_resistance(int r1, int r2, int r3)
{
	double parallel_resistance_l = 0.0;
	parallel_resistance_l = 1 / ((float)1 / r1 + (float)1 / r2 + (float)1 / r3);
	return parallel_resistance_l;
}

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

double calculate_resistive_divider(int r1, int r2, double vin)
{
	double vout_l = 0.0;
	vout_l = (float)r2 / (r1 + r2) * vin;
	return vout_l;
}

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

double calculate_distance_between_2pts(double x1, double x2, double y1, double y2)
{
	double distance_l = 0.0;
	distance_l = (float)sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	return distance_l;
}

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

double calculate_general_equation(int a, double x, double z)
{
	double y_l = 0.0;
	y_l = -x *((float)3 / 4) - z + a / (a % 2);
	return y_l;
}