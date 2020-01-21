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

int main(void)
{
	// local variables
	char plaintext_character = '\0', encoded_character = '\0';//using on equation 3
	int shift = 0,										//using on equation 3
		R1 = 0, R2 = 0, R3 = 0,								//using on equation 4 and 5
		a = 0;											//using on equation 7
	float force = 0.0, mass = 0.0, acceleration = 0.0,		//using on equation 1
		volume_cylinder = 0.0, radius = 0.0, height = 0.0,	//using on equation 2
		parallel_resistance = 0.0,						//using on equation 4
		vin = 0.0, vout = 0.0,								//using on equation 5
		x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0, distance = 0.0,	//using on equation 6
		x = 0.0, y = 0.0, z = 0.0;							//using on equation 7

	//1. Newton’s Second Law of Motion
	printf("< Equation1 : Newton's Second Law of Motion >\n");
	printf("-Enter mass which is floating-value: ");
	scanf("%f", &mass);
	printf("-Enter acceleration which is floating-value: ");
	scanf(" %f", &acceleration);

	force = calculate_newtons_2nd_law(mass, acceleration);
	printf("force : %f\n\n\n", force);


	//2.Volume of a cylinder
	printf("< Equation2 : Volume of a cylinder >\n");
	printf("-Enter radius of cylinder which is floating-value: ");
	scanf(" %f", &radius);
	printf("-Enter height of cylinder which is floating-value: ");
	scanf(" %f", &height);

	volume_cylinder =calculate_volume_cylinder(radius, height);
	printf("volume of cylinder : %f\n\n\n", volume_cylinder);

	
	//3.Character encoding 
	printf("< Equation3 : Character encoding >\n");
	printf("-Enter a character text:");
	scanf(" %c", &plaintext_character);
	printf("-Enter shift number which is integer:");
	scanf(" %d", &shift);

	encoded_character = perform_character_encoding(plaintext_character, shift);
	printf("Encoding character: %c\n\n\n", encoded_character);

	
	//4.Equivalent parallel resistance
	printf("< Equation4 : Equivalent parallel resistance >\n");
	printf("-Enter R1, R2 and R3, which are integer:");
	scanf(" %d%d%d", &R1, &R2, &R3);

	parallel_resistance = calculate_parallel_resistance(R1, R2, R3);
	printf("total parallel resistance : %f\n\n\n", parallel_resistance);


	//5.Resistive divider
	printf("< Equation5 : Resistive divider >\n");
	printf("-Enter R1 and R2, which are integer:");
	scanf("%d%d", &R1, &R2);
	printf("-Enter input Voltage which is floating-value:");
	scanf(" %f", &vin);

	vout = calculate_resistive_divider(R2,R2,vin);
	printf("Output voltage : %f\n\n\n", vout);


	//6. Distance between two points
	printf("< Equation6 : Distance between two points (x1,y1) and (x2,y2)>\n");
	printf("-Enter x1, y1, x2 and y2 which are floating-value:");
	scanf("%f%f%f%f", &x1, &y1, &x2, &y2);

	distance = calculate_distance_between_2pts(x1, x2, y1, y2);
	printf("Distance between (%f, %f) and (%f, %f) = %f\n\n\n", x1, y1, x2, y2, distance);


	//7. General equation: y = -x * (3 / 4) - z + a / (a % 2)
	printf("< Equation7 : General equation \n y = -x * (3 / 4) - z + a / (a % 2)\n");
	printf("-Enter x, z,which are floating-value, and integer a");
	scanf("%f %f %d", &x, &z, &a);

	y = calculate_general_equation(a, x, z);
	printf("y=%f\n\n", y);

	return 0;
}

