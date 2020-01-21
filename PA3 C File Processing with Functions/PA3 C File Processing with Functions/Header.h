/*******************************************************************************
* Programmer: Yeji Chung		                                              *
* Class: CptS 121; Lab Section 16                                             *
* Programming Assignment: PA3 C File Processing with Functions.               *
* Date:  9/19/2016                                                            *
*                                                                             *
* Description: This file defines the function prototypes that the compiler    *
*              uses to recognize function calls, and define the constant.     *
******************************************************************************/

#define NEWLINE 1
#define NOT_NEWLINE 0
#define VOWEL 2
#define NOT_VOWEL 0
#define DIGIT 3
#define NOT_DIGIT 0
#define ALPHA 4
#define NOT_ALPHA 0
#define LOWER 5
#define NOT_LOWER 0
#define UPPER 6
#define NOT_UPPER 0
#define WHITESPACE 7
#define NOT_WHITESPACE 0
#define ALNUM 8
#define NOT_ALNUM 0
#define PUNCT 9
#define NOT_PUNCT 0

#include<stdio.h>
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
FILE *open_input_file(void);
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
char read_character(FILE *infile);
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
int determine_ascii_value(char character);
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
int is_line(char character);
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
int number_lines(char character, int current_number_lines);
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
int is_vowel(char character);
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
int number_vowels(char character, int current_number_vowels);
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
int is_digit(char character);
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
int number_digits(char character, int current_number_digits);
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
int is_alpha(char character);
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
int number_alphas(char character, int current_number_alphas);
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
int is_lower(char character);
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
int number_lowers(char character, int current_number_lowers);
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
int is_upper(char character);
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
int number_uppers(char character, int current_number_uppers);
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
int is_space(char character);
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
int number_spaces(char character, int current_number_spaces);

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
int is_alnum(char character);
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
int number_alnums(char character, int current_number_alnums);
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
int is_punct(char character);

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
int number_puncts(char character, int current_number_puncts);
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
void print_int(FILE *outfile, int number);
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
void print_stats(FILE *outfile, char header[], int number);




