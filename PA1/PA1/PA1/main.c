/**************************************************************************************************
* Programmer: Andrew S. O'Fallon                                                                 *
* Class: CptS 121, Fall 2016; Lab Section 0                                                    *
* Programming Assignment: Solution to Programming Assignment #1 -                                *
*                         Equation Evaluator                                                     *
* Date:                                                                                          *
*                                                                                                *
* Description: This program evaluates seven different equations.                                 *
*              The constants represent coefficients and                                          *
*              coordinates that are used in the provided equations.                              *
*              The user is prompted to enter the values, and the formulas                        *
*              listed below are evaluated based on the user input.                               *
*              The equations are displayed with the constants and results.                       *
*                                                                                                *
*              Inputs: acceleration, mass_newton, cylinder_radius, cylinder_height,              *
*                      plaintext_character, shift,                                               *
*                      x1, x2, y1, y2, r1, r2, r3                                                *
*                      vin, x, z, a                                                              *
*              Constants: PI                                                                     *
*              Computations: See relevant formulas                                               *
*              Outputs: force_newton, volume_cylinder, encoded_character,                        *
*                       parallel_resistance, vout, distance_points, y                            *
*                                                                                                *
*              This program does not provide error checking and only                             *
*              uses sequential statements. This program defines only one                         *
*              function, main ().                                                                *
*                                                                                                *
* Relevant Formulas (The equation numbers are referenced in the comments of                      *
*                    the program):                                                               *
*          (1)Newton's 2nd Law: force_newton = mass_newton * acceleration                        *
*          (2)Volume of a cylinder: volume_cylinder = PI * radius^2 * cylinder_height            *
*          (3)Character encoding: encoded_character = (plaintext_character - 'A') + 'a' - shift  *
*          (4)Equivalent parallel resistance: parallel_resistance =                              *
*                                                                 1 / (1 / R1 + 1 / R2 + 1 / R3) *
*          (5)Resistive divider: vout = r2 / (r1 + r2) * vin                                     *
*          (6)Distance between two points: distance_points = square root of ((x1 - x2)^2 +       *
*                                                            (y1 - y2)^2)                        *
*          (7)General equation: y = -x * (3 / 4) - z + a / (a % 2)                               *
*************************************************************************************************/

#include <stdio.h> /* Include the standard input/output library for functions printf ( ) and scanf ( )*/
#include <math.h>  /* Included for sqrt ( ) */

#define PI 3.141592 /* Define a constant macro to represent PI for the relevant equations */

