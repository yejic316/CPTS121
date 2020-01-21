/*******************************************************************************
* Programmer: Yeji Chung		                                              *
* Class: CptS 121; Lab Section 16                                             *
* Programming Assignment: PA3 C File Processing with Functions.               *
* Date:  9/19/2016                                                            *
*                                                                             *
* Description: This file contains the C source code that defines the functions*
*              that display input and output file, count lines, vowels, digits*
*              , alphabets, lower, upper, spaces, alphabet and digits,		  *
*              and punctuations.                                              *
******************************************************************************/
#include"header.h"

/*************************************************************
* Function: open_input_file()                               *
* Date Created: 9/17/2016                                   *
* Date Last Modified: 9/19/2016                             *
* Description: open the input file "input.txt"              *
* Input parameters: none                                    *
* Returns:					                                *
* Preconditions: Input text file should be exist.           *
* Postconditions: read this input file.                     *
*************************************************************/
FILE *open_input_file(void)
{
	fopen("input.txt", "r");

}

/*************************************************************
* Function: read_character(FILE *infile)                    *
* Date Created: 9/17/2016                                   *
* Date Last Modified: 9/19/2016                             *
* Description: read each character in the text file.        *
* Input parameters: file                                    *
* Returns: one character in the sentence	                *
* Preconditions: Input text file should be open.            *
* Postconditions: various process of sentence               *
*************************************************************/
char read_character(FILE *infile)
{
	char read_one_char = '\0';
	fscanf(infile, "%c", &read_one_char);
	//printf("%c\n", read_one_char);
	return read_one_char;
}

/*************************************************************
* Function: determine_ascii_value(char character)           *
* Date Created: 9/17/2016                                   *
* Date Last Modified: 9/19/2016                             *
* Description: determine ascii value of a character.        *
* Input parameters: a character in the sentence.            *
* Returns: an ascii value.                                  *
* Preconditions: a character should be read.                *
* Postconditions: display ascii value on output file.       *
*************************************************************/
int determine_ascii_value(char character)
{
	//printf("%d\n", (int)character);
	return (int)character;

}

/*************************************************************
* Function: is_line(char character)					        *
* Date Created: 9/17/2016                                   *
* Date Last Modified: 9/19/2016                             *
* Description: cognize new line.                            *
* Input parameters: a character in the sentence.            *
* Returns: the number of new line.                          *
* Preconditions: a character should be read.                *
* Postconditions: count total number of new line			*
*************************************************************/
int is_line(char character)
{ 
	if (character == '\n')
	{
		return NEWLINE;
	}
	else
	{
		return NOT_NEWLINE;
	}
}
/*************************************************************
* Function: number_lines(character, current_number_lines)   *
* Date Created: 9/17/2016                                   *
* Date Last Modified: 9/19/2016                             *
* Description: count the number of new line.                *
* Input parameters: a character and current number of line. *
* Returns: the result of counted new line.                  *
* Preconditions: cognize new line.			                *
* Postconditions: get total number of new line for 10 char  *
*************************************************************/
int number_lines(char character, int current_number_lines)
{
	if (is_line(character))
	{
		current_number_lines += 1;
	}
	//printf("%d\n", current_number_lines);
	return current_number_lines;
}

/*************************************************************
* Function: is_vowel(char character)				        *
* Date Created: 9/17/2016                                   *
* Date Last Modified: 9/19/2016                             *
* Description: cognize vowel in the sentence.               *
* Input parameters: a character in the sentence.            *
* Returns: the number of vowel.                             *
* Preconditions: a character should be read.                *
* Postconditions: count total number of vowel.				*
*************************************************************/
int is_vowel(char character)
{
	if ((character =='a')|| (character == 'e')||(character == 'i')|| (character == 'o')|| (character == 'u')||
		(character == 'A') || (character == 'E') || (character == 'I') || (character == 'O') || (character == 'U'))
	{
		return VOWEL;
	}
	else
	{
		return NOT_VOWEL;
	}
}
/*************************************************************
* Function: number_vowels(character, current_number_vowels)	*
* Date Created: 9/17/2016                                   *
* Date Last Modified: 9/19/2016                             *
* Description: count the number of vowel	                *
* Input parameters: a character and current number of vowel.*
* Returns: the result of counted vowel.		                *
* Preconditions: cognize vowel. 			                *
* Postconditions: get total number of vowel for 10 character*
*************************************************************/
int number_vowels(char character, int current_number_vowels)
{
	if (is_vowel(character))
	{
		current_number_vowels += 1;
	}
	//printf("%d\n", current_number_vowels);
	return current_number_vowels;
	
}
/*************************************************************
* Function: is_digit(char character)				        *
* Date Created: 9/17/2016                                   *
* Date Last Modified: 9/19/2016                             *
* Description: cognize digit in the sentence.               *
* Input parameters: a character in the sentence.            *
* Returns: the number of digit.                             *
* Preconditions: a character should be read.                *
* Postconditions: count total number of digit.				*
*************************************************************/
int is_digit(char character)
{
	if ((character >= '0') && (character <= '9'))
	{
		return DIGIT;
	}
	else
	{
		return NOT_DIGIT;
	}
}

