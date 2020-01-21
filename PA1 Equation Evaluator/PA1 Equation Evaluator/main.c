/****************************************************************************************
* Programmer: Yeji Chung																*
* Class		: CptS 121, Fall  2016														*
* Programming Assignment: PA1															*
* Date		: September 3, 2016															*
* Description: This program prints out 7 Equation Evaluator								*
*****************************************************************************************/
#define PI 3.14
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int main(void)
{
	int plaintext_character=0, encoded_character=0, shift=0,//using on equation 3
		R1=0, R2=0, R3=0,								//using on equation 4 and 5
		a=0;											//using on equation 7
	float force=0.0, mass=0.0, acceleration=0.0,		//using on equation 1
		volume_cylinder=0.0, radius= 0.0, height=0.0,	//using on equation 2
		parallel_resistance=0.0,						//using on equation 4
		vin=0.0, vout= 0.0,								//using on equation 5
		x1=0.0, y1=0.0, x2=0.0, y2=0.0, distance=0.0,	//using on equation 6
		x=0.0, y=0.0, z=0.0;							//using on equation 7

	//1. Newton’s Second Law of Motion
	printf("< Equation1 : Newton's Second Law of Motion >\n");
	printf("-Enter mass which is floating-value: ");
	scanf("%f", &mass);
	printf("-Enter acceleration which is floating-value: ");
	scanf(" %f", &acceleration);
	force = mass * acceleration;
	printf("force : %f\n\n\n", force);

	//2.Volume of a cylinder
	printf("< Equation2 : Volume of a cylinder >\n");
	printf("-Enter radius of cylinder which is floating-value: ");
	scanf(" %f", &radius);
	printf("-Enter height of cylinder which is floating-value: ");
	scanf(" %f", &height);
	volume_cylinder = (float)PI * radius * height;
	printf("volume of cylinder : %f\n\n\n", volume_cylinder);

	//3.Character encoding 
	printf("< Equation3 : Character encoding >\n");
	printf("-Enter a character text:");
	scanf(" %c", &plaintext_character);
	printf("-Enter shift number which is integer:");
	scanf(" %d", &shift);
	encoded_character = (plaintext_character - 'A') + 'a'-shift;
	printf("Encoding character: %c\n\n\n", encoded_character);
	

	//4.Equivalent parallel resistance
	printf("< Equation4 : Equivalent parallel resistance >\n");
	printf("-Enter R1, R2 and R3, which are integer:");
	scanf("%d%d%d", &R1, &R2, &R3);
	parallel_resistance = 1 / ((float)1 / R1 + (float)1 / R2 + (float)1 / R3);
	printf("total parallel resistance : %f\n\n\n", parallel_resistance);

	//5.Resistive divider
	printf("< Equation5 : Resistive divider >\n");
	printf("-Enter R1 and R2, which are integer:");
	scanf("%d%d", &R1, &R2);
	printf("-Enter input Voltage which is floating-value:");
	scanf(" %f", &vin);
	vout = (float)R2 / (R1 + R2) * vin;
	printf("Output voltage : %f\n\n\n", vout);

	//6. Distance between two points
	printf("< Equation6 : Distance between two points (x1,y1) and (x2,y2)>\n");
	printf("-Enter x1, y1, x2 and y2 which are floating-value:");
	scanf("%f%f%f%f", &x1, &y1, &x2, &y2);
	distance = (float)sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	printf("Distance between (%f, %f) and (%f, %f) = %f\n\n\n", x1, y1, x2, y2, distance);

	//7. General equation: y = -x * (3 / 4) - z + a / (a % 2)
	printf("< Equation7 : General equation \n y = -x * (3 / 4) - z + a / (a % 2)\n");
	printf("-Enter x, z,which are floating-value, and integer a");
	scanf("%f %f %d", &x, &z, &a);
	y = -x *((float)3 / 4) - z + a / (a % 2);
	printf("y=%f\n\n", y);

	return 0;
}