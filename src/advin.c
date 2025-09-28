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
#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
 * get_int: provides validated integer input to the user. It will keep
 * asking for input until the provided input is a valid integer.
 */
int get_int(char *prompt)
{
	long int number;
	errno = 0;
	char *input;
	char *endptr;
	do
	{
		if (prompt)
		{
			printf("%s", prompt);
		}
		input = get_string("");
		number = strtol(input, &endptr, 10);
	} while (errno == ERANGE || number == LONG_MAX || number == LONG_MIN || endptr == input ||
	         number > INT_MAX || number < INT_MIN || *endptr != '\0' || isdigit(*input - '0') == 0);

	return (int)number;
}