int main(void) /* The main ( ) function is the starting point of the program */
{
	int shift = 0,  /* Stores the value for the user inputted shift value in equation (3) */
		r1 = 0,	    /* Stores the first resistor value entered by the user for equations (4, 5) */
		r2 = 0,	    /* Stores the second resistor value entered by the user for equations (4, 5) */
		r3 = 0,		/* Stores the third resistor value entered by the user for equation (4) */
		a = 0;		/* Stores the value for the user inputted a coefficient in equation (7) */

	char plaintext_character = '\0', /* Stores the character inputted by the user for use in equation (3) */
		 encoded_character = '\0';   /* Stores the result of the encoding from equation (3) */

	double mass_newton = 0.0,       /* Stores the mass in grams of the value inputted by the user for equation (1) */
		acceleration = 0.0,         /* Stores the acceleration in m/s^2 of the value inputted by the user for equation (1) */
		force_newton = 0.0,         /* Stores the result of equation (1) */
		cylinder_radius = 0.0,      /* Stores the radius of the cylinder inputted by the user for equation (2) */
		cylinder_height = 0.0,      /* Stores the height of the cylinder inputted by the user for equation (2) */
		volume_cylinder = 0.0,      /* Stores the result of equation (2) */
		parallel_resistance = 0.0,  /* Stores the result of equation (4) */
		vin = 0.0,                  /* Stores the input voltage value entered by the user for equation (5) */
		vout = 0.0,                 /* Stores the result of the resisitive divider equation (5) */
		x1 = 0.0,					/* Stores the x1 value inputted by the user for equation (6) */
		x2 = 0.0,					/* Stores the x2 value inputted by the user for equation (6) */
		y1 = 0.0,					/* Stores the y1 value inputted by the user for equation (6) */
		y2 = 0.0,					/* Stores the y2 value inputted by the user for equation (6) */
		distance_points = 0.0,		/* Stores the distance between two points computed from equation (6) */
		x = 0.0,                    /* Stores x value inputted by user for equation (7) */
		z = 0.0,                    /* Stores z value inputted by user for equation (7) */
		y = 0.0;                    /* Stores the result of the general equation (7) */

	printf("*************** WELCOME TO THE EQUATION EVALUATOR **************\n\n");

	/* Prompt the user for 2 floating-point values that are used in Netwon's 2nd Law of Motion
	equation (1) */
	printf("Please enter the mass and acceleration (both floating-point values) for use in Newton's Second Law: ");

	/* Read the floating-point values into the proper variables: do not forget the
	"address of" operator (&) before each variable */
	scanf("%lf%lf", &mass_newton, &acceleration);

	/* Calculate the result of equation (1), which is force on an object
	provided its mass and acceleration */
	force_newton = mass_newton * acceleration;

	/* Print out the result of equation (1) */
	printf("Newton's Second Law: force = mass * acceleration = %lf * %lf = %lf\n",
		mass_newton, acceleration, force_newton);



	/* Prompt the user for 2 floating-point values that are used in volume of a cylinder
	equation (2) */
	printf("\nPlease enter the radius and height (both floating-point values) for use in a volume of cylinder equation: ");

	/* Read the floating-point values into the proper variables that are used in equation (2) */
	scanf("%lf%lf", &cylinder_radius, &cylinder_height);

	/* Calculate the result of equation (2), which is the volume of the cylinder
	derived from radius and height of it */
	volume_cylinder = PI * cylinder_radius * cylinder_radius * cylinder_height;

	/* Print out the result of equation (2) */
	printf("Volume of a cylinder: volume_cylinder = PI * radius^2 * height = %lf * %lf^2 * %lf = %lf\n",
		PI, cylinder_radius, cylinder_height, volume_cylinder);



	/* Prompt the user for 1 character value for use in equation (3) */
	printf("\nPlease enter the plaintext character and shift value (an integer)\n");
	printf (" for use in a character encoding equation : ");

	/* Read the character and integer into the proper variables that are used in equation (3) */
	/* Recall a space between the " and %c ignores all white space characters */
	scanf(" %c%d", &plaintext_character, &shift);

	/* Calculate the result of equation (3), which is the encoded character */
	encoded_character = (plaintext_character - 'A') + 'a' - shift;

	/* Print out the result of equation (3) */
	printf("Character encoding: encoded_character = (plaintext_character - 'A') + 'a' - shift = (%c - %c) + %c - %d = %c\n",
		plaintext_character, 'A', 'a', shift, encoded_character);



	/* Prompt the user for 3 integer resistor values for use in equation (4) */
	printf("\nPlease enter the r1, r2, and r3 values (all integers) for use in a equivalent parallel resistance equation: ");

	/* Read the integers into the proper variables: do not forget the
	"address of" operator (&) before each variable */
	scanf("%d%d%d", &r1, &r2, &r3);

	/* Calculate the result of equation (4), which is the equivalent parallel resistance */
	/* Explicitly case each integer r value to a double precision value so that 
	   double precision division is performed instead of integer division */
	parallel_resistance = 1 / ((1 / (double)r1) + (1 / (double)r2) + (1 / (double)r3));

	/* Print out the result of equation (4) */
	printf("Equivalent parallel resistance: parallel_resistance = 1 / (1 / R1 + 1 / R2 + 1 / R3) = 1 / (1 / %d + 1 / %d + 1 / %d) = %lf\n",
		r1, r2, r3, parallel_resistance);



	/* Prompt the user for 3 values (one floating-point and two integers) that are used in the resistive divider
	equation (5) */
	printf("\nPlease enter two resistance values (both integers) and an input voltage (a floating-point value) for use in\n");
	printf(" resistive divider equation: ");

	/* Read the floating-point values into the proper variables for equation (5) */
	scanf("%d%d%lf", &r1, &r2, &vin);

	/* Calculate the ouptut voltage for the resistive divider equation (5) */
	vout = r2 / (double)(r1 + r2) * vin;

	/* Print out the result of equation (5) */
	printf("Resistive divider: vout = r2 / (r1 + r2) * vin = %d / (%d + %d) * %lf = %lf\n",
		r2, r1, r2, vin, vout);



	/* Prompt the user for the coordinates of two points for use in equation (6) */
	printf("\nPlease enter the x1, y1, x2, and y2 (all floating point values) for use in a distance between points equation: ");

	/* Read in the floating-point values in the correct order for equation (6) */
	scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);

	/* Calculate the distance between points for equation (6) */
	distance_points = sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));

	/* Print out the distance between two points derived from equation (6) */
	printf("\nDistance between 2 pts: distance = sqrt ((x1 - x2)^2 + (y1 - y2)^2)\n");
	printf(" = sqrt ((%lf - %lf)^2 + (%lf - %lf)^2) = %lf\n", x1, x2, y1, y2, distance_points);



	/* Prompt the user for 2 floating-point and 1 integer values to be used
	in the general equation calculation (7) */
	printf("\nPlease enter x and z (both floating_point values) and a (an integer value)\n");
	printf(" for use in a general equation: ");

	/* Get the values needed for equation (7) */
	scanf("%lf%lf%d", &x, &z, &a);

	/* Calculate the result of equation (7), the result is a y-coordinate */
	y = -x * ((double)3 / 4) - z + a / (a % 2);

	/* Print the result of the general equation (7) */
	printf("general equation: y = -x * (3 / 4) - z + a / (a %% 2)\n = %lf * %lf - %lf + %d / (%d %% 2) = %lf\n\n", -x, ((double)3 / 4), z, a, a, y);


	return 0;
} /* End of program */