/*************************************************************
* Function: number_digits(character, current_number_digits) *
* Date Created: 9/17/2016                                   *
* Date Last Modified: 9/19/2016                             *
* Description: count the number of digit.	                *
* Input parameters: a character and current number of digit.*
* Returns: the result of counted digit.		                *
* Preconditions: cognize digit. 			                *
* Postconditions: get total number of digit for 10 character*
*************************************************************/
int number_digits(char character, int current_number_digits)
{
	if (is_digit(character))
	{
		current_number_digits += 1;
	}
	return current_number_digits;
}

/*************************************************************
* Function: is_alpha(char character)				        *
* Date Created: 9/17/2016                                   *
* Date Last Modified: 9/19/2016                             *
* Description: cognize alphabets in the sentence.           *
* Input parameters: a character in the sentence.            *
* Returns: the number of alphabet.                          *
* Preconditions: a character should be read.                *
* Postconditions: count total number of alphabet.			*
*************************************************************/
int is_alpha(char character)
{
	if (((character >= 'a') && (character <= 'z'))||
		((character >= 'A') && (character <= 'Z')))
	{
		return ALPHA;
	}
	else
	{
		return NOT_ALPHA;
	}
}
/*************************************************************
* Function: number_alphas(character, current_number_alphas) *
* Date Created: 9/17/2016                                   *
* Date Last Modified: 9/19/2016                             *
* Description: count the number of alphabet.                *
* Input parameters: a character and current number of alpha.*
* Returns: the result of counted alphabets.		            *
* Preconditions: cognize alphabets			                *
* Postconditions: get total number of alpha for 10 character*
*************************************************************/
int number_alphas(char character, int current_number_alphas)
{
	if (is_alpha(character))
	{
		current_number_alphas += 1;
	}
	return current_number_alphas;
}

/*************************************************************
* Function: is_lower(char character)				        *
* Date Created: 9/17/2016                                   *
* Date Last Modified: 9/19/2016                             *
* Description: cognize lower level alphabet in the sentence.*
* Input parameters: a character in the sentence.            *
* Returns: the number of lowerlevel alphabet.               *
* Preconditions: a character should be read.                *
* Postconditions: count total number of lower level alphabet*
*************************************************************/
int is_lower(char character)
{
	if ((character >= 'a') && (character <= 'z'))
	{
		return LOWER;
	}
	else
	{
		return NOT_LOWER;
	}
}
/*************************************************************
* Function: number_lowers(character, current_number_lowers) *
* Date Created: 9/17/2016                                   *
* Date Last Modified: 9/19/2016                             *
* Description: count the number of lower level alphabet.    *
* Input parameters: a character and current number of lower.*
* Returns: the result of counted lower level of alphabets.  *
* Preconditions: cognize lower level of alphabets.			*
* Postconditions: get total number of lower for 10 character*
*************************************************************/
int number_lowers(char character, int current_number_lowers)
{
	if (is_lower(character))
	{
		current_number_lowers += 1;
	}
	return current_number_lowers;
}

/*************************************************************
* Function: is_upper(char character)				        *
* Date Created: 9/17/2016                                   *
* Date Last Modified: 9/19/2016                             *
* Description: cognize upper level alphabet in the sentence.*
* Input parameters: a character in the sentence.            *
* Returns: the number of upper level alphabet.              *
* Preconditions: a character should be read.                *
* Postconditions: count total number of upper level alphabet*
*************************************************************/
int is_upper(char character)
{
	if ((character >= 'A') && (character <= 'Z'))
	{
		return UPPER;
	}
	else
	{
		return NOT_UPPER;
	}
}

/*************************************************************
* Function: number_uppers(character, current_number_uppers) *
* Date Created: 9/17/2016                                   *
* Date Last Modified: 9/19/2016                             *
* Description: count the number of upper level alphabet.    *
* Input parameters: a character and current number of upper.*
* Returns: the result of counted upper level of alphabets.  *
* Preconditions: cognize upper level of alphabets.			*
* Postconditions: get total number of upper for 10 character*
*************************************************************/
int number_uppers(char character, int current_number_uppers)
{
	if (is_upper(character))
	{
		current_number_uppers += 1;
	}
	return current_number_uppers;
}

