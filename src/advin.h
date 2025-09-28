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
#ifndef ADVIN_H
#define ADVIN_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint8_t get_byte(char *prompt);

unsigned int get_uint(char *prompt);

short get_short(char *prompt);

int get_int(char *prompt);

long get_long(char *prompt);

long long get_long_long(char *prompt);

float get_float(char *prompt);

double get_double(char *prompt);

long double get_long_double(char *prompt);

char get_char(char *prompt);

char *get_string(char *prompt);

#endif
