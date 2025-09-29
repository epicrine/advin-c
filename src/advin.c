/*
 * © 2025 Sivan Kiran Jadhav. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to use,
 * copy, modify, merge, publish, and distribute the Software, subject to the
 * following condition:
 *
 * 1. Attribution: You must give appropriate credit to the original author,
 *    Sivan, and indicate if changes were made. You may do so in any reasonable
 *    manner, but not in any way that suggests the author endorses you or your use.
 *
 * 2. No Warranty: The Software is provided "as is", without warranty of any
 *    kind, express or implied, including but not limited to the warranties of
 *    merchantability, fitness for a particular purpose, and noninfringement.
 *    In no event shall the author be liable for any claim, damages, or other
 *    liability, whether in an action of contract, tort, or otherwise, arising
 *    from, out of, or in connection with the Software or the use or other
 *    dealings in the Software.
 *
 * Author: Sivan
 * Created: 2025
 */
#include "advin.h"
#include <errno.h>
#include <float.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* STRING AND CHARACTEr */

/*
 * get_string: provides string input to the user safely. The safety
 * is ensured by dynamically allocating memory as we move ahead and
 * checking if there is enough memory to allocate otherwise return
 * an error.
 */
#ifndef CHAR_LEN
#define CHAR_LEN sizeof(char)
#endif
char *get_string(char *prompt)
{
	long capacity = 1;
	char *str = (char *)malloc((CHAR_LEN * capacity) + 1);
	if (str == NULL)
	{
		perror("Error 1: Could not allocate memory for input!");
		exit(EXIT_FAILURE);
	}

	if (prompt != NULL)
	{
		printf("%s", prompt);
		fflush(stdout);
	}

	int c = getchar();
	long length = 0;
	for (int i = 0; c != EOF && c != '\n'; i++, length++, c = getchar())
	{
		if (length == capacity)
		{
			capacity *= 2;
			char *tmp = (char *)realloc(str, (CHAR_LEN * capacity) + 1);
			if (tmp == NULL)
			{
				perror("Error 1: Could not allocate memory for input!");
				exit(EXIT_FAILURE);
				free(str);
			}
			else
			{
				str = tmp;
				tmp = NULL;
			}
		}
		str[i] = c;
	}

	char *tmp = NULL;
	if (length + 1 < capacity)
	{
		tmp = (char *)realloc(str, length + 1);
	}
	if (tmp != NULL)
	{
		str = tmp;
		tmp = NULL;
	}

	str[length] = '\0'; // Setting the NULL character

	return str;
}

/*
 * get_char: provides char to the user.
 */
char get_char(char *prompt)
{
	if (prompt)
	{
		printf("%s", prompt);
	}

	char c = getchar();

	return c;
}

/* END */

/* INTEGER RELATED TYPES */

/*
 * get_long_long: provides long long int input to the user, any upfront
 * white spaces handeling is not done by the library.
 */
long long get_long_long(char *prompt)
{
	long long number;
	int invalid;
	char *input;
	char *endptr;
	do
	{
		input = get_string(prompt);
		endptr = NULL;
		errno = 0;
		number = strtoll(input, &endptr, 10);
		invalid = (errno != 0 || errno == ERANGE || *endptr != '\0' || endptr == input ||
		           ((*input < '0' || *input > '9') && *input != '+' && *input != '-'));

		free(input);
	} while (invalid);

	return number;
}

/*
 * get_long: provides long int input to the user, any upfront
 * white spaces handeling is not done by the library.
 */
long get_long(char *prompt)
{
	long long number;
	do
	{
		number = get_long_long(prompt);
	} while (number > LONG_MAX || number < LONG_MIN);

	return number;
}

/*
 * get_int: provides validated integer input to the user. It will keep
 * asking for input until the provided input is a valid integer.
 * Any white spaces should be handeled beforehand as the spirit of
 * this library is to only provide input exactly of the relevant
 * type, without doing any special handeling of the input.
 */
int get_int(char *prompt)
{
	long number;
	do
	{
		number = get_long(prompt);
	} while (number > INT_MAX || number < INT_MIN);

	return number;
}

short int get_short(char *prompt)
{
	int number;
	do
	{
		number = get_int(prompt);
	} while (number > SHRT_MAX || number < SHRT_MIN);

	return number;
}

/* END */

/* UNSIGNED INTEGER RELATED TYPES */

/*
 * get_long_long_uint: provides long long unsigned integer input to the
 * user, any upfront white space handeling will not be done by the
 * library.
 */
unsigned long long get_long_long_uint(char *prompt)
{
	unsigned long long number;
	char *input;
	char *endptr;
	int valid;
	do
	{
		input = get_string(prompt);
		endptr = NULL;
		errno = 0;
		number = strtoull(input, &endptr, 10);
		valid = (0 != errno || errno == ERANGE || number > ULLONG_MAX || number < 0 ||
		         endptr == input || *endptr != '\0' ||
		         ((*input < '0' || *input > '9') && (*input != '+')));

		free(input);

	} while (valid);

	return number;
}

/*
 * get_long_uint: provides long unsigned integer input to the user, any up
 * front white space handeling will not be done by the library.
 */
unsigned long get_long_uint(char *prompt)
{
	unsigned long long number;
	do
	{
		number = get_long_long_uint(prompt);
	} while (number > ULONG_MAX || number < 0);

	return number;
}

/*
 * get_uint: provides unsigned integer input to the user, any up
 * front white space handeling will not be done by the library.
 */
unsigned int get_uint(char *prompt)
{
	unsigned long long number;
	do
	{
		number = get_long_uint(prompt);
	} while (number > UINT_MAX || number < 0);

	return number;
}

unsigned short get_short_uint(char *prompt)
{
	unsigned int number;
	do
	{
		number = get_uint(prompt);
	} while (number > USHRT_MAX || number < 0);

	return number;
}

/* END */

/* FLOATING POINT INTEGER RELATED TYPES */

/*
 * get_long_double: provides long double input to the user, any up
 * front white space handeling will not be done by the library.
 */
long double get_long_double(char *prompt)
{
	long double number;
	char *input;
	char *endptr;
	do
	{
		input = get_string(prompt);
		endptr = NULL;
		errno = 0;
		number = strtold(input, &endptr);
	} while (errno != 0 || errno == ERANGE || endptr == input || *endptr != '\0' ||
	         ((*input < '0' || *input > '9') && *input != '+' && *input != '-'));

	return number;
}

/*
 * get_double: provides double input to the user, any up
 * front white space handeling will not be done by the library.
 */
double get_double(char *prompt)
{
	double number;
	char *input;
	char *endptr;
	do
	{
		input = get_string(prompt);
		endptr = NULL;
		errno = 0;
		number = strtod(input, &endptr);
	} while (errno != 0 || errno == ERANGE || endptr == input || *endptr != '\0' ||
	         ((*input < '0' || *input > '9') && *input != '+' && *input != '-'));

	return number;
}

/*
 * get_float: provides floating point number input to the user, any up
 * front white space handeling will not be done by the library.
 */
float get_float(char *prompt)
{
	long double number;
	char *input;
	char *endptr;
	do
	{
		input = get_string(prompt);
		endptr = NULL;
		errno = 0;
		number = strtof(input, &endptr);
	} while (errno != 0 || errno == ERANGE || endptr == input || *endptr != '\0' ||
	         ((*input < '0' || *input > '9') && *input != '+' && *input != '-'));

	return number;
}

/* END */