/*************************************************************
* Function: is_space(char character)				        *
* Date Created: 9/17/2016                                   *
* Date Last Modified: 9/19/2016                             *
* Description: cognize space in the sentence.               *
* Input parameters: a character in the sentence.            *
* Returns: the number of space.                             *
* Preconditions: a character should be read.                *
* Postconditions: count total number of space.				*
*************************************************************/
int is_space(char character)
{
	if ((character == ' ')|| (character == '\f')|| (character == '\n')||
		(character == '\r')|| (character == '\t')||(character == '\v'))
	{
		return WHITESPACE;
	}
	else
	{
		return NOT_WHITESPACE;
	}
}

/*************************************************************
* Function: number_spaces(character, current_number_spaces) *
* Date Created: 9/17/2016                                   *
* Date Last Modified: 9/19/2016                             *
* Description: count the number of space.	                *
* Input parameters: a character and current number of space.*
* Returns: the result of counted spaces.	                *
* Preconditions: cognize spaces.			                *
* Postconditions: get total number of space for 10 character*
*************************************************************/
int number_spaces(char character, int current_number_spaces)
{
	if (is_space(character))
	{
		current_number_spaces += 1;
	}
	return current_number_spaces;
}
/*************************************************************
* Function: is_alnum(char character)				        *
* Date Created: 9/17/2016                                   *
* Date Last Modified: 9/19/2016                             *
* Description: cognize alphabet and digit in the sentence.  *
* Input parameters: a character in the sentence.            *
* Returns: the number of alphabet and digit                 *
* Preconditions: a character should be read.                *
* Postconditions: count total number of alphabet and digit	*
*************************************************************/
int is_alnum(char character)
{
	if (((character >= 'a') && (character <= 'z')) ||
		((character >= 'A') && (character <= 'Z')) ||
		((character >= '0') && (character <= '9')))
	{
		return ALNUM;
	}
	else
	{
		return NOT_ALNUM;
	}
}
/*************************************************************
* Function: number_alnums(character, current_number_alnums) *
* Date Created: 9/17/2016                                   *
* Date Last Modified: 9/19/2016                             *
* Description: count the number of alphabets and digits     *
* Input parameters: a character and current number of alnum.*
* Returns: the result of counted alphabets and digits       *
* Preconditions: cognize alphabets and digits.              *
* Postconditions: get total number of alnum for 10 character*
*************************************************************/
int number_alnums(char character, int current_number_alnums)
{
	if (is_alnum(character))
	{
		current_number_alnums += 1;
	}
	return current_number_alnums;
}

/*************************************************************
* Function: is_punct(char character)				        *
* Date Created: 9/17/2016                                   *
* Date Last Modified: 9/19/2016                             *
* Description: cognize punctuations in the sentence.        *
* Input parameters: a character in the sentence.            *
* Returns: the number of punctuations.                      *
* Preconditions: a character should be read.                *
* Postconditions: count total number of punctuations.		*
*************************************************************/
int is_punct(char character)
{
	if (((character>='!')&& (character <='/'))||
		((character >= ':') && (character <= '@'))||
		((character >= '[') && (character <= 96))||
		((character >= '{') && (character <= '~')))
	{
		return PUNCT;
	}
	else
	{
		return NOT_PUNCT;
	}
}

/*************************************************************
* Function: number_puncts(character, current_number_puncts) *
* Date Created: 9/17/2016                                   *
* Date Last Modified: 9/19/2016                             *
* Description: count the number of punctuations.            *
* Input parameters: a character and current number of punct.*
* Returns: the result of counted punctuations.              *
* Preconditions: cognize punctuations.		                *
* Postconditions: get total number of punct for 10 character*
*************************************************************/
int number_puncts(char character, int current_number_puncts)
{
	if (is_punct(character))
	{
		current_number_puncts += 1;
	}
	return current_number_puncts;
}

/*************************************************************
* Function: print_int( outfile, number)				        *
* Date Created: 9/17/2016                                   *
* Date Last Modified: 9/19/2016                             *
* Description: Display ascii value to file "output_ascii"	*
* Input parameters: output file, number which is ascii value*
* Returns:	none 			                                *
* Preconditions: convert character to ascii value.	        *
* Postconditions: none						                *
*************************************************************/
void print_int(FILE *outfile, int number)
{	
	fprintf(outfile, "%d\n", number);
}
/*************************************************************
* Function: print_stats( outfile, header[], number)	        *
* Date Created: 9/17/2016                                   *
* Date Last Modified: 9/19/2016                             *
* Description: Display all result to file "output_status"	*
* Input parameters: output file, string text for display,	*
*					all result number on previous function	*
* Returns:	none 			                                *
* Preconditions: get final result for 10 character.	        *
* Postconditions: none						                *
*************************************************************/
void print_stats(FILE *outfile, char header[], int number)
{

	fprintf(outfile, "%s  %d\n", header, number);

}